//
//  Loader.hpp
//  RenderEngine
//
//  Created by Cameron Ralph on 14/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#ifndef Loader_hpp
#define Loader_hpp

#include "glew.h"
#include "glfw3.h"
#include <stdio.h>
#include "RawModel.hpp"
#include <vector>

class Loader{
public:
    RawModel* loadToVao(std::vector<float> positions, std::vector<int> indices);
    void cleanUp();
private:
    std::vector<GLuint> vaos;
    std::vector<GLuint> vbos;
    GLuint createVAO();
    void storeDataInAttributeList(int attributeNumber, std::vector<float> data);
    void bindIndicesBuffer(std::vector<int> data);
    void unbindVAO();
};

#endif /* Loader_hpp */
