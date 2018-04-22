#include "pch.h"
#include "Quaternion.h"
#include "Math/general.h"
#include "Math/trig.h"
#include "Math/Vector3.h"
#include "Math/Vector4.h"
#include "Math/Matrix3.h"
#include "Math/Matrix4.h"

namespace math
{
	auto operator+(const Quaternion & lhs, const Quaternion & rhs) -> Quaternion
	{
		auto sum { 
			Quaternion {
				lhs.x_ + rhs.x_,
				lhs.y_ + rhs.y_,
				lhs.z_ + rhs.z_,
				lhs.w_ + rhs.w_
			} 
		};
		return sum.Normalized();
	}

	auto operator-(const Quaternion & lhs, const Quaternion & rhs) -> Quaternion
	{
		auto difference {
			Quaternion {
				lhs.x_ - rhs.x_,
				lhs.y_ - rhs.y_,
				lhs.z_ - rhs.z_,
				lhs.w_ - rhs.w_
			} 
		};
		return difference.Normalized();
	}

	auto operator*(const Quaternion& lhs, const Quaternion& rhs) -> Quaternion
	{
		auto product { 
			Quaternion {
				lhs.x_ * rhs.x_,
				lhs.y_ * rhs.y_,
				lhs.z_ * rhs.z_,
				lhs.w_ * rhs.w_
			} 
		};
		return product.Normalized();
	}

	Quaternion::Quaternion(const Vector3& axis, float angle)
	{
		const auto sinEncoding = sin(angle / 2);
		x_ = axis.X() * sinEncoding;
		y_ = axis.Y() * sinEncoding;
		z_ = axis.Z() * sinEncoding;
		w_ = cos(angle / 2);

	}

	Quaternion::Quaternion(const Vector4 & values)
		: Quaternion {
		values.X(),
		values.Y(),
		values.Z(),
		values.W()
	} {}

	Quaternion::Quaternion(const Vector3 & eulerAngles)
	{
		const auto cosXHalf { cos(eulerAngles.X() / 2) };
		const auto cosYHalf { cos(eulerAngles.Y() / 2) };
		const auto cosZHalf { cos(eulerAngles.Z() / 2) };
		const auto sinXHalf { sin(eulerAngles.X() / 2) };
		const auto sinYHalf { sin(eulerAngles.Y() / 2) };
		const auto sinZHalf { sin(eulerAngles.Z() / 2) };

		w_ = cosXHalf * cosYHalf * cosZHalf - sinXHalf * sinYHalf * sinZHalf;
		x_ = sinXHalf * cosYHalf * cosZHalf + cosXHalf * sinYHalf * sinZHalf;
		y_ = cosXHalf * sinYHalf * cosZHalf - sinXHalf * cosYHalf * sinZHalf;
		z_ = cosXHalf * cosYHalf * sinZHalf + sinXHalf * sinYHalf * cosZHalf;

	}

	Quaternion::Quaternion(const Matrix3& matrix)
	{
		const auto m00 = matrix(0, 0);
		const auto m11 = matrix(1, 1);
		const auto m22 = matrix(2, 2);
		//Depending on the largest diagonal, we take the corresponding values from the matrix
		if (m00 > m11 && m00 > m22)
		{
			x_ = matrix(0, 0) - matrix(1, 1) - matrix(2, 2) + 1;
			y_ = matrix(1, 0) + matrix(0, 1);
			z_ = matrix(2, 0) + matrix(0, 2);
			w_ = matrix(1, 2) - matrix(2, 1);
		} 
		else if (m11 > m00)
		{
			y_ = matrix(1, 1) - matrix(0, 0) - matrix(2, 2) + 1;
			x_ = matrix(1, 0) + matrix(0, 1);
			z_ = matrix(2, 1) + matrix(1, 2);
			w_ = matrix(2, 0) - matrix(0, 2);
		}
		else
		{
			z_ = matrix(2, 2) - matrix(0, 0) - matrix(1, 1) + 1;
			x_ = matrix(2, 0) + matrix(0, 2);
			y_ = matrix(1, 2) + matrix(2, 1);
			w_ = matrix(0, 1) - matrix(1, 0);
		}
		Normalize();
	}

