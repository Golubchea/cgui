#pragma once
#include <glad.h>
#include "ctm_Mouse.h"
#include "ctm_Camera.h"
#include "ctm_Screen.h"
#include "LoadShaders.h"
// Program to render from the light's position

typedef struct ctm_light_uniforms_t
{
    GLint model_view_projection_matrix;
} ctm_light_uniforms;



// Program to render the scene from the viewer's position

typedef struct ctm_scene_uniforms_t
{
    GLint model_matrix;
    GLint view_matrix;
    GLint projection_matrix;
    GLint shadow_matrix;
    GLint light_position;
    GLint material_ambient;
    GLint material_diffuse;
    GLint material_specular;
    GLint material_specular_power;
} ctm_scene_uniforms;

// Ground plane






typedef struct ctm_3dobject_t
{
    VBObject object;
    mat4 scene_model_matrix;
}ctm_3dobject;



typedef struct ctm_Render_t
{
    GLuint  ground_vbo;
    GLuint  ground_vao;
    // FBO to render depth with
    GLuint  depth_fbo;
    GLuint  depth_texture;
    GLuint render_light_prog;
    GLuint render_scene_prog;
    int DEPTH_TEXTURE_SIZE  ;
    bool depth_only;
}ctm_Render;

ctm_Render ctm_Render_new()
{
    ctm_Render m;
    m.depth_only=false;
    m.DEPTH_TEXTURE_SIZE= 2048;
    return m;
}

void ctm_Render_DrawScene(bool depth_only,ctm_Render *r,ctm_scene_uniforms *su,ctm_3dobject *obj)
{
    // Set material properties for the object
    if (!depth_only)
    {
        vec3 v={0.1f, 0.0f, 0.2f};

        GLfloat* ptr=(GLfloat*) &v ;



        glUniform3fv(su->material_ambient, 1,ptr);
        v=vec3_new(0.18f, 0.76f, 0.1f);
        glUniform3fv(su->material_diffuse, 1, ptr);
        v=vec3_new( 1.0f, 1.0f, 1.0f);
        glUniform3fv(su->material_specular, 1, ptr);
        glUniform1f(su->material_specular_power, 25.0f);
    }


    // Draw the object
    VBObject  * ptr;
    ptr=&obj->object;
    VBObject_render(ptr,0,0);


    // Set material properties for the ground
    if (!depth_only)
    {
        vec3 v={0.5f, 0.5f, 0.5f};

        GLfloat* ptr=(GLfloat*) &v ;

        glUniform3fv(su->material_ambient, 1,ptr);
        v=vec3_new(1.0f, 1.0f, 1.0f);
        glUniform3fv(su->material_diffuse, 1, ptr);
        v=vec3_new(0.99f, 0.99f, 0.99f);
        glUniform3fv(su->material_specular, 1, ptr);

        glUniform1f(su->material_specular_power, 3.0f);
    }

    // Draw the ground
    glBindVertexArray(r->ground_vao);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glBindVertexArray(0);
}

