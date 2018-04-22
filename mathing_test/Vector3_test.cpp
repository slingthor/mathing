#include "pch.h"
#include "../mathing/Math/Vector3.h"

using namespace Math;

TEST(Vector3, initialization)
{
	auto vector = Vector3(1.0f, 2.0f, 3.0f);
	EXPECT_EQ(1, vector.X());
	EXPECT_EQ(2, vector.Y());
	EXPECT_EQ(3, vector.Z());
}

TEST(Vector3, EqualsTrue)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(1.0f, 2.0f, 3.0f);
	EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector3, EqualsFalse)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(1.0f, 2.0f, 2.0f);
	EXPECT_FALSE(vector1 == vector2);
}

TEST(Vector3, NotEqual)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(1.0f, 2.0f, 2.0f);
	EXPECT_TRUE(vector1 != vector2);
}

TEST(Vector3, NotEqualFalse)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(1.0f, 2.0f, 3.0f);
	EXPECT_FALSE(vector1 != vector2);
}

TEST(Vector3, Addition)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(4.0f, 5.0f, 6.0f);
	auto sum = vector1 + vector2;
	EXPECT_EQ(sum.X(), 5);
	EXPECT_EQ(sum.Y(), 7);
	EXPECT_EQ(sum.Z(), 9);
}

TEST(Vector3, Subtraction)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(6.0f, 5.0f, 4.0f);
	auto difference = vector2 - vector1;
	EXPECT_EQ(difference.X(), 5.0f);
	EXPECT_EQ(difference.Y(), 3.0f);
	EXPECT_EQ(difference.Z(), 1.0f);
}

TEST(Vector3, ComponentMultiplication)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(4.0f, 5.0f, 6.0f);
	auto product = vector1 * vector2;
	EXPECT_EQ(product.X(), 4.0f);
	EXPECT_EQ(product.Y(), 10.0f);
	EXPECT_EQ(product.Z(), 18.0f);
}

TEST(Vector3, leftScalarMultiplication)
{
	auto scalar = 2.0f;
	auto vector = Vector3(1.0f, 2.0f, 3.0f);
	auto product = scalar * vector;
	EXPECT_EQ(product.X(), 2.0f);
	EXPECT_EQ(product.Y(), 4.0f);
	EXPECT_EQ(product.Z(), 6.0f);
}

TEST(Vector3, rightScalarMultiplication)
{
	auto vector = Vector3(1.0f, 2.0f, 3.0f);
	auto scalar = 2.0f;
	auto product = vector * scalar;
	EXPECT_EQ(product.X(), 2.0f);
	EXPECT_EQ(product.Y(), 4.0f);
	EXPECT_EQ(product.Z(), 6.0f);
}

TEST(Vector3, componentWiseDivision)
{
	auto vector1 = Vector3(1.0f, 2.0f, 3.0f);
	auto vector2 = Vector3(2.0f, 4.0f, 6.0f);
	auto quotent = vector2 / vector1;
	EXPECT_EQ(quotent.X(), 2.0f);
	EXPECT_EQ(quotent.Y(), 2.0f);
	EXPECT_EQ(quotent.Z(), 2.0f);
}

TEST(Vector3, scalarDivision)
{
	auto vector = Vector3(2.0f, 4.0f, 6.0f);
	auto scalar = 2.0f;
	auto product = vector / scalar;
	EXPECT_EQ(product.X(), 1.0f);
	EXPECT_EQ(product.Y(), 2.0f);
	EXPECT_EQ(product.Z(), 3.0f);
}

TEST(Vector3, setters)
{
	auto vector = Vector3();
	vector.SetX(1.0f);
	vector.SetY(2.0f);
	vector.SetZ(3.0f);
	EXPECT_EQ(vector.X(), 1);
	EXPECT_EQ(vector.Y(), 2);
	EXPECT_EQ(vector.Z(), 3);
}

TEST(Vector3, zero)
{
	auto zero = Vector3::Zero();
	EXPECT_EQ(zero.X(), 0);
	EXPECT_EQ(zero.Y(), 0);
	EXPECT_EQ(zero.Z(), 0);
}

TEST(Vector3, Distance)
{
	auto distance = Vector3(1.0f, 1.0f, 1.0f).Distance(Vector3(1.0f, 2.0f, 1.0f));
	EXPECT_EQ(1, distance);
}

TEST(Vector3, Magnitude)
{
	auto magnitude = Vector3(0.0f, 2.0f, 0.0f).Magnitude();
	EXPECT_EQ(magnitude, 2);
}

TEST(Vector3, SquaredMagnitude)
{
	auto squaredMagnitude = Vector3(0.0f, 0.0f, 3.0f).SquaredMagnitude();
	EXPECT_EQ(squaredMagnitude, 9);
}

TEST(Vector3, Normalized)
{
	auto vector{ Vector3(4.0f,5.0f,6.0f).Normalized() };
	EXPECT_TRUE(abs(vector.X() - 0.455842f) < 0.001f);
	EXPECT_TRUE(abs(vector.Y() - 0.569803f) < 0.001f);
	EXPECT_TRUE(abs(vector.Z() - 0.683763f) < 0.001f);
}

TEST(Vector3, DotProduct)
{
	auto vector1{ Vector3(1.0f,2.0f,3.0f) };
	auto vector2{ Vector3(4.0f,5.0f,6.0f) };
	auto dotProduct = vector1.Dot(vector2);
	EXPECT_EQ(dotProduct, 32);
}

TEST(Vector3, CrossProduct)
{
	auto vector1{ Vector3(1.0f,2.0f,3.0f) };
	auto vector2{ Vector3(4.0f,5.0f,6.0f) };
	auto crossProduct = vector1.Cross(vector2);
	EXPECT_EQ(crossProduct, Vector3(-3.0f, 6.0f, -3.0f));
}

TEST(Vector3, Projection)
{
	auto vector1{ Vector3(2.0f,2.0f,2.0f) };
	auto vector2{ Vector3(1.0f,0.0f,0.0f) };
	auto projVec1onVec2 { vector1.Projection(vector2) };
	EXPECT_EQ(projVec1onVec2, Vector3(2.0f, 0.0f, 0.0f));
}

TEST(Vector3, AdditionAssignment)
{
	auto vector{ Vector3(1.0f, 1.0f, 1.0f) };
	vector += Vector3(2.0f, 2.0f, 2.0f);
	EXPECT_EQ(vector, Vector3(3.0f, 3.0f, 3.0f));
}

TEST(Vector3, SubtractionAssignment)
{
	auto vector{ Vector3(1.0f,1.0f,1.0f) };
	vector -= { Vector3(2.0f, 2.0f, 2.0f)};
	EXPECT_EQ(vector, Vector3(-1.0f, -1.0f, -1.0f));
}

TEST(Vector3, MultiplicationAssignment)
{
	auto vector{ Vector3(1.0f,1.0f,1.0f) };
	vector *= { Vector3(2.0f, 2.0f, 2.0f)};
	EXPECT_EQ(vector, Vector3(2.0f, 2.0f, 2.0f));
}

TEST(Vector3, DivisionAssignment)
{
	auto vector{ Vector3(1.0f,1.0f,1.0f) };
	vector *= { Vector3(0.5f, 0.5f, 2.0f)};
	EXPECT_EQ(vector, Vector3(2.0f, 2.0f, 2.0f));
}