//
//  Application.cpp
//  Reatrix
//
//  Created by Shamoo Zhou on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Application.h"

namespace rtx
{
    class ApplicationImpl
    {
    public:
        std::string _name;
        bool _isLoad;
        
        ApplicationImpl() : _isLoad(false)
        {
            
        }
        
        virtual ~ApplicationImpl()
        {
            
        }
        
        void init()
        {
            _isLoad = true;
        }
        
        void destroy()
        {
            _isLoad = false;
        }
        
        bool isLoad()
        {
            return _isLoad;
        }
        
        const std::string& getName() const
        {
            return _name;
        }
        
        void setName(const std::string& name)
        {
            _name = name;
        }
        
    };
    
    Application *Application::instance()
    {
        return nullptr;
    }
    
    Application::Application() : _impl(new ApplicationImpl)
    {
        
    }
    
    Application::~Application()
    {
        delete _impl;
    }
    
    void Application::init()
    {
        _impl->init();
    }
    
    void Application::destroy()
    {
        _impl->destroy();
    }
    
    void Application::update()
    {
        
    }
    
    bool Application::isLoad()
    {
        return _impl->isLoad();
    }
    
    const std::string& Application::getName() const
    {
        return _impl->getName();
    }
    
    void Application::setName(const std::string& name)
    {
        _impl->setName(name);
    }
    
}
