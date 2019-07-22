//
//  Reatrix.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Reatrix.h"
#include "World.h"
#include "time/Timer.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class ReatrixImpl
{
public:
    ReatrixImpl()
    {
        
    }
    
    bool loadWorld(SharedPtr<World> world)
    {
        m_world = world;
        return true;
    }
    
    SharedPtr<World> currentWorld()
    {
        return m_world;
    }
    
    void init()
    {
        if (m_world)
        {
            m_world->init();
        }
    }
    
    void destroy()
    {
        if (m_world)
        {
            m_world->destroy();
        }
    }
    
    void update()
    {
        Timer::update();
        if (m_world)
        {
            if (!m_world->isStarted())
            {
                m_world->init();
            }
            m_world->update();
        }
    }
    
private:
    SharedPtr<World> m_world;
    
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

bool Reatrix::loadWorld(SharedPtr<World> app)
{
    return m_impl->loadWorld(app);
}

SharedPtr<World> Reatrix::currentWorld()
{
    return m_impl->currentWorld();
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
