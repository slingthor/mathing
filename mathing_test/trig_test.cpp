#include "pch.h"
#include "../mathing/Math/trig.h"
#include "../mathing/Math/general.h"

const float acceptable_error = 0.001f;

TEST(trig, cosPositiveOne) 
{
	float actual = math::cos(0);
	float expected = 1;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, cosNegativeOne)
{
	float actual = math::cos(math::pi);
	float expected = -1;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}
 
TEST(trig, cosZero)
{
	float actual = math::cos(math::pi/2);
	float expected = 0;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinPositiveOne)
{
	float actual = math::sin(math::pi/2);
	float expected = 1;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinNegativeOne)
{
	float actual = math::sin(1.5*math::pi);
	float expected = -1;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinZero)
{
	float actual = math::sin(0);
	float expected = 0;
	bool isTrue = math::abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}