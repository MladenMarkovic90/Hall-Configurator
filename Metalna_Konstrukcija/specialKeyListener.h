#ifndef SPECIAL_KEY_LISTENER_H
#define SPECIAL_KEY_LISTENER_H


#include "glutcpp/glutSpecialKeyListener.h"
#include <vector>
#include "konstrukcija.h"
#include "animationStatus.h"


/* klasa za rad sa specijalnim karakterima sa tastature */
class SpecialKeyListener : public glutSpecialKeyListener
{
public:
    /* konstruktor i destruktor */
    SpecialKeyListener(konstrukcija & k,animationStatus & s):metalniObjekat(k),status(s){}
    ~SpecialKeyListener(){}

    /* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
    void keyDown(int key,int x,int y) const;

    /* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
    void keyUp(int key,int x,int y) const;

private:

    konstrukcija & metalniObjekat;

    /* promenljiva koja cuva status prikaza */
    animationStatus & status;
};


#include "specialKeyListener.cpp"


#endif // SPECIAL_KEY_LISTENER_H
