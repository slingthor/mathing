#include "pch.h"
#include "Matrix4.h"
#include "Vector4.h"
#include <cassert>
namespace Math
{
	auto operator*(const Matrix4& lhs, const Matrix4& rhs) -> Matrix4
	{
		const auto n00 = lhs(0, 0) * rhs(0, 0) + lhs(1, 0) * rhs(0, 1) + lhs(2, 0) * rhs(0, 2) + lhs(3, 0) * rhs(0, 3);
		const auto n10 = lhs(0, 0) * rhs(1, 0) + lhs(1, 0) * rhs(1, 1) + lhs(2, 0) * rhs(1, 2) + lhs(3, 0) * rhs(1, 3);
		const auto n20 = lhs(0, 0) * rhs(2, 0) + lhs(1, 0) * rhs(2, 1) + lhs(2, 0) * rhs(2, 2) + lhs(3, 0) * rhs(2, 3);
		const auto n30 = lhs(0, 0) * rhs(3, 0) + lhs(1, 0) * rhs(3, 1) + lhs(2, 0) * rhs(3, 2) + lhs(3, 0) * rhs(3, 3);

		const auto n01 = lhs(0, 1) * rhs(0, 0) + lhs(1, 1) * rhs(0, 1) + lhs(2, 1) * rhs(0, 2) + lhs(3, 1) * rhs(0, 3);
		const auto n11 = lhs(0, 1) * rhs(1, 0) + lhs(1, 1) * rhs(1, 1) + lhs(2, 1) * rhs(1, 2) + lhs(3, 1) * rhs(1, 3);
		const auto n21 = lhs(0, 1) * rhs(2, 0) + lhs(1, 1) * rhs(2, 1) + lhs(2, 1) * rhs(2, 2) + lhs(3, 1) * rhs(2, 3);
		const auto n31 = lhs(0, 1) * rhs(3, 0) + lhs(1, 1) * rhs(3, 1) + lhs(2, 1) * rhs(3, 2) + lhs(3, 1) * rhs(3, 3);

		const auto n02 = lhs(0, 2) * rhs(0, 0) + lhs(1, 2) * rhs(0, 1) + lhs(2, 2) * rhs(0, 2) + lhs(3, 2) * rhs(0, 3);
		const auto n12 = lhs(0, 2) * rhs(1, 0) + lhs(1, 2) * rhs(1, 1) + lhs(2, 2) * rhs(1, 2) + lhs(3, 2) * rhs(1, 3);
		const auto n22 = lhs(0, 2) * rhs(2, 0) + lhs(1, 2) * rhs(2, 1) + lhs(2, 2) * rhs(2, 2) + lhs(3, 2) * rhs(2, 3);
		const auto n32 = lhs(0, 2) * rhs(3, 0) + lhs(1, 2) * rhs(3, 1) + lhs(2, 2) * rhs(3, 2) + lhs(3, 2) * rhs(3, 3);

		const auto n03 = lhs(0, 3) * rhs(0, 0) + lhs(1, 3) * rhs(0, 1) + lhs(2, 3) * rhs(0, 2) + lhs(3, 3) * rhs(0, 3);
		const auto n13 = lhs(0, 3) * rhs(1, 0) + lhs(1, 3) * rhs(1, 1) + lhs(2, 3) * rhs(1, 2) + lhs(3, 3) * rhs(1, 3);
		const auto n23 = lhs(0, 3) * rhs(2, 0) + lhs(1, 3) * rhs(2, 1) + lhs(2, 3) * rhs(2, 2) + lhs(3, 3) * rhs(2, 3);
		const auto n33 = lhs(0, 3) * rhs(3, 0) + lhs(1, 3) * rhs(3, 1) + lhs(2, 3) * rhs(3, 2) + lhs(3, 3) * rhs(3, 3);


		return Matrix4
		{
			n00, n10, n20, n30,
			n01, n11, n21, n31,
			n02, n12, n22, n32,
			n03, n13, n23, n33
		};
	}

