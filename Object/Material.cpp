//
// Created by bear on 03.03.19.
//

#include "Material.h"

Material::Material(const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular) :
                  ambient(ambient),
                  diffuse(diffuse),
                  specular(specular)
{}

Material::Material() : Material(DEFAULT_AMBIENT, DEFAULT_DIFFUSE, DEFAULT_SPECULAR)
{}

const glm::vec3 &Material::getAmbient() const
{
    return ambient;
}

void Material::setAmbient(const glm::vec3 &ambient)
{
    Material::ambient = ambient;
}

const glm::vec3 &Material::getDiffuse() const
{
    return diffuse;
}

void Material::setDiffuse(const glm::vec3 &diffuse)
{
    Material::diffuse = diffuse;
}

const glm::vec3 &Material::getSpecular() const
{
    return specular;
}

void Material::setSpecular(const glm::vec3 &specular)
{
    Material::specular = specular;
}

void Material::draw(Shader &shader)
{
    shader.setMaterial(*this);
}

Material &Material::operator=(const objl::Mesh &mesh)
{
    ambient = vec3(mesh.MeshMaterial.Ka.X, mesh.MeshMaterial.Ka.Y, mesh.MeshMaterial.Ka.Z);
    diffuse = vec3(mesh.MeshMaterial.Kd.X, mesh.MeshMaterial.Kd.Y, mesh.MeshMaterial.Kd.Z);
    specular = vec3(mesh.MeshMaterial.Ks.X, mesh.MeshMaterial.Ks.Y, mesh.MeshMaterial.Ks.Z);
    return *this;
}

Material &Material::operator=(const Material &material)
{
    ambient = material.ambient;
    diffuse = material.diffuse;
    specular = material.specular;
    return *this;
}

const Material &Material::getDEFAULT_MATERIAL()
{
    return DEFAULT_MATERIAL;
}

bool Material::isEmpty()
{
    return ambient.x == ambient.y == ambient.z == 0 &&
           diffuse.x == diffuse.x == diffuse.z == 0 &&
           specular.x == specular.y == specular.z == 0;
}

const Material Material::DEFAULT_MATERIAL = Material();
