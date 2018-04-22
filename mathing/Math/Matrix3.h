#pragma once
namespace math
{
	class Vector3;
	class Matrix3
	{
		friend auto operator *(const Matrix3& lhs, const Matrix3& rhs)->Matrix3;
		friend auto operator *(const Vector3& lhs, const Matrix3& rhs)->Vector3;
	public:
		explicit Matrix3(
			const float n00, const float n10, const float n20,
			const float n01, const float n11, const float n21,
			const float n02, const float n12, const float n22) noexcept {
			matrix[0][0] = n00; matrix[1][0] = n10; matrix[2][0] = n20;
			matrix[0][1] = n01; matrix[1][1] = n11; matrix[2][1] = n21;
			matrix[0][2] = n02; matrix[1][2] = n12; matrix[2][2] = n22;
		}

		explicit Matrix3(const float matrix[4][4]) noexcept
		{
			for (auto x = 0; x < 3; ++x)
			{
				for (auto y = 0; y < 3; ++y)
				{
					this->matrix[x][y] = matrix[x][y];
				}
			}
		};
		auto Row(SIZE_T index) const->Vector3;
		auto Column(SIZE_T index) const->Vector3;
		auto Determinant() const noexcept -> float;
		auto Inverse() const noexcept ->Matrix3;
		auto operator ()(SIZE_T x, SIZE_T y) -> float&;
		auto operator ()(SIZE_T x, SIZE_T y) const -> const float&;

	private:
		float matrix[3][3];
	};
}