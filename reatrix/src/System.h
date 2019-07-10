//
//  System.h
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_SYSTEM_H_
#define _RTX_SYSTEM_H_

#include "Common.h"
#include <string>

NAMESPACE_RTX_BEGIN

class System
{
public:
    System();
    virtual ~System();
    virtual void init();
    void update();
    virtual void destroy();
    bool isLoad();
    const std::string& getName() const;
    void setName(const std::string& name);
    
private:
    virtual void onUpdate();
    
    std::string _name;
    bool _isLoad;
};

NAMESPACE_RTX_END

#endif /* System_h */
