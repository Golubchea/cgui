#ifndef VEC4_H
#define VEC4_H
/* vec4 */
#include "vec3.h"

typedef struct {
  float x;
  float y;
  float z;
  float w;
} vec4;

vec4 vec4_new(float x, float y, float z, float w);
vec4 vec4_zero();
vec4 vec4_one();

vec4 vec4_red();
vec4 vec4_green();
vec4 vec4_blue();
vec4 vec4_white();
vec4 vec4_black();
vec4 vec4_grey();
vec4 vec4_light_grey();
vec4 vec4_dark_grey();

vec4 vec4_add(vec4 v1, vec4 v2);
vec4 vec4_sub(vec4 v1, vec4 v2);
vec4 vec4_mul(vec4 v, float fac);
vec4 vec4_mul_vec4(vec4 v1, vec4 v2);
vec4 vec4_div(vec4 v, float fac);
vec4 vec4_pow(vec4 v, float fac);
vec4 vec4_neg(vec4 v);
vec4 vec4_abs(vec4 v);
vec4 vec4_floor(vec4 v);
vec4 vec4_fmod(vec4 v, float val);
vec4 vec4_sqrt(vec4 v);

vec4 vec4_max(vec4 v1, vec4 v2);
vec4 vec4_min(vec4 v1, vec4 v2);
bool vec4_equ(vec4 v1, vec4 v2);

float vec4_dot(vec4 v1, vec4 v2);
float vec4_length_sqrd(vec4 v);
float vec4_length(vec4 v);
float vec4_dist_sqrd(vec4 v1, vec4 v2);
float vec4_dist(vec4 v1, vec4 v2);
float vec4_dist_manhattan(vec4 v1, vec4 v2);
vec4 vec4_normalize(vec4 v);

vec4 vec4_reflect(vec4 v1, vec4 v2);

vec4 vec4_from_string(char* s);
void vec4_print(vec4 v);

void vec4_to_array(vec4 v, float* out);

vec4 vec3_to_homogeneous(vec3 v);
vec3 vec4_from_homogeneous(vec4 v);

int vec4_hash(vec4 v);

vec4 vec4_saturate(vec4 v);
vec4 vec4_lerp(vec4 v1, vec4 v2, float amount);
vec4 vec4_smoothstep(vec4 v1, vec4 v2, float amount);
vec4 vec4_smootherstep(vec4 v1, vec4 v2, float amount);
vec4 vec4_nearest_interp(vec4 v1, vec4 v2, float amount);

vec4 vec4_binearest_interp(vec4 top_left, vec4 top_right, vec4 bottom_left, vec4 bottom_right, float x_amount, float y_amount);
vec4 vec4_bilinear_interp(vec4 top_left, vec4 top_right, vec4 bottom_left, vec4 bottom_right, float x_amount, float y_amount);
#endif // VEC4
