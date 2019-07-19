//
//  Object.cpp
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Object.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

Object::Object()
{
    static int s_id = 0;
    m_id = ++s_id;
}

Object::~Object()
{
    
}

const String& Object::getName() const
{
    return m_name;
}

void Object::setName(const String& name)
{
    m_name = name;
}

int64_t Object::getId() const
{
    return m_id;
}

NAMESPACE_REATRIX_ENGINE_END
