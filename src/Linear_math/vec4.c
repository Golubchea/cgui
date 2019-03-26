#include "vec4.h"
#include <stdio.h>
#include <math.h>
/* vec4 */

vec4 vec4_new(float x, float y, float z, float w) {
  vec4 v;
  v.x = x;
  v.y = y;
  v.z = z;
  v.w = w;
  return v;
}

vec4 vec4_zero() {
  return vec4_new(0, 0, 0, 0);
}

vec4 vec4_one() {
  return vec4_new(1, 1, 1, 1);
}

vec4 vec4_red() {
  return vec4_new(1,0,0,1);
}

vec4 vec4_green() {
  return vec4_new(0,1,0,1);
}

vec4 vec4_blue() {
  return vec4_new(0,0,1,1);
}

vec4 vec4_white() {
  return vec4_new(1,1,1,1);
}

vec4 vec4_black() {
  return vec4_new(0,0,0,1);
}

vec4 vec4_grey() {
  return vec4_new(0.5,0.5,0.5, 1);
}

vec4 vec4_light_grey() {
  return vec4_new(0.75,0.75,0.75, 1);
}

vec4 vec4_dark_grey() {
  return vec4_new(0.25,0.25,0.25, 1);
}

vec4 vec4_add(vec4 v1, vec4 v2) {
  vec4 v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  v.z = v1.z + v2.z;
  v.w = v1.w + v2.w;
  return v;
}

vec4 vec4_sub(vec4 v1, vec4 v2) {
  vec4 v;
  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  v.z = v1.z - v2.z;
  v.w = v1.w - v2.w;
  return v;
}

vec4 vec4_div(vec4 v, float fac) {
  v.x = v.x / fac;
  v.y = v.y / fac;
  v.z = v.z / fac;
  v.w = v.w / fac;
  return v;
}

vec4 vec4_mul(vec4 v, float fac) {
  v.x = v.x * fac;
  v.y = v.y * fac;
  v.z = v.z * fac;
  v.w = v.w * fac;
  return v;
}

vec4 vec4_mul_vec4(vec4 v1, vec4 v2) {
  vec4 v;
  v.x = v1.x * v2.x;
  v.y = v1.y * v2.y;
  v.z = v1.z * v2.z;
  v.w = v1.w * v2.w;
  return v;
}

vec4 vec4_pow(vec4 v, float exp) {
  v.x = pow(v.x, exp);
  v.y = pow(v.y, exp);
  v.z = pow(v.z, exp);
  v.w = pow(v.w, exp);
  return v;
}

vec4 vec4_neg(vec4 v) {
  v.x = -v.x;
  v.y = -v.y;
  v.z = -v.z;
  v.w = -v.w;
  return v;
}

vec4 vec4_abs(vec4 v) {
  v.x = fabs(v.x);
  v.y = fabs(v.y);
  v.z = fabs(v.z);
  v.w = fabs(v.w);
  return v;
}

vec4 vec4_floor(vec4 v) {
  v.x = floor(v.x);
  v.y = floor(v.y);
  v.z = floor(v.z);
  v.w = floor(v.w);
  return v;
}

vec4 vec4_fmod(vec4 v, float val) {
  v.x = fmod(v.x, val);
  v.y = fmod(v.y, val);
  v.z = fmod(v.z, val);
  v.w = fmod(v.w, val);
  return v;
}

vec4 vec4_sqrt(vec4 v) {
  v.x = sqrt(v.x);
  v.y = sqrt(v.y);
  v.z = sqrt(v.z);
  v.w = sqrt(v.w);
  return v;
}

void vec4_print(vec4 v) {
  printf("vec4(%4.2f, %4.2f, %4.2f, %4.2f)", v.x, v.y, v.z,  v.w);
}

float vec4_dot(vec4 v1, vec4 v2) {
  return  (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z) + (v1.w * v2.w);
}

float vec4_length_sqrd(vec4 v) {
  float length = 0.0;
  length += v.x * v.x;
  length += v.y * v.y;
  length += v.z * v.z;
  length += v.w * v.w;
  return length;
}

float vec4_length(vec4 v) {
  return sqrt(vec4_length_sqrd(v));
}

float vec4_dist_sqrd(vec4 v1, vec4 v2) {
  return (v1.x - v2.x) * (v1.x - v2.x) +
         (v1.y - v2.y) * (v1.y - v2.y) +
         (v1.y - v2.z) * (v1.y - v2.z) +
         (v1.y - v2.w) * (v1.y - v2.w);
}

float vec4_dist(vec4 v1, vec4 v2) {
  return sqrt(vec4_dist_sqrd(v1, v2));
}

float vec4_dist_manhattan(vec4 v1, vec4 v2) {
  return fabs(v1.x - v2.x) + fabs(v1.y - v2.y) + fabs(v1.z - v2.z) + fabs(v1.w - v2.w);
}

vec4 vec4_normalize(vec4 v) {
  float len = vec4_length(v);
  if (len == 0.0) {
    return vec4_zero();
  } else {
    return vec4_div(v, len);
  }
}

vec4 vec4_reflect(vec4 v1, vec4 v2) {
  return vec4_sub(v1, vec4_mul(v2, 2 * vec4_dot(v1, v2)));
}

vec4 vec4_from_string(char* s) {
  char* end;
  double d1, d2, d3, d4;
  d1 = strtod(s,&end);
  d2 = strtod(end,&end);
  d3 = strtod(end,&end);
  d4 = strtod(end,NULL);

  vec4 v;
  v.x = d1;
  v.y = d2;
  v.z = d3;
  v.w = d4;

  return v;
}


bool vec4_equ(vec4 v1, vec4 v2) {
  if(!(v1.x == v2.x)) { return false; }
  if(!(v1.y == v2.y)) { return false; }
  if(!(v1.z == v2.z)) { return false; }
  if(!(v1.w == v2.w)) { return false; }
  return true;
}

void vec4_to_array(vec4 v, float* out) {
  out[0] = v.x;
  out[1] = v.y;
  out[2] = v.z;
  out[3] = v.w;
}

vec3 vec4_from_homogeneous(vec4 v) {
  vec3 vec = vec3_new(v.x,v.y,v.z);
  return vec3_div(vec, v.w);
}

