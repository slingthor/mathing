#pragma once
#include "Geometry/Mesh/Mesh.h"
#include "MeshImporter.h"
#include <unordered_map>

namespace AssetImporting
{
	class ObjMeshImporter :
		public MeshImporter
	{
	public:
		ObjMeshImporter();
		~ObjMeshImporter() override;
		enum LineType
		{
			Vertex,
			Normal,
			TextureCoordinate,
			Other
		};
		auto Import(std::string filePath) -> Mesh override;
	private:
		std::unordered_map<std::string, LineType> stringToLineTypeMap{};
		auto StringToLineType(const std::string& str)->ObjMeshImporter::LineType;

		template<typename Out>
		auto Split(const std::string &s, char delim, Out result) -> void;
		auto ObjMeshImporter::Split(const std::string &s, char delim)->std::vector<std::string>;
	};
}