void Initialize(ctm_Render *r,ctm_scene_uniforms *su,ctm_light_uniforms *lu,int DEPTH_TEXTURE_SIZE) {
    // Create the program for rendering the scene from the light's POV.

    glCreateProgram();

    ShaderInfo light_shaders[] =
    {
        { GL_VERTEX_SHADER, "resources/shaders/shadowmap_shadow.vs.glsl" },
        { GL_FRAGMENT_SHADER, "resources/shaders/shadowmap_shadow.fs.glsl" },
        { GL_NONE }
    };

    r->render_light_prog = LoadShaders(light_shaders);

    // Get the location of the projetion_matrix uniform
    lu->model_view_projection_matrix = glGetUniformLocation(r->render_light_prog, "model_view_projection_matrix");

    // Create the program for rendering the scene from the viewer's position
    ShaderInfo scene_shaders[] =
    {
        { GL_VERTEX_SHADER, "resources/shaders/shadowmap_scene.vs.glsl" },
        { GL_FRAGMENT_SHADER, "resources/shaders/shadowmap_scene.fs.glsl" },
        { GL_NONE }
    };

    r->render_scene_prog = LoadShaders(scene_shaders);

    // Get the locations of all the uniforms in the program
    su->model_matrix = glGetUniformLocation(r->render_scene_prog, "model_matrix");
    su->view_matrix = glGetUniformLocation(r->render_scene_prog, "view_matrix");
    su->projection_matrix = glGetUniformLocation(r->render_scene_prog, "projection_matrix");
    su->shadow_matrix = glGetUniformLocation(r->render_scene_prog, "shadow_matrix");
    su->light_position = glGetUniformLocation(r->render_scene_prog, "light_position");
    su->material_ambient = glGetUniformLocation(r->render_scene_prog, "material_ambient");
    su->material_diffuse = glGetUniformLocation(r->render_scene_prog, "material_diffuse");
    su->material_specular = glGetUniformLocation(r->render_scene_prog, "material_specular");
    su->material_specular_power = glGetUniformLocation(r->render_scene_prog, "material_specular_power");

    // Set the depth texture uniform to unit 0
    glUseProgram(r->render_scene_prog);
    glUniform1i(glGetUniformLocation(r->render_scene_prog, "depth_texture"), 0);

    // Create a depth texture
    glGenTextures(1, &r->depth_texture);
    glBindTexture(GL_TEXTURE_2D, r->depth_texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, DEPTH_TEXTURE_SIZE, DEPTH_TEXTURE_SIZE, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);

    // Create FBO to render depth into
    glGenFramebuffers(1, &r->depth_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, r->depth_fbo);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, r->depth_texture, 0);
    glDrawBuffer(GL_NONE);

    GLuint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);

    if(status != GL_FRAMEBUFFER_COMPLETE){
        //  std::cout<< "Framebuffer Error: " << std::hex << status << std::endl;
        exit(1);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Upload geometry for the ground plane
    static const float ground_vertices[] =
    {
        -500.0f, -50.0f, -500.0f, 1.0f,
        -500.0f, -50.0f,  500.0f, 1.0f,
        500.0f, -50.0f,  500.0f, 1.0f,
        500.0f, -50.0f, -500.0f, 1.0f,
    };

    static const float ground_normals[] =
    {
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };

    glGenVertexArrays(1, &r->ground_vao);
    glGenBuffers(1, &r->ground_vbo);
    glBindVertexArray(r->ground_vao);
    glBindBuffer(GL_ARRAY_BUFFER, r->ground_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(ground_vertices) + sizeof(ground_normals), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(ground_vertices), ground_vertices);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(ground_vertices), sizeof(ground_normals), ground_normals);

    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, NULL);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (const GLvoid *)sizeof(ground_vertices));
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);



}

