#include "mat4.h"
#include <math.h>
#include <stdio.h>
mat4 mat4_zero() {
    mat4 mat;

    mat.xx = 0.0f;
    mat.xy = 0.0f;
    mat.xz = 0.0f;
    mat.xw = 0.0f;

    mat.yx = 0.0f;
    mat.yy = 0.0f;
    mat.yz = 0.0f;
    mat.yw = 0.0f;

    mat.zx = 0.0f;
    mat.zy = 0.0f;
    mat.zz = 0.0f;
    mat.zw = 0.0f;

    mat.wx = 0.0f;
    mat.wy = 0.0f;
    mat.wz = 0.0f;
    mat.ww = 0.0f;

    return mat;
}

mat4 mat4_id(){

    mat4 mat = mat4_zero();

    mat.xx = 1.0f;
    mat.yy = 1.0f;
    mat.zz = 1.0f;
    mat.ww = 1.0f;


    return mat;
}

float mat4_at(mat4 m, int x, int y) {
    float* arr = (float*)(&m);
    return arr[x + (y*4)];
}

mat4 mat4_set(mat4 m, int x, int y, float v) {

    float* arr = (float*)(&m);
    arr[x + (y*4)] = v;

    return m;
}

mat4 mat4_new(float xx, float xy, float xz, float xw,
              float yx, float yy, float yz, float yw,
              float zx, float zy, float zz, float zw,
              float wx, float wy, float wz, float ww) {

    mat4 mat;

    mat.xx = xx;
    mat.xy = xy;
    mat.xz = xz;
    mat.xw = xw;

    mat.yx = yx;
    mat.yy = yy;
    mat.yz = yz;
    mat.yw = yw;

    mat.zx = zx;
    mat.zy = zy;
    mat.zz = zz;
    mat.zw = zw;

    mat.wx = wx;
    mat.wy = wy;
    mat.wz = wz;
    mat.ww = ww;

    return mat;
}

mat4 mat4_transpose(mat4 m) {
    mat4 mat;

    mat.xx = m.xx;
    mat.xy = m.yx;
    mat.xz = m.zx;
    mat.xw = m.wx;

    mat.yx = m.xy;
    mat.yy = m.yy;
    mat.yz = m.zy;
    mat.yw = m.wy;

    mat.zx = m.xz;
    mat.zy = m.yz;
    mat.zz = m.zz;
    mat.zw = m.wz;

    mat.wx = m.xw;
    mat.wy = m.yw;
    mat.wz = m.zw;
    mat.ww = m.ww;

    return mat;
}

mat4 mat3_to_mat4(mat3 m) {

    mat4 mat;

    mat.xx = m.xx;
    mat.xy = m.xy;
    mat.xz = m.xz;
    mat.xw = 0.0f;

    mat.yx = m.yx;
    mat.yy = m.yy;
    mat.yz = m.yz;
    mat.yw = 0.0f;

    mat.zx = m.zx;
    mat.zy = m.zy;
    mat.zz = m.zz;
    mat.zw = 0.0f;

    mat.wx = 0.0f;
    mat.wy = 0.0f;
    mat.wz = 0.0f;
    mat.ww = 1.0f;

    return mat;
}

