#ifndef SVIDELOVI
#define SVIDELOVI

#include "metalniDeo.h"
#include "materijal.h"

class konstrukcija
{

public:

    konstrukcija(){}
    ~konstrukcija(){}



    materijal Materijal;

    metalniDeo donjaAnkerPloca;
    metalniDeo stub;
    metalniDeo gornjaAnkerPloca;

    metalniDeo binderDonjiLeviPojas;
    metalniDeo binderDonjiDesniPojas;

    metalniDeo binderGornjiLeviPojas;
    metalniDeo binderGornjiDesniPojas;

    metalniDeo roznjaca;

    metalniDeo spreg;

    metalniDeo grede;
    metalniDeo koseGrede;

    metalniDeo strehaLevo;
    metalniDeo strehaDesno;
    metalniDeo celoStrehe;

    metalniDeo ispuna;

    unsigned int stuboviNapred;
    unsigned int stuboviNazad;
    unsigned int virenjeRoznjace;
    unsigned int brojIspuna;

    unsigned int ugao;

    unsigned int sirina;
    unsigned int duzina;
    unsigned int visina;

    double maxSirina;
    double maxVisina;

    double visinaSrednjeGredeBezCelaStrehe;
    double visinaSrednjeGredeSaCelomStrehe;

    void izracunajMaterijal()
    {
        izracunajRoznjace();

        Materijal.donjiBinder.duzina=binderDonjiLeviPojas.duzina+binderDonjiDesniPojas.duzina;
        Materijal.donjiBinder.duzina+=strehaLevo.duzina+strehaDesno.duzina;
        Materijal.donjiBinder.sirina=binderDonjiDesniPojas.sirina;
        Materijal.donjiBinder.visina=binderDonjiDesniPojas.visina;

        Materijal.gornjiBinder.duzina=binderGornjiDesniPojas.duzina+binderGornjiLeviPojas.duzina;
        Materijal.gornjiBinder.sirina=binderGornjiDesniPojas.sirina;
        Materijal.gornjiBinder.visina=binderGornjiDesniPojas.visina;

        Materijal.stub.duzina=stub.visina;
        Materijal.stub.sirina=stub.sirina;
        Materijal.stub.visina=stub.duzina;

        Materijal.kosnici.duzina=0;
        Materijal.kosnici.sirina=grede.sirina;
        Materijal.kosnici.visina=grede.duzina;

        Materijal.vertikale.duzina=0;
        Materijal.vertikale.sirina=koseGrede.sirina;
        Materijal.vertikale.visina=koseGrede.duzina;

        Materijal.brojIspuna=brojIspuna;

        Materijal.initIspuna(duzina,ispuna.sirina,ispuna.visina,stub.duzina);

    }

    void izracunajRoznjace()
    {

        Materijal.roznjacaUkupno.duzina=0;
        Materijal.roznjacaUkupno.sirina=roznjaca.sirina;
        Materijal.roznjacaUkupno.visina=roznjaca.visina;

        unsigned int duzinaRoznjace=(int)duzina + (2*virenjeRoznjace);


        //LEVO
        int duzina = binderDonjiLeviPojas.duzina + strehaLevo.duzina - celoStrehe.sirina;

        int num=duzina/1000;

        if(duzina%1000 < 100)
            num--;

        Materijal.roznjacaUkupno.duzina+=(num+2)*duzinaRoznjace;

        //DESNO
        duzina = binderDonjiDesniPojas.duzina + strehaDesno.duzina - celoStrehe.sirina;

        num=duzina/1000;

        if(duzina%1000 < 100)
            num--;

        Materijal.roznjacaUkupno.duzina+=(num+2)*duzinaRoznjace;

        Materijal.initVector(this->duzina,stuboviNapred,stuboviNazad);
    }


};


#endif // SVIDELOVI