void ctm_Display(ctm_Mouse* m,ctm_Camera *c,ctm_Screen *s,ctm_3dobject *obj,ctm_Render *r,ctm_light_uniforms *lu,ctm_scene_uniforms *su ) {


    float t =  (float)(SDL_GetTicks() & 0xFFFF) / (float)0xFFFF;


    vec3 Y1={0.0f, 1.0f, 0.0f};



    vec3 light_position1=vec3_new(sinf(t * 6.0f * 3.141592f) * 300.0f, 600.0f, cosf(t * 4.0f * 3.141592f) * 100.0f + 250.0f);

    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Matrices for rendering the scene

    obj->scene_model_matrix=mat4_rotation_axis_angle(Y1,t * (float)M_PI*4);

    c->horizontalAngle =  m->mouseSpeed * (float)( m->mouse_x_last/2.0f-m->mouse_x);
    c->verticalAngle   = m->mouseSpeed * (float)(  m->mouse_y_last/2.0f-m->mouse_y ) ;
    m->mouse_x_last= m->mouse_x;
    m->mouse_y_last=m->mouse_y;
    c->direction1=vec3_new(cosf(c->verticalAngle) *  sinf(c->horizontalAngle), sinf(c->verticalAngle), cosf(c->verticalAngle) *  cosf(c->horizontalAngle)) ;

    c->right1=vec3_new(sinf(c->horizontalAngle - 3.14f/2.0f),0, cosf(c->horizontalAngle - 3.14f/2.0f) );

    vec3 up1 = vec3_cross(c->right1,c->direction1);


    vec3 posPlusDirectionV31=vec3_add(c->position1,c->direction1);

    mat4 scene_view_matrix1=mat4_look_at(c->position1,posPlusDirectionV31,up1);

    mat4 scene_projection_matrix1=mat4_frustrum(-1.0f, 1.0f, -c->aspect, c->aspect, 1.0f, c->FRUSTUM_DEPTH);//mat4_perspective(60.0f, 1.0f, FRUSTUM_DEPTH,aspect);





    mat4 scale_bias_matrix1=mat4_new(0.5f, 0.0f, 0.0f, 0.0f,
                                     0.0f, 0.5f, 0.0f, 0.0f,
                                     0.0f, 0.0f, 0.5f, 0.0f,
                                     0.5f, 0.5f, 0.5f, 1.0f) ;


    // Matrices used when rendering from the light's position
    mat4 light_view_matrix1 = mat4_look_at(light_position1,vec3_zero(),Y1);


    mat4 light_projection_matrix1= mat4_frustrum(-1.0f, 1.0f, -1.0f, 1.0f, 1.0f, c->FRUSTUM_DEPTH  );

    // Now we render from the light's position into the depth buffer.
    // Select the appropriate program
    glUseProgram(r->render_light_prog);

    mat4 temp =mat4_mul_mat4(light_projection_matrix1,light_view_matrix1);
    mat4 temp2 = mat4_mul_mat4(temp,obj->scene_model_matrix);





    GLfloat* ptr1=(GLfloat*)  &temp2 ;
    glUniformMatrix4fv(lu->model_view_projection_matrix, 1, GL_FALSE,  ptr1);


    //  glUniformMatrix4fv(render_light_uniforms.model_view_projection_matrix, 1, GL_FALSE, glm::value_ptr(light_projection_matrix * light_view_matrix * scene_model_matrix));
    
    // Bind the 'depth only' FBO and set the viewport to the size of the depth texture
    glBindFramebuffer(GL_FRAMEBUFFER, r->depth_fbo);
    glViewport(0, 0, r->DEPTH_TEXTURE_SIZE, r->DEPTH_TEXTURE_SIZE);
    // Clear
    glClearDepth(1.0f);
    glClear(GL_DEPTH_BUFFER_BIT);
    glClearColor(255,255,255,1);
    // Enable polygon offset to resolve depth-fighting isuses
    glEnable(GL_POLYGON_OFFSET_FILL);
    glPolygonOffset(2.0f, 4.0f);
    // Draw from the light's point of view
    ctm_Render_DrawScene(true,r,su,obj);
    glDisable(GL_POLYGON_OFFSET_FILL);

    // Restore the default framebuffer and field of view
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, s->current_width, s->current_height);
    // Now render from the viewer's position
    glUseProgram(r->render_scene_prog);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Setup all the matrices
    //glUniformMatrix4fv(render_scene_uniforms.model_matrix, 1, GL_FALSE, glm::value_ptr(scene_model_matrix));



    GLfloat* ptr=(GLfloat*)  &obj->scene_model_matrix ;

    glUniformMatrix4fv(su->model_matrix, 1, GL_FALSE,ptr);
    ptr=(GLfloat*)&scene_view_matrix1 ;

    glUniformMatrix4fv(su->view_matrix, 1, GL_FALSE,   ptr );
    ptr=(GLfloat*)&scene_projection_matrix1 ;
    glUniformMatrix4fv(su->projection_matrix, 1, GL_FALSE, ptr);
    mat4 temp_m1= mat4_mul_mat4(scale_bias_matrix1 , light_projection_matrix1);
    mat4 temp_m2  = mat4_mul_mat4(temp_m1, light_view_matrix1);
    ptr=(GLfloat*)&temp_m2 ;
    glUniformMatrix4fv(su->shadow_matrix, 1, GL_FALSE, ptr);

    GLfloat* ptr2=(GLfloat*)  &light_position1 ;
    glUniform3fv(su->light_position, 1, ptr2);


    // Bind the depth texture
    glBindTexture(GL_TEXTURE_2D, r->depth_texture);
    glGenerateMipmap(GL_TEXTURE_2D);


    ctm_Render_DrawScene(false,r,su,obj);
}



void ctm_finalize(ctm_Render *r) {
    glUseProgram(0);
    glDeleteProgram(r->render_light_prog);
    glDeleteProgram(r->render_scene_prog);
    glDeleteBuffers(1, &r->ground_vbo);
    glDeleteVertexArrays(1, &r->ground_vao);
}


