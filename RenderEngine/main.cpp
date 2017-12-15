//
//  main.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 14/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include <iostream>
#define GLEW_STATIC
#include "glew.h"

#include "glfw3.h"

#include "Loader.hpp"
#include "Renderer.hpp"
#include "RawModel.hpp"
#include "StaticShader.hpp"

#include <vector>

int main(int argc, const char * argv[]) {
    
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(1280,  720, "Display", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    glewInit();
    
    Loader loader;
    Renderer renderer;
    StaticShader shader;
    
    float pos[] = {
        -0.5f, 0.5f, 0,
        -0.5f, -0.5f, 0,
        0.5f, -0.5f, 0,
        0.5f, 0.5f, 0,
    };
    
    int ind[] = {
        0,1,3,
        3,1,2
    };
    
    std::vector<float> positions (pos, pos + sizeof(pos) / sizeof(float));
    std::vector<int> indices (ind, ind + sizeof(ind) / sizeof(int));
    
    RawModel* model = loader.loadToVao(positions, indices);
    
    while (!glfwWindowShouldClose(window))
    {
        renderer.prepare();
        shader.start();
        renderer.render(model);
        shader.stop();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    shader.cleanUp();
    loader.cleanUp();
    
    glfwTerminate();
    return 0;
    
}
