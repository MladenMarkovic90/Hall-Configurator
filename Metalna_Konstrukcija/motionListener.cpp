#include "global.h"
#include "motionListener.h"
#include "glutcpp/glutcpp.h"


/* Rad na osnovu pozicije misa */
void motionListener::motion(int x,int y)
{
    if(status.down && status.modus==MODUS_3D)
    {
        status.alpha=status.oldAlpha-(float)(x-status.oldX)*(M_PI/1800.0);
        status.beta=status.oldBeta+(float)(y-status.oldY)*(M_PI/1800.0);

        if(status.beta > M_PI/2.0)
            status.beta=M_PI/2.0;
        if(status.beta < -M_PI/2.0)
            status.beta=-M_PI/2.0;
        glutcpp::reDisplay();
    }
}
