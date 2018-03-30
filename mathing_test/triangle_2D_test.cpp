#include "pch.h"
#include "../mathing/Math/triangle_2D.h"
#include "../mathing/Math/vector_2D.h"

TEST(triangle_2D, Construction) {
	math::vector_2D a = math::vector_2D(0, 0);
	math::vector_2D b = math::vector_2D(1, 0);
	math::vector_2D c = math::vector_2D(0, 1);

	math::triangle_2D triangle = math::triangle_2D(a, b, c);
	EXPECT_EQ(triangle.a.x, 0);
	EXPECT_EQ(triangle.a.y, 0);
	EXPECT_EQ(triangle.b.x, 1);
	EXPECT_EQ(triangle.b.y, 0);
	EXPECT_EQ(triangle.c.x, 0);
	EXPECT_EQ(triangle.c.y, 1);
}