//
//  Reatrix.h
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_REATRIX_H_
#define _RTX_REATRIX_H_

#include <stdio.h>
#include "Common.h"
#include "SharedPtr.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class World;
class ReatrixImpl;

class Reatrix
{
private:
    Reatrix();
    
public:
    static Reatrix *instance();
    virtual ~Reatrix();
    bool loadWorld(SharedPtr<World> world);
    SharedPtr<World> currentWorld();
    void init();
    void destroy();
    void update();
    
private:
    ReatrixImpl *m_impl;
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Reatrix_h */
