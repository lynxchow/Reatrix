//
//  Scene.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Scene.h"
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

void Scene::addSystem(SharedPtr<System> system)
{
    _systems.push_back(system);
}
    
NAMESPACE_REATRIX_END
