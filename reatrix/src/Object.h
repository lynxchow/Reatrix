//
//  Object.h
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_OBJECT_H_
#define _RTX_OBJECT_H_

#include "Common.h"
#include <string>

NAMESPACE_RTX_BEGIN

class Object
{
public:
    Object();
    virtual ~Object();
    const std::string& getName() const;
    void setName(const std::string& name);
    
private:
    std::string _name;
};

NAMESPACE_RTX_END

#endif /* Object_hpp */
