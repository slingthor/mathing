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
		radians += 1.57079632;
		if (radians < -3.14159265)
		{
			radians += 6.28318531;
		}
		else if (radians >  3.14159265)
		{
			radians -= 6.28318531;
		}

		if (radians < 0)
		{
			float cos = 1.27323954 * radians + 0.405284735 * radians * radians;

			if (cos < 0)
			{
				cos = .225 * (cos *-cos - cos) + cos;
			}
			else
			{
				cos = .225 * (cos * cos - cos) + cos;
			}
			return cos;
		}
		float cos = 1.27323954 * radians - 0.405284735 * radians * radians;

		if (cos < 0)
		{
			cos = .225 * (cos *-cos - cos) + cos;
		}
		else
		{
			cos = .225 * (cos * cos - cos) + cos;
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
		if (radians < -3.14159265)
		{
			radians += 6.28318531;
		}
			
		else
		{
			if (radians > 3.14159265)
			{
				radians -= 6.28318531;
			}
		}
		
		if (radians < 0)
		{
			float sin = 1.27323954 * radians + .405284735 * radians * radians;

			if (sin < 0)
			{
				sin = .225 * (sin *-sin - sin) + sin;
			}
			else
			{
				sin = .225 * (sin * sin - sin) + sin;
			}		
			return sin;
		}
		float sin = 1.27323954 * radians - 0.405284735 * radians * radians;

		if (sin < 0)
		{
			sin = .225 * (sin *-sin - sin) + sin;
		}
		else
		{
			sin = .225 * (sin * sin - sin) + sin;
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
		const auto negate = float(number < 0);
		number = Abs(number);
		float ret = -0.0187293;
		ret = ret * number;
		ret = ret + 0.0742610;
		ret = ret * number;
		ret = ret - 0.2121144;
		ret = ret * number;
		ret = ret + 1.5707288;
		ret = ret * Sqrt(1.0 - number);
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
		const auto half_pi = pi / 2;
		return half_pi - acos(number);
	}
}