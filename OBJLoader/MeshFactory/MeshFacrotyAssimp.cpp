//
// Created by bear on 05.03.19.
//

#include <assimp/scene.h>
#include "MeshFacrotyAssimp.h"

MeshFacrotyAssimp::MeshFacrotyAssimp()
{

}

MeshFacrotyAssimp::~MeshFacrotyAssimp()
{

}

objl::Mesh MeshFacrotyAssimp::createMesh(aiScene *scene, aiMesh *mesh)
{
    objl::Mesh m;
    vector<objl::Vertex> vertices;
    vector<unsigned int> indices;
    fillVNT(vertices, mesh);
    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        fillIndices(indices, &mesh->mFaces[i]);
    }
    m.Vertices = vertices;
    m.MeshName = mesh->mName.C_Str();
    return m;
}

void MeshFacrotyAssimp::fillVNT(vector<objl::Vertex> &vertices, aiMesh *mesh)
{
    vector<GLfloat> *pos, *normal, *tex;
    for(int i = 0; i < mesh->mNumVertices; i++)
    {
        pos = new vector<GLfloat>();
        normal = new vector<GLfloat>();
        tex = new vector<GLfloat>();
        pos->push_back(mesh->mVertices[i].x);
        pos->push_back(mesh->mVertices[i].y);
        pos->push_back(mesh->mVertices[i].z);
        normal->push_back(mesh->mNormals[i].x);
        normal->push_back(mesh->mNormals[i].y);
        normal->push_back(mesh->mNormals[i].z);
        tex->push_back(mesh->mTextureCoords[i]->x);
        tex->push_back(mesh->mTextureCoords[i]->y);
        vertices.emplace_back(*pos, *normal, *tex);
        delete tex;
        delete normal;
        delete pos;
    }
}

void MeshFacrotyAssimp::fillIndices(vector<unsigned int> &indices, aiFace *face)
{
        for(unsigned int j = 0; j < face->mNumIndices; j++)
            indices.push_back(face->mIndices[j]);
}

Model MeshFacrotyAssimp::createModel(aiScene *scene)
{
    unsigned int totalChildren = scene->mRootNode->mNumChildren;
    unsigned int totalMeshes;
    vector<Object3D*> meshes;
    for(unsigned int i = 0; i < totalChildren; i++)
    {
        totalMeshes = scene->mRootNode->mChildren[i]->mNumMeshes;
        for(unsigned int j = 0; j < totalMeshes; j++)
        {
            aiMesh *mesh = scene->mMeshes[scene->mRootNode->mChildren[i]->mMeshes[j]];
            objl::Mesh &&currentMesh = createMesh(scene, mesh);
            meshes.push_back(new Object3D(currentMesh.MeshName, currentMesh));
        }
    }
}
