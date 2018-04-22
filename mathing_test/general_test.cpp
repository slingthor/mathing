#include "pch.h"
#include "../mathing/Math/general.h"
using namespace Math;
TEST(General, powerPositive) {
	const float powered = Pow(4.0f, 3.0f);
	const float actual = 64;
	bool isTrue = abs(powered - actual) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(General, powerZero)
{
	const float powered = Pow(255.0f, 0.0f);
	bool isTrue = abs(powered - 1.0f) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(General, powerNegative)
{
	const float powered = Pow(4.0f, -3.0f);
	bool equals = false;

}

TEST(General, absPositive)
{
	EXPECT_EQ(Math::Abs(1.0f), 1.0f);
}

TEST(General, absNegative)
{
	EXPECT_EQ(Math::Abs(-1.0f), 1.0f);
}

TEST(General, sqrtZero)
{
	const float isTrue = (Sqrt(0.0f) - 0.0f) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(General, sqrtSixtyfour)
{
	const float isTrue = Sqrt(64.0f) - 8.0f < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(General, sqrtOneThousandTwentyFour)
{
	const float isTrue = Sqrt(1024.0f) - 32.0f < 0.001f;
	EXPECT_TRUE(isTrue);
}