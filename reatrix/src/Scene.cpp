//
//  Scene.cpp
//  Reatrix
//
//  Created by Shamoo Zhou on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Scene.h"
#include "System.h"

namespace rtx
{   
    Scene::Scene() : _isLoad(false)
    {
        
    }
    
    Scene::~Scene()
    {
        
    }
    
    void Scene::onUpdate()
    {
        
    }
    
    void Scene::init()
    {
        _isLoad = true;
        for (auto& system : _systems)
        {
            system->init();
        }
    }
    
    void Scene::destroy()
    {
        _isLoad = false;
        for (auto& system : _systems)
        {
            system->destroy();
        }
    }
    
    void Scene::update()
    {
        for (auto& system : _systems)
        {
            system->update();
        }
    }
    
    bool Scene::isLoad()
    {
        return _isLoad;
    }
    
    const std::string& Scene::getName() const
    {
        return _name;
    }
    
    void Scene::setName(const std::string& name)
    {
        _name = name;
    }
    
    void Scene::addSystem(System *system)
    {
        _systems.push_back(system);
    }
    
}
