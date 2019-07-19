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

NAMESPACE_REATRIX_BEGIN

class Object
{
public:
    Object();
    virtual ~Object();
    int64_t getId() const;
    const String& getName() const;
    void setName(const String& name);
    
private:
    int64_t _id;
    String _name;
};

NAMESPACE_REATRIX_END

#endif /* Object_hpp */