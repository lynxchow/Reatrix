//
//  Pool.hpp
//  Reatrix
//
//  Created by Lyn on 2019/7/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_POOL_H_
#define _RTX_POOL_H_

#include "Object.h"
#include "component/Component.h"
#include "container/Map.h"
#include "container/Set.h"
#include "container/Vector.h"
#include "container/Stack.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Pool
{
    friend class ReatrixImpl;
public:
    ~Pool();
    Map<ComponentId, Stack<Component *> > *getComponentPools();
    
    SharedPtr<Entity> createEntity();
    Stack<SharedPtr<Entity> > getEntityPools();
    bool hasEntity(const SharedPtr<Entity>& entity) const;
    void destroyEntity(SharedPtr<Entity> entity);
    void destroyAllEntities();
    Vector<SharedPtr<Entity> > getEntities();
    
    void clearComponentPool(const ComponentId index);
    void clearComponentPools();
    
private:
    Pool();
    Set<SharedPtr<Entity> > m_entities;
    Set<SharedPtr<Entity> > m_retained_entities;
    Vector<SharedPtr<Entity> > m_entities_cache;
    Stack<SharedPtr<Entity> > m_reusable_entities;
    Map<ComponentId, Stack<Component *> > m_component_pools;
    
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Pool_h */
