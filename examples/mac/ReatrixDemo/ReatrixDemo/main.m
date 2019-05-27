//
//  main.m
//  ReatrixDemo
//
//  Created by Lyn on 2019/5/24.
//  Copyright © 2019 Vin-Ex. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"

int main(int argc, const char * argv[]) {
    NSApplication* app = [NSApplication sharedApplication];
    AppDelegate* delegate = [[AppDelegate alloc] init];
    app.delegate = delegate;
    [app run];
    return 0;
}
