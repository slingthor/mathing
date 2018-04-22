#include "pch.h"
#include "../mathing/Math/trig.h"
#include "../mathing/Math/general.h"

const float acceptable_error = 0.001f;

TEST(trig, cosPositiveOne) 
{
	float actual = Math::Cos(0);
	float expected = 1;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, cosNegativeOne)
{
	float actual = Math::Cos(Math::pi);
	float expected = -1;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}
 
TEST(trig, cosZero)
{
	float actual = Math::Cos(Math::pi/2);
	float expected = 0;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinPositiveOne)
{
	float actual = Math::Sin(Math::pi/2);
	float expected = 1;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinNegativeOne)
{
	float actual = Math::Sin(1.5*Math::pi);
	float expected = -1;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(trig, sinZero)
{
	float actual = Math::Sin(0);
	float expected = 0;
	bool isTrue = Math::Abs(actual - expected) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(acos, one)
{
	const float actual = Math::acos(1);
	const float isTrue = Math::Abs(actual - 0) < acceptable_error;
	EXPECT_TRUE(isTrue);
}

TEST(asin, one)
{
	const float actual = Math::asin(1);
	const float isTrue = Math::Abs(actual - Math::pi/2) < acceptable_error;
	EXPECT_TRUE(isTrue);
}