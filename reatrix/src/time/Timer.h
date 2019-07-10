//
//  Timer.h
//  Reatrix
//
//  Created by Lyn on 2019/6/2.
//

#ifndef _RTX_TIME_TIMER_H_
#define _RTX_TIME_TIMER_H_

namespace rtx
{
    class Timer
    {
    public:
        static int getFrameCount() { return s_frame_count; }
        static float getTime() { return s_time; }
        static float getRealTimeSinceStartup();
        static float getDeltaTime() { return s_time_delta; }
        static long long getTimeMS();
        static int getFPS() { return s_fps; }
        static void update();
        
    private:
        static long long s_time_startup;
        static float s_time_delta;
        static float s_time_record;
        static float s_time;
        static int s_frame_count;
        static int s_frame_record;
        static int s_fps;
    };
}

#endif /* Timer_h */
