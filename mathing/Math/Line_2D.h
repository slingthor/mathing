include "vector_2D.h"
#include "general.h"
#pragma once

namespace math
{
	class line_2D
	{
	public:
		
		vector_2D p1;
		vector_2D p2;

		line_2D(const vector_2D& p1, const vector_2D& p2)
			: p1{ p1 },
			p2{ p2 }
		{}
		float length();
		
	};
}