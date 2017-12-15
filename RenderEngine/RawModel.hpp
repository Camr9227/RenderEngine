//
//  RawModel.hpp
//  RenderEngine
//
//  Created by Cameron Ralph on 14/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#ifndef RawModel_hpp
#define RawModel_hpp

#include <stdio.h>

class RawModel{
public:
    RawModel(int vaoID, int vertexCount);
    int getVaoID();
    int getVertexCount();
private:
    int m_vaoID;
    int m_vertexCount;
};

#endif /* RawModel_hpp */
