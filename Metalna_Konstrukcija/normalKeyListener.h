#ifndef NORMAL_KEY_LISTENER_H
#define NORMAL_KEY_LISTENER_H


#include "glutcpp/glutNormalKeyListener.h"
#include "animationStatus.h"
#include "konstrukcija.h"


/* Klasa za rad sa obicnim karakterima */
class normalKeyListener : public glutNormalKeyListener
{
public:
    /* konstruktor i destruktor */
    normalKeyListener(konstrukcija & k,animationStatus & s):metalniObjekat(k),status(s){}
    ~normalKeyListener(){}

    /* postavljanje flagova ili radnja za karaktere koja su stisnuta na tastaturi */
    void keyDown(unsigned char normalKey,int x,int y) const;

    /* skidanje flagova za karaktere koja su stisnuta na tastaturi */
    void keyUp(unsigned char normalKey,int x,int y) const;

private:
    konstrukcija & metalniObjekat;

    /* promenljiva koja cuva status prikaza */
    animationStatus & status;
};


#include "normalKeyListener.cpp"


#endif // NORMAL_KEY_LISTENER_H
