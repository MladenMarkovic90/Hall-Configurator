#ifndef MOUSE_LISTENER_H
#define MOUSE_LISTENER_H


#include "glutcpp/glutMouseListener.h"
#include "animationStatus.h"
#include "konstrukcija.h"


/* klasa za rad sa klikom misa */
class mouseListener : public glutMouseListener
{
public:
    /* konstruktor i destruktor */
    mouseListener(konstrukcija & k,animationStatus & s):status(s),metalniObjekat(k){}
    ~mouseListener(){}

    /* Desavanje na osnovu klika misa */
    virtual void mouse(int button,int state,int x,int y);

private:
    animationStatus & status;
    konstrukcija & metalniObjekat;
};

#include "mouseListener.cpp"


#endif // MOUSE_LISTENER_H
