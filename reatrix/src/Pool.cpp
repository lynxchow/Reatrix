//
//  Pool.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Pool.h"
#include "Entity.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

Pool::Pool()
{
    
}

Pool::~Pool()
{
    
}

SharedPtr<Entity> Pool::createEntity(const String& name)
{
    SharedPtr<Entity> entity;
    
    if (m_reusable_entities.size() > 0)
    {
        entity = m_reusable_entities.top();
        m_reusable_entities.pop();
    }
    else
    {
        entity = SharedPtr<Entity>(new Entity());
    }
    entity->setName(name);
    entity->m_component_pools = &m_component_pools;
    entity->m_weak_this = entity;
    
    m_entities.insert(entity);
    m_entities_cache.clear();
    
    return entity;
}

bool Pool::hasEntity(const SharedPtr<Entity>& entity) const
{
    return std::find(m_entities.begin(), m_entities.end(), WeakPtr<Entity>(entity)) != m_entities.end();
}

void Pool::destroyEntity(SharedPtr<Entity> entity)
{
    auto removed = m_entities.erase(entity);
    
    if (!removed)
    {
        throw std::runtime_error("Error, cannot destroy entity. Pool does not contain entity.");
    }
    
    m_entities_cache.clear();
    
//    onEntityWillBeDestroyed(this, entity);
//    entity->destroy();
//    onEntityDestroyed(this, entity);
    
    if (entity.use_count() == 1)
    {
//        entity->OnEntityReleased -= mOnEntityReleasedCache;
        m_reusable_entities.push(entity);
    }
    else
    {
        m_retained_entities.insert(entity);
    }
}

void Pool::destroyAllEntities()
{
    {
        Vector<SharedPtr<Entity> > entitiesTemp = Vector<SharedPtr<Entity> >(m_entities.begin(), m_entities.end());
        
        while (!m_entities.empty())
        {
            destroyEntity(entitiesTemp.back());
            entitiesTemp.pop_back();
        }
    }
    
    m_entities.clear();
    
    if (!m_retained_entities.empty())
    {
        // Try calling Pool.ClearGroups() and SystemContainer.ClearReactiveSystems() before calling pool.DestroyAllEntities() to avoid memory leaks
        throw std::runtime_error("Error, pool detected retained entities although all entities got destroyed. Did you release all entities?");
    }
}

Vector<SharedPtr<Entity> > Pool::getEntities()
{
    if (m_entities_cache.empty())
    {
        m_entities_cache = Vector<SharedPtr<Entity> >(m_entities.begin(), m_entities.end());
    }
    
    return m_entities_cache;
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
