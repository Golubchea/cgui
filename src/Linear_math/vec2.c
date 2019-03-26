#include "vec2.h"
#include "stdio.h"
#include <math.h>
vec2 vec2_new(float x, float y) {
  vec2 v;
  v.x = x;
  v.y = y;
  return v;
}

vec2 vec2_zero() {
  return vec2_new(0, 0);
}

vec2 vec2_one() {
  return vec2_new(1, 1);
}

vec2 vec2_add(vec2 v1, vec2 v2) {
  vec2 v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  return v;
}

vec2 vec2_sub(vec2 v1, vec2 v2) {
  vec2 v;
  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  return v;
}

vec2 vec2_div(vec2 v, float fac) {
  v.x = v.x / fac;
  v.y = v.y / fac;
  return v;
}

vec2 vec2_div_vec2(vec2 v1, vec2 v2) {
  v1.x = v1.x / v2.x;
  v1.y = v1.y / v2.y;
  return v1;
}

vec2 vec2_mul(vec2 v, float fac) {
  v.x = v.x * fac;
  v.y = v.y * fac;
  return v;
}

vec2 vec2_mul_vec2(vec2 v1, vec2 v2) {
  vec2 v;
  v.x = v1.x * v2.x;
  v.y = v1.y * v2.y;
  return v;
}

vec2 vec2_pow(vec2 v, float exp) {
  v.x = pow(v.x, exp);
  v.y = pow(v.y, exp);
  return v;
}

vec2 vec2_neg(vec2 v) {
  v.x = -v.x;
  v.y = -v.y;
  return v;
}

vec2 vec2_abs(vec2 v) {
  v.x = fabs(v.x);
  v.y = fabs(v.y);
  return v;
}

vec2 vec2_floor(vec2 v) {
  v.x = floor(v.x);
  v.y = floor(v.y);
  return v;
}

vec2 vec2_fmod(vec2 v, float val) {
  v.x = fmod(v.x, val);
  v.y = fmod(v.y, val);
  return v;
}



void vec2_print(vec2 v) {
  printf("vec2(%4.2f,%4.2f)", v.x, v.y);
}

float vec2_dot(vec2 v1, vec2 v2) {
  return (v1.x * v2.x) + (v1.y * v2.y);
}

float vec2_length_sqrd(vec2 v) {
  float length = 0.0;
  length += v.x * v.x;
  length += v.y * v.y;
  return length;
}

float vec2_length(vec2 v) {
  return sqrt(vec2_length_sqrd(v));
}

float vec2_dist_sqrd(vec2 v1, vec2 v2) {
  return (v1.x - v2.x) * (v1.x - v2.x) +
         (v1.y - v2.y) * (v1.y - v2.y);
}

float vec2_dist(vec2 v1, vec2 v2) {
  return sqrt(vec2_dist_sqrd(v1, v2));
}

float vec2_dist_manhattan(vec2 v1, vec2 v2) {
  return fabs(v1.x - v2.x) + fabs(v1.y - v2.y);
}

vec2 vec2_normalize(vec2 v) {
  float len = vec2_length(v);
  return vec2_div(v, len);
}

vec2 vec2_reflect(vec2 v1, vec2 v2) {
  return vec2_sub(v1, vec2_mul(v2, 2 * vec2_dot(v1, v2)));
}

vec2 vec2_from_string(char* s) {

  char* pEnd;
  double d1, d2;
  d1 = strtod(s,&pEnd);
  d2 = strtod(pEnd,NULL);

  vec2 v;
  v.x = d1;
  v.y = d2;

  return v;
}

bool vec2_equ(vec2 v1, vec2 v2) {
  if(!(v1.x == v2.x)) { return false; }
  if(!(v1.y == v2.y)) { return false; }
  return true;
}

void vec2_to_array(vec2 v, float* out) {
  out[0] = v.x;
  out[1] = v.y;
}

