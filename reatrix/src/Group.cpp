//
//  Group.cpp
//  Reatrix
//
//  Created by Lyn on 2019/8/15.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Group.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

Group::Group(const Matcher& matcher) : m_matcher(matcher)
{
    
}

Vector<SharedPtr<Entity> > Group::getEntities()
{
    if (m_entities_cache.empty() && !m_entities.empty())
    {
        m_entities_cache = Vector<SharedPtr<Entity> >(m_entities.begin(), m_entities.end());
    }

    return m_entities_cache;
}

Matcher Group::getMatcher() const
{
    return m_matcher;
}

bool Group::addEntitySilently(SharedPtr<Entity> entity)
{
    if(m_entities.insert(entity).second)
    {
        m_entities_cache.clear();
        return true;
    }

    return false;
}

bool Group::removeEntitySilently(SharedPtr<Entity> entity)
{
    if (m_entities.erase(entity))
    {
        m_entities_cache.clear();
        return true;
    }

    return false;
}

void Group::handleEntitySilently(SharedPtr<Entity> entity)
{
    if (m_matcher.matches(entity))
    {
        addEntitySilently(entity);
    }
    else
    {
        removeEntitySilently(entity);
    }
}

NAMESPACE_REATRIX_ENGINE_END