mat4 mat4_mul_mat4(mat4 m2, mat4 m1) {


//    typedef struct {
//      float xx; float xy; float xz; float xw;
//      float yx; float yy; float yz; float yw;
//      float zx; float zy; float zz; float zw;
//      float wx; float wy; float wz; float ww;
//    } mat4;


    mat4 mat;

    mat.xx = (m1.xx * m2.xx) + (m1.xy * m2.yx) + (m1.xz * m2.zx) + (m1.xw * m2.wx);
    mat.xy = (m1.xx * m2.xy) + (m1.xy * m2.yy) + (m1.xz * m2.zy) + (m1.xw * m2.wy);
    mat.xz =( (m1.xx * m2.xz) + (m1.xy * m2.yz) + (m1.xz * m2.zz) + (m1.xw * m2.wz) );
    mat.xw = (m1.xx * m2.xw) + (m1.xy * m2.yw) + (m1.xz * m2.zw) + (m1.xw * m2.ww);

    mat.yx = (m1.yx * m2.xx) + (m1.yy * m2.yx) + (m1.yz * m2.zx) + (m1.yw * m2.wx);
    mat.yy = (m1.yx * m2.xy) + (m1.yy * m2.yy) + (m1.yz * m2.zy) + (m1.yw * m2.wy);
    mat.yz =( (m1.yx * m2.xz) + (m1.yy * m2.yz) + (m1.yz * m2.zz) + (m1.yw * m2.wz) );
    mat.yw = (m1.yx * m2.xw) + (m1.yy * m2.yw) + (m1.yz * m2.zw) + (m1.yw * m2.ww);

    mat.zx = (m1.zx * m2.xx) + (m1.zy * m2.yx) + (m1.zz * m2.zx) + (m1.zw * m2.wx);
    mat.zy = (m1.zx * m2.xy) + (m1.zy * m2.yy) + (m1.zz * m2.zy) + (m1.zw * m2.wy);
    mat.zz = (m1.zx * m2.xz) + (m1.zy * m2.yz) + (m1.zz * m2.zz) + (m1.zw * m2.wz);
    mat.zw = (m1.zx * m2.xw) + (m1.zy * m2.yw) + (m1.zz * m2.zw) + (m1.zw * m2.ww);

    mat.wx = (m1.wx * m2.xx) + (m1.wy * m2.yx) + (m1.wz * m2.zx) + (m1.ww * m2.wx);
    mat.wy = (m1.wx * m2.xy) + (m1.wy * m2.yy) + (m1.wz * m2.zy) + (m1.ww * m2.wy);
    mat.wz = (m1.wx * m2.xz) + (m1.wy * m2.yz) + (m1.wz * m2.zz) + (m1.ww * m2.wz);
    mat.ww = (m1.wx * m2.xw) + (m1.wy * m2.yw) + (m1.wz * m2.zw) + (m1.ww * m2.ww);

    return mat;

}

vec4 mat4_mul_vec4(mat4 m, vec4 v) {

    vec4 vec;

    vec.x = (m.xx * v.x) + (m.xy * v.y) + (m.xz * v.z) + (m.xw * v.w);
    vec.y = (m.yx * v.x) + (m.yy * v.y) + (m.yz * v.z) + (m.yw * v.w);
    vec.z = (m.zx * v.x) + (m.zy * v.y) + (m.zz * v.z) + (m.zw * v.w);
    vec.w = (m.wx * v.x) + (m.wy * v.y) + (m.wz * v.z) + (m.ww * v.w);

    return vec;
}

vec3 mat4_mul_vec3(mat4 m, vec3 v) {

    vec4 v_homo = vec4_new(v.x, v.y, v.z, 1);
    v_homo = mat4_mul_vec4(m, v_homo);

    v_homo = vec4_div(v_homo, v_homo.w);

    return vec3_new(v_homo.x, v_homo.y, v_homo.z);
}

mat3 mat4_to_mat3(mat4 m) {

    mat3 mat;

    mat.xx = m.xx;
    mat.xy = m.xy;
    mat.xz = m.xz;

    mat.yx = m.yx;
    mat.yy = m.yy;
    mat.yz = m.yz;

    mat.zx = m.zx;
    mat.zy = m.zy;
    mat.zz = m.zz;

    return mat;

}




float mat4_det(mat4 m) {

    float cofact_xx =  mat3_det(mat3_new(m.yy, m.yz, m.yw, m.zy, m.zz, m.zw, m.wy, m.wz, m.ww));
    float cofact_xy = -mat3_det(mat3_new(m.yx, m.yz, m.yw, m.zx, m.zz, m.zw, m.wx, m.wz, m.ww));
    float cofact_xz =  mat3_det(mat3_new(m.yx, m.yy, m.yw, m.zx, m.zy, m.zw, m.wx, m.wy, m.ww));
    float cofact_xw = -mat3_det(mat3_new(m.yx, m.yy, m.yz, m.zx, m.zy, m.zz, m.wx, m.wy, m.wz));

    return (cofact_xx * m.xx) + (cofact_xy * m.xy) + (cofact_xz * m.xz) + (cofact_xw * m.xw);
}

