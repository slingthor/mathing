#include "pch.h"
#include "Matrix3.h"
#include <cassert>
#include "Vector3.h"

namespace math
{
	auto operator*(const Matrix3& lhs, const Matrix3& rhs) -> Matrix3 
	{
		const auto n00 = lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1) + lhs(2, 0) * rhs(0, 2);
		const auto n10 = lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(1, 2);
		const auto n20 = lhs(0, 0) * rhs(2, 0) + lhs(1, 0) * rhs(2, 1) + lhs(2, 0) * rhs(2, 2);

		const auto n01 = lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(2, 1) * rhs(0, 2);
		const auto n11 = lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(1, 2);
		const auto n21 = lhs(0, 1) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(2, 1) * rhs(2, 2);

		const auto n02 = lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2);
		const auto n12 = lhs(0, 2) * rhs(1, 0) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2);
		const auto n22 = lhs(0, 2) * rhs(2, 0) + lhs(1, 2) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2);

		return Matrix3
		{
			n00, n10, n20,
			n01, n11, n21,
			n02, n12, n22
		};
	}

	auto operator*(const Vector3& lhs, const Matrix3& rhs) -> Vector3
	{
		const auto x = lhs.X() * rhs(0, 0) + lhs.Y() * rhs(0, 1) + lhs.Z() * rhs(0, 2);
		const auto y = lhs.X() * rhs(1, 0) + lhs.Y() * rhs(1, 1) + lhs.Z() * rhs(1, 2);
		const auto z = lhs.X() * rhs(2, 0) + lhs.Y() * rhs(2, 1) + lhs.Z() * rhs(2, 2);

		return { x, y, z };
	}

	auto Matrix3::operator()(SIZE_T x, SIZE_T y) -> float&
	{
		return matrix[x][y];
	}

	auto Matrix3::operator()(SIZE_T x, SIZE_T y) const -> const float&
	{
		return matrix[x][y];
	}

	auto Matrix3::Row(const SIZE_T index) const -> Vector3
	{
#if !PRODUCTION
		assert(index < 4);
#endif
		return 
		{ 
			matrix[index][0], matrix[index][1], matrix[index][2]
		};
	}

	auto Matrix3::Column(const SIZE_T index) const -> Vector3
	{
#if !PRODUCTION
		assert(index < 4);
#endif
		return
		{
			matrix[0][index],
			matrix[1][index],
			matrix[2][index]
		};
	}

	auto Matrix3::Determinant() const noexcept -> float
	{
		const auto det0 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
		const auto det1 = matrix[1][0] * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
		const auto det2 = matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);
		return det0 - det1 + det2;
	}

	auto Matrix3::Inverse() const noexcept -> Matrix3
	{
		const auto a = Column(0);
		const auto b = Column(1);
		const auto c = Column(2);

		auto r0 = b.Cross(c);
		auto r1 = c.Cross(a);
		auto r2 = a.Cross(b);

		const auto invDet = 1.0f / r2.Dot(c);

		return Matrix3
		{
			invDet* r0.X(), invDet* r0.Y(), invDet* r0.Z(),
			invDet* r1.X(), invDet* r1.Y(), invDet* r1.Z(),
			invDet* r2.X(), invDet* r2.Y(), invDet* r2.Z()
		};
	}
}