//
//  DemoSystem.h
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef m_DEMO_SYSTEM_H_
#define m_DEMO_SYSTEM_H_

#include "System.h"

class DemoSystem : public rtx::System
{
public:
    DemoSystem();
    virtual ~DemoSystem();
    
private:
    virtual void onInit();
    virtual void onUpdate();
    virtual void onDestroy();
    
    unsigned int VBO, VAO, EBO;
    int shaderProgram;
};

#endif /* DemoSystem_h */
