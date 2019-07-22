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
#include "component/Component.h"
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
    
    bool operator ==(const SharedPtr<Entity>& right) const;
    bool operator ==(const Entity right) const;
private:
    Entity();
    WeakPtr<Entity> m_weak_this;
    
    bool m_is_enable;
    Vector<SharedPtr<Component> > m_components;
};

template <class T, typename ...Params>
SharedPtr<T> Entity::addComponent(Params... args)
{
    SharedPtr<T> component = MakeShared<T>(args...);
    
    m_components.push_back(component);
    component->m_entity = m_weak_this;
    
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

namespace std
{
    template <>
    struct hash<WeakPtr<rtx::Entity> >
    {
        std::size_t operator()(const WeakPtr<rtx::Entity>& ptr) const
        {
            return hash<unsigned int>()(ptr.lock()->getUUID());
        }
    };
    
    bool operator ==(WeakPtr<rtx::Entity> left, WeakPtr<rtx::Entity> right);
}


#endif /* Entity_h */
