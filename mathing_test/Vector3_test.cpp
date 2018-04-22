#include "pch.h"
#include "../mathing/Math/Vector3.h"

TEST(Vector3, initialization)
{
	auto vector = Math::Vector3(1, 2, 3);
	EXPECT_EQ(1, vector.X());
	EXPECT_EQ(2, vector.Y());
	EXPECT_EQ(3, vector.Z());
}

