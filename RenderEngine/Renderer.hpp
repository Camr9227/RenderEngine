//
//  Renderer.hpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <stdio.h>
#include "RawModel.hpp"

class Renderer{
public:
    void prepare();
    void render(RawModel* model);
};

#endif /* Renderer_hpp */
