//
//  Scene.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Scene.h"
#include "Entity.h"
#include "System.h"

NAMESPACE_REATRIX_BEGIN

Scene::Scene() : _is_started(false)
{
    
}

Scene::~Scene()
{
    
}

void Scene::init()
{
    _is_started = true;
    for (auto& system : _systems)
    {
        system->init();
    }
}

void Scene::destroy()
{
    _is_started = false;
    for (auto& system : _systems)
    {
        system->destroy();
    }
    _systems.clear();
}

void Scene::update()
{
    for (auto& system : _systems)
    {
        system->update();
    }
}

bool Scene::isStarted()
{
    return _is_started;
}

void Scene::addSystem(const SharedPtr<System> system)
{
    _systems.push_back(system);
}

bool Scene::removeSystem(const SharedPtr<System> system)
{
    for (auto it = _systems.begin(); it != _systems.end(); it++)
    {
        if (*it == system)
        {
            _systems.erase(it);
            return true;
        }
    }
    
    return false;
}

void Scene::addEntity(const std::shared_ptr<Entity>& entity)
{
    _entities[entity->getId()] = entity;
}

bool Scene::removeEntity(const SharedPtr<Entity>& entity)
{
    if (_entities.find(entity->getId()) != _entities.end())
    {
        _entities.erase(entity->getId());
        
        return true;
    }
    
    return false;
}

NAMESPACE_REATRIX_END
