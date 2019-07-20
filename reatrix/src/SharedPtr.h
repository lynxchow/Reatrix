//
//  SharedPtr.h
//  Reatrix
//
//  Created by Lyn on 2019/7/10.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_SHARED_PTR_H_
#define _RTX_SHARED_PTR_H_

#include <memory>

#define WeakPtr std::weak_ptr
#define SharedPtr std::shared_ptr
#define MakeShared std::make_shared
#define DynamicCast std::dynamic_pointer_cast
#define SharedThis std::enable_shared_from_this

#endif /* SharedPtr_h */
