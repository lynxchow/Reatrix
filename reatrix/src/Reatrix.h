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
    class Application;
    
    class Reatrix
    {
    private:
        Reatrix();
        
    public:
        static Reatrix *instance();
        virtual ~Reatrix();
        bool loadApplication(Application *app);
        Application *currentApplication();
        void init();
        void destroy();
        void onUpdate();
    };
};

#endif /* Reatrix_h */
