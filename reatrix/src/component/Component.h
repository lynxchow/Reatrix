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
class Component;

typedef unsigned int ComponentId;
class ComponentTypeId
{
public:
    template<typename T>
    static const ComponentId get()
    {
        static_assert((std::is_base_of<Component, T>::value && !std::is_same<Component, T>::value),
                      "Class type must be derived from Component");
        
        static ComponentId id = m_counter++;
        return id;
    }
    
    static unsigned int count()
    {
        return m_counter;
    }
    
private:
    static unsigned int m_counter;
};

class Component : public Object
{
    friend class Entity;
public:
    virtual ~Component();
    
    SharedPtr<Entity> getEntity();
    
protected:
    Component();
    
private:
    WeakPtr<Entity> m_entity;
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Component_h */
