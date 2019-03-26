#ifndef MAT3_H
#define MAT3_H


#include"vec3.h"


typedef struct {
  float xx; float xy; float xz;
  float yx; float yy; float yz;
  float zx; float zy; float zz;
} mat3;

mat3 mat3_id();
mat3 mat3_zero();
mat3 mat3_new(float xx, float xy, float xz,
              float yx, float yy, float yz,
              float zx, float zy, float zz);
mat3 mat3_mul_mat3(mat3 m1, mat3 mat2);
vec3 mat3_mul_vec3(mat3 m, vec3 v);

mat3 mat3_transpose(mat3 m);
float mat3_det(mat3 m);
mat3 mat3_inverse(mat3 m);

void mat3_to_array(mat3 m, float* out);
void mat3_print(mat3 m);

mat3 mat3_scale(vec3 s);
mat3 mat3_rotation_x(float a);
mat3 mat3_rotation_y(float a);
mat3 mat3_rotation_z(float a);
mat3 mat3_rotation_angle_axis(float angle, vec3 axis);


#endif // MAT3
