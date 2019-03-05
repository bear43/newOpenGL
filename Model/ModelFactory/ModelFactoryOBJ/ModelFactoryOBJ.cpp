//
// Created by bear on 05.03.19.
//

#include "ModelFactoryOBJ.h"

ModelFactoryOBJ::ModelFactoryOBJ(bool autoFree) : loader(new objl::Loader()), autoFree(autoFree)
{
#ifdef DEBUG
    cout << "Constructor ModelFactory" << endl;
#endif
}

ModelFactoryOBJ::ModelFactoryOBJ() : ModelFactoryOBJ(true)
{}

ModelFactoryOBJ::~ModelFactoryOBJ()
{
    free();
#ifdef DEBUG
    cout << "Destructor ModelFactory" << endl;
#endif
}


Model ModelFactoryOBJ::createModel(const string &name, const string &path)
{
    loadModel(path);
    Model model(name, *loader);
    if(autoFree) free();
    return model;
}

Model ModelFactoryOBJ::createModel(const string &path)
{
    loadModel(path);
    Model model(*loader);
    if(autoFree) free();
    return model;
}

void ModelFactoryOBJ::free()
{
    delete loader;
    loader = nullptr;
}

objl::Loader &ModelFactoryOBJ::getLoader()
{
    return *loader;
}

void ModelFactoryOBJ::loadModel(const string &path)
{
    if(!loader->LoadFile(path)) throw runtime_error(fmt::format("Cannot load model file {0}", path));
}
