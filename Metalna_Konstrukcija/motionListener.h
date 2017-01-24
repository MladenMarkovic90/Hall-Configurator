#ifndef MOTION_LISTENER_H
#define MOTION_LISTENER_H


#include "glutcpp/glutMotionListener.h"
#include "animationStatus.h"
#include "konstrukcija.h"


/* klasa za rad sa pozicijom misa */
class motionListener : public glutMotionListener
{
public:
    /* konstruktor i destruktor */
    motionListener(animationStatus & s):status(s){}
    ~motionListener(){}

    /* Rad na osnovu pozicije misa */
    virtual void motion(int x, int y);

private:
    animationStatus & status;
};

#include "motionListener.cpp"


#endif // MOTION_LISTENER_H
