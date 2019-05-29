//
//  ViewController.m
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/29.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#import "ViewController.h"
#import "Reatrix.h"

@interface ViewController()
{
    Reatrix *_rtx;
}
@end

@implementation ViewController

- (void)loadView
{
    NSWindow *window = [[NSApplication sharedApplication] keyWindow];
    CGSize size = [window contentRectForFrameRect:window.contentLayoutRect].size;
    _rtx = [[Reatrix alloc] initWithFrame:NSMakeRect(0, 0, size.width, size.height)];
    self.view = _rtx.view;
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
