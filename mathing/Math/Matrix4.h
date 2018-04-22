#pragma once

namespace Math
{
	class Vector4;
	class Matrix4
	{
		friend auto operator *(const Matrix4& lhs, const Matrix4& rhs) -> Matrix4;
		friend auto operator *(const Vector4& lhs, const Matrix4& rhs) -> Vector4;
	public:
		explicit Matrix4(float n00, float n10, float n20, float n30,
		                   float n01, float n11, float n21, float n31,
		                   float n02, float n12, float n22, float n32,
		                   float n03, float n13, float n23, float n33) noexcept;

		explicit Matrix4(const float matrix[4][4]) noexcept;
		auto Row(SIZE_T index) const -> Vector4;
		auto Column(SIZE_T index) const -> Vector4;
		auto Determinant() const noexcept -> float;
		auto Inverse() const noexcept -> Matrix4;
		auto operator ()(SIZE_T x, SIZE_T y) -> float&;
		auto operator ()(SIZE_T x, SIZE_T y) const -> const float&;
	private:
		float matrix[4][4];
	};
}
