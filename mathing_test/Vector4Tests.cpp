#include "pch.h"
#include "../mathing/Math/Vector4.h"

using namespace Math;

TEST(Vector4, initialization)
{
	auto vector = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	EXPECT_EQ(1, vector.X());
	EXPECT_EQ(2, vector.Y());
	EXPECT_EQ(3, vector.Z());
	EXPECT_EQ(4, vector.W());
}

TEST(Vector4, EqualsTrue)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	EXPECT_TRUE(vector1 == vector2);
}

TEST(Vector4, EqualsFalse)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(1.0f, 2.0f, 3.0f, 5.0f);
	EXPECT_FALSE(vector1 == vector2);
}

TEST(Vector4, NotEqual)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(1.0f, 2.0f, 3.0f, 5.0f);
	EXPECT_TRUE(vector1 != vector2);
}

TEST(Vector4, NotEqualFalse)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	EXPECT_FALSE(vector1 != vector2);
}

TEST(Vector4, Addition)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(5.0f, 6.0f, 7.0f, 8.0f);
	auto sum = vector1 + vector2;
	EXPECT_EQ(sum.X(), 6);
	EXPECT_EQ(sum.Y(), 8);
	EXPECT_EQ(sum.Z(), 10);
	EXPECT_EQ(sum.W(), 12);
}

TEST(Vector4, Subtraction)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(8.0f, 7.0f, 6.0f, 5.0f);
	auto difference = vector2 - vector1;
	EXPECT_EQ(difference.X(), 7.0f);
	EXPECT_EQ(difference.Y(), 5.0f);
	EXPECT_EQ(difference.Z(), 3.0f);
	EXPECT_EQ(difference.W(), 1.0f);
}

TEST(Vector4, ComponentMultiplication)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(5.0f, 6.0f, 7.0f, 8.0f);
	auto product = vector1 * vector2;
	EXPECT_EQ(product.X(), 5.0f);
	EXPECT_EQ(product.Y(), 12.0f);
	EXPECT_EQ(product.Z(), 21.0f);
	EXPECT_EQ(product.W(), 32.0f);
}

TEST(Vector4, leftScalarMultiplication)
{
	auto scalar = 2.0f;
	auto vector = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto product = scalar * vector;
	EXPECT_EQ(product.X(), 2.0f);
	EXPECT_EQ(product.Y(), 4.0f);
	EXPECT_EQ(product.Z(), 6.0f);
	EXPECT_EQ(product.W(), 8.0f);
}

TEST(Vector4, rightScalarMultiplication)
{
	auto vector = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto scalar = 2.0f;
	auto product = vector * scalar;
	EXPECT_EQ(product.X(), 2.0f);
	EXPECT_EQ(product.Y(), 4.0f);
	EXPECT_EQ(product.Z(), 6.0f);
	EXPECT_EQ(product.W(), 8.0f);
}

TEST(Vector4, componentWiseDivision)
{
	auto vector1 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
	auto vector2 = Vector4(5.0f, 6.0f, 12.0f, 8.0f);
	auto quotent = vector2 / vector1;
	EXPECT_EQ(quotent.X(), 5.0f);
	EXPECT_EQ(quotent.Y(), 3.0f);
	EXPECT_EQ(quotent.Z(), 4.0f);
	EXPECT_EQ(quotent.W(), 2.0f);
}

TEST(Vector4, scalarDivision)
{
	auto vector = Vector4(2.0f, 4.0f, 6.0f, 8.0f);
	auto scalar = 2.0f;
	auto product = vector / scalar;
	EXPECT_EQ(product.X(), 1.0f);
	EXPECT_EQ(product.Y(), 2.0f);
	EXPECT_EQ(product.Z(), 3.0f);
	EXPECT_EQ(product.W(), 4.0f);
}

TEST(Vector4, setters)
{
	auto vector = Vector4();
	vector.SetX(1.0f);
	vector.SetY(2.0f);
	vector.SetZ(3.0f);
	EXPECT_EQ(vector.X(), 1);
	EXPECT_EQ(vector.Y(), 2);
	EXPECT_EQ(vector.Z(), 3);
}

