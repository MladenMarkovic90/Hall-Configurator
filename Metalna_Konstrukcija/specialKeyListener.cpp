#include "global.h"
#include "animationStatus.h"


/* postavljanje flagova ili radnja za specijalne karaktere koja su stisnuta na tastaturi */
void SpecialKeyListener::keyDown(int key, int x, int y) const
{
    x=x;y=y;
    if(key==GLUT_KEY_F12)
        glutcpp::fullScreenToggle();

}


/* skidanje flagova za specijalne karaktere koja su stisnuta na tastaturi */
void SpecialKeyListener::keyUp(int key, int x, int y) const
{
    x=x;y=y;key=key;
}
