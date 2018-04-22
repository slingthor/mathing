#include "pch.h"
#pragma once

namespace Math
{
	float Pow(float number, float exponent);
	float Abs(float number);
	float Sqrt(float number);

	float Pow(double, double) = delete;
	float Pow(int, int) = delete;
	float Abs(double) = delete;
	float Abs(int) = delete;
	float Sqrt(double) = delete;
	float Sqrt(int) = delete;
}