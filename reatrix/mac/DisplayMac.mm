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

const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char *fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

static bool s_init = false;
static unsigned int VBO, VAO, EBO;
static int shaderProgram;

- (CVReturn)drawFrame:(const CVTimeStamp*)outputTime
{
    [[self openGLContext] makeCurrentContext];
    // test OpenGL draw
    if (s_init == false)
    {
        int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        
        int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // link shaders
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        
        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
            0.5f,  0.5f, 0.0f,  // top right
            0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
            -0.5f,  0.5f, 0.0f   // top left
        };
        unsigned int indices[] = {  // note that we start from 0!
            0, 1, 3,  // first Triangle
            1, 2, 3   // second Triangle
        };
        
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        
        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
    
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        
        glBindVertexArray(0);
        
        s_init = true;
    }
    
    glViewport(0, 0, 1280, 720);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    [[self openGLContext] flushBuffer];
    return kCVReturnSuccess;
}

- (void)stopRender
{
    stop = true;
    
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    
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

@interface ViewController : NSViewController
@property (weak, nonatomic) NSWindow* window;
@property (strong, nonatomic) NSOpenGLPixelFormat* pixelFormat;
@end

@implementation ViewController;

- (void)loadView
{
    CGSize size = self.window.contentLayoutRect.size;
    size = [self.window contentRectForFrameRect:self.window.contentLayoutRect].size;
    
    const uint32_t attrs[] =
    {
        NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
        NSOpenGLPFADoubleBuffer,
        NSOpenGLPFAColorSize, 24,
        NSOpenGLPFADepthSize, 24,
        0
    };
    self.pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
    NSOpenGLView* view = [[OpenGLView alloc] initWithFrame:NSMakeRect(0, 0, size.width, size.height) pixelFormat:self.pixelFormat];
    
    auto context = [view openGLContext];
    [context makeCurrentContext];
    
    self.view = view;
}

@end

namespace rtx
{
    
    static ViewController* s_view_controller;
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
        
        s_view_controller = [[ViewController alloc] init];
        s_view_controller.window = window;
        window.contentViewController = s_view_controller;
        
        _window = (void*) CFBridgingRetain(window);
    }
    
    void DisplayMac::deinit()
    {
        s_view_controller = nil;
    }
    
    void DisplayMac::stopRender()
    {
        auto view = (OpenGLView*) s_view_controller.view;
        [view stopRender];
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
        auto view = (OpenGLView*) s_view_controller.view;
        s_shared_context = [[NSOpenGLContext alloc] initWithFormat:s_view_controller.pixelFormat shareContext:[view openGLContext]];
        [s_shared_context makeCurrentContext];
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
