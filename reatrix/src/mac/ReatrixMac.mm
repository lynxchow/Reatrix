//
//  Reatrix.m
//  ReatrixDemo
//
//  Created by Lyn Chow on 2019/5/29.
//  Copyright © 2019 Lyn. All rights reserved.
//

#import "ReatrixMac.h"
#import <OpenGL/gl3.h>
#include <iostream>
#include "Reatrix.h"
#include "Scene.h"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

@interface OpenGLView : NSOpenGLView
{
    CVDisplayLinkRef displayLink;
    bool stop;
}
@end

@implementation OpenGLView;

- (instancetype)initWithFrame:(NSRect)frameRect pixelFormat:(NSOpenGLPixelFormat *)format
{
    self = [super initWithFrame:frameRect pixelFormat:format];
    NSTrackingArea* area = [[NSTrackingArea alloc] initWithRect:self.bounds
                                                        options:NSTrackingMouseMoved | NSTrackingActiveInKeyWindow
                                                          owner:self
                                                       userInfo:nil];
    [self addTrackingArea:area];
    return self;
}

- (void)prepareOpenGL
{
    stop = false;
    
    GLint swapInt = 1;
    [[self openGLContext] setValues:&swapInt forParameter:NSOpenGLContextParameterSwapInterval];
    CVDisplayLinkCreateWithActiveCGDisplays(&displayLink);
    CVDisplayLinkSetOutputCallback(displayLink, &outputFrame, (__bridge void * _Nullable)(self));
    CGLContextObj cglContext = [[self openGLContext] CGLContextObj];
    CGLPixelFormatObj cglPixelFormat = [[self pixelFormat] CGLPixelFormatObj];
    CVDisplayLinkSetCurrentCGDisplayFromOpenGLContext(displayLink, cglContext, cglPixelFormat);
    CVDisplayLinkStart(displayLink);
}

static CVReturn outputFrame(CVDisplayLinkRef displayLink, const CVTimeStamp* now, const CVTimeStamp* outputTime,
                            CVOptionFlags flagsIn, CVOptionFlags* flagsOut, void* displayLinkContext)
{
    CVReturn result = [(__bridge OpenGLView*)displayLinkContext drawFrame:outputTime];
    return result;
}



- (CVReturn)drawFrame:(const CVTimeStamp *)outputTime
{
    [[self openGLContext] makeCurrentContext];
    
    rtx::Reatrix::instance()->update();
    
    [[self openGLContext] flushBuffer];
    return kCVReturnSuccess;
}

- (void)stopRender
{
    stop = true;
    
    CVDisplayLinkStop(displayLink);
    CVDisplayLinkRelease(displayLink);
}

- (void)mouseDown:(NSEvent *)event
{
    
}

- (void)mouseUp:(NSEvent *)event
{
    
}

- (void)mouseMoved:(NSEvent *)event
{
    
}

- (void)mouseDragged:(NSEvent *)event
{
    
}

@end

@interface ReatrixMac()
{
    OpenGLView *_view;
}
@end

@implementation ReatrixMac

- (instancetype)initWithFrame:(NSRect)frameRect
{
    self = [super init];
    if (self)
    {
        rtx::Reatrix::instance()->init();
        const uint32_t attrs[] =
        {
            NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
            NSOpenGLPFADoubleBuffer,
            NSOpenGLPFAColorSize, 24,
            NSOpenGLPFADepthSize, 24,
            0
        };
        OpenGLView *view = [[OpenGLView alloc] initWithFrame:frameRect pixelFormat:[[NSOpenGLPixelFormat alloc] initWithAttributes:attrs]];
        [[view openGLContext] makeCurrentContext];
        _view = view;
    }
    
    return self;
}

- (NSView *)view
{
    return _view;
}

- (BOOL)loadScene:(rtx::Scene *)scene
{
    rtx::Reatrix::instance()->loadScene(scene);
    return YES;
}

- (void)destroy
{
    rtx::Reatrix::instance()->destroy();
}
@end

#pragma GCC diagnostic pop
