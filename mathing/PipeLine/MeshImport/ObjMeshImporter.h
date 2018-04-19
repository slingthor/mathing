#pragma once
#include "../../Geometry/Mesh/Mesh.h"
#include "MeshImporter.h"
#include <unordered_map>
#include <memory>

namespace AssetImporting
{
	class ObjMeshImporter :
		public MeshImporter
	{
	public:
		ObjMeshImporter();
		enum LineType
		{
			Vertex,
			Normal,
			TextureCoordinate,
			Other
		};
		auto Import(std::string filePath) -> std::shared_ptr<Mesh> override;
	private:
		std::unordered_map<std::string, LineType> stringToLineTypeMap{};
		auto StringToLineType(const std::string& str)->LineType;

		template<typename Out>
		auto Split(const std::string &s, char delim, Out result) -> void;
		auto Split(const std::string &s, char delim)->std::vector<std::string>;
	};
}


