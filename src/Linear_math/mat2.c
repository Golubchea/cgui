#include"mat2.h"

mat2 mat2_id() {
  mat2 mat;
  mat.xx = 1.0f; mat.xy = 0.0f;
  mat.yx = 0.0f; mat.yy = 1.0f;
  return mat;
}

mat2 mat2_zero() {
  mat2 mat;
  mat.xx = 0.0f; mat.xy = 0.0f;
  mat.yx = 0.0f; mat.yy = 0.0f;
  return mat;
}

mat2 mat2_new(float xx, float xy, float yx, float yy) {
  mat2 mat;
  mat.xx = xx;
  mat.xy = xy;
  mat.yx = yx;
  mat.yy = yy;
  return mat;
}

mat2 mat2_mul_mat2(mat2 m1, mat2 m2) {
  mat2 mat;

  mat.xx = m1.xx * m2.xx + m1.xy * m2.yx;
  mat.xy = m1.xx * m2.xy + m1.xy * m2.yy;
  mat.yx = m1.yx * m2.xx + m1.yy * m2.yx;
  mat.yy = m1.yx * m2.xy + m1.yy * m2.yy;

  return mat;
}

vec2 mat2_mul_vec2(mat2 m, vec2 v) {
  vec2 vec;

  vec.x = v.x * m.xx + v.y * m.xy;
  vec.y = v.x * m.yx + v.y * m.yy;

  return vec;
}

mat2 mat2_transpose(mat2 m) {
  mat2 ret;
  ret.xx = m.xx;
  ret.xy = m.yx;
  ret.yx = m.xy;
  ret.yy = m.yy;
  return ret;
}

float mat2_det(mat2 m) {
  return m.xx * m.yy - m.xy * m.yx;
}

mat2 mat2_inverse(mat2 m) {

  float det = mat2_det(m);
  float fac = 1.0 / det;

  mat2 ret;

  ret.xx = fac * m.yy;
  ret.xy = fac * -m.xy;
  ret.yx = fac * -m.yx;
  ret.yy = fac * m.xx;

  return ret;
}

void mat2_to_array(mat2 m, float* out) {

  out[0] = m.xx;
  out[1] = m.xy;
  out[2] = m.yx;
  out[3] = m.yy;

}

void mat2_print(mat2 m) {
  printf("|%4.2f, %4.2f|\n", m.xx, m.xy);
  printf("|%4.2f, %4.2f|\n", m.yx, m.yy);
}

mat2 mat2_rotation(float a) {
  mat2 m;

  m.xx = cos(a);
  m.xy = -sin(a);
  m.yx = sin(a);
  m.yy = cos(a);

  return m;
}
