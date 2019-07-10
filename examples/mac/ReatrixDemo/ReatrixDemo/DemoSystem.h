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
    
    void init() override;
    void destroy() override;
    
private:
    void onUpdate() override;
    
    unsigned int VBO, VAO, EBO;
    int shaderProgram;
};

#endif /* DemoSystem_h */
