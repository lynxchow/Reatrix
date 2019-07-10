//
//  System.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "System.h"

namespace rtx
{
    
    System::System()
    {
        
    }
    
    System::~System()
    {
        
    }
    
    void System::init()
    {
        _isLoad = true;
    }
    
    void System::onUpdate()
    {
        
    }
    
    void System::update()
    {
        this->onUpdate();
    }
    
    void System::destroy()
    {
        _isLoad = false;
    }
    
    bool System::isLoad()
    {
        return _isLoad;
    }
    
    const std::string& System::getName() const
    {
        return _name;
    }
    
    void System::setName(const std::string& name)
    {
        _name = name;
    }
    
}
