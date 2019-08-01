//
//  Pool.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Pool.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

Pool::Pool()
{
    
}

Pool::~Pool()
{
    
}

Map<ComponentId, Stack<Component *> > *Pool::getComponentPools()
{
    return &m_component_pools;
}

void Pool::clearComponentPool(const ComponentId index)
{
    while (!m_component_pools.at(index).empty())
    {
        m_component_pools.at(index).pop();
    }
}

void Pool::clearComponentPools()
{
    for(const auto &pair : m_component_pools)
    {
        clearComponentPool(pair.first);
    }
}

NAMESPACE_REATRIX_ENGINE_END
