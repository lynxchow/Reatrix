//
//  Component.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "component/Component.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

unsigned int ComponentTypeId::m_counter = 0;

Component::Component()
{
    
}

Component::~Component()
{
    
}

SharedPtr<Entity> Component::getEntity()
{
    return m_entity.lock();
}

NAMESPACE_REATRIX_ENGINE_END

