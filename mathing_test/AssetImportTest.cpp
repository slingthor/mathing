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
	EXPECT_TRUE(Math::abs(vertex1.X() - 1.11) < 0.2);
	auto lastVertex = mesh->Vertices()[6737];
	EXPECT_TRUE(Math::abs(lastVertex.X() - 6.07) < 0.2);
	auto lastNormal = mesh->Normals()[6737];
	EXPECT_TRUE(Math::abs(lastNormal.X() - 0.35 < 0.2));
	auto lastTextureCoordinate = mesh->TextureCoordinates()[8091];
	EXPECT_TRUE(Math::abs(lastTextureCoordinate.X() - 0.003) < 0.01);	
}