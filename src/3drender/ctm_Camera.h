


#pragma once
#include "ctm_Mouse.h"
#include "ctm_Screen.h"
#include <SDL2/SDL.h>
// Initial position : on +Z
typedef struct camera_t
{
    vec3 position1;
    float horizontalAngle;
    float verticalAngle;
    float FoV;
    float aspect;
    vec3 direction1;
    vec3 right1;
   float FRUSTUM_DEPTH ;

}ctm_Camera;

ctm_Camera ctm_Camera_new()
{
    ctm_Camera cam;
    cam.position1=vec3_new( 200.17, 200.53, 200.43);
    cam.horizontalAngle= 3.14f;
    cam.verticalAngle=0.0f;
    cam.FoV=45.0f;
    cam.FRUSTUM_DEPTH=   1800.0f;

    return cam;
}


void mouseButtonDown(SDL_MouseButtonEvent *ev,ctm_Screen *s) {
    /* Read color, depth and stencil index from the framebuffer */
//    GLbyte color[4];
//    GLfloat depth;
//    GLuint index;




//    glReadPixels(ev->x, s->window_height - ev->y - 1, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
//    glReadPixels(ev->x, s->window_height - ev->y - 1, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
//    glReadPixels(ev->x, s->window_height - ev->y - 1, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

//    printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
//           ev->x, ev->y, color[0], color[1], color[2], color[3], depth, index);

//    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
//                   "mouse pushed in function");
//    //scene_model_matrix1=mat4_rotation_y(14 * float(M_PI*4));

//    //*********************************************************************************************



}

void ctm_Camera_handle(SDL_Event *event,SDL_Window *w,ctm_Mouse* m,ctm_Camera *c,ctm_Screen *s)
{
    if(event->button.button==SDL_BUTTON_LEFT){
        mouseButtonDown(&event->button,s);
    }

    if(event->type==SDL_MOUSEMOTION&&event->button.button==SDL_BUTTON_MIDDLE){
        m->mouse_x = event->motion.x;
        m->mouse_y = event->motion.y;
    }
    if(event->type==SDL_KEYDOWN){
        switch(event->key.keysym.sym){
        case SDLK_w:
            c->position1  = vec3_add(c->position1,c->direction1) ;
            break;
        case SDLK_s:
            c->position1  =  vec3_sub(c->position1,c->direction1)  ;
            break;
        case SDLK_a:
            c->position1  =  vec3_sub(c->position1,c->right1)  ;
            break;
        case SDLK_d:
            c->position1  =   vec3_add(c->position1,c->right1) ;
            break;
        }
    }
    if(event->type ==SDL_WINDOWEVENT){
        if(event->window.event = SDL_WINDOWEVENT_SIZE_CHANGED){

            SDL_GetWindowSize(w,&s->window_width,&s->window_height);
            s->current_width =s->window_width;
            s->current_height = s->window_height;

            c->aspect = (float)(s->window_height) / (float)(s->window_width);
        }
    }
}
