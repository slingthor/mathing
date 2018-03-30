#include "pch.h"
#include "../mathing/Math/Line_2D.h"
#include "../mathing/Math/general.h"
using namespace math;

line_2D mockLine()
{
	return line_2D(vector_2D(1, 2), vector_2D(3, 4));
}

TEST(line_2D, construction) {
	line_2D line = mockLine();
	EXPECT_EQ(line.p1.x, 1);
	EXPECT_EQ(line.p1.y, 2);
	EXPECT_EQ(line.p2.x, 3);
	EXPECT_EQ(line.p2.y, 4);
}

TEST(line_2D, length)
{
	line_2D line = mockLine();
	float actual = line.length();
	float expected = 2.828427f;
	bool isTrue = math::abs(actual - expected) < 0.001f;
	EXPECT_TRUE(isTrue);
}