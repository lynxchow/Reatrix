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
#include "container/Map.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity : public Object
{
public:
    static SharedPtr<Entity> create(const String& name);
    virtual ~Entity();
    
    static void destroy(SharedPtr<Entity>& entity);
    
    template <class T, typename ...Params>
    T *addComponent(Params... args);
    
    template <class T>
    bool hasComponent() const;

    template <class T>
    T *getComponent();
    
    template <class T>
    void removeComponent();
    
    bool isEnable() const { return m_is_enable; }
    void setEnable(bool enable) { m_is_enable = enable; }
    
    bool operator ==(const SharedPtr<Entity>& right) const;
    bool operator ==(const Entity right) const;
private:
    Entity();
    WeakPtr<Entity> m_weak_this;
    
    bool m_is_enable;
    Map<ComponentId, Component *> m_components;
};

template <class T, typename ...Params>
T *Entity::addComponent(Params... args)
{
    T *component = new T(args...);
    
    m_components[ComponentTypeId::get<T>()] = component;
    component->m_entity = m_weak_this;
    
    return component;
}

template <class T>
bool Entity::hasComponent() const
{
    return (m_components.find(ComponentTypeId::get<T>()) != m_components.end());
}

template <class T>
T *Entity::getComponent()
{
    if (hasComponent<T>())
    {
        return static_cast<T *>(m_components[ComponentTypeId::get<T>()]);
    }
    
    return nullptr;
}

template <class T>
void Entity::removeComponent()
{
    auto& it = m_components.erase(ComponentTypeId::get<T>());
    if (it != m_components.end())
    {
        delete it->secend();
    }
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
