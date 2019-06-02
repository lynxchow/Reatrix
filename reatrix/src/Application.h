//
//  Application.hpp
//  Reatrix
//
//  Created by Lyn on 2019/5/30.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_APPLICATION_H_
#define _RTX_APPLICATION_H_

#include <string>

namespace rtx
{
    class ApplicationImpl;
    
    class Application
    {
        friend class Reatrix;
    public:
        static Application *instance();
        Application();
        virtual ~Application();
        virtual void init();
        virtual void update();
        virtual void destroy();
        bool isLoad();
        const std::string& getName() const;
        void setName(const std::string& name);
    private:
        void onUpdate();
        ApplicationImpl *_impl;
    };
    
};


#endif /* Application_h */
