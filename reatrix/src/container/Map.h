//
//  Map.h
//  Reatrix
//
//  Created by Lyn on 2019/7/19.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_CONTAINER_MAP_H_
#define _RTX_CONTAINER_MAP_H_

#include "Common.h"
#include <unordered_map>

NAMESPACE_REATRIX_BEGIN

template <typename K, typename V>
using Map = std::unordered_map<K, V>;

NAMESPACE_REATRIX_END

#endif /* Map_h */
