#ifndef VEC3_H
#define VEC3_H


#include<stdbool.h>

typedef struct {
  float x;
  float y;
  float z;
} vec3;

vec3 vec3_new(float x, float y, float z);
vec3 vec3_zero();
vec3 vec3_one();
vec3 vec3_up();

vec3 vec3_red();
vec3 vec3_green();
vec3 vec3_blue();
vec3 vec3_white();
vec3 vec3_black();
vec3 vec3_grey();
vec3 vec3_light_grey();
vec3 vec3_dark_grey();

vec3 vec3_add(vec3 v1, vec3 v2);
vec3 vec3_sub(vec3 v1, vec3 v2);
vec3 vec3_mul(vec3 v, float fac);
vec3 vec3_mul_vec3(vec3 v1, vec3 v2);
vec3 vec3_div(vec3 v, float fac);
vec3 vec3_div_vec3(vec3 v1, vec3 v2);
vec3 vec3_pow(vec3 v, float fac);
vec3 vec3_neg(vec3 v);
vec3 vec3_abs(vec3 v);
vec3 vec3_floor(vec3 v);
vec3 vec3_fmod(vec3 v, float val);

bool vec3_equ(vec3 v1, vec3 v2);
bool vec3_neq(vec3 v1, vec3 v2);

float vec3_dot(vec3 v1, vec3 v2);
float vec3_length_sqrd(vec3 v);
float vec3_length(vec3 v);
float vec3_dist_sqrd(vec3 v1, vec3 v2);
float vec3_dist(vec3 v1, vec3 v2);
float vec3_dist_manhattan(vec3 v1, vec3 v2);
vec3 vec3_cross(vec3 v1, vec3 v2);
vec3 vec3_normalize(vec3 v);

vec3 vec3_reflect(vec3 v1, vec3 v2);
vec3 vec3_project(vec3 v1, vec3 v2);

vec3 vec3_from_string(char* s);
void vec3_print(vec3 v);

void vec3_to_array(vec3 v, float* out);

int vec3_hash(vec3 v);

vec3 vec3_saturate(vec3 v);
vec3 vec3_lerp(vec3 v1, vec3 v2, float amount);
vec3 vec3_smoothstep(vec3 v1, vec3 v2, float amount);
vec3 vec3_smootherstep(vec3 v1, vec3 v2, float amount);

#endif // VEC3
