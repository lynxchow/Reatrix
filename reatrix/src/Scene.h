//
//  Scene.h
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
#include "container/Map.h"


NAMESPACE_REATRIX_ENGINE_BEGIN

class Entity;
class System;
class Scene : public Object
{
public:
    Scene();
    virtual ~Scene();
    void init();
    void update();
    void destroy();
    bool isStarted();
    void addEntity(const SharedPtr<Entity>& entity);
    bool removeEntity(const SharedPtr<Entity>& entity);
    void addSystem(const SharedPtr<System> system);
    bool removeSystem(const SharedPtr<System> system);
    
private:
    bool m_is_started;
    Vector<SharedPtr<System> > m_systems;
    Map<int64_t, SharedPtr<Entity> > m_entities;
};
    
NAMESPACE_REATRIX_ENGINE_END

#endif /* Scene_h */
