//
//  Loader.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 14/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include "Loader.hpp"

RawModel* Loader::loadToVao(std::vector<float> positions, std::vector<int> indices){
    GLuint vaoID = createVAO();
    vaos.push_back(vaoID);
    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, positions);
    unbindVAO();
    return new RawModel(vaoID,indices.size());
}

void Loader::cleanUp(){
    for (GLuint vao: vaos) {
        glDeleteVertexArrays(1, &vao);
    }
    for(GLuint vbo: vbos){
        glDeleteBuffers(1, &vbo);
    }
}

GLuint Loader::createVAO(){
    GLuint vaoID;
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    return vaoID;
}

void Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> data){
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(GL_FLOAT), data.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, GL_FLOAT, false, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Loader::bindIndicesBuffer(std::vector<int> data){
    GLuint vboID;
    glGenBuffers(1, &vboID);
    vbos.push_back(vboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(GL_INT), data.data(), GL_STATIC_DRAW);
}

void Loader::unbindVAO(){
    glBindVertexArray(0);
}
