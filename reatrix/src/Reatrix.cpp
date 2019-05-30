//
//  Reatrix.cpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Reatrix.h"
#include "Application.h"

namespace rtx
{
    Application *s_application = nullptr;
    
    Reatrix *Reatrix::instance()
    {
        static Reatrix *s_instance = nullptr;
        if (s_instance)
        {
            s_instance = new Reatrix();
        }
        
        return s_instance;
    }
    
    Reatrix::Reatrix()
    {
        
    }
    
    Reatrix::~Reatrix()
    {
        
    }
    
    bool Reatrix::loadApplication(Application *app)
    {
        s_application = app;
        
        return true;
    }
    
    Application *Reatrix::currentApplication()
    {
        return s_application;
    }
    
    void Reatrix::init()
    {
        if (s_application)
        {
            s_application->init();
        }
    }
    
    void Reatrix::destroy()
    {
        if (s_application)
        {
            s_application->destroy();
        }
    }
    
    void Reatrix::onUpdate()
    {
        if (s_application)
        {
            if (!s_application->isLoad())
            {
                s_application->init();
            }
            s_application->update();
        }
    }
}
