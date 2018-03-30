#pragma once
#include "vector_2D.h"
namespace math
{
	class triangle_2D
	{
	public:
		vector_2D a;
		vector_2D b;
		vector_2D c;

		triangle_2D(const vector_2D& a, const vector_2D& b, const vector_2D& c)
			: a{ a },
			b{ b },
			c{ c }
		{}
		~triangle_2D();
	};
}
