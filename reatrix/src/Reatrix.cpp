//
//  Reatrix.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Reatrix.h"
#include "Scene.h"
#include "time/Timer.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class ReatrixImpl
{
public:
    ReatrixImpl()
    {
        
    }
    
    bool loadScene(SharedPtr<Scene> scene)
    {
        m_scene = scene;
        return true;
    }
    
    SharedPtr<Scene> currentScene()
    {
        return m_scene;
    }
    
    void init()
    {
        if (m_scene)
        {
            m_scene->init();
        }
    }
    
    void destroy()
    {
        if (m_scene)
        {
            m_scene->destroy();
        }
    }
    
    void update()
    {
        Timer::update();
        if (m_scene)
        {
            if (!m_scene->isStarted())
            {
                m_scene->init();
            }
            m_scene->update();
        }
    }
    
private:
    SharedPtr<Scene> m_scene;
    
};

Reatrix *Reatrix::instance()
{
    static Reatrix *s_instance = nullptr;
    if (s_instance == nullptr)
    {
        s_instance = new Reatrix();
    }
    
    return s_instance;
}

Reatrix::Reatrix()
{
    m_impl = new ReatrixImpl();
}

Reatrix::~Reatrix()
{
    delete m_impl;
}

bool Reatrix::loadScene(SharedPtr<Scene> app)
{
    return m_impl->loadScene(app);
}

SharedPtr<Scene> Reatrix::currentScene()
{
    return m_impl->currentScene();
}

void Reatrix::init()
{
    m_impl->init();
}

void Reatrix::destroy()
{
    m_impl->destroy();
}

void Reatrix::update()
{
    m_impl->update();
}

NAMESPACE_REATRIX_ENGINE_END
