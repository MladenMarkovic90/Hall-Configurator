#ifndef MOUSE_WHEEL_LISTENER_H
#define MOUSE_WHEEL_LISTENER_H


#include "glutcpp/glutMouseWheelListener.h"
#include "animationStatus.h"


class mouseWheelListener : public glutMouseWheelListener
{
public:
    mouseWheelListener(animationStatus & s):status(s){}
    ~mouseWheelListener(){}

    virtual void mouseWheel(int button,int state,int x,int y);

private:
    animationStatus & status;
};

#include "mouseWheelListener.cpp"


#endif // MOUSE_WHEEL_LISTENER_H
