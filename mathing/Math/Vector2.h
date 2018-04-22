#pragma once
namespace Math
{
	class Vector2
	{
	public:
		Vector2(const float x, const float y)
			: x_{ x },
			y_{ y }
		{}

		Vector2() = default;

		auto X() const -> float { return x_; }
		auto Y() const -> float { return y_; }
		auto SetX(const float x) -> void { x_ = x; }
		auto SetY(const float y) -> void { y_ = y; }

		Vector2(double, double) = delete;
		Vector2(int, int) = delete;

		auto SetX(double) -> void = delete;
		auto SetY(double) -> void = delete;
		auto SetX(int) -> void = delete;
		auto SetY(int) -> void = delete;

	private:
		float x_;
		float y_;
	};
}
