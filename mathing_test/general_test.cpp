#include "pch.h"
#include "../mathing/Math/general.h"

TEST(power, positive) {
	const float powered = Math::pow(4, 3);
	const float actual = 64;
	bool isTrue = abs(powered - actual) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(power, zero)
{
	const float powered = Math::pow(255.0f, 0);
	bool isTrue = abs(powered - 1) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(power, negative)
{
	const float powered = Math::pow(4, -3);
	bool equals = false;

}

TEST(abs, positive)
{
	EXPECT_EQ(math::abs(1), 1);
}

TEST(abs, negative)
{
	EXPECT_EQ(math::abs(-1), 1);
}

TEST(sqrt, zero)
{
	const float isTrue = (Math::sqrt(0) - 0) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(sqrt, sixtyfour)
{
	const float isTrue = (Math::sqrt(64) - 8) < 0.001f;
	EXPECT_TRUE(isTrue);
}

TEST(sqrt, oneThousandTwentyFour)
{
	const float isTrue = (Math::sqrt(1024) - 32) < 0.001f;
	EXPECT_TRUE(isTrue);
}