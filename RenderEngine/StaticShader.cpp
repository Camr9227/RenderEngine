//
//  StaticShader.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include "StaticShader.hpp"

StaticShader::StaticShader() : ShaderProgram(VERTEX_FILE="/Users/cameronralph/Projects/RenderEngine/RenderEngine/vertexShader.txt",FRAGMENT_FILE="/Users/cameronralph/Projects/RenderEngine/RenderEngine/fragmentShader.txt"){}

void StaticShader::bindAttributes(){
    bindAttribute(0, "position");
}
