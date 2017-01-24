#ifndef DELOVI2D_H
#define DELOVI2D_H

#include "konstrukcija.h"
#include "glutcpp/glutcpp.h"
#include "global.h"

class delovi2D
{
public:

    static void ceoStub(double X,double Y,double maxSirina,double maxVisina,konstrukcija & metalniObjekat)
    {
        double sirina;
        double visina;

        double X1,X2,Y1,Y2;

        double oldY2;

        double centarX;



        //#######################################################################################
        //DONJA ANKER PLOCA
        //#######################################################################################


        sirina=metalniObjekat.donjaAnkerPloca.sirina / maxSirina;
        visina=metalniObjekat.donjaAnkerPloca.visina / maxVisina;

        X1=X;
        X2=X1+sirina;

        Y1=Y;
        Y2=Y1+visina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        ispisi((X1+X2)/2,(Y1+Y2)/2,metalniObjekat.donjaAnkerPloca.visina);


        //#######################################################################################
        //STUB
        //#######################################################################################


        centarX=(X1+X2)/2;
        oldY2=Y2;

        sirina=metalniObjekat.stub.sirina / maxSirina;
        visina=metalniObjekat.stub.visina / maxVisina;

        X1=centarX-sirina/2;
        X2=centarX+sirina/2;

        Y1=oldY2;
        Y2=Y1+visina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        ispisi((X1+X2)/2,(Y1+Y2)/2,metalniObjekat.stub.visina);


        //#######################################################################################
        //LEVO GORNJA ANKER PLOCA
        //#######################################################################################


        oldY2=Y2;

        sirina=metalniObjekat.gornjaAnkerPloca.sirina / maxSirina;
        visina=metalniObjekat.gornjaAnkerPloca.visina / maxVisina;

        X1=centarX-sirina/2;
        X2=centarX+sirina/2;

        Y1=oldY2;
        Y2=Y1+visina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        ispisi((X1+X2)/2,(Y1+Y2)/2,metalniObjekat.gornjaAnkerPloca.visina);
    }


    static void ceoDonjiPojas(double X,double Y,double maxSirina,double maxVisina,konstrukcija & metalniObjekat)
    {
        double X1,X2,Y1,Y2;


        //#######################################################################################
        //CELO STREHA LEVO
        //#######################################################################################


        X1 = X;
        X2 = X1 + metalniObjekat.celoStrehe.sirina / maxSirina;

        Y1 = Y + metalniObjekat.strehaLevo.visina / maxVisina;
        Y2 = Y1 + metalniObjekat.celoStrehe.visina / maxVisina;

        //Greda Levo
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        ispisi((X1+X2)/2 , (Y1+Y2)/2 , metalniObjekat.celoStrehe.visina);

        metalniObjekat.Materijal.vertikale.duzina+=metalniObjekat.celoStrehe.visina;



        double tmpX1,tmpX2,tmpY1,tmpY2;

        tmpX1 = (X1+X2)/2 - metalniObjekat.roznjaca.sirina / (2*maxSirina);
        tmpX2 = (X1+X2)/2 + metalniObjekat.roznjaca.sirina / (2*maxSirina);

        tmpY1 = Y2 + metalniObjekat.binderGornjiLeviPojas.visina / maxVisina;
        tmpY2 = tmpY1 + metalniObjekat.roznjaca.visina / maxVisina;

        //Roznjaca Zadnja
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(tmpX1,tmpY1,tmpX2,tmpY2);


        //#######################################################################################
        //STREHA LEVO
        //#######################################################################################


        X1 = X;
        X2 = X1 + metalniObjekat.strehaLevo.duzina / maxSirina;

        Y1 = Y;
        Y2 = Y1 + metalniObjekat.strehaLevo.visina / maxVisina;;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        //#######################################################################################
        //BINDER DONJI LEVI POJAS
        //#######################################################################################


        X1=X2;
        X2=X1 + metalniObjekat.binderDonjiLeviPojas.duzina / maxSirina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        //#######################################################################################
        //BINDER DONJI DESNI POJAS
        //#######################################################################################


        X1=X2;
        X2=X1 + metalniObjekat.binderDonjiDesniPojas.duzina / maxSirina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        //#######################################################################################
        //STREHA DESNO
        //#######################################################################################


        X1=X2;
        X2=X1 + metalniObjekat.strehaDesno.duzina / maxSirina;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        //#######################################################################################
        //CELO STREHA DESNO
        //#######################################################################################


        X1 = X2 - metalniObjekat.celoStrehe.sirina / maxSirina;
        X2 = X2;

        Y1 = Y + metalniObjekat.strehaDesno.visina / maxVisina;
        Y2 = Y1 + metalniObjekat.celoStrehe.visina / maxVisina;

        //Greda desno
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        ispisi((X1+X2)/2,(Y1+Y2)/2,metalniObjekat.celoStrehe.visina);

        metalniObjekat.Materijal.vertikale.duzina+=metalniObjekat.celoStrehe.visina;


        tmpX1 = (X1+X2)/2 - metalniObjekat.roznjaca.sirina / (2*maxSirina);
        tmpX2 = (X1+X2)/2 + metalniObjekat.roznjaca.sirina / (2*maxSirina);

        tmpY1 = Y2 + metalniObjekat.binderGornjiLeviPojas.visina / maxVisina;
        tmpY2 = tmpY1 + metalniObjekat.roznjaca.visina / maxVisina;

        //Roznjaca Zadnja
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(tmpX1,tmpY1,tmpX2,tmpY2);
    }


