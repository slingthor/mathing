#include "pch.h"
#include "ObjMeshImporter.h"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <sstream>

namespace AssetImporting
{
	using namespace std::experimental;
	using namespace Math;

	ObjMeshImporter::ObjMeshImporter()
	{
		stringToLineTypeMap["v"] = Vertex;
		stringToLineTypeMap["vn"] = Normal;
		stringToLineTypeMap["vt"] = TextureCoordinate;
	}
	

	auto ObjMeshImporter::StringToLineType(const std::string& str) -> LineType
	{
		//if map contains prefix
		if(stringToLineTypeMap.find(str) != stringToLineTypeMap.end())
		{
			return stringToLineTypeMap[str];
		}
		return Other;
	}


	//todo tech debt: move this to another class
	template<typename Out>
	auto ObjMeshImporter::Split(const std::string &s, char delim, Out result) -> void {
		std::stringstream ss(s);
		std::string item;
		while (std::getline(ss, item, delim)) {
			*(result++) = item;
		}
	}

	auto ObjMeshImporter::Split(const std::string &s, char delim) -> std::vector<std::string> {
		std::vector<std::string> elems;
		Split(s, delim, std::back_inserter(elems));
		return elems;
	}

	auto ObjMeshImporter::Import(std::string filePath) -> std::shared_ptr<Mesh>
	{
		//todo turn this into an assertion
		if (!filesystem::exists(filePath))
		{
			throw std::invalid_argument("filePath " + filePath + " does not exist when importing .obj file in ObjMeshImporter");
		}

		std::ifstream inFile { filePath };
		if(!inFile.is_open())
		{
			throw std::runtime_error("Unable to open file at path " + filePath + "when importing .obj file in ObjMeshImporter");
		}
		std::string line;

		auto mesh = std::make_shared<Mesh>();
		try
		{
			while (std::getline(inFile, line))
			{
				auto elems = Split(line, ' ');
				const auto size = elems.size();
				if (size > 0)
				{
					const auto firstWord = elems[0];
					switch (StringToLineType(firstWord))
					{
					case Vertex:
						const auto vertex = Vector3{ std::stof(elems[2]), std::stof(elems[3]), std::stof(elems[4]) };
						mesh->Vertices().push_back(vertex);
						break;
					case Normal:
						const auto normal = Vector3{ std::stof(elems[2]), std::stof(elems[3]), std::stof(elems[4]) };
						mesh->Normals().push_back(normal);
						break;
					case TextureCoordinate:
						const auto coordinate = Vector2{ std::stof(elems[2]), std::stof(elems[3]) };
						mesh->TextureCoordinates().push_back(coordinate);
						break;
					case Other: break;
					default:;
					}
				}
			}

		}
		catch(std::exception ex)
		{
			std::cout << ex.what();
		}
		return mesh;
	}
}
