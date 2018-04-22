#pragma once

namespace Math
{
	class Vector3;
	class Vector4;
	class Matrix3;
	class Matrix4;
	class Quaternion
	{
		friend auto operator+(const Quaternion& lhs, const Quaternion& rhs) -> Quaternion;
		friend auto operator-(const Quaternion& lhs, const Quaternion& rhs) -> Quaternion;
		friend auto operator*(const Quaternion& lhs, const Quaternion& rhs)->Quaternion;

	public:
		Quaternion(const float x, const float y, const float z, const float w)
			: x_{ x },
			y_{ y },
			z_{ z },
			w_{ w }
		{}
		Quaternion(const Vector3& axis, float angle);
		Quaternion(const Vector4& xyzw);
		Quaternion(const Vector3& eulerAngles);
		Quaternion(const Matrix3& matrix);
		Quaternion(const Matrix4& matrix);
		Quaternion() = default;

		auto X() const -> float { return x_; }
		auto Y() const -> float { return y_; }
		auto Z() const -> float { return z_; }
		auto W() const -> float { return w_; }
		auto SetX(const float x) -> void { x_ = x; }
		auto SetY(const float y) -> void { y_ = y; }
		auto SetZ(const float z) -> void { z_ = z; }
		auto SetW(const float w) -> void { w_ = w; }

		auto ToMatrix3() const ->Matrix3;
		auto ToMatrix4() const ->Matrix4;

		auto Magnitude() const -> float;
		auto Normalized() const->Quaternion;
		auto Normalize() -> void;


		Quaternion(double, double, double, double) = delete;
		Quaternion(int, int, int, int) = delete;
		Quaternion(Vector3&, double) = delete;
		Quaternion(Vector3&, int) = delete;

		auto SetX(double) -> void = delete;
		auto SetY(double) -> void = delete;
		auto SetZ(double) -> void = delete;
		auto SetW(double) -> void = delete;
		auto SetX(int) -> void = delete;
		auto SetY(int) -> void = delete;
		auto SetZ(int) -> void = delete;
		auto SetW(int) -> void = delete;

	private:
		float x_;
		float y_;
		float z_;
		float w_;
	};
}



