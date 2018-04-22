#include "pch.h"
#include "trig.h"
#include "general.h"
namespace Math
{
	/// <summary>
	/// Given radians, returns the cosine
	/// </summary>
	/// <param name="radians">radians</param>
	/// <returns>The Cosine</returns>
	auto Cos(float radians) -> float
	{
		radians += 1.57079632f;
		if (radians < -3.14159265f)
		{
			radians += 6.28318531f;
		}
		else if (radians >  3.14159265f)
		{
			radians -= 6.28318531f;
		}

		if (radians < 0.0f)
		{
			float cos = 1.27323954f * radians + 0.405284735f * radians * radians;

			if (cos < 0.0f)
			{
				cos = .225f * (cos *-cos - cos) + cos;
			}
			else
			{
				cos = .225f * (cos * cos - cos) + cos;
			}
			return cos;
		}
		float cos = 1.27323954f * radians - 0.405284735f * radians * radians;

		if (cos < 0.0f)
		{
			cos = .225f * (cos *-cos - cos) + cos;
		}
		else
		{
			cos = .225f * (cos * cos - cos) + cos;
		}
		return cos;
	}

	/// <summary>
	/// Given radians, returns the Sin
	/// </summary>
	/// <param name="radians">Radians</param>
	/// <returns>The sine</returns>
	auto Sin(float radians) -> float
	{
		if (radians < -3.14159265f)
		{
			radians += 6.28318531f;
		}
			
		else
		{
			if (radians > 3.14159265f)
			{
				radians -= 6.28318531f;
			}
		}
		
		if (radians < 0.0f)
		{
			float sin = 1.27323954f * radians + .405284735f * radians * radians;

			if (sin < 0.0f)
			{
				sin = .225f * (sin *-sin - sin) + sin;
			}
			else
			{
				sin = .225f * (sin * sin - sin) + sin;
			}		
			return sin;
		}
		float sin = 1.27323954f * radians - 0.405284735f * radians * radians;

		if (sin < 0.0f)
		{
			sin = .225f * (sin *-sin - sin) + sin;
		}
		else
		{
			sin = .225f * (sin * sin - sin) + sin;
		}	
		return sin;
	}

	/// <summary>
	/// Given a number, returns angle in radians
	/// </summary>
	/// <param name="number">A cosine number</param>
	/// <returns>The angle in radians</returns>
	auto acos(float number) -> float
	{
		const float negate = float(number < 0);
		number = Abs(number);
		float ret = -0.0187293f;
		ret = ret * number;
		ret = ret + 0.0742610f;
		ret = ret * number;
		ret = ret - 0.2121144f;
		ret = ret * number;
		ret = ret + 1.5707288f;
		ret = ret * Sqrt(1.0f - number);
		ret = ret - 2 * negate * ret;
		return negate * pi + ret;
	}

	/// <summary>
	/// Given a number, returns angle in 
	/// </summary>
	/// <param name="number"></param>
	/// <returns></returns>
	auto asin(float number) -> float
	{
		const auto half_pi = pi / 2.0f;
		return half_pi - acos(number);
	}
}