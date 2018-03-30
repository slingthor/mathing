#pragma once

namespace math
{
	struct vector_2D
	{
		vector_2D(const float x, const float y)
			: x{ x },
			y{ y }
		{}

		float x;
		float y;
	};
}


