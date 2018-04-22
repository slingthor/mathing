#include "pch.h"
#include "general.h"
#pragma once

namespace Math
{
	/// <summary>
	/// Calculates positive power.
	/// </summary>
	/// <param name="number">Number to be raised into a power</param>
	/// <param name="exponent">The exponent</param>
	/// <returns></returns>
	float Pow(const float number, const float exponent)
	{
		float total = 1;
		if (exponent > 0)
		{
			for (int i = 0; i < exponent; i++)
			{
				total *= number;
			}
		}
		else if (exponent < 0)
		{
			for (int i = 0; i > exponent; i++)
			{
				total /= number;
			}
		}
		return total;
	}

	float Abs(const float number)
	{
		if(number < 0)
		{
			return -number;
		}
		return number;
	}

	float Sqrt(const float number)
	{
		union
		{
			int i;
			float x;
		} u;
		u.x = number;
		u.i = (1 << 29) + (u.i >> 1) - (1 << 22);
		u.x = u.x + number / u.x;
		u.x = 0.25f*u.x + number / u.x;

		return u.x;
	}
}