	Quaternion::Quaternion(const Matrix4 & matrix)
	{
		const auto m00 = matrix(0, 0);
		const auto m11 = matrix(1, 1);
		const auto m22 = matrix(2, 2);
		//Depending on the largest diagonal, we take the corresponding values from the matrix
		if (m00 > m11 && m00 > m22)
		{
			x_ = matrix(0, 0) - matrix(1, 1) - matrix(2, 2) + 1;
			y_ = matrix(1, 0) + matrix(0, 1);
			z_ = matrix(2, 0) + matrix(0, 2);
			w_ = matrix(1, 2) - matrix(2, 1);
		}
		else if (m11 > m00)
		{
			y_ = matrix(1, 1) - matrix(0, 0) - matrix(2, 2) + 1;
			x_ = matrix(1, 0) + matrix(0, 1);
			z_ = matrix(2, 1) + matrix(1, 2);
			w_ = matrix(2, 0) - matrix(0, 2);
		}
		else
		{
			z_ = matrix(2, 2) - matrix(0, 0) - matrix(1, 1) + 1;
			x_ = matrix(2, 0) + matrix(0, 2);
			y_ = matrix(1, 2) + matrix(2, 1);
			w_ = matrix(0, 1) - matrix(1, 0);
		}
		Normalize();
	}

	auto Quaternion::ToMatrix3() const -> Matrix3
	{
		const auto twoXSquared { 2 * pow(x_, 2) };
		const auto twoYSquared { 2 * pow(y_, 2) };
		const auto twoZSquared { 2 * pow(x_, 2) };
		const auto twoXY { 2 * x_ * y_ };
		const auto twoWZ { 2 * w_ * z_ };
		const auto twoXZ { 2 * x_ * z_ };
		const auto twoWY { 2 * w_ * y_ };
		const auto twoWX { 2 * w_ * x_ };
		const auto twoYZ { 2 * w_ * z_ };

		const auto m00 { 1 - twoYSquared - twoZSquared };
		const auto m10 { twoXY - twoWZ };
		const auto m20 { twoXZ + twoWY };
		const auto m01 { twoXY + twoWZ };
		const auto m11 { 1 - twoXSquared - twoZSquared };
		const auto m21 { twoYZ - twoWX };
		const auto m02 { twoXZ - twoWY };
		const auto m12 { twoYZ + twoWX };
		const auto m22 { 1 - twoXSquared - twoYSquared };
		return Matrix3{
			m00, m10, m20,
			m01, m11, m21,
			m02, m12, m22
		};
	}

	auto Quaternion::ToMatrix4() const -> Matrix4
	{
		const auto twoXSquared{ 2 * pow(x_, 2) };
		const auto twoYSquared{ 2 * pow(y_, 2) };
		const auto twoZSquared{ 2 * pow(x_, 2) };
		const auto twoXY{ 2 * x_ * y_ };
		const auto twoWZ{ 2 * w_ * z_ };
		const auto twoXZ{ 2 * x_ * z_ };
		const auto twoWY{ 2 * w_ * y_ };
		const auto twoWX{ 2 * w_ * x_ };
		const auto twoYZ{ 2 * w_ * z_ };

		const auto m00{ 1 - twoYSquared - twoZSquared };
		const auto m10{ twoXY - twoWZ };
		const auto m20{ twoXZ + twoWY };
		const auto m01{ twoXY + twoWZ };
		const auto m11{ 1 - twoXSquared - twoZSquared };
		const auto m21{ twoYZ - twoWX };
		const auto m02{ twoXZ - twoWY };
		const auto m12{ twoYZ + twoWX };
		const auto m22{ 1 - twoXSquared - twoYSquared };

		return Matrix4 {
			m00, m10, m20, 0,
			m01, m11, m21, 0,
			m02, m12, m22, 0,
			0, 0, 0, 1
		};
	}


	auto Quaternion::Magnitude() const -> float
	{
		return sqrt(
			pow(x_, 2) +
			pow(y_, 2) +
			pow(z_, 2) +
			pow(w_, 2)
		);
	}

	auto Quaternion::Normalized() const -> Quaternion
	{
		const auto magnitude{ Magnitude() };
		return {
			x_ / magnitude,
			y_ / magnitude,
			z_ / magnitude,
			w_ / magnitude
		};
	}

	auto Quaternion::Normalize()
	{
		const auto magnitude{ Magnitude() };
		x_ = x_ / magnitude;
		y_ = y_ / magnitude;
		z_ = z_ / magnitude;
		w_ = w_ / magnitude;
		w_ = w_ / magnitude;
	}
}
