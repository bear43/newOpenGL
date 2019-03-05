//
// Created by bear on 05.03.19.
//

#ifndef UNTITLED2_MODELFACTORY_H
#define UNTITLED2_MODELFACTORY_H

#include <string>
#include <vector>
#include "../../Model.h"
#include "../../../OBJLoader/OBJ_Loader.h"
#include <fmt/format.h>
#define DEBUG

using namespace std;


class ModelFactoryOBJ
{
private:
    objl::Loader *loader;
    bool autoFree;
    void loadModel(const string& path);
public:
    explicit ModelFactoryOBJ(bool autoFree);
    ModelFactoryOBJ();
    ~ModelFactoryOBJ();
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
    /**
     *
     * @return OBJLoader pointer
     */
    objl::Loader &getLoader();

    void free();
};


#endif //UNTITLED2_MODELFACTORY_H
