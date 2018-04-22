#pragma once
#include <utility>
#include <vector>
#include "../../Math/Vector2.h"
#include "../../Math/Vector3.h"
//TODO implement calculate normals
namespace AssetImporting
{
	class Mesh
	{
	public:
		auto Vertices() -> std::vector<Math::Vector3>& { return vertices_; }
		auto SetVertices(std::vector<Math::Vector3> vertices) -> void { vertices_ = std::move(vertices); }
		auto Normals() -> std::vector<Math::Vector3>& { return normals_; }
		auto SetNormals(std::vector<Math::Vector3> vector3s) -> void { normals_ = std::move(vector3s); }
		auto TextureCoordinates() -> std::vector<Math::Vector2>& { return textureCoordinates_; }
		auto SetTextureCoordinates(std::vector<Math::Vector2> texture_coordinates) -> void { textureCoordinates_ = std::move(texture_coordinates); }
	private:
		std::vector<Math::Vector3> vertices_;
		std::vector<Math::Vector3> normals_;
		std::vector<Math::Vector2> textureCoordinates_;
	public:
		Mesh()
			: vertices_{ std::vector<Math::Vector3>(0) },
			normals_{ std::vector<Math::Vector3>(0) },
			textureCoordinates_{ std::vector<Math::Vector2>(0) }
		{}
		Mesh(std::vector<Math::Vector3> vertices, std::vector<Math::Vector3> normals, std::vector<Math::Vector2> textureCoordinates)
			: vertices_{ std::move(vertices) },
			normals_{ std::move(normals) },
			textureCoordinates_{ std::move(textureCoordinates) }
		{}
	};
}