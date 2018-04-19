#pragma once
#include <utility>
#include <vector>
#include "Math/Vector2.h"
#include "Math/Vector3.h"
//TODO implement calculate normals
namespace AssetImporting
{
	class Mesh
	{
	public:
		auto Vertices() const -> std::vector<math::Vector3> { return vertices_; }
		auto SetVertices(std::vector<math::Vector3> vertices) -> void { vertices_ = std::move(vertices); }
		auto Normals() const -> std::vector<math::Vector3> { return normals_; }
		auto SetNormals(std::vector<math::Vector3> vector3s) -> void { normals_ = std::move(vector3s); }
		auto TextureCoordinates() const -> std::vector<math::Vector2> { return textureCoordinates_; }
		auto SetTextureCoordinates(std::vector<math::Vector2> texture_coordinates) -> void { textureCoordinates_ = std::move(texture_coordinates); }
	private:
		std::vector<math::Vector3> vertices_;
		std::vector<math::Vector3> normals_;
		std::vector<math::Vector2> textureCoordinates_;
	public:
		Mesh(std::vector<math::Vector3> vertices)
			: vertices_{std::move(vertices)},
			normals_{ std::vector<math::Vector3>(0) },
			textureCoordinates_{ std::vector<math::Vector2>(0) }
		{}
	};
}