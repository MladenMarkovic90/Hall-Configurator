#ifndef GLUT_MOUSE_WHEEL_LISTENER_H
#define GLUT_MOUSE_WHEEL_LISTENER_H


#include <GL/freeglut.h>


class glutMouseWheelListener
{
public:
    glutMouseWheelListener(){}
    virtual ~glutMouseWheelListener(){}

    virtual void mouseWheel(int button,int state,int x,int y){button=button;state=state;x=x;y=y;}
};


class glutMouseWheelListenerInit
{
public:
    static void run(glutMouseWheelListener * ml)
    {
        delete mouseWheelListener;

        mouseWheelListener=ml;
        glutMouseWheelFunc(onMouseWheel);
    }

    static glutMouseWheelListener * getMouseWheelListener() {return mouseWheelListener;}

private:
    static glutMouseWheelListener * mouseWheelListener;

    glutMouseWheelListenerInit(){}
    ~glutMouseWheelListenerInit(){}

    static void onMouseWheel(int button,int state,int x,int y) {mouseWheelListener->mouseWheel(button,state,x,y);}
};
glutMouseWheelListener * glutMouseWheelListenerInit::mouseWheelListener=nullptr;


#endif // GLUT_MOUSE_WHEEL_LISTENER_H
