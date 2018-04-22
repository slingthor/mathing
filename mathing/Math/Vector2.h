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
	private:
		float x_;
		float y_;
	};
}
