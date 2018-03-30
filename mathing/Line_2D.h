#pragma once
#include "Math/vector_2D.h"
#include "Math/general.h"

namespace math
{
	class Line_2D
	{
	public:
		vector_2D p1;
		vector_2D p2;

		Line_2D(const vector_2D& p1, const vector_2D& p2)
			: p1{ p1 },
			p2{ p2 }
		{}
		float length();
	};
}