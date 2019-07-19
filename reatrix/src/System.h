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

class System : public Object
{
public:
    System();
    virtual ~System();
    virtual void init();
    void update();
    virtual void destroy();
    bool isLoad();
    
private:
    virtual void onUpdate();
    
    bool _isLoad;
};

NAMESPACE_REATRIX_END

#endif /* System_h */