mat4 mat4_inverse(mat4 m) {

    float det = mat4_det(m);
    float fac = 1.0 / det;

    mat4 ret;
    ret.xx = fac *  mat3_det(mat3_new(m.yy, m.yz, m.yw, m.zy, m.zz, m.zw, m.wy, m.wz, m.ww));
    ret.xy = fac * -mat3_det(mat3_new(m.yx, m.yz, m.yw, m.zx, m.zz, m.zw, m.wx, m.wz, m.ww));
    ret.xz = fac *  mat3_det(mat3_new(m.yx, m.yy, m.yw, m.zx, m.zy, m.zw, m.wx, m.wy, m.ww));
    ret.xw = fac * -mat3_det(mat3_new(m.yx, m.yy, m.yz, m.zx, m.zy, m.zz, m.wx, m.wy, m.wz));

    ret.yx = fac * -mat3_det(mat3_new(m.xy, m.xz, m.xw, m.zy, m.zz, m.zw, m.wy, m.wz, m.ww));
    ret.yy = fac *  mat3_det(mat3_new(m.xx, m.xz, m.xw, m.zx, m.zz, m.zw, m.wx, m.wz, m.ww));
    ret.yz = fac * -mat3_det(mat3_new(m.xx, m.xy, m.xw, m.zx, m.zy, m.zw, m.wx, m.wy, m.ww));
    ret.yw = fac *  mat3_det(mat3_new(m.xx, m.xy, m.xz, m.zx, m.zy, m.zz, m.wx, m.wy, m.wz));

    ret.zx = fac *  mat3_det(mat3_new(m.xy, m.xz, m.xw, m.yy, m.yz, m.yw, m.wy, m.wz, m.ww));
    ret.zy = fac * -mat3_det(mat3_new(m.xx, m.xz, m.xw, m.yx, m.yz, m.yw, m.wx, m.wz, m.ww));
    ret.zz = fac *  mat3_det(mat3_new(m.xx, m.xy, m.xw, m.yx, m.yy, m.yw, m.wx, m.wy, m.ww));
    ret.zw = fac * -mat3_det(mat3_new(m.xx, m.xy, m.xz, m.yx, m.yy, m.yz, m.wx, m.wy, m.wz));

    ret.wx = fac * -mat3_det(mat3_new(m.xy, m.xz, m.xw, m.yy, m.yz, m.yw, m.zy, m.zz, m.zw));
    ret.wy = fac *  mat3_det(mat3_new(m.xx, m.xz, m.xw, m.yx, m.yz, m.yw, m.zx, m.zz, m.zw));
    ret.wz = fac * -mat3_det(mat3_new(m.xx, m.xy, m.xw, m.yx, m.yy, m.yw, m.zx, m.zy, m.zw));
    ret.ww = fac *  mat3_det(mat3_new(m.xx, m.xy, m.xz, m.yx, m.yy, m.yz, m.zx, m.zy, m.zz));

    ret = mat4_transpose(ret);

    return ret;
}

void mat4_to_array(mat4 m, float* out) {

    out[0] = m.xx;
    out[1] = m.yx;
    out[2] = m.zx;
    out[3] = m.wx;

    out[4] = m.xy;
    out[5] = m.yy;
    out[6] = m.zy;
    out[7] = m.wy;

    out[8] = m.xz;
    out[9] = m.yz;
    out[10] = m.zz;
    out[11] = m.wz;

    out[12] = m.xw;
    out[13] = m.yw;
    out[14] = m.zw;
    out[15] = m.ww;

}

void mat4_to_array_trans(mat4 m, float* out) {

    out[0] = m.xx;
    out[1] = m.xy;
    out[2] = m.xz;
    out[3] = m.xw;

    out[4] = m.yx;
    out[5] = m.yy;
    out[6] = m.yz;
    out[7] = m.yw;

    out[8] = m.zx;
    out[9] = m.zy;
    out[10] = m.zz;
    out[11] = m.zw;

    out[12] = m.wx;
    out[13] = m.wy;
    out[14] = m.wz;
    out[15] = m.ww;

}

void mat4_print(mat4 m) {

    printf("|%4.2f, %4.2f, %4.2f, %4.2f|\n", m.xx, m.xy, m.xz, m.xw);
    printf("|%4.2f, %4.2f, %4.2f, %4.2f|\n", m.yx, m.yy, m.yz, m.yw);
    printf("|%4.2f, %4.2f, %4.2f, %4.2f|\n", m.zx, m.zy, m.zz, m.zw);
    printf("|%4.2f, %4.2f, %4.2f, %4.2f|\n", m.wx, m.wy, m.wz, m.ww);

}

mat4 mat4_view_look_at(vec3 position, vec3 target, vec3 up) {

    vec3 zaxis = vec3_normalize( vec3_sub(target, position) );
    vec3 xaxis = vec3_normalize( vec3_cross(up, zaxis) );
    vec3 yaxis = vec3_cross(zaxis, xaxis);

    mat4 view_matrix = mat4_id();
    view_matrix.xx = xaxis.x;
    view_matrix.xy = xaxis.y;
    view_matrix.xz = xaxis.z;

    view_matrix.yx = yaxis.x;
    view_matrix.yy = yaxis.y;
    view_matrix.yz = yaxis.z;

    view_matrix.zx = -zaxis.x;
    view_matrix.zy = -zaxis.y;
    view_matrix.zz = -zaxis.z;

    view_matrix = mat4_mul_mat4(view_matrix, mat4_translation(vec3_neg(position)) );

    return view_matrix;
}

