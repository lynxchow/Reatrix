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


NAMESPACE_REATRIX_BEGIN

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
    void addSystem(SharedPtr<System> system);
    
private:
    bool _is_started;
    Vector<SharedPtr<System> > _systems;
};
    
NAMESPACE_REATRIX_END

#endif /* Scene_h */
