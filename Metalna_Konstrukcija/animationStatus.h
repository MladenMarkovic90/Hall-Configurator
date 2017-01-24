#ifndef STATUS_H
#define STATUS_H


#include "global.h"


/* klasa koja sluzi da azurira status animacije */
class animationStatus
{
public:
    animationStatus(){}
    ~animationStatus(){}

    int modus=MODUS_2D;

    float alpha=0;
    float beta=0;

    float move=500;

    float position_x=0;
    float position_y=0;
    float position_z=10000;

    int oldX;
    int oldY;
    float oldAlpha;
    float oldBeta;

    bool down=false;
};


#endif // STATUS_H