mat4 mat4_perspective(float fov, float near_clip, float far_clip, float ratio) {

    float right, left, bottom, top;

    right = -(near_clip * tanf(fov));
    left = -right;

    top = ratio * near_clip * tanf(fov);
    bottom = -top;

    mat4 proj_matrix = mat4_zero();
    proj_matrix.xx = (2.0 * near_clip) / (right - left);
    proj_matrix.yy = (2.0 * near_clip) / (top - bottom);
    proj_matrix.xz = (right + left) / (right - left);
    proj_matrix.yz = (top + bottom) / (top - bottom);
    proj_matrix.zz = (-far_clip - near_clip) / (far_clip - near_clip);
    proj_matrix.wz = -1.0;
    proj_matrix.zw = ( -(2.0 * near_clip) * far_clip) / (far_clip - near_clip);

    return proj_matrix;
}

mat4 mat4_orthographic(float left, float right, float bottom, float top, float clip_near, float clip_far) {

    mat4 m = mat4_id();

    m.xx = 2 / (right - left);
    m.yy = 2 / (top - bottom);
    m.zz = 1 / (clip_near - clip_far);

    m.xw = -1 - 2 * left / (right - left);
    m.yw =  1 + 2 * top  / (bottom - top);
    m.zw = clip_near / (clip_near - clip_far);

    return m;

}

mat4 mat4_translation(vec3 v) {

    mat4 m = mat4_id();
    m.xw = v.x;
    m.yw = v.y;
    m.zw = v.z;

    return m;

}

mat4 mat4_scale(vec3 v) {

    mat4 m = mat4_id();
    m.xx = v.x;
    m.yy = v.y;
    m.zz = v.z;

    return m;
}

mat4 mat4_rotation_x(float a) {

    mat4 m = mat4_id();

    m.yy = cos(a);
    m.yz = -sin(a);
    m.zy = sin(a);
    m.zz = cos(a);

    return m;

}

mat4 mat4_rotation_y(float a) {

    mat4 m = mat4_id();

    m.xx = cos(a);
    m.xz = sin(a);
    m.zx = -sin(a);
    m.zz = cos(a);

    return m;

}

mat4 mat4_rotation_z(float a) {

    mat4 m = mat4_id();

    m.xx = cos(a);
    m.xy = -sin(a);
    m.yx = sin(a);
    m.yy = cos(a);

    return m;

}

mat4 mat4_rotation_axis_angle(vec3 v, float angle) {

    //    typedef struct {
    //      float xx; float xy; float xz; float xw;
    //      float yx; float yy; float yz; float yw;
    //      float zx; float zy; float zz; float zw;
    //      float wx; float wy; float wz; float ww;
    //    } mat4;


    mat4 m = mat4_id();

    float c = cos(angle);
    float s = sin(angle);
    float nc = 1 - c;

    m.xx = v.x * v.x * nc + c;
    m.xy = v.x * v.y * nc - v.z * s;
    m.xz =-( v.x * v.z * nc + v.y * s);

    m.yx = v.y * v.x * nc + v.z * s;
    m.yy = v.y * v.y * nc + c;
    m.yz = v.y * v.z * nc - v.x * s;

    m.zx = -(v.z * v.x * nc - v.y * s);
    m.zy = v.z * v.y * nc + v.x * s;
    m.zz = v.z * v.z * nc + c;

    return m;

}

mat4 mat4_rotation_euler(float x, float y, float z) {

    mat4 m = mat4_zero();

    float cosx = cos(x);
    float cosy = cos(y);
    float cosz = cos(z);
    float sinx = sin(x);
    float siny = sin(y);
    float sinz = sin(z);

    m.xx = cosy * cosz;
    m.yx = -cosx * sinz + sinx * siny * cosz;
    m.zx = sinx * sinz + cosx * siny * cosz;

    m.xy = cosy * sinz;
    m.yy = cosx * cosz + sinx * siny * sinz;
    m.zy = -sinx * cosz + cosx * siny * sinz;

    m.xz = -siny;
    m.yz = sinx * cosy;
    m.zz = cosx * cosy;

    m.ww = 1;

    return m;
}

mat4 mat4_rotation_quat(vec4 q) {

    float x2 = q.x + q.x;
    float y2 = q.y + q.y;
    float z2 = q.z + q.z;
    float xx = q.x * x2;
    float yy = q.y * y2;
    float wx = q.w * x2;
    float xy = q.x * y2;
    float yz = q.y * z2;
    float wy = q.w * y2;
    float xz = q.x * z2;
    float zz = q.z * z2;
    float wz = q.w * z2;

    return mat4_new(
                1.0f - ( yy + zz ),	xy - wz, xz + wy,	0.0f,
                xy + wz, 1.0f - ( xx + zz ), yz - wx, 0.0f,
                xz - wy, yz + wx, 1.0f - ( xx + yy ), 0.0f,
                0.0f,	0.0f, 0.0f,	1.0f);

}


