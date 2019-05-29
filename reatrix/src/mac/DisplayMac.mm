//
//  DisplayMac.m
//  Reatrix
//
//  Created by Lyn on 2018/6/2.
//  Copyright © 2018 Vin-Ex. All rights reserved.
//

#include "DisplayMac.h"
#import <Cocoa/Cocoa.h>

#import <OpenGL/gl3.h>
#include <iostream>

using namespace rtx;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"



//@interface ViewController : NSViewController
//@property (weak, nonatomic) NSWindow* window;
//@property (strong, nonatomic) NSOpenGLPixelFormat* pixelFormat;
//@end
//
//@implementation ViewController;
//
//- (void)loadView
//{
//    CGSize size = self.window.contentLayoutRect.size;
//    size = [self.window contentRectForFrameRect:self.window.contentLayoutRect].size;
//
//
//    NSOpenGLView* view = [[OpenGLView alloc] initWithFrame:NSMakeRect(0, 0, size.width, size.height) pixelFormat:self.pixelFormat];
//
//    auto context = [view openGLContext];
//    [context makeCurrentContext];
//
//    self.view = view;
//}
//
//@end

namespace rtx
{
    
//    static ViewController* s_view_controller;
    static NSOpenGLContext* s_shared_context;
    
    void DisplayMac::init(int width, int height, int fps)
    {
        _target_width = width;
        _target_height = height;
        
        DisplayBase::init(width, height, fps);
        
        auto style = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskResizable;
        auto frame = [NSWindow frameRectForContentRect:NSMakeRect(0, 0, width, height) styleMask:style];
        
        NSWindow* window = [[NSWindow alloc] initWithContentRect:frame styleMask:style backing:NSBackingStoreBuffered defer:TRUE];
        window.title = @"Reatrix Demo";
        [window center];
        [window makeKeyAndOrderFront:window];
        
//        s_view_controller = [[ViewController alloc] init];
//        s_view_controller.window = window;
//        window.contentViewController = s_view_controller;
        
        _window = (void*) CFBridgingRetain(window);
    }
    
    void DisplayMac::deinit()
    {
//        s_view_controller = nil;
    }
    
    void DisplayMac::stopRender()
    {
//        auto view = (OpenGLView*) s_view_controller.view;
//        [view stopRender];
    }
    
    void* DisplayMac::getWindowBridge()
    {
        return _window;
    }
    
    void DisplayMac::bindDefaultFramebuffer()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    
    void DisplayMac::createSharedContext()
    {
//        auto view = (OpenGLView*) s_view_controller.view;
//        s_shared_context = [[NSOpenGLContext alloc] initWithFormat:s_view_controller.pixelFormat shareContext:[view openGLContext]];
//        [s_shared_context makeCurrentContext];
    }
    
    void DisplayMac::destroySharedContext()
    {
        s_shared_context = nil;
    }
    
    void DisplayMac::onWillResize(int width, int height)
    {
        
    }
    
}


#pragma GCC diagnostic pop
