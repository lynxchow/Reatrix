//
//  System.h
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_SYSTEM_H_
#define _RTX_SYSTEM_H_

#include "Object.h"
#include <string>

NAMESPACE_REATRIX_BEGIN

class Component;
class System : public Object
{
    friend class Scene;
public:
    System();
    virtual ~System();
    bool isStarted();
    
private:
    void init();
    void update();
    void destroy();
    virtual void onInit();
    virtual void onUpdate();
    virtual void onDestroy();
    virtual void onComponentAdded(Component* comp);
    virtual void onComponentRemoved(Component* comp);
    
    bool _is_started;
};

NAMESPACE_REATRIX_END

#endif /* System_h */
