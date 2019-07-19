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
    static int s_id = 0;
    _id = ++s_id;
}

Object::~Object()
{
    
}

const String& Object::getName() const
{
    return _name;
}

void Object::setName(const String& name)
{
    _name = name;
}

int64_t Object::getId() const
{
    return _id;
}

NAMESPACE_REATRIX_END
