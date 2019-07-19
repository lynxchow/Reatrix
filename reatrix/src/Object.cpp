//
//  Object.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Object.h"

NAMESPACE_REATRIX_BEGIN

Object::Object()
{
    
}

Object::~Object()
{
    
}

const std::string& Object::getName() const
{
    return _name;
}

void Object::setName(const std::string& name)
{
    _name = name;
}

NAMESPACE_REATRIX_END
