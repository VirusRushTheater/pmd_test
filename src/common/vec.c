// Copyright(c) 2016 Purpasmart
// The MIT License
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "common/vec.h"


float lerp(float a, float b, float t)
{
    return (1.0f - t) * a + t * b;
}


vec4 vec4_zero()
{
    vec4 v;
    v.v[0] = 0;
    v.v[1] = 0;
    v.v[2] = 0;
    v.v[3] = 0;
    return v;
}

vec4 vec4_add(vec4 v, vec4 u)
{
    vec4 t;
    t.x = v.x + u.x;
    t.y = v.y + u.y;
    t.z = v.z + u.z;
    t.w = v.w + u.w;

    return t;
}

ivec4 ivec4_add(ivec4 v, ivec4 u)
{
    ivec4 t;
    t.x = v.x + u.x;
    t.y = v.y + u.y;
    t.z = v.z + u.z;
    t.w = v.w + u.w;

    return t;
}

vec4 vec4_sub(vec4 v, vec4 u)
{
    vec4 t;
    t.x = v.x - u.x;
    t.y = v.y - u.y;
    t.z = v.z - u.z;
    t.w = v.w - u.w;

    return t;
}

ivec4 ivec4_sub(ivec4 v, ivec4 u)
{
    ivec4 t;
    t.x = v.x - u.x;
    t.y = v.y - u.y;
    t.z = v.z - u.z;
    t.w = v.w - u.w;

    return t;
}

vec4 vec4_mul(vec4 v, vec4 u)
{
    vec4 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;
    t.z = v.z * u.z;
    t.w = v.w * u.w;

    return t;
}

ivec4 ivec4_mul(ivec4 v, ivec4 u)
{
    ivec4 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;
    t.z = v.z * u.z;
    t.w = v.w * u.w;

    return t;
}

int ivec4_dot(ivec4 v, ivec4 u)
{
    return (v.x * u.x) + (v.y * u.y) + (v.z * u.z);
}

float vec4_dot(vec4 v, vec4 u)
{
    return (v.x * u.x) + (v.y * u.y) + (v.z * u.z);
}

vec4 vec4_cross(vec4 a, vec4 b)
{
    vec4 t;
    t.x = a.y * b.z - a.z * b.y;
    t.y = a.z * b.x - a.x * b.z;
    t.z = a.x * b.y - a.y * b.x;
    t.w = 1.0f;
    return t;
}

ivec4 ivec4_cross(ivec4 a, ivec4 b)
{
    ivec4 t;
    t.x = a.y * b.z - a.z * b.y;
    t.y = a.z * b.x - a.x * b.z;
    t.z = a.x * b.y - a.y * b.x;
    t.w = 1.0;
    return t;
}

vec4 vec4_abs(vec4 v)
{
    vec4 t;
	t.x = fabsf(v.x);
	t.y = fabsf(v.y);
	t.z = fabsf(v.z);
	t.w = fabsf(v.w);

    return t;
}

ivec4 ivec4_abs(ivec4 v)
{
    ivec4 t;
	t.x = abs(v.x);
	t.y = abs(v.y);
	t.z = abs(v.z);
	t.w = abs(v.w);

    return t;
}

vec4 vec4_floor(vec4 v)
{
    vec4 t;
	t.x = floorf(v.x);
	t.y = floorf(v.y);
	t.z = floorf(v.z);
	t.w = floorf(v.w);

    return t;
}

ivec4 ivec4_floor(ivec4 v)
{
    ivec4 t;
	t.x = (int)floor(v.x);
	t.y = (int)floor(v.y);
	t.z = (int)floor(v.z);
	t.w = (int)floor(v.w);

    return t;
}

vec4 vec4_ceil(vec4 v)
{
    vec4 t;
	t.x = ceilf(v.x);
	t.y = ceilf(v.y);
	t.z = ceilf(v.z);
	t.w = ceilf(v.w);

    return t;
}

ivec4 ivec4_ceil(ivec4 v)
{
    ivec4 t;
	t.x = (int)ceil(v.x);
	t.y = (int)ceil(v.y);
	t.z = (int)ceil(v.z);
	t.w = (int)ceil(v.w);

    return t;
}

float vec4_length(vec4 a)
{
    return sqrtf(vec4_dot(a, a));
}

int ivec4_length(ivec4 a)
{
    return (int)sqrt(ivec4_dot(a, a));
}

vec4 vec4_scale(vec4 a, float lambda)
{
    vec4 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;
    b.z = a.z * lambda;
    b.w = a.w * lambda;

    return b;
}

ivec4 ivec4_scale(ivec4 a, int lambda)
{
    ivec4 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;
    b.z = a.z * lambda;
    b.w = a.w * lambda;

    return b;
}

vec4 vec4_normalize(vec4 a)
{
    return vec4_scale(a, 1 / vec4_length(a));
}

ivec4 ivec4_normalize(ivec4 a)
{
    return ivec4_scale(a, 1 / ivec4_length(a));
}

