#ifndef DISPLAY_H
#define DISPLAY_H


#include "glutcpp/glutDisplay.h"
#include "animationStatus.h"
#include "konstrukcija.h"


/* klasa koja ima sadrzaj prozora */
class Display : public glutDisplay
{
public:
    /* konstruktor i destruktor */
    Display(konstrukcija & k,animationStatus & s):metalniObjekat(k),status(s){}
    ~Display(){}

    /* prikazuje sadrzaj prozora */
    void show();

    void crtezMreza();

    void crtezStubovi();

    void objekat();

    void materijal();

private:
    /* promenljiva koja cuva status prikaza */
    konstrukcija & metalniObjekat;
    animationStatus & status;
};


#include "display.cpp"


#endif // DISPLAY_H
