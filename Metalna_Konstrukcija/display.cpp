#include <iostream>
#include "global.h"
#include <cmath>
#include "glutcpp/glutReshapeListener.h"
#include "glutcpp/glutAnimationTimer.h"
#include "glutcpp/glutcpp.h"
#include "display.h"
#include "mreza.h"
#include <GL/freeglut.h>
#include "delovi.h"
#include "delovi2d.h"
#include <vector>
#include "konstrukcija.h"
#include "metalniDeo.h"
#include "materijal.h"


/* prikazuje sadrzaj prozora */
void Display::show(void)
{
    if(status.modus==MODUS_2D)
        Display::crtezMreza();
    else if(status.modus==MODUS_STUBOVI)
        Display::crtezStubovi();
    else if(status.modus==MODUS_3D)
        Display::objekat();
    else if(status.modus==MODUS_MATERIJAL)
        Display::materijal();
     glutcpp::swapBuffers();

}


/* prikazuje meni */
void Display::crtezMreza()
{
    glutcpp::light(GL_OFF);
    glutcpp::modelView2D();


    double MUL=0.6;

    double maxSirina=metalniObjekat.maxSirina * MUL;
    double maxVisina=metalniObjekat.maxVisina * MUL;

    metalniObjekat.Materijal.kosnici.duzina=0;
    metalniObjekat.Materijal.vertikale.duzina=0;

    double X;
    double Y;

    X=-0.8;
    Y=-0.9;

    /* LEVO */
    delovi2D::ceoStub(X , Y , maxSirina , maxVisina , metalniObjekat);


    X = -0.8 + metalniObjekat.sirina / maxSirina;
    X = X - metalniObjekat.stub.sirina / maxSirina;

    Y = -0.9;


    /* DESNO */
    delovi2D::ceoStub(X , Y , maxSirina , maxVisina , metalniObjekat);


    X = -0.8 + metalniObjekat.donjaAnkerPloca.sirina / (2*maxSirina);
    X = X - metalniObjekat.stub.sirina / (2*maxSirina);
    X = X - metalniObjekat.strehaLevo.duzina / maxSirina;

    Y = -0.9 + metalniObjekat.visina / maxVisina;


    delovi2D::ceoDonjiPojas(X , Y , maxSirina , maxVisina , metalniObjekat);


    X = X + metalniObjekat.strehaLevo.duzina / maxSirina + metalniObjekat.binderDonjiLeviPojas.duzina / maxSirina;

    Y = Y + metalniObjekat.strehaLevo.visina / maxVisina;


    delovi2D::sveGrede(X , Y , maxSirina , maxVisina , metalniObjekat);


    delovi2D::ceoGornjiPojas(X , Y , maxSirina , maxVisina , metalniObjekat);



    delovi2D::ispisMaterijal1(-0.25,-0.9,metalniObjekat);

}


void Display::crtezStubovi()
{
    glutcpp::light(GL_OFF);
    glutcpp::modelView2D();

    double tmpY=1.8;
    double tmpX=1.8;

    double deoY=0;
    double deoX=0;

    int num=metalniObjekat.Materijal.StuboviLevo.size();

    deoY=tmpY/(2*num-1);

    double oldX=-0.9;
    double oldY=0.9;

    for(int i=0;i<num;i++)
    {
        metalniObjekat.Materijal.StuboviLevo[i].podaci(oldX,oldY,oldX+0.1,oldY-deoY);
        /*metalniObjekat.Materijal.StuboviLevo[i].X1=oldX;
        metalniObjekat.Materijal.StuboviLevo[i].X2=oldX+0.1;
        metalniObjekat.Materijal.StuboviLevo[i].Y1=oldY;
        metalniObjekat.Materijal.StuboviLevo[i].Y2=oldY-deoY;*/
        metalniObjekat.Materijal.StuboviLevo[i].crtaj();

        oldY-=deoY;

        if(i<num-1)
        {
            metalniObjekat.Materijal.IspunaLevo[i].podaci(oldX,oldY,oldX+0.05,oldY-deoY);
            /*metalniObjekat.Materijal.IspunaLevo[i].X1=oldX;
            metalniObjekat.Materijal.IspunaLevo[i].X2=oldX+0.05;
            metalniObjekat.Materijal.IspunaLevo[i].Y1=oldY;
            metalniObjekat.Materijal.IspunaLevo[i].Y2=oldY-deoY;*/
            metalniObjekat.Materijal.IspunaLevo[i].crtaj();
            oldY-=deoY;
        }
    }


    num=metalniObjekat.Materijal.StuboviDesno.size();

    oldX=0.9;
    oldY=0.9;

    for(int i=0;i<num;i++)
    {
        metalniObjekat.Materijal.StuboviDesno[i].podaci(oldX-0.1,oldY,oldX,oldY-deoY);
        /*metalniObjekat.Materijal.StuboviDesno[i].X1=oldX-0.1;
        metalniObjekat.Materijal.StuboviDesno[i].X2=oldX;
        metalniObjekat.Materijal.StuboviDesno[i].Y1=oldY;
        metalniObjekat.Materijal.StuboviDesno[i].Y2=oldY-deoY;*/
        metalniObjekat.Materijal.StuboviDesno[i].crtaj();

        oldY-=deoY;

        if(i<num-1)
        {
            metalniObjekat.Materijal.IspunaDesno[i].podaci(oldX-0.05,oldY,oldX,oldY-deoY);
            /*metalniObjekat.Materijal.IspunaDesno[i].X1=oldX-0.05;
            metalniObjekat.Materijal.IspunaDesno[i].X2=oldX;
            metalniObjekat.Materijal.IspunaDesno[i].Y1=oldY;
            metalniObjekat.Materijal.IspunaDesno[i].Y2=oldY-deoY;*/
            metalniObjekat.Materijal.IspunaDesno[i].crtaj();
            oldY-=deoY;
        }
    }


    num=metalniObjekat.Materijal.StuboviNapred.size();

    tmpX=1.6;

    deoX=tmpX/(num+1);

    oldX=-0.8+deoX;
    oldY=-0.9;

    for(int i=0;i<num;i++)
    {
        metalniObjekat.Materijal.StuboviNapred[i].podaci(oldX-0.05,oldY+deoY,oldX+0.05,oldY);
        /*metalniObjekat.Materijal.StuboviNapred[i].X1=oldX-0.05;
        metalniObjekat.Materijal.StuboviNapred[i].X2=oldX+0.05;
        metalniObjekat.Materijal.StuboviNapred[i].Y1=oldY+deoY;
        metalniObjekat.Materijal.StuboviNapred[i].Y2=oldY;*/
        metalniObjekat.Materijal.StuboviNapred[i].crtaj();
        oldX+=deoX;
    }


    num=metalniObjekat.Materijal.StuboviNazad.size();

    tmpX=1.6;

    deoX=tmpX/(double)(num+1);

    oldX=-0.8+deoX;
    oldY=0.9;

    for(int i=0;i<num;i++)
    {
        metalniObjekat.Materijal.StuboviNazad[i].podaci(oldX-0.05,oldY,oldX+0.05,oldY-deoY);
        /*metalniObjekat.Materijal.StuboviNazad[i].X1=oldX-0.05;
        metalniObjekat.Materijal.StuboviNazad[i].X2=oldX+0.05;
        metalniObjekat.Materijal.StuboviNazad[i].Y1=oldY;
        metalniObjekat.Materijal.StuboviNazad[i].Y2=oldY-deoY;*/
        metalniObjekat.Materijal.StuboviNazad[i].crtaj();
        oldX+=deoX;
    }




}