vec4 vec4_mad(vec4 a, vec4 b, vec4 c)
{
    vec4 t;
    t = vec4_add(vec4_mul(a, b), c);

    return t;
}

ivec4 ivec4_mad(ivec4 a, ivec4 b, ivec4 c)
{
    ivec4 t;
    t = ivec4_add(ivec4_mul(a, b), c);

    return t;
}

vec4 make_vec4(float x, float y, float z, float w)
{
    vec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;

    return v;
}

ivec4 make_ivec4(int x, int y, int z, int w)
{
    ivec4 v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;

    return v;
}

vec3 vec3_add(vec3 a, vec3 b)
{
    vec3 t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;
    t.z = a.z + b.z;

    return t;
}

ivec3 ivec3_add(ivec3 a, ivec3 b)
{
    ivec3 t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;
    t.z = a.z + b.z;

    return t;
}

vec3 vec3_sub(vec3 a, vec3 b)
{
    vec3 t;
    t.x = a.x - b.x;
    t.y = a.y - b.y;
    t.z = a.z - b.z;

    return t;
}

ivec3 ivec3_sub(ivec3 a, ivec3 b)
{
    ivec3 t;
    t.x = a.x - b.x;
    t.y = a.y - b.y;
    t.z = a.z - b.z;

    return t;
}

vec3 vec3_mul(vec3 v, vec3 u)
{
    vec3 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;
    t.z = v.z * u.z;

    return t;
}

ivec3 ivec3_mul(ivec3 v, ivec3 u)
{
    ivec3 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;
    t.z = v.z * u.z;

    return t;
}

vec3 vec3_abs(vec3 v)
{
    vec3 t;
	t.x = fabsf(v.x);
	t.y = fabsf(v.y);
	t.z = fabsf(v.z);

    return t;
}

ivec3 ivec3_abs(ivec3 v)
{
    ivec3 t;
	t.x = abs(v.x);
	t.y = abs(v.y);
	t.z = abs(v.z);

    return t;
}

vec3 vec3_floor(vec3 v)
{
    vec3 t;
	t.x = floorf(v.x);
	t.y = floorf(v.y);
	t.z = floorf(v.z);

    return t;
}

ivec3 ivec3_floor(ivec3 v)
{
    ivec3 t;
	t.x = (int)floor(v.x);
	t.y = (int)floor(v.y);
	t.z = (int)floor(v.z);

    return t;
}

vec3 vec3_ceil(vec3 v)
{
    vec3 t;
	t.x = ceilf(v.x);
	t.y = ceilf(v.y);
	t.z = ceilf(v.z);

    return t;
}

ivec3 ivec3_ceil(ivec3 v)
{
    ivec3 t;
	t.x = (int)ceil(v.x);
	t.y = (int)ceil(v.y);
	t.z = (int)ceil(v.z);

    return t;
}

