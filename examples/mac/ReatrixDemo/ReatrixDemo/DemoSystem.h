//
//  DemoSystem.h
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _DEMO_SYSTEM_H_
#define _DEMO_SYSTEM_H_

#include "System.h"

class DemoSystem : public rtx::System
{
public:
    DemoSystem();
    virtual ~DemoSystem();
    
protected:
    virtual void onInit();
    virtual void onUpdate();
    virtual void onDestroy();
    
private:
    
    unsigned int VBO, VAO, EBO;
    int shaderProgram;
};

#endif /* DemoSystem_h */
