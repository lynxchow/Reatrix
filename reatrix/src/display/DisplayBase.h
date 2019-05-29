//
//  DeviceBase.h
//  Reatrix
//
//  Created by Lyn on 2018/6/2.
//  Copyright © 2018 Vin-Ex. All rights reserved.
//

#ifndef _RTX_DISPLAY_DISPLAY_BASE_H_
#define _RTX_DISPLAY_DISPLAY_BASE_H_


namespace rtx
{
    class DisplayBase
    {
    public:
        void init(int width, int height, int fps);
        void processSystemEvents();
        int getWidth() const { return _width; }
        int getWeight() const { return _height; }
        int getPreferredFps() const { return _fps; }
        
    protected:
        int _width;
        int _height;
        int _fps;
    };
    
}

#endif /* DisplayBase_h */
