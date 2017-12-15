//
//  ShaderProgram.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include "glew.h"
#include "glfw3.h"
#include "ShaderProgram.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

ShaderProgram::ShaderProgram(const char *vertexFile, const char *fragmentFile){
    vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
    programID =  glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);
    glValidateProgram(programID);
}

void ShaderProgram::start(){
    glUseProgram(programID);
}

void ShaderProgram::stop(){
    glUseProgram(0);
}

void ShaderProgram::cleanUp(){
    stop();
    glDetachShader(programID, vertexShaderID);
    glDetachShader(programID, fragmentShaderID);
    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
    glDeleteProgram(programID);
}

void ShaderProgram::bindAttribute(int attribute, const GLchar *variableName){
    glBindAttribLocation(programID, attribute, variableName);
}

std::string ShaderProgram::readFile(const char *filePath){
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);
    
    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }
    
    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }
    
    fileStream.close();
    return content;
}

int ShaderProgram::loadShader(const char *file, GLuint type){
    GLuint shaderID = glCreateShader(type);
    
    // Read shaders
    std::string shaderStr = readFile(file);
    const char *shaderSrc = shaderStr.c_str();
    
    GLint result = GL_FALSE;
    int logLength;
    
    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(shaderID, 1, &shaderSrc, NULL);
    glCompileShader(shaderID);
    
    // Check vertex shader
    /**glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
    glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
    std::vector vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(shaderID, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;**/
    
    return shaderID;
}
