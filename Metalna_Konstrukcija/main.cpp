#include "glutcpp/glutcpp.h"
#include "glutcpp/glutDisplay.h"
#include "glutcpp/glutReshapeListener.h"
#include "glutcpp/glutNormalKeyListener.h"
#include "glutcpp/glutSpecialKeyListener.h"
#include "glutcpp/glutMouseListener.h"
#include "glutcpp/glutMotionListener.h"
#include "glutcpp/glutMouseWheelListener.h"


#include "animationStatus.h"
#include "display.h"
#include "reshapeListener.h"
#include "normalKeyListener.h"
#include "specialKeyListener.h"
#include "mouseListener.h"
#include "mouseWheelListener.h"
#include "motionListener.h"
#include "konstrukcija.h"


int main(int argc,char ** argv)
{
    animationStatus status;
    konstrukcija metalniObjekat;

    int i=1;

    if(argc < 30)
    {
        std::cout << "Nedovoljno argumenata" << std::endl;
        return -1;
    }

    metalniObjekat.duzina=atoi(argv[i++]);

    metalniObjekat.donjaAnkerPloca.sirina=atoi(argv[i++]);
    metalniObjekat.donjaAnkerPloca.duzina=atoi(argv[i++]);
    metalniObjekat.donjaAnkerPloca.visina=atoi(argv[i++]);

    metalniObjekat.stub.sirina=atoi(argv[i++]);
    metalniObjekat.stub.duzina=atoi(argv[i++]);
    metalniObjekat.stub.visina=atoi(argv[i++]);

    metalniObjekat.gornjaAnkerPloca.sirina=atoi(argv[i++]);
    metalniObjekat.gornjaAnkerPloca.duzina=atoi(argv[i++]);
    metalniObjekat.gornjaAnkerPloca.visina=atoi(argv[i++]);

    metalniObjekat.binderDonjiLeviPojas.sirina=atoi(argv[i++]);
    metalniObjekat.binderDonjiLeviPojas.duzina=atoi(argv[i++]);
    metalniObjekat.binderDonjiLeviPojas.visina=atoi(argv[i++]);

    metalniObjekat.binderDonjiDesniPojas.sirina=atoi(argv[i++]);
    metalniObjekat.binderDonjiDesniPojas.duzina=atoi(argv[i++]);
    metalniObjekat.binderDonjiDesniPojas.visina=atoi(argv[i++]);

    metalniObjekat.binderGornjiLeviPojas.sirina=atoi(argv[i++]);
    metalniObjekat.binderGornjiLeviPojas.duzina=atoi(argv[i++]);
    metalniObjekat.binderGornjiLeviPojas.visina=atoi(argv[i++]);

    metalniObjekat.binderGornjiDesniPojas.sirina=atoi(argv[i++]);
    metalniObjekat.binderGornjiDesniPojas.duzina=atoi(argv[i++]);
    metalniObjekat.binderGornjiDesniPojas.visina=atoi(argv[i++]);

    metalniObjekat.strehaLevo.duzina=atoi(argv[i++]);
    metalniObjekat.strehaDesno.duzina=atoi(argv[i++]);

    metalniObjekat.celoStrehe.sirina=atoi(argv[i++]);
    metalniObjekat.celoStrehe.duzina=atoi(argv[i++]);
    metalniObjekat.celoStrehe.visina=atoi(argv[i++]);

    metalniObjekat.roznjaca.sirina=atoi(argv[i++]);
    metalniObjekat.roznjaca.visina=atoi(argv[i++]);

    metalniObjekat.grede.sirina=atoi(argv[i++]);
    metalniObjekat.grede.duzina=atoi(argv[i++]);

    metalniObjekat.koseGrede.sirina=atoi(argv[i++]);
    metalniObjekat.koseGrede.duzina=atoi(argv[i++]);

    metalniObjekat.ugao=atoi(argv[i++]);

    metalniObjekat.virenjeRoznjace=atoi(argv[i++]);
    metalniObjekat.brojIspuna=atoi(argv[i++]);

    metalniObjekat.stuboviNapred=atoi(argv[i++]);
    metalniObjekat.stuboviNazad=atoi(argv[i++]);

    metalniObjekat.ispuna.sirina=atoi(argv[i++]);
    metalniObjekat.ispuna.visina=atoi(argv[i++]);
    metalniObjekat.ispuna.duzina=metalniObjekat.duzina;


    // Inicijalizovanje ostatka
    metalniObjekat.sirina=metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.binderDonjiLeviPojas.duzina;
    metalniObjekat.visina=metalniObjekat.donjaAnkerPloca.visina + metalniObjekat.stub.visina + metalniObjekat.gornjaAnkerPloca.visina;

    metalniObjekat.strehaLevo.sirina=metalniObjekat.binderDonjiLeviPojas.sirina;
    metalniObjekat.strehaLevo.visina=metalniObjekat.binderDonjiLeviPojas.visina;

    metalniObjekat.strehaDesno.sirina=metalniObjekat.binderDonjiDesniPojas.sirina;
    metalniObjekat.strehaDesno.visina=metalniObjekat.binderDonjiDesniPojas.visina;

    metalniObjekat.roznjaca.duzina=metalniObjekat.duzina;

    metalniObjekat.grede.visina=0; // nije potrebno
    metalniObjekat.koseGrede.visina=0; // nije potrebno

    metalniObjekat.maxSirina=metalniObjekat.sirina + metalniObjekat.strehaLevo.duzina + metalniObjekat.strehaDesno.duzina;

    metalniObjekat.visinaSrednjeGredeBezCelaStrehe = metalniObjekat.maxSirina * std::tan(((double)metalniObjekat.ugao)*(M_PI/180.0)) / 2;
    metalniObjekat.visinaSrednjeGredeSaCelomStrehe = metalniObjekat.visinaSrednjeGredeBezCelaStrehe + metalniObjekat.celoStrehe.visina;

    metalniObjekat.maxVisina=metalniObjekat.visina + metalniObjekat.visinaSrednjeGredeSaCelomStrehe;


    metalniObjekat.izracunajMaterijal();


    /* Inicalizujemo glut */
    glutcpp::init(argc,argv,500,500,"Metalna Konstrukcija");

    glutcpp::backgroundColor(1,1,1,1);

    /* Inicijalizujemo glut niti */
    glutReshapeListenerInit::run(new reshapeListener(500,500,status));
    glutDisplayInit::run(new Display(metalniObjekat,status));
    glutNormalKeyListenerInit::run(new normalKeyListener(metalniObjekat,status));
    glutSpecialKeyListenerInit::run(new SpecialKeyListener(metalniObjekat,status));
    glutMouseListenerInit::run(new mouseListener(metalniObjekat,status));
    glutMotionListenerInit::run(new motionListener(status));
    glutMouseWheelListenerInit::run(new mouseWheelListener(status));

    /* Pokrecemo glut petlju */
    glutcpp::start();

    return 0;
}
