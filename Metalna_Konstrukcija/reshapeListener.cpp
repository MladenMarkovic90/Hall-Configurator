#include "global.h"
#include "reshapeListener.h"


/* Obrada prikaza za prozor u zavisnosti od modusa */
void reshapeListener::reshape(int width, int height)
{
    windowWidth=width;
    windowHeight=height;
    if(status.modus==MODUS_3D)
        glutcpp::projection3D(width,height,45,1,5000000);
    else
        glutcpp::projection2D(width,height);
}

void reshapeListener::reshape()
{
    reshape(windowWidth,windowHeight);
}
