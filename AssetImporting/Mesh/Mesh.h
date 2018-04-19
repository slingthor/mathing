#pragma once
#include <utility>
#include <vector>
//TODO implement calculate normals
namespace AssetImporting
{
	class Vector3;
	class Vector2;
	class Mesh
	{
	public:
		auto Vertices() const -> std::vector<Vector3> { return vertices_; }
		auto SetVertices(std::vector<Vector3> vertices) -> void { vertices_ = std::move(vertices); }
		auto Normals() const -> std::vector<Vector3> { return normals_; }
		auto SetNormals(std::vector<Vector3> vector3s) -> void { normals_ = std::move(vector3s); }
		auto TextureCoordinates() const -> std::vector<Vector2> { return textureCoordinates_; }
		auto SetTextureCoordinates(std::vector<Vector2> texture_coordinates) -> void { textureCoordinates_ = std::move(texture_coordinates); }
	private:
		std::vector<Vector3> vertices_;
		std::vector<Vector3> normals_;
		std::vector<Vector2> textureCoordinates_;
	public:
		Mesh(std::vector<Vector3> vertices)
			: vertices_{std::move(vertices)},
			normals_{ std::vector<Vector3>(0) },
			textureCoordinates_{ std::vector<Vector2>(0) }
		{}
	};
}