TEST(Vector4, zero)
{
	auto zero = Vector4::Zero();
	EXPECT_EQ(zero.X(), 0);
	EXPECT_EQ(zero.Y(), 0);
	EXPECT_EQ(zero.Z(), 0);
	EXPECT_EQ(zero.W(), 0);
}

TEST(Vector4, Distance)
{
	auto distance = Vector4(1.0f, 1.0f, 1.0f, 1.0f).Distance(Vector4(1.0f, 1.0f, 1.0f, 2.0f));
	EXPECT_EQ(1, distance);
}

TEST(Vector4, Magnitude)
{
	auto magnitude = Vector4(0.0f, 0.0f, 0.0f, 2.0f).Magnitude();
	EXPECT_EQ(magnitude, 2);
}

TEST(Vector4, SquaredMagnitude)
{
	auto squaredMagnitude = Vector4(0.0f, 0.0f, 0.0f, 3.0f).SquaredMagnitude();
	EXPECT_EQ(squaredMagnitude, 9);
}

TEST(Vector4, Normalized)
{
	auto vector{ Vector4(4.0f,5.0f,6.0f,7.0f).Normalized() };
	EXPECT_TRUE(abs(vector.X() - 0.356348f) < 0.001f);
	EXPECT_TRUE(abs(vector.Y() - 0.44535f) < 0.001f);
	EXPECT_TRUE(abs(vector.Z() - 0.534522f) < 0.001f);
	EXPECT_TRUE(abs(vector.W() - 0.62361f) < 0.001f);
}

TEST(Vector4, DotProduct)
{
	auto vector1{ Vector4(1.0f,2.0f,3.0f,4.0f) };
	auto vector2{ Vector4(5.0f,6.0f,7.0f, 8.0f) };
	auto dotProduct = vector1.Dot(vector2);
	EXPECT_EQ(dotProduct, 70);
}

TEST(Vector4, Projection)
{
	auto vector1{ Vector4(2.0f,2.0f,2.0f, 0.0f) };
	auto vector2{ Vector4(1.0f,0.0f,0.0f, 0.0f) };
	auto projVec1onVec2{ vector1.Projection(vector2) };
	EXPECT_EQ(projVec1onVec2, Vector4(2.0f, 0.0f, 0.0f, 0.0f));
}

TEST(Vector4, AdditionAssignment)
{
	auto vector{ Vector4(1.0f, 1.0f, 1.0f, 1.0f) };
	vector += Vector4(2.0f, 2.0f, 2.0f, 2.0f);
	EXPECT_EQ(vector, Vector4(3.0f, 3.0f, 3.0f, 3.0f));
}

TEST(Vector4, SubtractionAssignment)
{
	auto vector{ Vector4(1.0f,1.0f,1.0f, 1.0f) };
	vector -= { Vector4(2.0f, 2.0f, 2.0f, 2.0f)};
	EXPECT_EQ(vector, Vector4(-1.0f, -1.0f, -1.0f, -1.0f));
}

TEST(Vector4, MultiplicationAssignment)
{
	auto vector{ Vector4(1.0f,1.0f,1.0f, 1.0f) };
	vector *= { Vector4(2.0f, 2.0f, 2.0f, 2.0f)};
	EXPECT_EQ(vector, Vector4(2.0f, 2.0f, 2.0f, 2.0f));
}

TEST(Vector4, DivisionAssignment)
{
	auto vector{ Vector4(1.0f,1.0f,1.0f, 1.0f) };
	vector /= { Vector4(0.5f, 0.5f, 0.5f, 0.5f)};
	EXPECT_EQ(vector, Vector4(2.0f, 2.0f, 2.0f, 2.0f));
}

TEST(Vector4, ScalarMultiplicationAssignment)
{
	auto vector{ Vector4(1.0f, 1.0f, 1.0f, 1.0f) };
	vector *= 2.0f;
	EXPECT_EQ(vector, Vector4(2.0f, 2.0f, 2.0f, 2.0f));
}

TEST(Vector4, ScalarDivisionAssignment)
{
	auto vector{ Vector4(4.0f, 4.0f, 4.0f, 4.0f) };
	vector /= 2.0f;
	EXPECT_EQ(vector, Vector4(2.0f, 2.0f, 2.0f, 2.0f));
}