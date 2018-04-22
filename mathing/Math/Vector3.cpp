#include "pch.h"
#include "general.h"
#include "Vector3.h"

namespace Math
{
	auto Vector3::Distance(const Vector3& vector1, const Vector3& vector2) -> float
	{
		return Sqrt(
			Pow(vector2.x_ - vector1.x_, 2) +
			Pow(vector2.y_ - vector1.y_, 2) +
			Pow(vector2.z_ - vector1.z_, 2)
		);
	}

	auto Vector3::Distance(const Vector3& other) const -> float
	{
		return Distance(*this, other);
	}

	auto Vector3::Magnitude() const -> float
	{
		return Sqrt(
			Pow(X(), 2) +
			Pow(Y(), 2) +
			Pow(Z(), 2)
		);
	}

	auto Vector3::SquaredMagnitude() const -> float
	{
		return Pow(X(), 2) +
			Pow(Y(), 2) +
			Pow(Z(), 2);
	}

	auto Vector3::Normalized() const -> Vector3
	{
		const auto length = Magnitude();
		return Vector3{
			x_ / length,
			y_ / length,
			z_ / length,
		};
	}

	auto Vector3::Dot(const Vector3& vector1, const Vector3& vector2) -> float
	{
		return vector1.X() * vector2.X() +
			vector1.Y() * vector2.Y() +
			vector1.Z() * vector2.Z();
	}

	auto Vector3::Dot(const Vector3& vector) const -> float
	{
		return Dot(*this, vector);
	}

	auto Vector3::Cross(const Vector3& vector1, const Vector3& vector2) -> Vector3
	{
		const float x = vector1.Y()*vector2.Z() - vector1.Z()*vector2.Y();
		const float y = vector1.Z()*vector2.X() - vector1.X()*vector2.Z();
		const float z = vector1.X()*vector2.Y() - vector1.Y()*vector2.X();
		return { x, y, z };
	}

	auto Vector3::Cross(const Vector3& vector) const -> Vector3
	{
		return Cross(*this, vector);
	}

	auto Vector3::Projection(const Vector3& from, const Vector3& onto) -> Vector3
	{
		return (onto * Dot(from, onto)) / Dot(onto, onto);
	}

	auto Vector3::Projection(const Vector3& onto) const -> Vector3
	{
		return Projection(*this, onto);
	}

	auto operator==(const Vector3& lhs, const Vector3& rhs) -> bool
	{
		return lhs.x_ == rhs.x_
			&& lhs.y_ == rhs.y_
			&& lhs.z_ == rhs.z_;
	}

	auto operator!=(const Vector3& lhs, const Vector3& rhs) -> bool
	{
		return !(lhs == rhs);
	}

	auto operator+(const Vector3& lhs, const Vector3& rhs) -> Vector3
	{
		return {
			lhs.x_ + rhs.x_,
			lhs.y_ + rhs.y_,
			lhs.z_ + rhs.z_
		};
	}

	auto operator-(const Vector3& lhs, const Vector3& rhs) -> Vector3
	{
		return {
			lhs.x_ - rhs.x_,
			lhs.y_ - rhs.y_,
			lhs.z_ - rhs.z_
		};
	}

	auto operator*(const Vector3& lhs, const Vector3& rhs) -> Vector3
	{
		return {
			lhs.x_ * rhs.x_,
			lhs.y_ * rhs.y_,
			lhs.z_ * rhs.z_
		};
	}

	auto operator*(const float lhs, const Vector3& rhs) -> Vector3
	{
		return Vector3{
			lhs * rhs.x_,
			lhs * rhs.y_,
			lhs * rhs.z_,
		};
	}

	auto operator*(const Vector3& lhs, const float rhs) -> Vector3
	{
		return rhs * lhs;
	}

	auto operator/(const Vector3& lhs, const Vector3& rhs) -> Vector3
	{
		return {
			lhs.x_ / rhs.x_,
			lhs.y_ / rhs.y_,
			lhs.z_ / rhs.z_
		};
	}

	auto operator/(const Vector3& lhs, const float rhs) -> Vector3
	{
		return {
			lhs.x_ / rhs,
			lhs.y_ / rhs,
			lhs.z_ / rhs
		};
	}

	auto operator/(const float lhs, const Vector3& rhs) -> Vector3
	{
		return rhs / lhs;
	}

	auto Vector3::operator+=(const Vector3& rhs) -> Vector3&

	{
		x_ += rhs.x_;
		y_ += rhs.y_;
		z_ += rhs.z_;
		return *this;
	}

	auto Vector3::operator-=(const Vector3& rhs) -> Vector3&

	{
		x_ -= rhs.x_;
		y_ -= rhs.y_;
		z_ -= rhs.z_;
		return *this;
	}

	auto Vector3::operator*=(const Vector3& rhs) -> Vector3&

	{
		x_ *= rhs.x_;
		y_ *= rhs.y_;
		z_ *= rhs.z_;
		return *this;
	}

	auto Vector3::operator/=(const Vector3& rhs) -> Vector3&

	{
		x_ /= rhs.x_;
		y_ /= rhs.y_;
		z_ /= rhs.z_;
		return *this;
	}

	auto Vector3::operator*=(const float rhs) -> Vector3&
	{
		x_ *= rhs;
		y_ *= rhs;
		z_ *= rhs;
		return *this;
	}

	auto Vector3::operator/=(const float rhs) -> Vector3&
	{
		x_ /= rhs;
		y_ /= rhs;
		z_ /= rhs;
		return *this;
	}
}

