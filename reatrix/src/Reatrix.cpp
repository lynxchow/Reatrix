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

NAMESPACE_REATRIX_BEGIN

Scene *s_scene = nullptr;

class ReatrixImpl
{
public:
    ReatrixImpl()
    {
        
    }
    
    bool loadScene(Scene *app)
    {
        s_scene = app;
        return true;
    }
    
    Scene *currentScene()
    {
        return s_scene;
    }
    
    void init()
    {
        if (s_scene)
        {
            s_scene->init();
        }
    }
    
    void destroy()
    {
        if (s_scene)
        {
            s_scene->destroy();
        }
    }
    
    void update()
    {
        Timer::update();
        if (s_scene)
        {
            if (!s_scene->isLoad())
            {
                s_scene->init();
            }
            s_scene->update();
        }
    }
    
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
    _impl = new ReatrixImpl();
}

Reatrix::~Reatrix()
{
    delete _impl;
}

bool Reatrix::loadScene(Scene *app)
{
    return _impl->loadScene(app);
}

Scene *Reatrix::currentScene()
{
    return _impl->currentScene();
}

void Reatrix::init()
{
    _impl->init();
}

void Reatrix::destroy()
{
    _impl->destroy();
}

void Reatrix::update()
{
    _impl->update();
}

NAMESPACE_REATRIX_END
