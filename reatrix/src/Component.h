//
//  Component.hpp
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_COMPONENT_H_
#define _RTX_COMPONENT_H_

#include "Object.h"

NAMESPACE_REATRIX_BEGIN

class Component : public Object
{
public:
    Component();
    virtual ~Component();
};

NAMESPACE_REATRIX_END

#endif /* Component_h */
