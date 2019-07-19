//
//  Entity.h
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_ENTITY_H_
#define _RTX_ENTITY_H_

#include "Object.h"
#include "Component.h"
#include "container/Vector.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity : public Object
{
public:
    static SharedPtr<Entity> create(const String& name);
    virtual ~Entity();
    
    static void destroy(SharedPtr<Entity>& entity);
    
    template <class T, typename ...Params>
    SharedPtr<T> addComponent(Params... args);
    
    template <class T>
    SharedPtr<T> getComponent() const;
    
    void removeComponent(const SharedPtr<Component>& component);
    
    bool isEnable() const { return m_is_enable; }
    void setEnable(bool enable) { m_is_enable = enable; }
    
private:
    Entity();
    
    bool m_is_enable;
    Vector<SharedPtr<Component> > m_components;
};

template <class T, typename ...Params>
SharedPtr<T> Entity::addComponent(Params... args)
{
    SharedPtr<T> component = MakeShared<T>(args...);
    
    m_components.push_back(component);
//    component->m_entity = this;
    
    return component;
}

NAMESPACE_REATRIX_ENGINE_END


#endif /* Entity_h */
