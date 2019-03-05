//
// Created by bear on 05.03.19.
//

#ifndef UNTITLED2_MODELFACTORYASSIMP_H
#define UNTITLED2_MODELFACTORYASSIMP_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <string>
#include "../../Model.h"

using namespace std;


class ModelFactoryAssimp
{
    aiScene *scene = nullptr;
    bool autoFree;
    void loadScene(const string &path);
public:
    explicit ModelFactoryAssimp(bool autoFree);
    ModelFactoryAssimp();
    ~ModelFactoryAssimp();

    /**
     * Create model instance from file
     * @param name Model name for constructing
     * @param path Path to model file
     * @return Loaded model
     * @throws Exception if cannot load file
     */
    Model createModel(const string &name, const string &path);
    /**
     * Create model instance from file
     * @param path Path to model file
     * @return Loaded model
     * @throws Exception if cannot load file
     */
    Model createModel(const string &path);
    void free();
};


#endif //UNTITLED2_MODELFACTORYASSIMP_H