float vec3_dot(vec3 a, vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

int ivec3_dot(ivec3 a, ivec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vec3 vec3_cross(vec3 a, vec3 b)
{
    vec3 t;
    t.x = a.y * b.z - a.z * b.y;
    t.y = a.z * b.x - a.x * b.z;
    t.z = a.x * b.y - a.y * b.x;
    return t;
}

ivec3 ivec3_cross(ivec3 a, ivec3 b)
{
    ivec3 t;
    t.x = a.y * b.z - a.z * b.y;
    t.y = a.z * b.x - a.x * b.z;
    t.z = a.x * b.y - a.y * b.x;
    return t;
}

float vec3_length(vec3 a)
{
    return sqrtf(vec3_dot(a, a));
}

int ivec3_length(ivec3 a)
{
    return (int)sqrt(ivec3_dot(a, a));
}

vec3 vec3_scale(vec3 a, float lambda)
{
    vec3 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;
    b.z = a.z * lambda;

    return b;
}

ivec3 ivec3_scale(ivec3 a, int lambda)
{
    ivec3 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;
    b.z = a.z * lambda;

    return b;
}

vec3 vec3_normalize(vec3 a)
{
    return vec3_scale(a, 1 / vec3_length(a));
}

ivec3 ivec3_normalize(ivec3 a)
{
    return ivec3_scale(a, 1 / ivec3_length(a));
}

vec3 make_vec3(float x, float y, float z)
{
    vec3 v;
    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

ivec3 make_ivec3(int x, int y, int z)
{
    ivec3 v;
    v.x = x;
    v.y = y;
    v.z = z;

    return v;
}

vec3 vec3_lerp(vec3 a, vec3 b, float t)
{
    vec3 c;
    a = vec3_scale(a, t);
    b = vec3_scale(b, 1 - t);
    c = vec3_add(a, b);

    return c;
}

ivec3 ivec3_lerp(ivec3 a, ivec3 b, int t)
{
    ivec3 c;
    a = ivec3_scale(a, t);
    b = ivec3_scale(b, 1 - t);
    c = ivec3_add(a, b);

    return c;
}

vec3 vec3_mad(vec3 a, vec3 b, vec3 c)
{
    vec3 t = vec3_add(vec3_mul(a, b), c);

    return t;
}

ivec3 ivec3_mad(ivec3 a, ivec3 b, ivec3 c)
{
    ivec3 t;
    t = ivec3_add(ivec3_mul(a, b), c);

    return t;
}

vec2 vec2_add(vec2 a, vec2 b)
{
    vec2 t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;

    return t;
}

ivec2 ivec2_add(ivec2 a, ivec2 b)
{
    ivec2 t;
    t.x = a.x + b.x;
    t.y = a.y + b.y;

    return t;
}

vec2 vec2_mul(vec2 v, vec2 u)
{
    vec2 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;

    return t;
}

ivec2 ivec2_mul(ivec2 v, ivec2 u)
{
    ivec2 t;
    t.x = v.x * u.x;
    t.y = v.y * u.y;

    return t;
}

float vec2_dot(vec2 a, vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

int ivec2_dot(ivec2 a, ivec2 b)
{
    return a.x * b.x + a.y * b.y;
}

vec2 vec2_abs(vec2 v)
{
    vec2 t;
    t.x = fabsf(v.x);
    t.y = fabsf(v.y);

    return t;
}

ivec2 ivec2_abs(ivec2 v)
{
    ivec2 t;
    t.x = abs(v.x);
    t.y = abs(v.y);

    return t;
}

float vec2_length(vec2 a)
{
    return sqrtf(vec2_dot(a, a));
}

int ivec2_length(ivec2 a)
{
    return (int)sqrt(ivec2_dot(a, a));
}

vec2 vec2_scale(vec2 a, float lambda)
{
    vec2 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;

    return b;
}

ivec2 ivec2_scale(ivec2 a, int lambda)
{
    ivec2 b;
    b.x = a.x * lambda;
    b.y = a.y * lambda;

    return b;
}

vec2 vec2_normalize(vec2 a)
{
    return vec2_scale(a, 1 / vec2_length(a));
}

ivec2 ivec2_normalize(ivec2 a)
{
    return ivec2_scale(a, 1 / ivec2_length(a));
}

vec2 make_vec2(float x, float y)
{
    vec2 v;
    v.x = x;
    v.y = y;

    return v;
}

ivec2 make_ivec2(int x, int y)
{
    ivec2 v;
    v.x = x;
    v.y = y;

    return v;
}

vec2 vec2_lerp(vec2 a, vec2 b, float t)
{
    vec2 c;
    a = vec2_scale(a, t);
    b = vec2_scale(b, 1.0f - t);
    c = vec2_add(a, b);

    return c;
}

ivec2 ivec2_lerp(ivec2 a, ivec2 b, int t)
{
    ivec2 c;
    a = ivec2_scale(a, t);
    b = ivec2_scale(b, 1 - t);
    c = ivec2_add(a, b);

    return c;
}

vec2 vec2_mad(vec2 a, vec2 b, vec2 c)
{
    vec2 t;
    t = vec2_add(vec2_mul(a, b), c);

    return t;
}

ivec2 ivec2_mad(ivec2 a, ivec2 b, ivec2 c)
{
    ivec2 t;
    t = ivec2_add(ivec2_mul(a, b), c);

    return t;
}

mat4 mat4_make(vec4 a, vec4 b, vec4 c, vec4 d)
{
    mat4 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;

    return m;
}

imat4 imat4_make(ivec4 a, ivec4 b, ivec4 c, ivec4 d)
{
    imat4 m;
    m.a = a;
    m.b = b;
    m.c = c;
    m.d = d;

    return m;
}

mat4 mat4_translate(float x, float y, float z)
{
    return mat4_make(make_vec4(1.0, 0.0, 0.0, 0.0),
                     make_vec4(0.0, 1.0, 0.0, 0.0),
                     make_vec4(0.0, 0.0, 1.0, 0.0),
                     make_vec4(x,   y,   z,   1.0));
}

imat4 imat4_translate(int x, int y, int z)
{
    return imat4_make(make_ivec4(1.0, 0.0, 0.0, 0.0),
                      make_ivec4(0.0, 1.0, 0.0, 0.0),
                      make_ivec4(0.0, 0.0, 1.0, 0.0),
                      make_ivec4(x,   y,   z,   1.0));
}

mat4 mat4_rotate(float x, float y, float z)
{
    mat4 m;

    return m;
}


mat4 mat4_tranpose()
{
    mat4 m;

    //swap(&m.a.y, &m.m[1][2]);
	//swap(&m.a,z, &m.m[2][2]);
	//swap(&m.m[0][3], &m.m[3][0]);
	//swap(&m.m[1][2], &m.m[2][1]);
	//swap(&m.m[1][3], &m.m[3][1]);
    //swap(&m.m[2][3], &m.m[3][2]);

    return m;
}
