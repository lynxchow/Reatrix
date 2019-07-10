//
//  Scene.h
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_SCENE_H_
#define _RTX_SCENE_H_

#include <string>
#include <vector>

namespace rtx
{
    class System;
    
    class Scene
    {
    public:
        Scene();
        virtual ~Scene();
        virtual void init();
        virtual void update();
        virtual void destroy();
        bool isLoad();
        const std::string& getName() const;
        void setName(const std::string& name);
        void addSystem(System *system);
        
    private:
        void onUpdate();
        
        std::string _name;
        bool _isLoad;
        std::vector<System *> _systems;
    };
    
};


#endif /* Scene_h */
