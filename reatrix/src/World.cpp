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

void World::addEntity(const std::shared_ptr<Entity>& entity)
{
    m_entities[entity->getId()] = entity;
}

bool World::removeEntity(const SharedPtr<Entity>& entity)
{
    if (m_entities.find(entity->getId()) != m_entities.end())
    {
        m_entities.erase(entity->getId());
        
        return true;
    }
    
    return false;
}

NAMESPACE_REATRIX_ENGINE_END
