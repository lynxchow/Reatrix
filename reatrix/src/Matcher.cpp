//
//  Matcher.cpp
//  Reatrix
//
//  Created by Lyn on 2019/8/15.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#include "Matcher.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

unsigned int Matcher::getHashCode() const
{
    return m_cached_hash;
}

const Matcher Matcher::allOf(const Vector<ComponentId> indices)
{
    Matcher matcher;
//    matcher.mAllOfIndices = DistinctIndices(indices);
//    matcher.CalculateHash();
//    
    return matcher;
}

//Vector<ComponentTypeId> Matcher::distinctIndices(Vector<ComponentId> indices)
//{
//    std::sort(indices.begin(), indices.end());
//    indices.erase(std::unique(indices.begin(), indices.end()), indices.end());
//
//    return indices;
//}

NAMESPACE_REATRIX_ENGINE_END
