#ifndef GLUT_ANIMATION_TIMER_H
#define GLUT_ANIMATION_TIMER_H


#include <GL/freeglut.h>


/* klasa koja sluzi kao Interface za animacije */
class glutAnimationTimer
{
public:
    /* konstruktor i virtualni destruktor */
    glutAnimationTimer(){}
    virtual ~glutAnimationTimer(){}

    /* getter za milisekunde */
    virtual int getMs() const {return 0;}

    /* getter za tikove po sekundi */
    virtual float getTicksPerSecond() const {return 0;}

    /* Funkcija za timer i izracunavanje */
    virtual void timer(int id) const {id=id;}
};


/* klasa za postavljanje timera za animacije */
class glutAnimationTimerInit
{
public:
    /* pokretanje animacije za glut */
    static void run(glutAnimationTimer * at)
    {
        /* brisemo stari animation timer, da ne bi bilo curenje memorije */
        delete animationTimer;

        /* upisemo novi animation timer i pokrecemo ga */
        animationTimer=at;
        glutTimerFunc(at->getMs(),onTimer,0);
    }

    /* getter za AnimationTimer */
    static glutAnimationTimer * getAnimationTimer() {return animationTimer;}

private:
    /* konstruktor i destruktor */
    glutAnimationTimerInit(){}
    ~glutAnimationTimerInit(){}

    /* glut input funkcija za rad sa vremenom koja prima milisekunde */
    static void onTimer(int id)
    {
        /* pokrecemo animation timer i pokrecemo ga ponovo za neki broj mili sekundi */
        animationTimer->timer(id);
        glutTimerFunc(animationTimer->getMs(),onTimer,0);
    }

    /* promenljiva koja cuva timer za animacije */
    static glutAnimationTimer * animationTimer;
};
/* inicijalizacija statickog pokazivaca na null */
glutAnimationTimer * glutAnimationTimerInit::animationTimer=nullptr;


#endif // GLUT_ANIMATION_TIMER_H
