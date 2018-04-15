#include "pch.h"
#include "trig.h"
#include "general.h"
namespace math
{
	/// <summary>
	/// Given radians, returns the cosine
	/// </summary>
	/// <param name="radians">radians</param>
	/// <returns>The Cosine</returns>
	float cos(float radians)
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
	/// Given radians, returns the sin
	/// </summary>
	/// <param name="radians">Radians</param>
	/// <returns>The sine</returns>
	float sin(float radians)
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
	float acos(float number) {
		const float negate = float(number < 0);
		number = abs(number);
		float ret = -0.0187293;
		ret = ret * number;
		ret = ret + 0.0742610;
		ret = ret * number;
		ret = ret - 0.2121144;
		ret = ret * number;
		ret = ret + 1.5707288;
		ret = ret * sqrt(1.0 - number);
		ret = ret - 2 * negate * ret;
		return negate * pi + ret;
	}

	/// <summary>
	/// Given a number, returns angle in 
	/// </summary>
	/// <param name="number"></param>
	/// <returns></returns>
	float asin(float number)
	{
		const float half_pi = pi / 2;
		return half_pi - acos(number);
	}
}