mat4 mat4_look_at(vec3 eye, vec3 center, vec3 up) {

    //    tvec3<T, P> const & eye,
    //    tvec3<T, P> const & center,
    //    tvec3<T, P> const & up
    //)
    //{
    //    tvec3<T, P> const f(normalize(center - eye));
    //    tvec3<T, P> const s(normalize(cross(f, up)));
    //    tvec3<T, P> const u(cross(s, f));

    //    tmat4x4<T, P> Result(1);
    //    Result[0][0] = s.x;
    //    Result[1][0] = s.y;
    //    Result[2][0] = s.z;
    //    Result[0][1] = u.x;
    //    Result[1][1] = u.y;
    //    Result[2][1] = u.z;
    //    Result[0][2] =-f.x;
    //    Result[1][2] =-f.y;
    //    Result[2][2] =-f.z;
    //    Result[3][0] =-dot(s, eye);
    //    Result[3][1] =-dot(u, eye);
    //    Result[3][2] = dot(f, eye);
    //    return Result;
    //}

    //template <typename T, precision P>
    //GLM_FUNC_QUALIFIER tmat4x4<T, P> lookAtLH
    //(
    //    tvec3<T, P> const & eye,
    //    tvec3<T, P> const & center,
    //    tvec3<T, P> const & up
    //)
    //{
    //    tvec3<T, P> const f(normalize(center - eye));
    //    tvec3<T, P> const s(normalize(cross(up, f)));
    //    tvec3<T, P> const u(cross(f, s));

    //    tmat4x4<T, P> Result(1);
    //    Result[0][0] = s.x;
    //    Result[1][0] = s.y;
    //    Result[2][0] = s.z;
    //    Result[0][1] = u.x;
    //    Result[1][1] = u.y;
    //    Result[2][1] = u.z;
    //    Result[0][2] = f.x;
    //    Result[1][2] = f.y;
    //    Result[2][2] = f.z;
    //    Result[3][0] = -dot(s, eye);
    //    Result[3][1] = -dot(u, eye);
    //    Result[3][2] = -dot(f, eye);
    //    return Result;


    //    typedef struct {
    //      float xx; float xy; float xz; float xw;
    //      float yx; float yy; float yz; float yw;
    //      float zx; float zy; float zz; float zw;
    //      float wx; float wy; float wz; float ww;
    //    } mat4;




    vec3 f =vec3_normalize( vec3_sub(center , eye) );
    vec3 s =vec3_normalize( vec3_cross(f, up) );
    vec3 u =vec3_cross(s, f);

    mat4 view_matrix = mat4_id();
    view_matrix.xx = s.x;
    view_matrix.xy = u.x;
    view_matrix.xz =-f.x;

    view_matrix.yx = s.y;
    view_matrix.yy = u.y;
    view_matrix.yz = -f.y;

    view_matrix.zx =  s.z;
    view_matrix.zy =  u.z;
    view_matrix.zz =  -f.z;

    view_matrix.wx=-vec3_dot(s,eye);
    view_matrix.wy= -vec3_dot(u,eye);
    view_matrix.wz= vec3_dot(f,eye);
    return view_matrix;
}

mat4 mat4_frustrum( float left,
                    float right,
                    float bottom,
                    float top,
                    float nearVal,
                    float farVal)
{

        mat4 Result= mat4_zero();





        Result.xx = ( 2.0f  * nearVal) / (right - left);
        Result.yy = ( 2.0f  * nearVal) / (top - bottom);
        Result.zx = (right + left) / (right - left);
        Result.zy = (top + bottom) / (top - bottom);
        Result.zz = -(farVal + nearVal) / (farVal - nearVal);
        Result.zw = (-1.0f);
        Result.wz = -(2.0f * farVal * nearVal) / (farVal - nearVal);

//        Result[0][0] = ( 2.0f  * nearVal) / (right - left);
//        Result[1][1] = ( 2.0f  * nearVal) / (top - bottom);
//        Result[2][0] = (right + left) / (right - left);
//        Result[2][1] = (top + bottom) / (top - bottom);
//        Result[2][2] = -(farVal + nearVal) / (farVal - nearVal);
//        Result[2][3] = (-1.0f);
//        Result[3][2] = -(2.0f * farVal * nearVal) / (farVal - nearVal);
        return Result;
}
