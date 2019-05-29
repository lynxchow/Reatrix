//
//  DeviceBase.cpp
//  Reatrix
//
//  Created by Lyn on 2018/6/2.
//  Copyright © 2018 Vin-Ex. All rights reserved.
//

#include "DisplayBase.h"

namespace rtx
{
    void DisplayBase::init(int width, int height, int fps)
    {
        _width = width;
        _height = height;
        _fps = fps;
    }
    
    void DisplayBase::processSystemEvents()
    {
        
    }
}
