//
//  Component.h
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_COMPONENT_H_
#define _RTX_COMPONENT_H_

#include "Object.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity;
class Component : public Object
{
    friend class Entity;
public:
    Component();
    virtual ~Component();
    
    SharedPtr<Entity> getEntity();
    
private:
    WeakPtr<Entity> m_entity;
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Component_h */
