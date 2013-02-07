/* 
 * File:   Timer.h
 * Author: jamie
 *
 * Created on 17 December 2011, 17:26
 */

#ifndef TIMER_H
#define	TIMER_H

#include <SDL/SDL_timer.h>

class Timer 
{
public:
    void Start();
    void Stop();
    void Pause();
    void Resume();
    
    bool IsStarted();
    bool IsPaused();
    
    Uint32 GetTicks();
    
    Timer();
    Timer(const Timer& orig);
    virtual ~Timer();
private:
    Uint32 _startTick;
    Uint32 _pausedTick;
    bool _started;
    bool _paused;
};

#endif	/* TIMER_H */

