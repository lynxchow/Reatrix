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

namespace rtx
{
    class Scene;
    
    class ReatrixImpl;
    
    class Reatrix
    {
    private:
        Reatrix();
        
    public:
        static Reatrix *instance();
        virtual ~Reatrix();
        bool loadScene(Scene *app);
        Scene *currentScene();
        void init();
        void destroy();
        void update();
        
    private:
        ReatrixImpl *_impl;
    };
};

#endif /* Reatrix_h */
