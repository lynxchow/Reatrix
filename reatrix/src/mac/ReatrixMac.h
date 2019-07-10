//
//  ReatrixMac.h
//  ReatrixDemo
//
//  Created by Lyn Chow on 2019/5/29.
//  Copyright © 2019 Lyn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

NS_ASSUME_NONNULL_BEGIN

namespace rtx
{
    class Scene;
};

@interface ReatrixMac : NSObject
- (instancetype)initWithFrame:(NSRect)frameRect;
- (NSView *)view;
- (BOOL)loadScene:(rtx::Scene *)scene;
- (void)destroy;
@end

NS_ASSUME_NONNULL_END
