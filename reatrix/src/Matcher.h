//
//  Matcher.h
//  Reatrix
//
//  Created by Lyn on 2019/8/15.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_MATCHER_H_
#define _RTX_MATCHER_H_

#include "Common.h"
#include "container/Map.h"
#include "container/Vector.h"
#include "component/Component.h"

NAMESPACE_REATRIX_ENGINE_BEGIN

class Matcher
{
public:
    Matcher() {}
    ~Matcher() {}
    static const Matcher allOf(const Vector<ComponentId> indices);
    unsigned int getHashCode() const;
//    Vector<ComponentTypeId> distinctIndices(Vector<ComponentId> indices);
protected:
    Vector<ComponentTypeId> m_all_of_indices;
    
private:
    unsigned int m_cached_hash = 0;
};

NAMESPACE_REATRIX_ENGINE_END

namespace std
{
template <>
struct hash<rtx::Matcher>
{
    std::size_t operator()(const rtx::Matcher& matcher) const
    {
        return hash<unsigned int>()(matcher.getHashCode());
    }
};
}

namespace
{
#define FUNC_1(MODIFIER, X) MODIFIER(X)
#define FUNC_2(MODIFIER, X, ...) MODIFIER(X), FUNC_1(MODIFIER, __VA_ARGS__)
#define FUNC_3(MODIFIER, X, ...) MODIFIER(X), FUNC_2(MODIFIER, __VA_ARGS__)
#define FUNC_4(MODIFIER, X, ...) MODIFIER(X), FUNC_3(MODIFIER, __VA_ARGS__)
#define FUNC_5(MODIFIER, X, ...) MODIFIER(X), FUNC_4(MODIFIER, __VA_ARGS__)
#define FUNC_6(MODIFIER, X, ...) MODIFIER(X), FUNC_5(MODIFIER, __VA_ARGS__)
#define GET_MACRO(_1, _2, _3, _4, _5, _6, NAME,...) NAME
#define FOR_EACH(MODIFIER,...) GET_MACRO(__VA_ARGS__, FUNC_6, FUNC_5, FUNC_4, FUNC_3, FUNC_2, FUNC_1)(MODIFIER, __VA_ARGS__)
    
#define COMPONENT_GET_TYPE_ID(COMPONENT_CLASS) rtx::ComponentTypeId::get<COMPONENT_CLASS>()
#define Matcher_allOf(...) (rtx::Matcher)rtx::Matcher::allOf(Vector<rtx::ComponentId>({ FOR_EACH(COMPONENT_GET_TYPE_ID, __VA_ARGS__) }))
}
#endif /* Matcher_h */
