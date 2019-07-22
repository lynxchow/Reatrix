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

NAMESPACE_REATRIX_ENGINE_BEGIN

class Component;
class System : public Object
{
    friend class World;
public:
    System();
    virtual ~System();
    bool isStarted();
    
private:
    void init();
    void update();
    void lateUpdate();
    void destroy();
    virtual void onInit();
    virtual void onUpdate();
    virtual void onLateUpdate();
    virtual void onDestroy();
    virtual void onComponentAdded(Component* comp);
    virtual void onComponentRemoved(Component* comp);
    
    bool m_is_started;
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* System_h */
