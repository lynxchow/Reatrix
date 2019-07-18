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
#include "SharedPtr.h"
#include "string/String.h"

NAMESPACE_RTX_BEGIN

class Object
{
public:
    Object();
    virtual ~Object();
    const std::string& getName() const;
    void setName(const std::string& name);
    
private:
    String _name;
};

NAMESPACE_RTX_END

#endif /* Object_hpp */
