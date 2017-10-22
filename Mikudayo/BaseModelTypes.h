#pragma once

#include <memory>
#include <vector>

typedef std::shared_ptr<struct BaseMaterial> MaterialPtr;
typedef std::shared_ptr<struct BaseMesh> MeshPtr;
typedef std::shared_ptr<class BaseModel> ModelPtr;

typedef std::vector<MaterialPtr> Materials;
typedef std::vector<MeshPtr> Meshes;

