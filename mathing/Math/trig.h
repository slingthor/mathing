#pragma once
#include "pch.h"

namespace Math
{
	const float pi = 3.141592653589793;
	float Cos(float radians);
	float Sin(float radians);
	float asin(float number);
	float acos(float number);

	float Cos(double) = delete;
	float Sin(double) = delete;
	float asin(double) = delete;
	float acos(double) = delete;

	float Cos(int) = delete;
	float Sin(int) = delete;
	float asin(int) = delete;
	float acos(int) = delete;
}