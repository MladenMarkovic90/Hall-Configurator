#include "global.h"
#include "glutcpp/glutcpp.h"
#include "mouseWheelListener.h"


void mouseWheelListener::mouseWheel(int button,int state,int x,int y)
{
    button=button;
    state=state;
    x=x;
    y=y;
    if(status.modus==MODUS_3D)
    {
        if(state==-1)
        {
            status.position_x+=status.move*sin(sin(status.alpha)*cos(status.beta));
            status.position_y+=status.move*sin(status.beta);
            status.position_z+=status.move*cos(status.alpha)*cos(status.beta);
            glutcpp::reDisplay();
        }
        else if(state==1)
        {
            status.position_x-=status.move*sin(sin(status.alpha)*cos(status.beta));
            status.position_y-=status.move*sin(status.beta);
            status.position_z-=status.move*cos(status.alpha)*cos(status.beta);
            glutcpp::reDisplay();
        }
    }
    return;
}

