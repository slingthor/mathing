#include "pch.h"
#include "general.h"
#include "Vector4.h"


namespace Math
{
	auto Vector4::Distance(const Vector4& vector1, const Vector4& vector2) -> float
	{
		return Sqrt(
			Pow(vector2.x_ - vector1.x_, 2.0f) +
			Pow(vector2.y_ - vector1.y_, 2.0f) +
			Pow(vector2.z_ - vector1.z_, 2.0f) +
			Pow(vector2.w_ - vector1.w_, 2.0f)
		);
	}

	auto Vector4::Distance(const Vector4& other) const -> float
	{
		return Distance(*this, other);
	}

	auto Vector4::Magnitude() const -> float
	{
		return Sqrt(
			Pow(X(), 2.0f) +
			Pow(Y(), 2.0f) +
			Pow(Z(), 2.0f) +
			Pow(W(), 2.0f)
		);
	}

	auto Vector4::SquaredMagnitude() const -> float
	{
		return Pow(X(), 2.0f) +
			Pow(Y(), 2.0f) +
			Pow(Z(), 2.0f) +
			Pow(W(), 2.0f);
	}

	auto Vector4::Normalized() const -> Vector4
	{
		const auto length = Magnitude();
		return Vector4{
			x_ / length,
			y_ / length,
			z_ / length,
			w_ / length
		};
	}

	auto Vector4::Dot(const Vector4& vector1, const Vector4& vector2) -> float
	{
		return vector1.X() * vector2.X() +
			vector1.Y() * vector2.Y() +
			vector1.Z() * vector2.Z() +
			vector1.W() * vector2.W();
	}

	auto Vector4::Dot(const Vector4& vector) const -> float
	{
		return Dot(*this, vector);
	}

	auto Vector4::Cross(const Vector4& vector1, const Vector4& vector2) -> Vector4
	{
		auto x = vector1.Y() * vector2.Z() - vector1.Z() * vector2.Y();
		auto y = vector2.X() * vector1.Z() - vector1.X() * vector2.Z();
		auto z = vector1.X() * vector2.Y() - vector2.X() * vector1.Y();
		return { x,y,z,0.0f };
	}
	auto Vector4::Cross(const Vector4& vector) const -> Vector4
	{
		return Cross(*this, vector);
	}

	auto Vector4::Projection(const Vector4& from, const Vector4& onto) -> Vector4
	{
		return (onto * Dot(from, onto)) / Dot(onto, onto);
	}

	auto Vector4::Projection(const Vector4& onto) const -> Vector4
	{
		return Projection(*this, onto);
	}


	auto operator==(const Vector4& lhs, const Vector4& rhs) -> bool
	{
		return lhs.x_ == rhs.x_
			&& lhs.y_ == rhs.y_
			&& lhs.z_ == rhs.z_
			&& lhs.w_ == rhs.w_;
	}

	auto operator!=(const Vector4& lhs, const Vector4& rhs) -> bool
	{
		return !(lhs == rhs);
	}

	auto operator+(const Vector4& lhs, const Vector4& rhs) -> Vector4
	{
		return Vector4{
			lhs.x_ + rhs.x_,
			lhs.y_ + rhs.y_,
			lhs.z_ + rhs.z_,
			lhs.w_ + rhs.w_
		};
	}

	auto operator-(const Vector4& lhs, const Vector4& rhs) -> Vector4
	{
		return Vector4{
			lhs.x_ - rhs.x_,
			lhs.y_ - rhs.y_,
			lhs.z_ - rhs.z_,
			lhs.w_ - rhs.w_
		};
	}

	auto operator*(const Vector4& lhs, const Vector4& rhs) -> Vector4
	{
		return Vector4{
			lhs.x_ * rhs.x_,
			lhs.y_ * rhs.y_,
			lhs.z_ * rhs.z_,
			lhs.w_ * rhs.w_
		};
	}

	auto operator*(const float lhs, const Vector4& rhs) -> Vector4
	{
		return Vector4{
			lhs * rhs.x_,
			lhs * rhs.y_,
			lhs * rhs.z_,
			lhs * rhs.w_
		};
	}

	auto operator*(const Vector4& lhs, const float rhs) -> Vector4
	{
		return rhs * lhs;
	}

	auto operator/(const Vector4& lhs, const Vector4& rhs) -> Vector4
	{
		return Vector4{
			lhs.x_ / rhs.x_,
			lhs.y_ / rhs.y_,
			lhs.z_ / rhs.z_,
			lhs.w_ / rhs.w_
		};
	}

	auto operator/(const Vector4& lhs, const float rhs) -> Vector4
	{
		return Vector4{
			lhs.x_ / rhs,
			lhs.y_ / rhs,
			lhs.z_ / rhs,
			lhs.w_ / rhs
		};
	}

	auto operator/(const float lhs, const Vector4& rhs) -> Vector4
	{
		return rhs / lhs;
	}

	auto Vector4::operator+=(const Vector4& rhs) -> Vector4&

	{
		x_ += rhs.x_;
		y_ += rhs.y_;
		z_ += rhs.z_;
		w_ += rhs.w_;
		return *this;
	}

	auto Vector4::operator-=(const Vector4& rhs) -> Vector4&

	{
		x_ -= rhs.x_;
		y_ -= rhs.y_;
		z_ -= rhs.z_;
		w_ -= rhs.w_;
		return *this;
	}

	auto Vector4::operator*=(const Vector4& rhs) -> Vector4&

	{
		x_ *= rhs.x_;
		y_ *= rhs.y_;
		z_ *= rhs.z_;
		w_ *= rhs.w_;
		return *this;
	}

	auto Vector4::operator/=(const Vector4& rhs) -> Vector4&

	{
		x_ /= rhs.x_;
		y_ /= rhs.y_;
		z_ /= rhs.z_;
		w_ /= rhs.w_;
		return *this;
	}

	auto Vector4::operator*=(const float rhs) -> Vector4&
	{
		x_ *= rhs;
		y_ *= rhs;
		z_ *= rhs;
		w_ *= rhs;
		return *this;
	}

	auto Vector4::operator/=(const float rhs) -> Vector4&
	{
		x_ /= rhs;
		y_ /= rhs;
		z_ /= rhs;
		w_ /= rhs;
		return *this;
	}
}
