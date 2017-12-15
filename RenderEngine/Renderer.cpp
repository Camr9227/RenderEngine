//
//  Renderer.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 15/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include "glew.h"
#include "glfw3.h"
#include "Renderer.hpp"

void Renderer::prepare(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 0, 0, 1);
}

void Renderer::render(RawModel* model){
    glBindVertexArray(model->getVaoID());
    glEnableVertexAttribArray(0);
    glDrawElements(GL_TRIANGLES, model->getVertexCount(), GL_UNSIGNED_INT, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
}
