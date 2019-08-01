//
//  Transform.h
//  Reatrix
//
//  Created by Lyn on 2019/7/19.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_TRANSFORM_H_
#define _RTX_TRANSFORM_H_

#include "component/Component.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Transform : public Component
{
public:
    Transform();
    virtual ~Transform();
    
    void reset();
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Transform_h */
