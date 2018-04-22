#include "pch.h"
#include "../mathing/Geometry/Mesh/Mesh.h"
#include "../mathing/Math/Vector3.h"
#include "../mathing/PipeLine/MeshImport/ObjMeshImporter.h"
#include "../mathing/Math/general.h"


TEST(ObjMeshImport, runs)
{
	auto file = "apple.obj";
	auto importer = AssetImporting::ObjMeshImporter();
	const auto mesh = importer.Import(file);
	auto vertex1 = mesh->Vertices()[0];
	EXPECT_TRUE(Math::Abs(vertex1.X() - 1.11f) < 0.2f);
	auto lastVertex = mesh->Vertices()[6737];
	EXPECT_TRUE(Math::Abs(lastVertex.X() - 6.07f) < 0.2f);
	auto lastNormal = mesh->Normals()[6737];
	EXPECT_TRUE(Math::Abs(lastNormal.X() - 0.35f) < 0.2f);
	auto lastTextureCoordinate = mesh->TextureCoordinates()[8091];
	EXPECT_TRUE(Math::Abs(lastTextureCoordinate.X() - 0.003f) < 0.1f);	
}