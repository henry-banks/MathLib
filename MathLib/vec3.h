#pragma once

struct vec3
{
	float x, y, z;
};

vec3 vInit3(float inX, float inY, float inZ);

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &v);

vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);

vec3 operator/(const vec3 &lhs, const vec3 &rhs);

vec3 &operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);

vec3 &operator*=(vec3 &lhs, float rhs);
vec3 &operator*=(float lhs, vec3 &rhs);

vec3 &operator/=(vec3 &lhs, vec3 &rhs);

bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

float magnitude(const vec3 &v);