    static void sveGrede(double X,double Y,double maxSirina,double maxVisina,konstrukcija & metalniObjekat)
    {
        double sirina;
        //double duzina;
        double visina;

        double X1,X2,Y1,Y2;

        double oldX1,oldX2,oldY2;


        double visinaGredeSaCelom = metalniObjekat.visinaSrednjeGredeSaCelomStrehe / maxVisina;

        double visinaGredeBezCela = metalniObjekat.visinaSrednjeGredeBezCelaStrehe / maxVisina;


        //#######################################################################################
        //GREDE
        //#######################################################################################


        sirina=metalniObjekat.grede.sirina / maxSirina;

        X1=X - sirina/2;
        X2=X + sirina/2;

        Y1=Y;
        Y2=Y1 + visinaGredeSaCelom;

        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        delovi2D::ispisi((X1+X2)/2,(Y1+Y2)/2,metalniObjekat.visinaSrednjeGredeSaCelomStrehe);


        metalniObjekat.Materijal.vertikale.duzina+=metalniObjekat.visinaSrednjeGredeSaCelomStrehe;


        //#######################################################################################
        //GREDICE LEVO
        //#######################################################################################


        unsigned int duzinaLevo = metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.strehaLevo.duzina - metalniObjekat.celoStrehe.sirina;

        double ostatakLevo = metalniObjekat.binderGornjiLeviPojas.duzina;

        int num = duzinaLevo/1000;

        if(duzinaLevo%1000 < 100)
            num--;

        oldX1=X - sirina/2;
        oldX2=X + sirina/2;


        oldY2 = Y + visinaGredeSaCelom + visinaGredeBezCela*(sirina * maxSirina)/(2*duzinaLevo); // (X1 / X2) == (Y1 / Y2)

        visina =  2 * metalniObjekat.koseGrede.sirina / maxVisina;


        /*
        X1=oldX1 - metalniObjekat.grede.sirina / (maxSirina/2);
        X2=X1 - metalniObjekat.roznjaca.sirina/(maxSirina);
        Y1=oldY2 + metalniObjekat.binderGornjiDesniPojas.visina / maxVisina;
        Y2=Y1 + metalniObjekat.roznjaca.visina / maxVisina;*/


        /* pomeramo za 0.1 metar */
        /* pomeramo za 0.1 metar */
        X1=(oldX1 + oldX2)/2 - 100.0/maxSirina - metalniObjekat.roznjaca.sirina / (2*maxSirina);
        X2=(oldX1 + oldX2)/2 - 100.0/maxSirina + metalniObjekat.roznjaca.sirina / (2*maxSirina);

        Y1=oldY2 - visinaGredeBezCela*100.0/duzinaLevo + metalniObjekat.binderGornjiLeviPojas.visina/maxVisina; // (X1 / X2) == (Y1 / Y2)
        Y2 = Y1 + metalniObjekat.roznjaca.visina/maxVisina;

        // Prva Roznjaca
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        for(int i=0;i<num;i++)
        {

            Y1 = Y;

            /* pomeramo za 1 metar */
            X1=oldX1 - 1000.0/maxSirina;
            X2=oldX2 - 1000.0/maxSirina;

            Y2=oldY2 - visinaGredeBezCela*1000.0/duzinaLevo; // (X1 / X2) == (Y1 / Y2)

            // Uspravna greda
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
            delovi2D::ispisi((X1+X2)/2,(Y1+Y2)/2,(Y2 - Y1) * maxVisina);

            metalniObjekat.Materijal.vertikale.duzina+=(Y2 - Y1) * maxVisina;

            //Kosa Greda
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik(Tacka(oldX1,Y1),Tacka(oldX1,Y1 + visina) , Tacka(X2,Y2) , Tacka(X2,Y2 - visina) , GL_LINE_LOOP);
            delovi2D::ispisi((X2+oldX1)/2,(Y1+Y2)/2,duzina_gredice(oldX1,X2,Y1,Y2,maxSirina,maxVisina));

            metalniObjekat.Materijal.kosnici.duzina+=duzina_gredice(oldX1,X2,Y1,Y2,maxSirina,maxVisina);


            visina = visina - (double)metalniObjekat.koseGrede.sirina / (num * maxSirina);  // ispravka za kose gredice

            delovi2D::ispisi((X2+oldX1)/2,Y1,1000);

            double deoLevo = duzina_gredice((oldX1+oldX2)/2,(X1+X2)/2,Y2,oldY2,maxSirina,maxVisina);

            ostatakLevo -= deoLevo;

            /* DEO BINDER GORE LEVO */
            delovi2D::ispisi((X2+oldX1)/2,(Y2 + oldY2)/2,deoLevo);


            oldX1=X1;
            oldX2=X2;
            oldY2=Y2;

            X1=(oldX1+oldX2)/2 - metalniObjekat.roznjaca.sirina/(2*maxSirina);
            X2=(oldX1+oldX2)/2 + metalniObjekat.roznjaca.sirina/(2*maxSirina);

            Y1=oldY2 + metalniObjekat.binderGornjiDesniPojas.visina / (maxVisina);
            Y2=Y1 + metalniObjekat.roznjaca.visina / maxVisina;

            //Roznjace
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
        }

        Y1=Y;
        X2=X1;
        X1=X - duzinaLevo/maxSirina;

        if(duzinaLevo%1000 < 100)
            delovi2D::ispisi((X1+X2)/2,Y1,duzinaLevo%1000 + 1000);
        else
            delovi2D::ispisi((X1+X2)/2,Y1,duzinaLevo%1000);


        X1=X2 - ostatakLevo/maxSirina;

        /* DEO BINDER GORE LEVO ZADNJI */
        delovi2D::ispisi((X1+X2)/2,Y2,ostatakLevo);

        //#######################################################################################
        //GREDICE DESNO
        //#######################################################################################

        unsigned int duzinaDesno=metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.strehaDesno.duzina - metalniObjekat.celoStrehe.sirina;

        double ostatakDesno = metalniObjekat.binderGornjiDesniPojas.duzina;

        num=duzinaDesno/1000;

        if(duzinaDesno%1000 < 100)
            num--;

        oldX1=X - sirina/2;
        oldX2=X + sirina/2;

        oldY2 = Y + visinaGredeSaCelom + visinaGredeBezCela*(sirina * maxSirina)/(2*duzinaDesno);

        visina = 2 * metalniObjekat.koseGrede.sirina / maxVisina;


        /*
        X1=oldX1 + metalniObjekat.grede.sirina / (maxSirina/2);
        X2=X1 + metalniObjekat.roznjaca.sirina/(maxSirina);
        Y1=oldY2 + metalniObjekat.binderGornjiDesniPojas.visina / maxVisina;
        Y2=Y1 + metalniObjekat.roznjaca.visina / maxVisina;*/


        /* pomeramo za 0.1 metar */
        X1=(oldX1 + oldX2)/2 + 100.0/maxSirina - metalniObjekat.roznjaca.sirina / (2*maxSirina);
        X2=(oldX1 + oldX2)/2 + 100.0/maxSirina + metalniObjekat.roznjaca.sirina / (2*maxSirina);

        Y1=oldY2 - visinaGredeBezCela*100.0/duzinaDesno + metalniObjekat.binderGornjiDesniPojas.visina/maxVisina; // (X1 / X2) == (Y1 / Y2)
        Y2 = Y1 + metalniObjekat.roznjaca.visina/maxVisina;


        // Prva Roznjaca
        glutcpp::color(0,0,1,alpha);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);


