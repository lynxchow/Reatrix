//
//  System.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "System.h"

NAMESPACE_REATRIX_BEGIN
    
System::System()
{
    
}

System::~System()
{
    
}

void System::init()
{
    _is_started = true;
    this->onInit();
}

void System::onInit()
{
    
}

void System::onUpdate()
{
    
}

void System::onDestroy()
{
    
}

void System::update()
{
    this->onUpdate();
}

void System::destroy()
{
    _is_started = false;
    this->onDestroy();
}

bool System::isStarted()
{
    return _is_started;
}
    
NAMESPACE_REATRIX_END
