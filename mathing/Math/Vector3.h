#pragma once
namespace Math
{
	// TODO: Tech debt - Debug time asserts for division by zero needed
	class Vector3
	{
		friend auto operator==(const Vector3& lhs, const Vector3& rhs) -> bool;
		friend auto operator!=(const Vector3& lhs, const Vector3& rhs) -> bool;
		friend auto operator+(const Vector3& lhs, const Vector3& rhs)->Vector3;
		friend auto operator-(const Vector3& lhs, const Vector3& rhs)->Vector3;
		friend auto operator*(const Vector3& lhs, const Vector3& rhs)->Vector3;
		friend auto operator*(float lhs, const Vector3& rhs)->Vector3;
		friend auto operator*(const Vector3& lhs, float rhs)->Vector3;
		friend auto operator/(const Vector3& lhs, const Vector3& rhs)->Vector3;
		friend auto operator/(const Vector3& lhs, float rhs)->Vector3;

		
	public:
		Vector3(const float x, const float y, const float z)
			: x_{ x },
			y_{ y },
			z_{ z }
		{}

		Vector3() = default;

		auto X() const -> float { return x_; }
		auto Y() const -> float { return y_; }
		auto Z() const -> float { return z_; }
		auto SetX(const float x) -> void { x_ = x; }
		auto SetY(const float y) -> void { y_ = y; }
		auto SetZ(const float z) -> void { z_ = z; }

		static auto Zero()->Vector3 { return { 0.0f,0.0f,0.0f }; }
		static auto Distance(const Vector3& vector1, const Vector3& vector2) -> float;
		auto Distance(const Vector3& other) const -> float;
		auto Magnitude() const -> float;
		auto SquaredMagnitude() const -> float;
		auto Normalized() const->Vector3;
		static auto Dot(const Vector3& vector1, const Vector3& vector2) -> float;
		auto Dot(const Vector3& vector) const -> float;
		static auto Cross(const Vector3& vector1, const Vector3& vector2)->Vector3;
		auto Cross(const Vector3& vector) const->Vector3;
		static auto Projection(const Vector3& from, const Vector3& onto)->Vector3;
		auto Projection(const Vector3& onto) const->Vector3;

		auto operator+=(const Vector3& rhs)->Vector3&;
		auto operator-=(const Vector3& rhs)->Vector3&;
		auto operator*=(const Vector3& rhs)->Vector3&;
		auto operator/=(const Vector3& rhs)->Vector3&;
		auto operator*=(float rhs)->Vector3&;
		auto operator/=(float rhs)->Vector3&;

		Vector3(double, double, double) = delete;
		Vector3(int, int, int) = delete;

		auto SetX(double) -> void = delete;
		auto SetY(double) -> void = delete;
		auto SetZ(double) -> void = delete;
		auto SetX(int) -> void = delete;
		auto SetY(int) -> void = delete;
		auto SetZ(int) -> void = delete;

		auto operator*=(double)->Vector3& = delete;
		auto operator/=(double)->Vector3& = delete;
		auto operator*=(int)->Vector3& = delete;
		auto operator/=(int)->Vector3& = delete;
	private:
		float x_;
		float y_;
		float z_;
	};
}