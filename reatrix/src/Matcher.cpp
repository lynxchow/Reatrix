//
//  Matcher.cpp
//  Reatrix
//
//  Created by Lyn on 2019/8/15.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Matcher.h"
#include "Entity.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

unsigned int Matcher::getHashCode() const
{
    return m_cached_hash;
}

const Matcher Matcher::allOf(const Vector<ComponentId> indices)
{
    Matcher matcher;
    matcher.m_all_of_indices = distinctIndices(indices);
    matcher.calculateHash();
    
    return matcher;
}

void Matcher::calculateHash()
{
    unsigned int hash = typeid(Matcher).hash_code();

    hash = applyHash(hash, m_all_of_indices, 3, 53);

    m_cached_hash = hash;
}

unsigned int Matcher::applyHash(unsigned int hash, const Vector<ComponentId> indices, int i1, int i2) const
{
    if (indices.size() > 0)
    {
        for (int i = 0, indices_size = indices.size(); i < indices_size; i++)
        {
            hash ^= indices[i] * i1;
        }

        hash ^= indices.size() * i2;
    }

    return hash;
}

Vector<ComponentId> Matcher::distinctIndices(Vector<ComponentId> indices)
{
    // sort fist, and use std::unique remove same ids.
    std::sort(indices.begin(), indices.end());
    indices.erase(std::unique(indices.begin(), indices.end()), indices.end());

    return indices;
}

bool Matcher::matches(const SharedPtr<Entity>& entity)
{
    auto matchesAllOf = m_all_of_indices.empty() || entity->hasComponents(m_all_of_indices);

    return matchesAllOf;
}

const Vector<ComponentId> Matcher::getIndices()
{
    if (m_indices.empty())
    {
        m_indices = m_all_of_indices;
    }
    
    return m_indices;
}

bool Matcher::isEmpty() const
{
    return m_all_of_indices.empty();
}

bool Matcher::compareIndices(const Matcher& matcher) const
{
    if (matcher.isEmpty())
    {
        return false;
    }

    auto leftIndices = this->m_all_of_indices;
    auto rightIndices = matcher.m_all_of_indices;

    if (leftIndices.size() != rightIndices.size())
    {
        return false;
    }

    for (unsigned int i = 0, count = leftIndices.size(); i < count; ++i)
    {
        if (leftIndices[i] != rightIndices[i])
        {
            return false;
        }
    }

    return true;
}

bool Matcher::operator ==(const Matcher right) const
{
    return this->getHashCode() == right.getHashCode() && this->compareIndices(right);
}

NAMESPACE_REATRIX_ENGINE_END
