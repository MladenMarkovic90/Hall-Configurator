#include "global.h"
#include "glutcpp/glutcpp.h"
#include "glutcpp/glutReshapeListener.h"
#include "mouseListener.h"
#include "konstrukcija.h"


/* Desavanje na osnovu klika misa */
void mouseListener::mouse(int button,int state,int x,int y)
{

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        status.oldX=x;
        status.oldY=y;
        status.oldAlpha=status.alpha;
        status.oldBeta=status.beta;

        status.down=true;
    }

    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
        status.down=false;
    }


    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN && status.modus==MODUS_STUBOVI)
    {
        int height=glutReshapeListenerInit::getReshapeListener()->getWindowHeight();
        int width=glutReshapeListenerInit::getReshapeListener()->getWindowWidth();

        double curX=(double)x/width;
        double curY=(double)y/height;

        curX=2*curX-1.0;
        curY=1.0-2*curY;

        int size;


        //std::cout<<"curX: "<<curX<< " curY: "<<curY<<std::endl;



        size=metalniObjekat.Materijal.StuboviNapred.size();

        for(int i=0;i<size;i++)
            if(metalniObjekat.Materijal.StuboviNapred[i].kolizija(curX,curY))
                return;

        size=metalniObjekat.Materijal.StuboviNazad.size();

        for(int i=0;i<size;i++)
            if(metalniObjekat.Materijal.StuboviNazad[i].kolizija(curX,curY))
                return;

        size=metalniObjekat.Materijal.StuboviLevo.size();
        for(int i=0;i<size;i++)
        {
            if(metalniObjekat.Materijal.StuboviLevo[i].kolizija(curX,curY))
                return;
            if(metalniObjekat.Materijal.StuboviDesno[i].kolizija(curX,curY))
                return;
        }

        size=metalniObjekat.Materijal.IspunaLevo.size();

        for(int i=0;i<size;i++)
        {
            //metalniObjekat.Materijal.IspunaLevo[i].ispisi("IspunaLevo: ");
            if(metalniObjekat.Materijal.IspunaLevo[i].kolizija(curX,curY))
                return;
            if(metalniObjekat.Materijal.IspunaDesno[i].kolizija(curX,curY))
                return;
        }



    }
}

