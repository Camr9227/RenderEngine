//
//  ShaderProgram.hpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp

#include "glew.h"
#include "glfw3.h"
#include <stdio.h>
#include <string>

class ShaderProgram{
public:
    ShaderProgram(const char *vertexFile, const char *fragmentFile);
    void start();
    void stop();
    void cleanUp();
protected:
    virtual void bindAttributes() = 0;
    void bindAttribute(int attribute, const GLchar *variableName);
private:
    int programID;
    int vertexShaderID;
    int fragmentShaderID;
    static int loadShader(const char *file, GLuint type);
    static std::string readFile(const char *filePath);
};

#endif /* ShaderProgram_hpp */
