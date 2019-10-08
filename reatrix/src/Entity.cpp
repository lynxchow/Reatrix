//
//  Entity.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Entity.h"
#include "Reatrix.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

Entity::Entity()
{
    
}

Entity::~Entity()
{
    
}

void Entity::destroy(SharedPtr<Entity>& entity)
{
    entity.reset();
}

bool Entity::operator ==(const SharedPtr<Entity>& right) const
{
    return this->getUUID() == right->getUUID();
}

bool Entity::operator ==(const Entity right) const
{
    return this->getUUID() == right.getUUID();
}

bool Entity::hasComponent(const ComponentId index) const
{
    return (m_components.find(index) != m_components.end());
}

bool Entity::hasComponents(const Vector<ComponentId >& indices) const
{
    for (const ComponentId &index : indices)
    {
        if (!hasComponent(index))
        {
            return false;
        }
    }

    return true;
}

NAMESPACE_REATRIX_ENGINE_END

namespace std
{
    bool operator ==(WeakPtr<rtx::Entity> left, WeakPtr<rtx::Entity> right)
    {
        return left.lock().get() == right.lock().get();
    }
}