        for(int i=0;i<num;i++)
        {

            Y1 = Y;

            /* pomeramo za 1 metar */
            X1 = oldX1 + 1000.0/maxSirina;
            X2 = oldX2 + 1000.0/maxSirina;

            Y2=oldY2 - visinaGredeBezCela*1000.0/duzinaDesno;

            // Uspravna greda
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
            delovi2D::ispisi((X1+X2)/2,(Y1+Y2)/2,(Y2 - Y1) * maxVisina);


            metalniObjekat.Materijal.vertikale.duzina+=(Y2 - Y1) * maxVisina;

            // Kosa greda
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik(Tacka(oldX2,Y1),Tacka(oldX2,Y1 + visina) , Tacka(X1,Y2) , Tacka(X1,Y2 - visina) , GL_LINE_LOOP);
            delovi2D::ispisi((X1+oldX2)/2,(Y1+Y2)/2,duzina_gredice(oldX2,X1,Y1,Y2,maxSirina,maxVisina));

            metalniObjekat.Materijal.kosnici.duzina+=duzina_gredice(oldX2,X1,Y1,Y2,maxSirina,maxVisina);

            visina = visina - (double)metalniObjekat.koseGrede.sirina / (num * maxSirina);  // ispravka za kose gredice

            delovi2D::ispisi((X1+oldX2)/2,Y1,1000);

            double deoDesno = duzina_gredice((oldX1 + oldX2)/2,(X1 + X2)/2,Y2,oldY2,maxSirina,maxVisina);

            ostatakDesno -= deoDesno;

            /* DEO BINDER GORE DESNO */
            delovi2D::ispisi((X1+oldX2)/2,(Y2 + oldY2)/2,deoDesno);

            oldX1=X1;
            oldX2=X2;
            oldY2=Y2;

            X1=(oldX1+oldX2)/2 - metalniObjekat.roznjaca.sirina/(2*maxSirina);
            X2=(oldX1+oldX2)/2 + metalniObjekat.roznjaca.sirina/(2*maxSirina);

            Y1=oldY2 + metalniObjekat.binderGornjiDesniPojas.visina / (maxVisina);
            Y2=Y1 + metalniObjekat.roznjaca.visina / maxVisina;

            //Roznjace
            glutcpp::color(0,0,1,alpha);
            glutcpp::pravougaonik_z(X1,Y1,X2,Y2);

        }

