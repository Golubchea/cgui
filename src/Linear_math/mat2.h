#ifndef MAT2_H
#define MAT2_H

#include "vec2.h"
typedef struct {
  float xx; float xy;
  float yx; float yy;
} mat2;

mat2 mat2_id();
mat2 mat2_zero();
mat2 mat2_new(float xx, float xy, float yx, float yy);
mat2 mat2_mul_mat2(mat2 m1, mat2 mat2);
vec2 mat2_mul_vec2(mat2 m, vec2 v);

mat2 mat2_transpose(mat2 m);
float mat2_det(mat2 m);
mat2 mat2_inverse(mat2 m);

void mat2_to_array(mat2 m, float* out);
void mat2_print(mat2 m);
mat2 mat2_rotation(float a);
#endif //MAT2
