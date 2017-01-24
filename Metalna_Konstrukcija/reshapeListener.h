#ifndef RESHAPE_LISTENER_H
#define RESHAPE_LISTENER_H


#include "glutcpp/glutReshapeListener.h"
#include "animationStatus.h"


/* klasa za rad sa prozorom */
class reshapeListener : public glutReshapeListener
{
public:
    /* konstruktor i destruktor */
    reshapeListener(int width,int height,animationStatus & s):windowWidth(width),windowHeight(height),status(s){}
    ~reshapeListener(){}

    /* Obrada prikaza za prozor u zavisnosti od modusa */
    virtual void reshape(int width,int height);

    /* pozivanje obrade ponovo */
    virtual void reshape();

    /* getter za sirinu i visinu prozora */
    virtual int getWindowWidth() const {return windowWidth;}
    virtual int getWindowHeight() const {return windowHeight;}

private:
    /* promenljive za sirinu i visinu prozora */
    int windowWidth;
    int windowHeight;

    /* promenljiva koja cuva status prikaza */
    animationStatus & status;
};


#include "reshapeListener.cpp"


#endif // RESHAPE_LISTENER_H
