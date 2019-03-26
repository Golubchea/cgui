#include"mat3.h"

mat3 mat3_zero() {
  mat3 mat;

  mat.xx = 0.0f;
  mat.xy = 0.0f;
  mat.xz = 0.0f;

  mat.yx = 0.0f;
  mat.yy = 0.0f;
  mat.yz = 0.0f;

  mat.zx = 0.0f;
  mat.zy = 0.0f;
  mat.zz = 0.0f;

  return mat;
}

mat3 mat3_id() {
  mat3 mat;

  mat.xx = 1.0f;
  mat.xy = 0.0f;
  mat.xz = 0.0f;

  mat.yx = 0.0f;
  mat.yy = 1.0f;
  mat.yz = 0.0f;

  mat.zx = 0.0f;
  mat.zy = 0.0f;
  mat.zz = 1.0f;

  return mat;
}

mat3 mat3_new(float xx, float xy, float xz,
              float yx, float yy, float yz,
              float zx, float zy, float zz) {
  mat3 mat;

  mat.xx = xx;
  mat.xy = xy;
  mat.xz = xz;

  mat.yx = yx;
  mat.yy = yy;
  mat.yz = yz;

  mat.zx = zx;
  mat.zy = zy;
  mat.zz = zz;

  return mat;
}

mat3 mat3_mul_mat3(mat3 m1, mat3 m2) {
  mat3 mat;

  mat.xx = (m1.xx * m2.xx) + (m1.xy * m2.yx) + (m1.xz * m2.zx);
  mat.xy = (m1.xx * m2.xy) + (m1.xy * m2.yy) + (m1.xz * m2.zy);
  mat.xz = (m1.xx * m2.xz) + (m1.xy * m2.yz) + (m1.xz * m2.zz);

  mat.yx = (m1.yx * m2.xx) + (m1.yy * m2.yx) + (m1.yz * m2.zx);
  mat.yy = (m1.yx * m2.xy) + (m1.yy * m2.yy) + (m1.yz * m2.zy);
  mat.yz = (m1.yx * m2.xz) + (m1.yy * m2.yz) + (m1.yz * m2.zz);

  mat.zx = (m1.zx * m2.xx) + (m1.zy * m2.yx) + (m1.zz * m2.zx);
  mat.zy = (m1.zx * m2.xy) + (m1.zy * m2.yy) + (m1.zz * m2.zy);
  mat.zz = (m1.zx * m2.xz) + (m1.zy * m2.yz) + (m1.zz * m2.zz);

  return mat;

}

vec3 mat3_mul_vec3(mat3 m, vec3 v) {

  vec3 vec;

  vec.x = (m.xx * v.x) + (m.xy * v.y) + (m.xz * v.z);
  vec.y = (m.yx * v.x) + (m.yy * v.y) + (m.yz * v.z);
  vec.z = (m.zx * v.x) + (m.zy * v.y) + (m.zz * v.z);

  return vec;

}

mat3 mat3_transpose(mat3 m) {
  mat3 ret;
  ret.xx = m.xx;
  ret.xy = m.yx;
  ret.xz = m.zx;

  ret.yx = m.xy;
  ret.yy = m.yy;
  ret.yz = m.zy;

  ret.zx = m.xz;
  ret.zy = m.yz;
  ret.zz = m.zz;
  return ret;
}

float mat3_det(mat3 m) {
  return (m.xx * m.yy * m.zz) + (m.xy * m.yz * m.zx) + (m.xz * m.yx * m.zy) -
         (m.xz * m.yy * m.zx) - (m.xy * m.yx * m.zz) - (m.xx * m.yz * m.zy);
}

mat3 mat3_inverse(mat3 m) {

  float det = mat3_det(m);
  float fac = 1.0 / det;

  mat3 ret;
  ret.xx = fac * mat2_det(mat2_new(m.yy, m.yz, m.zy, m.zz));
  ret.xy = fac * mat2_det(mat2_new(m.xz, m.xy, m.zz, m.zy));
  ret.xz = fac * mat2_det(mat2_new(m.xy, m.xz, m.yy, m.yz));

  ret.yx = fac * mat2_det(mat2_new(m.yz, m.yx, m.zz, m.zx));
  ret.yy = fac * mat2_det(mat2_new(m.xx, m.xz, m.zx, m.zz));
  ret.yz = fac * mat2_det(mat2_new(m.xz, m.xx, m.yz, m.yx));

  ret.zx = fac * mat2_det(mat2_new(m.yx, m.yy, m.zx, m.zy));
  ret.zy = fac * mat2_det(mat2_new(m.xy, m.xx, m.zy, m.zx));
  ret.zz = fac * mat2_det(mat2_new(m.xx, m.xy, m.yx, m.yy));

  return ret;

}

void mat3_to_array(mat3 m, float* out) {

  out[0] = m.xx;
  out[1] = m.yx;
  out[2] = m.zx;

  out[3] = m.xy;
  out[4] = m.yy;
  out[5] = m.zy;

  out[6] = m.xz;
  out[7] = m.yz;
  out[8] = m.zz;

}

void mat3_print(mat3 m) {
  printf("|%4.2f, %4.2f, %4.2f|\n", m.xx, m.xy, m.xz);
  printf("|%4.2f, %4.2f, %4.2f|\n", m.yx, m.yy, m.yz);
  printf("|%4.2f, %4.2f, %4.2f|\n", m.zx, m.zy, m.zz);
}

mat3 mat3_rotation_x(float a) {

  mat3 m = mat3_id();

  m.yy = cos(a);
  m.yz = -sin(a);
  m.zy = sin(a);
  m.zz = cos(a);

  return m;

}

mat3 mat3_scale(vec3 s) {

  mat3 m = mat3_id();
  m.xx = s.x;
  m.yy = s.y;
  m.zz = s.z;
  return m;

}

mat3 mat3_rotation_y(float a) {

  mat3 m = mat3_id();

  m.xx = cos(a);
  m.xz = sin(a);
  m.zx = -sin(a);
  m.zz = cos(a);

  return m;

}

mat3 mat3_rotation_z(float a) {

  mat3 m = mat3_id();

  m.xx = cos(a);
  m.xy = -sin(a);
  m.yx = sin(a);
  m.yy = cos(a);

  return m;

}

mat3 mat3_rotation_angle_axis(float a, vec3 v) {

  mat3 m;

  float c = cos(a);
  float s = sin(a);
  float nc = 1 - c;

  m.xx = v.x * v.x * nc + c;
  m.xy = v.x * v.y * nc - v.z * s;
  m.xz = v.x * v.z * nc + v.y * s;

  m.yx = v.y * v.x * nc + v.z * s;
  m.yy = v.y * v.y * nc + c;
  m.yz = v.y * v.z * nc - v.x * s;

  m.zx = v.z * v.x * nc - v.y * s;
  m.zy = v.z * v.y * nc + v.x * s;
  m.zz = v.z * v.z * nc + c;

  return m;
}
