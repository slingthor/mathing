#pragma once
#include <string>

namespace AssetImporting
{
	class Mesh;

	class MeshImporter
	{
	public:
		MeshImporter();
		virtual ~MeshImporter() = 0;
		virtual auto Import(std::string filePath)->Mesh = 0;
	};
}