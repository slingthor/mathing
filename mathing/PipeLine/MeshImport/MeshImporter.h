#pragma once
#include <string>
#include <memory>

namespace AssetImporting
{
	class Mesh;

	class MeshImporter
	{
	public:
		MeshImporter();
		virtual ~MeshImporter() = 0;
		virtual auto Import(std::string filePath)->std::shared_ptr<Mesh> = 0;
	};
}
