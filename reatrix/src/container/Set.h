//
//  Set.h
//  Reatrix
//
//  Created by Lyn on 2019/7/22.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_CONTAINER_SET_H_
#define _RTX_CONTAINER_SET_H_

#include "Common.h"
#include <unordered_set>

NAMESPACE_REATRIX_ENGINE_BEGIN

template <typename T>
using Set = std::unordered_set<T>;

NAMESPACE_REATRIX_ENGINE_END

#endif /* Set_h */
