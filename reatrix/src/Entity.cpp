//
//  Entity.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Entity.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

SharedPtr<Entity> Entity::create(const String& name)
{
    SharedPtr<Entity> entity = SharedPtr<Entity>(new Entity);
    entity->setName(name);
    return entity;
}

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

void Entity::removeComponent(const SharedPtr<Component>& component)
{
    
}

NAMESPACE_REATRIX_ENGINE_END
