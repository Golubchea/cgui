#ifndef MAT4_H
#define MAT4_H


#include "vec3.h"
#include "vec4.h"

#include "mat3.h"
/* mat4 */

typedef struct {
  float xx; float xy; float xz; float xw;
  float yx; float yy; float yz; float yw;
  float zx; float zy; float zz; float zw;
  float wx; float wy; float wz; float ww;
} mat4;

mat4 mat4_id();
mat4 mat4_zero();
mat4 mat4_new(float xx, float xy, float xz, float xw,
              float yx, float yy, float yz, float yw,
              float zx, float zy, float zz, float zw,
              float wx, float wy, float wz, float ww);
float mat4_at(mat4 m, int i, int j);
mat4 mat4_set(mat4 m, int x, int y, float v);
mat4 mat4_transpose(mat4 m);

mat4 mat4_mul_mat4(mat4 m1, mat4 mat2);

vec4 mat4_mul_vec4(mat4 m, vec4 v);
vec3 mat4_mul_vec3(mat4 m, vec3 v);

float mat4_det(mat4 m);
mat4 mat4_inverse(mat4 m);

mat4 mat3_to_mat4(mat3 m);
mat3 mat4_to_mat3(mat4 m);


void mat4_to_array(mat4 m, float* out);
void mat4_to_array_trans(mat4 m, float* out);

void mat4_print(mat4 m);

mat4 mat4_translation(vec3 v);
mat4 mat4_scale(vec3 v);

mat4 mat4_rotation_x(float a);
mat4 mat4_rotation_y(float a);
mat4 mat4_rotation_z(float a);
mat4 mat4_rotation_axis_angle(vec3 axis, float angle);

mat4 mat4_rotation_euler(float x, float y, float z);


mat4 mat4_view_look_at(vec3 position, vec3 target, vec3 up);
mat4 mat4_perspective(float fov, float near_clip, float far_clip, float ratio);
mat4 mat4_orthographic(float left, float right, float bottom, float top, float near, float far);

mat4 mat4_lerp(mat4 m1, mat4 mat2, float amount);
mat4 mat4_smoothstep(mat4 m1, mat4 mat2, float amount);
mat4 mat4_frustrum( float left,  float right, float bottom, float top,  float nearVal, float farVal);


mat4 mat4_look_at(vec3 position, vec3 target, vec3 up);
#endif // MAT4
