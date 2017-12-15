//
//  StaticShader.hpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#ifndef StaticShader_hpp
#define StaticShader_hpp

#include "ShaderProgram.hpp"
#include <stdio.h>

class StaticShader : public ShaderProgram{
private:
    const char *VERTEX_FILE;
    const char *FRAGMENT_FILE;
public:
    StaticShader();
protected:
    void bindAttributes(void);
};

#endif /* StaticShader_hpp */
