//
//  DemoApplication.h
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _DEMO_APPLICATION_H_
#define _DEMO_APPLICATION_H_

#include "Application.h"

class DemoApplication : public rtx::Application
{
public:
    DemoApplication();
    virtual ~DemoApplication();
    
    void init() override;
    void destroy() override;
    void update() override;
    
private:
    unsigned int VBO, VAO, EBO;
    int shaderProgram;
};

#endif /* DemoApplication_h */
