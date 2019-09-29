//
//  Group.h
//  Reatrix
//
//  Created by Lyn on 2019/8/15.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_GROUP_H_
#define _RTX_GROUP_H_

#include "Entity.h"
#include "Matcher.h"
#include "container/Set.h"
#include "container/Vector.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Group
{
    friend class World;
public:
    Group(const Matcher& matcher);
    unsigned int count() const;
    Vector<SharedPtr<Entity> > getEntities();
    Matcher *getMatcher() const;
    
private:
    Matcher m_matcher;
    Set<SharedPtr<Entity> > mEntities;
    Vector<SharedPtr<Entity> > mEntitiesCache;
};

NAMESPACE_REATRIX_ENGINE_END

#endif /* Group_h */
