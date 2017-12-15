//
//  RawModel.cpp
//  RenderEngine
//
//  Created by Cameron Ralph on 14/12/2017.
//  Copyright © 2017 CameronRalph. All rights reserved.
//

#include "RawModel.hpp"

RawModel::RawModel(int vaoID, int vertexCount){
    m_vaoID = vaoID;
    m_vertexCount = vertexCount;
}

int RawModel::getVaoID(){
    return m_vaoID;
}

int RawModel::getVertexCount(){
    return m_vertexCount;
}