	auto operator*(const Vector4& lhs, const Matrix4& rhs) -> Vector4
	{
		const auto x = lhs.X() * rhs(0, 0) + lhs.Y() * rhs(0, 1) + lhs.Z() * rhs(0, 2) + lhs.W() * rhs(0, 3);
		const auto y = lhs.X() * rhs(1, 0) + lhs.Y() * rhs(1, 1) + lhs.Z() * rhs(1, 2) + lhs.W() * rhs(1, 3);
		const auto z = lhs.X() * rhs(2, 0) + lhs.Y() * rhs(2, 1) + lhs.Z() * rhs(2, 2) + lhs.W() * rhs(2, 3);
		const auto w = lhs.X() * rhs(3, 0) + lhs.Y() * rhs(3, 1) + lhs.Z() * rhs(3, 2) + lhs.W() * rhs(3, 3);

		return { x, y, z, w };
	}

	auto Matrix4::operator()(const SIZE_T x, const SIZE_T y) -> float&

	{
		return (matrix[x][y]);
	}

	auto Matrix4::operator()(const SIZE_T x, const SIZE_T y) const -> const float&
	{
		return (matrix[x][y]);
	}

	Matrix4::Matrix4(
		const float n00, const float n10, const float n20, const float n30, 
		const float n01, const float n11, const float n21, const float n31,
		const float n02, const float n12, const float n22, const float n32,
		const float n03, const float n13, const float n23, const float n33) noexcept
	{
		matrix[0][0] = n00;	matrix[1][0] = n10;	matrix[2][0] = n20;	matrix[3][0] = n30;
		matrix[0][1] = n01;	matrix[1][1] = n11;	matrix[2][1] = n21;	matrix[3][1] = n31;
		matrix[0][2] = n02;	matrix[1][2] = n12;	matrix[2][2] = n22;	matrix[3][2] = n32;
		matrix[0][3] = n03;	matrix[1][3] = n13;	matrix[2][3] = n23;	matrix[3][3] = n33;
	}

	Matrix4::Matrix4(const float matrix[4][4]) noexcept
	{
		for (auto x = 0; x < 4; ++x)
		{
			for (auto y = 0; y < 4; ++y)
			{
				this->matrix[x][y] = matrix[x][y];
			}
		}
	}

	auto Matrix4::row(const SIZE_T index) const -> Vector4
	{
#if !PRODUCTION
		assert(index < 4);
#endif
		return 
		{
			matrix[index][0], matrix[index][1], matrix[index][2], matrix[index][3]
		};
	}

	auto Matrix4::column(const SIZE_T index) const -> Vector4
	{
#if !PRODUCTION
		assert(index < 4);
#endif
		return
		{
			matrix[0][index],
			matrix[1][index],
			matrix[2][index],
			matrix[3][index]
		};
	}

	auto Matrix4::determinant() const noexcept -> float
	{
		const auto det0 = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
		const auto det1 = matrix[1][0] * (matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[0][2]);
		const auto det2 = matrix[2][0] * (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]);

		return det0 - det1 + det2;
	}

	auto Matrix4::inverse() const noexcept -> Matrix4
	{
		const auto a = column(0);
		const auto b = column(1);
		const auto c = column(2);
		const auto d = column(3);

		const auto bottomRow = row(3);

		auto s = a.Cross(b);
		auto t = c.Cross(d);
		auto u = a * bottomRow.Y() - b * bottomRow.X();
		auto v = c * bottomRow.W() - d * bottomRow.Z();

		const auto invDet = 1.0f / (s.Dot(v) + t.Dot(u));
		s *= invDet;
		t *= invDet;
		u *= invDet;
		v *= invDet;

		auto r0 = b.Cross(v) + t * bottomRow.Y();
		auto r1 = v.Cross(a) - t * bottomRow.X();
		auto r2 = d.Cross(u) + s * bottomRow.W();
		auto r3 = u.Cross(c) - s * bottomRow.Z();

		return Matrix4{
			r0.X(), r0.Y(), r0.Z(), -b.Dot(t),
			r1.X(), r1.Y(), r1.Z(), a.Dot(t),
			r2.X(), r2.Y(), r2.Z(), -d.Dot(a),
			r3.X(), r3.Y(), r3.Z(), c.Dot(s)
		};
	}
}

