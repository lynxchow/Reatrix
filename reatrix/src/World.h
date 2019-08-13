//
//  World.h
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_SCENE_H_
#define _RTX_SCENE_H_

#include "Object.h"
#include "SharedPtr.h"
#include <string>
#include "container/Vector.h"
#include "container/Set.h"
#include "container/Map.h"
#include "container/Stack.h"
#include "component/Component.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity;
class System;
class World : public Object
{
public:
    static SharedPtr<World> create(const String& name);
    virtual ~World();
    void init();
    void update();
    void destroy();
    bool isStarted();
    
    SharedPtr<Entity> createEntity(const String& name);
    
    bool removeEntity(const SharedPtr<Entity>& entity);
    void addSystem(const SharedPtr<System> system);
    bool removeSystem(const SharedPtr<System> system);
    
    
    Map<ComponentId, Stack<Component *> > *getComponentPools();
    Stack<SharedPtr<Entity> > getEntityPools();
    bool hasEntity(const SharedPtr<Entity>& entity) const;
    void destroyEntity(SharedPtr<Entity> entity);
    void destroyAllEntities();
    Vector<SharedPtr<Entity> > getEntities();
    
    void clearComponentPool(const ComponentId index);
    void clearComponentPools();
    
private:
    World();
    bool m_is_started;
    Vector<SharedPtr<System> > m_systems;
    
    Set<SharedPtr<Entity> > m_entities;
    Set<SharedPtr<Entity> > m_retained_entities;
    Vector<SharedPtr<Entity> > m_entities_cache;
    Stack<SharedPtr<Entity> > m_reusable_entities;
    Map<ComponentId, Stack<Component *> > m_component_pools;
    
};
    
NAMESPACE_REATRIX_ENGINE_END

#endif /* World_h */
