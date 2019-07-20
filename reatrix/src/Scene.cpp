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

NAMESPACE_REATRIX_ENGINE_BEGIN

SharedPtr<Scene> Scene::create(const String& name)
{
    SharedPtr<Scene> scene = SharedPtr<Scene>(new Scene);
    scene->setName(name);
    return scene;
}

Scene::Scene() : m_is_started(false)
{
    
}

Scene::~Scene()
{
    
}

void Scene::init()
{
    m_is_started = true;
    for (auto& system : m_systems)
    {
        system->init();
    }
}

void Scene::destroy()
{
    m_is_started = false;
    for (auto& system : m_systems)
    {
        system->destroy();
    }
    m_systems.clear();
}

void Scene::update()
{
    for (auto& system : m_systems)
    {
        system->update();
    }
}

bool Scene::isStarted()
{
    return m_is_started;
}

void Scene::addSystem(const SharedPtr<System> system)
{
    m_systems.push_back(system);
}

bool Scene::removeSystem(const SharedPtr<System> system)
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

void Scene::addEntity(const std::shared_ptr<Entity>& entity)
{
//    m_entities[entity->getId()] = entity;
}

bool Scene::removeEntity(const SharedPtr<Entity>& entity)
{
//    if (m_entities.find(entity->getId()) != m_entities.end())
//    {
//        m_entities.erase(entity->getId());
//        
//        return true;
//    }
    
    return false;
}

NAMESPACE_REATRIX_ENGINE_END
