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


NAMESPACE_RTX_BEGIN

class System;
class Scene : public Object
{
public:
    Scene();
    virtual ~Scene();
    virtual void init();
    virtual void update();
    virtual void destroy();
    bool isLoad();
    void addSystem(SharedPtr<System> system);
    
private:
    void onUpdate();
    
    bool _isLoad;
    Vector<SharedPtr<System> > _systems;
};
    
NAMESPACE_RTX_END

#endif /* Scene_h */
