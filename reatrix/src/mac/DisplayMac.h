//
//  DisplayMac.h
//  Reatrix
//
//  Created by Lyn on 2018/6/2.
//  Copyright © 2018 Vin-Ex. All rights reserved.
//

#ifndef _RTX_MAC_DISPLAY_MAC_H_
#define _RTX_MAC_DISPLAY_MAC_H_

#include "DisplayBase.h"

namespace rtx {
    
    class DisplayMac : public DisplayBase {
    public:
        void init(int width, int height, int fps);
        void deinit();
        void* getWindowBridge();
        void bindDefaultFramebuffer();
        void keepScreenOn(bool enable) { }
        void onWillResize(int width, int height);
        
        int getTargetWidth() const { return _target_width; }
        int getTargetHeight() const { return _target_height; }
        void stopRender();
        
        void createSharedContext();
        void destroySharedContext();
        
    private:
        void *_window;
        int _target_width;
        int _target_height;
    };
    
}

#endif
