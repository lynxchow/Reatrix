//
//  Timer.cpp
//  Reatrix
//
//  Created by Lyn on 2019/6/2.
//

#include "Timer.h"
#include <time.h>
#include <sys/time.h>

NAMESPACE_REATRIX_ENGINE_BEGIN

long long Timer::s_time_startup = 0;
float Timer::s_time_delta = 0;
float Timer::s_time_record = -1;
int Timer::s_frame_count = 0;
int Timer::s_frame_record;
float Timer::s_time = 0;
int Timer::s_fps;

long long Timer::getTimeMS()
{
    long long t;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    t = tv.tv_sec;
    t *= 1000;
    t += tv.tv_usec / 1000;
    
    return t;
}

float Timer::getRealTimeSinceStartup()
{
    if (s_time_startup == 0)
    {
        s_time_startup = getTimeMS();
    }
    
    long long Timer = getTimeMS() - s_time_startup;
    
    return Timer / 1000.0f;
}

void Timer::update()
{
    float time = Timer::getRealTimeSinceStartup();
    Timer::s_time_delta = time - Timer::s_time;
    Timer::s_time = time;
    
    if (Timer::s_time_record < 0)
    {
        Timer::s_time_record = Timer::getRealTimeSinceStartup();
        Timer::s_frame_record = Timer::getFrameCount();
    }
    
    int frame = Timer::getFrameCount();
    if (time - Timer::s_time_record >= 1)
    {
        Timer::s_fps = frame - Timer::s_frame_record;
        Timer::s_time_record = time;
        Timer::s_frame_record = frame;
    }
    
    Timer::s_frame_count++;
}

NAMESPACE_REATRIX_ENGINE_END