void Display::objekat()
{


    glutcpp::modelView3D(sin(status.alpha)*cos(status.beta),sin(status.beta),cos(status.alpha)*cos(status.beta));

    glutcpp::light(GL_ON);
    glutcpp::lightPosition(0,0,0,1);

    glutcpp::color(0.5,0.5,0.5,1.0);

    glutcpp::translate(-status.position_x - metalniObjekat.sirina/2,-status.position_y - metalniObjekat.visina/2,-status.position_z); /* Pomeramo sve tako da simuliramo pomeranje kamere */


    delovi::sveMreze(0,0,0,metalniObjekat);

    /* LEVO */
    delovi::sipkeDuzinom(-((int)metalniObjekat.ispuna.sirina + (int)metalniObjekat.stub.sirina)/2.0,
                         (metalniObjekat.ispuna.visina + metalniObjekat.donjaAnkerPloca.visina) / 2.0,
                         -metalniObjekat.duzina, metalniObjekat,LEVO);

    /* DESNO */
    delovi::sipkeDuzinom(metalniObjekat.ispuna.sirina/2.0 + metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.binderDonjiDesniPojas.duzina - (int)metalniObjekat.stub.sirina/2.0,
                        (metalniObjekat.ispuna.visina + metalniObjekat.donjaAnkerPloca.visina) / 2.0,
                        -metalniObjekat.duzina, metalniObjekat,DESNO);

    double deoDuzineNapred=(metalniObjekat.binderDonjiLeviPojas.duzina+metalniObjekat.binderDonjiDesniPojas.duzina) / (double)(metalniObjekat.stuboviNapred+1);


    // stubovi napred
    for(int i=0;i<(int)metalniObjekat.stuboviNapred;i++)
        if(metalniObjekat.Materijal.StuboviNapred[i].exists)
            delovi::stub(-(int)metalniObjekat.stub.sirina/2.0 + (i+1)*deoDuzineNapred,0,0,metalniObjekat);

    double deoDuzineNazad=(metalniObjekat.binderDonjiLeviPojas.duzina+metalniObjekat.binderDonjiDesniPojas.duzina) / (double)(metalniObjekat.stuboviNazad+1);


    //stubovi nazad
    for(int i=0;i<(int)metalniObjekat.stuboviNazad;i++)
        if(metalniObjekat.Materijal.StuboviNazad[i].exists)
            delovi::stub(-(int)metalniObjekat.stub.sirina/2.0 + (i+1)*deoDuzineNazad,0,-metalniObjekat.duzina,metalniObjekat);


    delovi::roznjace(-(int)metalniObjekat.stub.sirina/2.0,0,0,metalniObjekat);

}

void Display::materijal()
{
    glutcpp::light(GL_OFF);
    glutcpp::modelView2D();

    delovi2D::ispisMaterijal2(-0.9,0.9,metalniObjekat);
}
