//
//  System.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "System.h"
#include "component/Component.h"

NAMESPACE_REATRIX_ENGINE_BEGIN
    
System::System()
{
    
}

System::~System()
{
    
}

void System::init()
{
    m_is_started = true;
    this->onInit();
}

void System::onInit()
{
    
}

void System::onUpdate()
{
    
}

void System::onLateUpdate()
{
    
}

void System::onDestroy()
{
    
}

void System::onComponentAdded(Component* comp)
{
    
}

void System::onComponentRemoved(Component* comp)
{
    
}

World *System::getWorld()
{
    return m_world;
}

void System::update()
{
    this->onUpdate();
}

void System::lateUpdate()
{
    this->onLateUpdate();
}

void System::destroy()
{
    m_is_started = false;
    this->onDestroy();
}

bool System::isStarted()
{
    return m_is_started;
}
    
NAMESPACE_REATRIX_ENGINE_END