        X1=X2;
        X2=X + duzinaDesno/maxSirina;
        Y1=Y;


        if(duzinaDesno%1000 < 100)
            delovi2D::ispisi((X1+X2)/2,Y1,duzinaDesno%1000 + 1000);// - metalniObjekat.grede.sirina/2);
        else
            delovi2D::ispisi((X1+X2)/2,Y1,duzinaDesno%1000);// - metalniObjekat.grede.sirina/2);


        X2=X1 + ostatakDesno/maxSirina;

        /* DEO BINDER GORE DESNO ZADNJI */
        delovi2D::ispisi((X1+X2)/2,Y2,ostatakLevo);
    }


    static void ceoGornjiPojas(double X3,double Y3,double maxSirina,double maxVisina,konstrukcija & metalniObjekat)
    {

        double X1,X2,Y1,Y2;

        double visinaGredeSaCelom = metalniObjekat.visinaSrednjeGredeSaCelomStrehe;

        double visinaGredeBezCela = metalniObjekat.visinaSrednjeGredeBezCelaStrehe;

        double tmp;

        double X,Y;


        //#######################################################################################
        //BINDER GORNJI LEVI POJAS
        //#######################################################################################


        unsigned int duzinaLevo=metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.strehaLevo.duzina - metalniObjekat.celoStrehe.sirina;

        Y2 = Y3 + visinaGredeSaCelom/maxVisina;
        X2=X3;

        X=duzinaLevo;
        Y=visinaGredeBezCela;

        tmp=std::sqrt(X*X + Y*Y);

        Y1=Y2 - (visinaGredeBezCela/maxVisina)*metalniObjekat.binderGornjiLeviPojas.duzina/tmp;
        X1=X3 - (duzinaLevo/maxSirina) * metalniObjekat.binderGornjiLeviPojas.duzina/tmp;

        glutcpp::color(0,0,1,alpha);
        //glutcpp::linija(X1,Y1,0,X2,Y2,0);


        double visinaLevo = (metalniObjekat.binderGornjiLeviPojas.visina/maxVisina);

        glutcpp::pravougaonik(Tacka(X1,Y1) , Tacka(X2,Y2) , Tacka(X2,Y2 + visinaLevo) , Tacka(X1,Y1+visinaLevo) , GL_LINE_LOOP);

        //#######################################################################################
        //BINDER GORNJI DESNI POJAS
        //#######################################################################################


        unsigned duzinaDesno=metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.strehaDesno.duzina  - metalniObjekat.celoStrehe.sirina;


        Y2 = Y3 + visinaGredeSaCelom/maxVisina;
        X1=X3;

        X=duzinaDesno;
        Y=visinaGredeBezCela;

        tmp=std::sqrt(X*X + Y*Y);

        Y1=Y2 - (visinaGredeBezCela/maxVisina)*metalniObjekat.binderGornjiDesniPojas.duzina/tmp;
        X2=X3 + (duzinaDesno/maxSirina)*metalniObjekat.binderGornjiDesniPojas.duzina/tmp;

        glutcpp::color(0,0,1,alpha);
        //glutcpp::linija(X1,Y2,0,X2,Y1,0);

        double visinaDesno = (metalniObjekat.binderGornjiDesniPojas.visina/maxVisina);

        glutcpp::pravougaonik(Tacka(X1,Y2) , Tacka(X2,Y1) , Tacka(X2,Y1 + visinaDesno) , Tacka(X1,Y2+visinaDesno) , GL_LINE_LOOP);
    }


    static void ispisi(double x,double y,int value)
    {
        char text[100];
        sprintf(text,"%d",value);
        glutcpp::color(0,0,0,1);
        glutcpp::text(x,y,text,GLUT_BITMAP_TIMES_ROMAN_10);
    }


    static double duzina_gredice(double X1,double X2,double Y1,double Y2,double maxSirina,double maxVisina)
    {
        double X=(X1-X2)*maxSirina;
        double Y=(Y1-Y2)*maxVisina;

        return sqrt(X*X+Y*Y);
    }

    static void ispisMaterijal1(double X,double Y,konstrukcija & metalniObjekat)
    {

        formatIspisa(X,Y,metalniObjekat.Materijal.donjiBinder.duzina,
                     metalniObjekat.Materijal.donjiBinder.sirina,
                     metalniObjekat.Materijal.donjiBinder.visina,"DonjiBinder: ",0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.gornjiBinder.duzina,
                     metalniObjekat.Materijal.gornjiBinder.sirina,
                     metalniObjekat.Materijal.gornjiBinder.visina,"GornjiBinder: ",0.1);

        formatIspisa(X,Y,2*metalniObjekat.Materijal.stub.duzina,
                     metalniObjekat.Materijal.stub.sirina,
                     metalniObjekat.Materijal.stub.visina,"Stub: ",0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.kosnici.duzina,
                     metalniObjekat.Materijal.kosnici.sirina,
                     metalniObjekat.Materijal.kosnici.visina,"Kosnici: ",0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.vertikale.duzina,
                     metalniObjekat.Materijal.vertikale.sirina,
                     metalniObjekat.Materijal.vertikale.visina,"Vertikale: ",0.1);

    }


    static void ispisMaterijal2(double X,double Y,konstrukcija & metalniObjekat)
    {
        glutcpp::color(0,0,0,1);
        glutcpp::text(X,Y,"Potreban Materijal: ");
        Y-=0.2;


        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaStubova(),
                     metalniObjekat.Materijal.stub.sirina,
                     metalniObjekat.Materijal.stub.visina,"Stubovi: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaDonjiBinder(),
                     metalniObjekat.Materijal.donjiBinder.sirina,
                     metalniObjekat.Materijal.donjiBinder.visina,"DonjiBinderi: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaGornjiBinder(),
                     metalniObjekat.Materijal.gornjiBinder.sirina,
                     metalniObjekat.Materijal.gornjiBinder.visina,"GornjiBinderi: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaVertikale(),
                     metalniObjekat.Materijal.vertikale.sirina,
                     metalniObjekat.Materijal.vertikale.visina,"Vertikale: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaKosnici(),
                     metalniObjekat.Materijal.kosnici.sirina,
                     metalniObjekat.Materijal.kosnici.visina,"Kosnici: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.DuzinaIspuna(),
                     metalniObjekat.Materijal.ispuna.sirina,
                     metalniObjekat.Materijal.ispuna.visina,"Ispune: ",-0.1);

        formatIspisa(X,Y,metalniObjekat.Materijal.roznjacaUkupno.duzina,
                     metalniObjekat.Materijal.roznjacaUkupno.sirina,
                     metalniObjekat.Materijal.roznjacaUkupno.visina,"Roznjace: ",-0.1);

    }

    static void formatIspisa(double X,double & Y,int duzina,int visina,int sirina,std::string s,double changeY)
    {
        char text[1000];
        sprintf(text,"%s%dx%dx%d",s.c_str(),duzina,sirina,visina);
        glutcpp::color(0,0,0,1);
        glutcpp::text(X,Y,text,GLUT_BITMAP_HELVETICA_18);
        Y+=changeY;
    }

};

#endif // DELOVI2D_H

