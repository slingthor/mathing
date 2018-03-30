#include "pch.h"
#include "../mathing/Math/vector_2D.h"

TEST(vector_2D, Construction) {
	math::vector_2D a = math::vector_2D(0, 1);
	EXPECT_EQ(a.x, 0);
	EXPECT_EQ(a.y, 1);
}