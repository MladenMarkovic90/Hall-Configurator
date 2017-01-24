#ifndef GLUT_MOTION_LISTENER_H
#define GLUT_MOTION_LISTENER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za osluskivac pozicije misa */
class glutMotionListener
{
public:
    /* konstruktor i virtualni destruktor */
    glutMotionListener(){}
    virtual ~glutMotionListener(){}

    /* Rad na osnovu pozicije misa */
    virtual void motion(int x, int y) {x=x;y=y;}
};


/* klasa za postavljanje osluskivaca za poziciju misa u glutu */
class glutMotionListenerInit
{
public:
    /* pokretanje glut osluskivac za poziciju misa */
    static void run(glutMotionListener * ml)
    {
        /* brisemo stari motion listener, da ne bi bilo curenje memorije */
        delete motionListener;

        /* upisemo novi motion listener i pokrecemo ga */
        motionListener=ml;
        glutMotionFunc(onMotion);
    }

    /* ukoliko je potrebno, moze da se uzme pokazivac na motionListener */
    static glutMotionListener * getMotionListener() {return motionListener;}

private:
    /* promenljiva koja cuva osluskivac za poziciju misa */
    static glutMotionListener * motionListener;

    /* konstruktor i destruktor */
    glutMotionListenerInit(){}
    ~glutMotionListenerInit(){}

    /* glut input funkcija za citanje pozicije misa */
    static void onMotion(int x,int y) {motionListener->motion(x,y);}
};
/* inicijalizacija statickog pokazivaca na null */
glutMotionListener * glutMotionListenerInit::motionListener=nullptr;


#endif // GLUT_MOTION_LISTENER_H
