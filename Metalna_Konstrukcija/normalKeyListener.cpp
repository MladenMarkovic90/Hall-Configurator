#include "global.h"
#include "glutcpp/glutReshapeListener.h"
#include "glutcpp/glutcpp.h"
#include "animationStatus.h"
#include "normalKeyListener.h"


/* postavljanje flagova ili radnja za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyDown(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;
    switch(normalKey)
    {
        case '1':
            status.modus=MODUS_2D;
            glutReshapeListenerInit::getReshapeListener()->reshape();
            glutcpp::reDisplay();
        break;

        case '2':
            status.modus=MODUS_STUBOVI;
            glutReshapeListenerInit::getReshapeListener()->reshape();
            glutcpp::reDisplay();
        break;

        case '3':
            status.modus=MODUS_3D;
            glutReshapeListenerInit::getReshapeListener()->reshape();
            glutcpp::reDisplay();
        break;

        case '4':
            status.modus=MODUS_MATERIJAL;
            glutReshapeListenerInit::getReshapeListener()->reshape();
            glutcpp::reDisplay();
        break;
    }

    if(status.modus==MODUS_3D)
        if(normalKey=='r')
        {
                status.alpha=0;
                status.beta=0;
                status.position_x=0;
                status.position_y=0;
                status.position_z=5000;
                glutcpp::reDisplay();
        }
}


/* skidanje flagova za karaktere koja su stisnuta na tastaturi */
void normalKeyListener::keyUp(unsigned char normalKey, int x, int y) const
{
    x=x;y=y;normalKey=normalKey;
}
