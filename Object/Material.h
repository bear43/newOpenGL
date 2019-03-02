//
// Created by bear on 03.03.19.
//

#ifndef UNTITLED2_MATERIAL_H
#define UNTITLED2_MATERIAL_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../OBJLoader/OBJ_Loader.h"
#include "../OpenGL/Shader/Shader.h"

class Material
{
private:
    static constexpr glm::vec3 DEFAULT_AMBIENT = { 1.0f, 1.0f, 1.0f };
    static constexpr glm::vec3 DEFAULT_DIFFUSE = { 1.0f, 1.0f, 1.0f };
    static constexpr glm::vec3 DEFAULT_SPECULAR = { 1.0f, 1.0f, 1.0f };
    static const Material DEFAULT_MATERIAL;
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
public:
    Material(const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular);
    Material();

    Material& operator=(const objl::Mesh &mesh);

    Material& operator=(const Material &material);

    const glm::vec3 &getAmbient() const;

    void setAmbient(const glm::vec3 &ambient);

    const glm::vec3 &getDiffuse() const;

    void setDiffuse(const glm::vec3 &diffuse);

    const glm::vec3 &getSpecular() const;

    void setSpecular(const glm::vec3 &specular);

    void draw(Shader &shader);

    static const Material &getDEFAULT_MATERIAL();

    bool isEmpty();
};


#endif //UNTITLED2_MATERIAL_H
