//
//  System.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "System.h"

NAMESPACE_RTX_BEGIN
    
System::System()
{
    
}

System::~System()
{
    
}

void System::init()
{
    _isLoad = true;
}

void System::onUpdate()
{
    
}

void System::update()
{
    this->onUpdate();
}

void System::destroy()
{
    _isLoad = false;
}

bool System::isLoad()
{
    return _isLoad;
}
    
NAMESPACE_RTX_END
