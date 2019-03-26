#ifndef VEC2_H
#define VEC2_H

#include <stdbool.h>
/* vec2 */

typedef struct {
  float x;
  float y;
} vec2;

vec2 vec2_new(float x, float y);
vec2 vec2_zero();
vec2 vec2_one();

vec2 vec2_add(vec2 v1, vec2 v2);
vec2 vec2_sub(vec2 v1, vec2 v2);
vec2 vec2_mul(vec2 v, float fac);
vec2 vec2_mul_vec2(vec2 v1, vec2 v2);
vec2 vec2_div(vec2 v, float fac);
vec2 vec2_div_vec2(vec2 v1, vec2 v2);
vec2 vec2_pow(vec2 v, float exp);
vec2 vec2_neg(vec2 v);
vec2 vec2_abs(vec2 v);
vec2 vec2_floor(vec2 v);
vec2 vec2_fmod(vec2 v, float val);

vec2 vec2_max(vec2 v, float x);
vec2 vec2_min(vec2 v, float x);
vec2 vec2_clamp(vec2 v, float b, float t);

bool vec2_equ(vec2 v1, vec2 v2);

float vec2_dot(vec2 v1, vec2 v2);
float vec2_length_sqrd(vec2 v);
float vec2_length(vec2 v);
float vec2_dist_sqrd(vec2 v1, vec2 v2);
float vec2_dist(vec2 v1, vec2 v2);
float vec2_dist_manhattan(vec2 v1, vec2 v2);
vec2 vec2_normalize(vec2 v);

vec2 vec2_reflect(vec2 v1, vec2 v2);

vec2 vec2_from_string(char* s);
void vec2_print(vec2 v);

void vec2_to_array(vec2 v, float* out);

int vec2_hash(vec2 v);
int vec2_mix_hash(vec2 v);

vec2 vec2_saturate(vec2 v);
vec2 vec2_lerp(vec2 v1, vec2 v2, float amount);
vec2 vec2_smoothstep(vec2 v1, vec2 v2, float amount);
vec2 vec2_smootherstep(vec2 v1, vec2 v2, float amount);


#endif // VEC2
