//
//  AppDelegate.m
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/24.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#import "AppDelegate.h"
#import "DisplayMac.h"

@interface AppDelegate ()<NSApplicationDelegate, NSWindowDelegate>
{
    rtx::DisplayMac *_display;
}
@property (strong, nonatomic) NSWindow* window;
@end

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Insert code here to initialize your application
    _display = new rtx::DisplayMac();
    _display->init(1280, 720, 60);
    
    self.window = (__bridge_transfer NSWindow*) _display->getWindowBridge();
    self.window.delegate = self;
}


- (void)applicationWillTerminate:(NSNotification *)notification {
    // Insert code here to tear down your application
    _display->stopRender();
    delete _display;
    _display = nullptr;
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender {
    return YES;
}

@end
