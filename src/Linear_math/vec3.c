#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include"vec3.h"
#include"vec4.h"

/* vec3 */

vec3 vec3_new(float x, float y, float z) {
  vec3 v;
  v.x = x;
  v.y = y;
  v.z = z;
  return v;
}

vec3 vec3_zero() {
  return vec3_new(0, 0, 0);
}

vec3 vec3_one() {
  return vec3_new(1, 1, 1);
}

vec3 vec3_red() {
  return vec3_new(1, 0, 0);
}

vec3 vec3_green() {
  return vec3_new(0, 1, 0);
}

vec3 vec3_blue() {
  return vec3_new(0, 0, 1);
}

vec3 vec3_white() {
  return vec3_new(1, 1, 1);
}

vec3 vec3_black() {
  return vec3_new(0, 0, 0);
}

vec3 vec3_grey() {
  return vec3_new(0.5, 0.5, 0.5);
}

vec3 vec3_light_grey() {
  return vec3_new(0.75,0.75,0.75);
}

vec3 vec3_dark_grey() {
  return vec3_new(0.25,0.25,0.25);
}

vec3 vec3_up() {
  return vec3_new(0, 1, 0);
}

vec3 vec3_add(vec3 v1, vec3 v2) {
  vec3 v;
  v.x = v1.x + v2.x;
  v.y = v1.y + v2.y;
  v.z = v1.z + v2.z;
  return v;
}

vec3 vec3_sub(vec3 v1, vec3 v2) {
  vec3 v;
  v.x = v1.x - v2.x;
  v.y = v1.y - v2.y;
  v.z = v1.z - v2.z;
  return v;
}

vec3 vec3_div(vec3 v, float fac) {
  v.x = v.x / fac;
  v.y = v.y / fac;
  v.z = v.z / fac;
  return v;
}

vec3 vec3_div_vec3(vec3 v1, vec3 v2) {
  vec3 v;
  v.x = v1.x / v2.x;
  v.y = v1.y / v2.y;
  v.z = v1.z / v2.z;
  return v;
}

vec3 vec3_mul(vec3 v, float fac) {
  v.x = v.x * fac;
  v.y = v.y * fac;
  v.z = v.z * fac;
  return v;
}

vec3 vec3_mul_vec3(vec3 v1, vec3 v2) {
  vec3 v;
  v.x = v1.x * v2.x;
  v.y = v1.y * v2.y;
  v.z = v1.z * v2.z;
  return v;
}

vec3 vec3_pow(vec3 v, float exp) {
  v.x = pow(v.x, exp);
  v.y = pow(v.y, exp);
  v.z = pow(v.z, exp);
  return v;
}

vec3 vec3_neg(vec3 v) {
  v.x = -v.x;
  v.y = -v.y;
  v.z = -v.z;
  return v;
}

vec3 vec3_abs(vec3 v) {
  v.x = fabs(v.x);
  v.y = fabs(v.y);
  v.z = fabs(v.z);
  return v;
}

vec3 vec3_floor(vec3 v) {
  v.x = floor(v.x);
  v.y = floor(v.y);
  v.z = floor(v.z);
  return v;
}

vec3 vec3_fmod(vec3 v, float val) {
  v.x = fmod(v.x, val);
  v.y = fmod(v.y, val);
  v.z = fmod(v.z, val);
  return v;
}

void vec3_print(vec3 v) {
  printf("vec3(%4.2f,%4.2f,%4.2f) \n", v.x, v.y, v.z);
}

float vec3_dot(vec3 v1, vec3 v2) {
  return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

vec3 vec3_cross(vec3 v1, vec3 v2) {
  vec3 v;
  v.x = (v1.y * v2.z) - (v1.z * v2.y);
  v.y = (v1.z * v2.x) - (v1.x * v2.z);
  v.z = (v1.x * v2.y) - (v1.y * v2.x);
  return v;
}

float vec3_length_sqrd(vec3 v) {
  float length = 0.0;
  length += v.x * v.x;
  length += v.y * v.y;
  length += v.z * v.z;
  return length;
}

float vec3_length(vec3 v) {
  return sqrt(vec3_length_sqrd(v));
}

float vec3_dist_sqrd(vec3 v1, vec3 v2) {
  return (v1.x - v2.x) * (v1.x - v2.x) +
         (v1.y - v2.y) * (v1.y - v2.y) +
         (v1.z - v2.z) * (v1.z - v2.z);
}

float vec3_dist(vec3 v1, vec3 v2) {
  return sqrt(vec3_dist_sqrd(v1, v2));
}

float vec3_dist_manhattan(vec3 v1, vec3 v2) {
  return fabs(v1.x - v2.x) + fabs(v1.y - v2.y) + fabs(v1.z - v2.z);
}

vec3 vec3_normalize(vec3 v) {
  float len = vec3_length(v);
  if (len == 0.0) {
    return vec3_zero();
  } else {
    return vec3_div(v, len);
  }
}

vec3 vec3_reflect(vec3 v1, vec3 v2) {
  return vec3_sub(v1, vec3_mul(v2, 2 * vec3_dot(v1, v2)));
}

vec3 vec3_project(vec3 v1, vec3 v2) {
  return vec3_sub(v1, vec3_mul(v2, vec3_dot(v1, v2)));
}

vec3 vec3_from_string(char* s) {

  char* pEnd;
  double d1, d2, d3;
  d1 = strtod(s,&pEnd);
  d2 = strtod(pEnd,&pEnd);
  d3 = strtod(pEnd,NULL);

  vec3 v;
  v.x = d1;
  v.y = d2;
  v.z = d3;

  return v;

}

bool vec3_equ(vec3 v1, vec3 v2) {
  if (v1.x != v2.x) { return false; }
  if (v1.y != v2.y) { return false; }
  if (v1.z != v2.z) { return false; }
  return true;
}

bool vec3_neq(vec3 v1, vec3 v2) {
  if (v1.x != v2.x) { return true; }
  if (v1.y != v2.y) { return true; }
  if (v1.z != v2.z) { return true; }
  return false;
}

void vec3_to_array(vec3 v, float* out) {

  out[0] = v.x;
  out[1] = v.y;
  out[2] = v.z;

}


vec4 vec3_to_homogeneous(vec3 v){
  return vec4_new(v.x, v.y, v.z, 1.0);
};



