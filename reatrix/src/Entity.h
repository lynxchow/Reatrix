//
//  Entity.h
//  Reatrix
//
//  Created by Lyn on 2019/7/11.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#ifndef _RTX_ENTITY_H_
#define _RTX_ENTITY_H_

#include "Object.h"
#include "Component.h"

NAMESPACE_RTX_BEGIN

class Entity : public Object
{
public:
    static SharedPtr<Entity> create();
    virtual ~Entity();
    
    static void destroy(SharedPtr<Entity>& entity);
    
    template <class T, typename ...Params> SharedPtr<T> addComponent(Params... args);
    template <class T> SharedPtr<T> getComponent() const;
    
    void removeComponent(const SharedPtr<Component>& component);
    
    bool isEnable() const { return _is_enable; }
    void setEnable(bool enable) { _is_enable = enable; }
    
private:
    Entity();
    
    bool _is_enable;
};

NAMESPACE_RTX_END


#endif /* Entity_h */
