#pragma once
#include "Vector3.h"

namespace Math
{
	class Vector4
	{
		friend auto operator==(const Vector4& lhs, const Vector4& rhs) -> bool;
		friend auto operator!=(const Vector4& lhs, const Vector4& rhs) -> bool;
		friend auto operator+(const Vector4& lhs, const Vector4& rhs) -> Vector4;
		friend auto operator-(const Vector4& lhs, const Vector4& rhs) -> Vector4;
		friend auto operator*(const Vector4& lhs, const Vector4& rhs) -> Vector4;
		friend auto operator*(float lhs, const Vector4& rhs) -> Vector4;
		friend auto operator*(const Vector4& lhs, float rhs) -> Vector4;
		friend auto operator/(const Vector4& lhs, const Vector4& rhs) -> Vector4;
		friend auto operator/(const Vector4& lhs, float rhs) -> Vector4;
		friend auto operator/(float lhs, const Vector4& rhs) -> Vector4;

	public:
		Vector4(const float x, const float y, const float z, const float w)
			: x_{x},
			  y_{y},
			  z_{z},
			  w_{w}
		{}

		Vector4() = default;

		auto X() const -> float { return x_; }
		auto Y() const -> float { return y_; }
		auto Z() const -> float { return z_; }
		auto W() const -> float { return w_; }
		auto SetX(const float x) -> void { x_ = x; }
		auto SetY(const float y) -> void { y_ = y; }
		auto SetZ(const float z) -> void { z_ = z; }
		auto SetW(const float w) -> void { w_ = w; }

		auto ToVector3() const -> Vector3 { return { x_, y_, z_ }; }

		static auto Zero()->Vector4 { return { 0.0f,0.0f,0.0f,0.0f }; }
		static auto Distance(const Vector4& vector1, const Vector4& vector2) -> float;
		auto Distance(const Vector4& other) const -> float;
		auto Magnitude() const -> float;
		auto SquaredMagnitude() const -> float;
		auto Normalized() const -> Vector4;
		static auto Dot(const Vector4& vector1, const Vector4& vector2) -> float;
		auto Dot(const Vector4& vector) const -> float;
		static auto Cross(const Vector4& vector1, const Vector4& vector2) -> Vector4;
		auto Cross(const Vector4& vector) const -> Vector4;
		static auto Projection(const Vector4& from, const Vector4& onto) -> Vector4;
		auto Projection(const Vector4& onto) const->Vector4;

		auto operator+=(const Vector4& rhs)->Vector4&;
		auto operator-=(const Vector4& rhs)->Vector4&;
		auto operator*=(const Vector4& rhs)->Vector4&;
		auto operator/=(const Vector4& rhs)->Vector4&;
		auto operator*=(float rhs)->Vector4&;
		auto operator/=(float rhs)->Vector4&;

		Vector4(double, double, double, double) = delete;
		Vector4(int, int, int, int) = delete;

		auto SetX(double) -> void = delete;
		auto SetY(double) -> void = delete;
		auto SetZ(double) -> void = delete;
		auto SetW(double) -> void = delete;
		auto SetX(int) -> void = delete;
		auto SetY(int) -> void = delete;
		auto SetZ(int) -> void = delete;
		auto SetW(int) -> void = delete;

		auto operator*=(double)->Vector4& = delete;
		auto operator/=(double)->Vector4& = delete;
		auto operator*=(int)->Vector4& = delete;
		auto operator/=(int)->Vector4& = delete;

	private:
		float x_;
		float y_;
		float z_;
		float w_;
	};
}
