//
//  World.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "World.h"
#include "Entity.h"
#include "System.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

SharedPtr<World> World::create(const String& name)
{
    SharedPtr<World> world = SharedPtr<World>(new World);
    world->setName(name);
    return world;
}

World::World() : m_is_started(false)
{
    
}

World::~World()
{
    
}

void World::init()
{
    m_is_started = true;
    for (auto& system : m_systems)
    {
        system->init();
    }
}

void World::destroy()
{
    m_is_started = false;
    for (auto& system : m_systems)
    {
        system->destroy();
    }
    m_systems.clear();
}

void World::update()
{
    for (auto& system : m_systems)
    {
        system->update();
    }
    for (auto& system : m_systems)
    {
        system->lateUpdate();
    }
}

bool World::isStarted()
{
    return m_is_started;
}

void World::addSystem(const SharedPtr<System> system)
{
    m_systems.push_back(system);
    system->m_world = this;
}

bool World::removeSystem(const SharedPtr<System> system)
{
    for (auto it = m_systems.begin(); it != m_systems.end(); it++)
    {
        if (*it == system)
        {
            m_systems.erase(it);
            return true;
        }
    }
    
    return false;
}

SharedPtr<Entity> World::createEntity(const String& name)
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

bool World::hasEntity(const SharedPtr<Entity>& entity) const
{
    return std::find(m_entities.begin(), m_entities.end(), WeakPtr<Entity>(entity)) != m_entities.end();
}

void World::destroyEntity(SharedPtr<Entity> entity)
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

void World::destroyAllEntities()
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

Vector<SharedPtr<Entity> > World::getEntities()
{
    if (m_entities_cache.empty())
    {
        m_entities_cache = Vector<SharedPtr<Entity> >(m_entities.begin(), m_entities.end());
    }
    
    return m_entities_cache;
}

Map<ComponentId, Stack<Component *> > *World::getComponentPools()
{
    return &m_component_pools;
}

void World::clearComponentPool(const ComponentId index)
{
    while (!m_component_pools.at(index).empty())
    {
        m_component_pools.at(index).pop();
    }
}

void World::clearComponentPools()
{
    for(const auto &pair : m_component_pools)
    {
        clearComponentPool(pair.first);
    }
}
NAMESPACE_REATRIX_ENGINE_END
