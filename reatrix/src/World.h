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
#include "Group.h"
#include "Matcher.h"
#include "SharedPtr.h"
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
    bool hasEntity(const SharedPtr<Entity>& entity) const;
    void destroyEntity(SharedPtr<Entity> entity);
    void destroyAllEntities();
    Stack<SharedPtr<Entity> > getEntityPools();
    Vector<SharedPtr<Entity> > getEntities();
    
    SharedPtr<Group> getGroup(Matcher matcher);
    void clearGroups();
    
    void addSystem(const SharedPtr<System> system);
    bool removeSystem(const SharedPtr<System> system);
    
    Map<ComponentId, Stack<Component *> > *getComponentPools();
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
    Map<ComponentId, Vector<WeakPtr<Group> > > m_groups_for_index;
    
    Map<Matcher, SharedPtr<Group> > m_groups;
    
};
    
NAMESPACE_REATRIX_ENGINE_END

#endif /* World_h */
