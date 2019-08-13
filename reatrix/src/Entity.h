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
#include "container/Stack.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity : public Object
{
    friend class Pool;
public:
    
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
    
    Stack<Component *> *getComponentPool(const ComponentId index) const
    {
        return &((*m_component_pools)[index]);
    }
    
    bool m_is_enable;
    Map<ComponentId, Component *> m_components;
    Map<ComponentId, Stack<Component *> > *m_component_pools;
};

template <class T, typename ...Args>
T *Entity::addComponent(Args... args)
{
    const ComponentId id = ComponentTypeId::get<T>();
    Stack<Component *> *component_pool = getComponentPool(id);
    T *component = nullptr;
    
    if (component_pool->size() > 0)
    {
        component = static_cast<T *>(component_pool->top());
        component_pool->pop();
    }
    else
    {
        component = new T();
    }
    
    component->reset(std::forward<Args>(args)...);

    m_components[id] = component;
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
    Component *component = getComponent<T>();
    if (component)
    {
        const ComponentId id = ComponentTypeId::get<T>();
        m_components.erase(id);
        getComponentPool(id)->push(component);
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
