#include "pch.h"
namespace math
{
	/// <summary>
	/// Given radians, returns the cosine
	/// </summary>
	/// <param name="radians">radians</param>
	/// <returns></returns>
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
	/// <param name="radians">radians</param>
	/// <returns></returns>
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
}