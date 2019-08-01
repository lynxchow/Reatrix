//
//  Stack.hpp
//  Reatrix
//
//  Created by Lyn on 2019/7/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_CONTAINER_STACK_H_
#define _RTX_CONTAINER_STACK_H_

#include "Common.h"
#include <stack>

NAMESPACE_REATRIX_ENGINE_BEGIN

template <typename T>
using Stack = std::stack<T>;

NAMESPACE_REATRIX_ENGINE_END

#endif /* Stack_h */
