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

class Entity : public Object, public SharedThis<Entity>
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
    // 这里不能赋值Entity类型的智能指针给Component
    // 要么从World里面获取Entity的SharedPtr，但是这样代码就依赖当前的Entity
    // 要么通过继承std::enable_shared_from_this
    component->m_entity = shared_from_this();
    
    return component;
}

template <class T>
SharedPtr<T> Entity::getComponent() const
{
    for (int i = 0; i < m_components.size(); ++i)
    {
        auto& component = m_components[i];
        auto t = DynamicCast<T>(component);
        if (t)
        {
            return t;
        }
    }
    
    return SharedPtr<T>();
}

NAMESPACE_REATRIX_ENGINE_END


#endif /* Entity_h */
