#ifndef DELOVI_H
#define DELOVI_H

#include "konstrukcija.h"
#include "glutcpp/glutcpp.h"
#include "mreza.h"
#include "global.h"



class delovi
{
public:

    static void sipkeDuzinom(int x, int y,int z, konstrukcija & metalniObjekat,int oznaka)
    {
        if(metalniObjekat.brojIspuna==0)
            return;

        glutcpp::push();
        {
            glutcpp::color(0.5,0.5,0.5,1.0);

            glutcpp::translate(x,y,z);

            int brojIspuna=metalniObjekat.brojIspuna-1;

            int num=metalniObjekat.duzina/4500 + 1;

            double deoDuzine=metalniObjekat.duzina / num;



            double deoVisine=(metalniObjekat.stub.visina - 250) / ((double)brojIspuna);

            brojIspuna++;


            glutcpp::translate(0,0,(deoDuzine/2));

            for(int i=0;i<num;i++)
            {
                bool exists;
                if(oznaka==LEVO)
                    exists=metalniObjekat.Materijal.IspunaLevo[i].exists;
                if(oznaka==DESNO)
                    exists=metalniObjekat.Materijal.IspunaDesno[i].exists;

                glutcpp::push();
                if(exists)
                    for(int j=0;j<brojIspuna;j++)
                    {
                            glutcpp::kvadar((int)metalniObjekat.ispuna.sirina,
                                            deoDuzine + metalniObjekat.stub.duzina,
                                            (int)metalniObjekat.ispuna.visina);
                            glutcpp::translate(0,deoVisine,0);
                    }
                glutcpp::pop();

                glutcpp::translate(0,0,deoDuzine);
            }

        }
        glutcpp::pop();

    }


    static void sveMreze(int x,int y,int z,konstrukcija & metalniObjekat)
    {

        int num=metalniObjekat.duzina/4500 + 1;

        double deoDuzine=metalniObjekat.duzina / num;

        glutcpp::push();

            glutcpp::translate(x,y,z);

            mreza::draw(metalniObjekat,num);

            for(int i=0;i<num;i++)
            {
                glutcpp::translate(0,0,-deoDuzine);
                mreza::draw(metalniObjekat,num-i-1);
            }

        glutcpp::pop();
    }


    static void stub(int x,int y,int z,konstrukcija & metalniObjekat)
    {
        glutcpp::push();
        {
            glutcpp::color(0.5,0.5,0.5,1.0);
            glutcpp::translate(x,y,z);

            //glutcpp::translate(0,metalniObjekat.donjaAnkerPloca.visina/2.0,0);

            glutcpp::kvadar(metalniObjekat.donjaAnkerPloca.sirina,metalniObjekat.donjaAnkerPloca.duzina,metalniObjekat.donjaAnkerPloca.visina);

            glutcpp::translate(0,metalniObjekat.donjaAnkerPloca.visina/2.0 + metalniObjekat.stub.visina/2.0,0);

            glutcpp::kvadar(metalniObjekat.stub.sirina,metalniObjekat.stub.duzina,metalniObjekat.stub.visina);

            glutcpp::translate(0,metalniObjekat.gornjaAnkerPloca.visina/2.0 + metalniObjekat.stub.visina/2.0,0);

            glutcpp::kvadar(metalniObjekat.gornjaAnkerPloca.sirina,metalniObjekat.gornjaAnkerPloca.duzina,metalniObjekat.gornjaAnkerPloca.visina);

        }
        glutcpp::pop();
    }


    static void roznjace(int x,int y,int z,konstrukcija & metalniObjekat)
    {

        glutcpp::color(0.5,0.5,0.5,1.0);

        double visina=metalniObjekat.donjaAnkerPloca.visina/2;
        visina+=metalniObjekat.stub.visina;
        visina+=metalniObjekat.gornjaAnkerPloca.visina;
        visina+=metalniObjekat.binderDonjiDesniPojas.visina;

        double visinaGredeBezCela=metalniObjekat.visinaSrednjeGredeBezCelaStrehe;
        double visinaGredeSaCelom=metalniObjekat.visinaSrednjeGredeSaCelomStrehe;

        unsigned int duzinaRoznjace=(int)metalniObjekat.duzina + metalniObjekat.binderGornjiLeviPojas.sirina + (2*metalniObjekat.virenjeRoznjace);


        glutcpp::push();
        {

            /* LEVO */

            int duzinaLevo = metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.strehaLevo.duzina - metalniObjekat.celoStrehe.sirina;

            int num=duzinaLevo/1000;

            if(duzinaLevo%1000 < 100)
                num--;

            double trenutnaVisina=visinaGredeSaCelom;// + visinaGredeBezCela*sirinaGrede/duzinaLevo;


            glutcpp::translate(x + metalniObjekat.binderDonjiLeviPojas.duzina,y+visina,z);

            glutcpp::push();
            {

                for(int i=0;i<num;i++)
                {

                    trenutnaVisina=trenutnaVisina - (double)visinaGredeBezCela*1000.0/duzinaLevo;

                    glutcpp::translate(-1000,0,0);

                    glutcpp::push();
                    {

                        glutcpp::translate(0,trenutnaVisina + metalniObjekat.binderGornjiLeviPojas.visina,-(int)metalniObjekat.duzina/2);

                        glutcpp::translate(0,metalniObjekat.roznjaca.visina/2,0);

                        glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);
                    }
                    glutcpp::pop();
                }


            }
            glutcpp::pop();

            //Prva Roznjaca
            glutcpp::push();

                trenutnaVisina=visinaGredeSaCelom - (double)visinaGredeBezCela*100.0/duzinaLevo;

                glutcpp::translate(-100,0,-(int)metalniObjekat.duzina/2);

                //glutcpp::translate(-(int)metalniObjekat.strehaLevo.duzina - (int)metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.grede.sirina/2,-visina + metalniObjekat.celoStrehe.visina,0);
                glutcpp::translate(0,metalniObjekat.roznjaca.visina/2.0 + trenutnaVisina + metalniObjekat.binderGornjiLeviPojas.visina,0);

                //Prva Roznjaca
                glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);

            glutcpp::pop();

            //Zadnja Roznjaca
            glutcpp::push();

                //glutcpp::translate(-(int)metalniObjekat.strehaLevo.duzina - (int)metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.grede.sirina/2,-visina + metalniObjekat.celoStrehe.visina,0);
                glutcpp::translate(-(int)metalniObjekat.strehaLevo.duzina - (int)metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.grede.sirina/2.0 , metalniObjekat.celoStrehe.visina + metalniObjekat.binderGornjiLeviPojas.visina,-(int)metalniObjekat.duzina/2);
                glutcpp::translate(0,metalniObjekat.roznjaca.visina/2,0);

                //Zadnja Roznjaca
                glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);

            glutcpp::pop();




            /* DESNO */

            int duzinaDesno = metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.strehaDesno.duzina - metalniObjekat.celoStrehe.sirina;

            num=duzinaDesno/1000;

            if(duzinaDesno%1000 < 100)
                num--;

            trenutnaVisina=visinaGredeSaCelom;// + (double)visinaGredeSaCelom*50.0/metalniObjekat.binderDonjiDesniPojas.duzina;

            glutcpp::push();
            {

                for(int i=0;i<num;i++)
                {

                    trenutnaVisina=trenutnaVisina - (double)visinaGredeBezCela*1000.0/duzinaDesno;

                    glutcpp::translate(+1000,0,0);

                    glutcpp::push();
                    {

                        glutcpp::translate(0,trenutnaVisina + metalniObjekat.binderGornjiLeviPojas.visina,-(int)metalniObjekat.duzina/2);

                        glutcpp::translate(0,metalniObjekat.roznjaca.visina/2,0);

                        glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);
                    }
                    glutcpp::pop();
                }
            }
            glutcpp::pop();



            //Zadnja Roznjaca
            glutcpp::push();
            {

                glutcpp::translate((int)metalniObjekat.strehaDesno.duzina + (int)metalniObjekat.binderDonjiDesniPojas.duzina  - metalniObjekat.grede.sirina/2.0,
                                   metalniObjekat.celoStrehe.visina + metalniObjekat.binderGornjiDesniPojas.visina,
                                   -(int)metalniObjekat.duzina/2);

                glutcpp::translate(0,metalniObjekat.roznjaca.visina/2,0);

                glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);
            }
            glutcpp::pop();


            //Prva Roznjaca
            glutcpp::push();

                trenutnaVisina=visinaGredeSaCelom - (double)visinaGredeBezCela*100.0/duzinaDesno;

                glutcpp::translate(+100,0,-(int)metalniObjekat.duzina/2);

                glutcpp::translate(0,metalniObjekat.roznjaca.visina/2.0 + trenutnaVisina + metalniObjekat.binderGornjiDesniPojas.visina,0);

                //Prva Roznjaca
                glutcpp::kvadar(metalniObjekat.roznjaca.sirina,duzinaRoznjace,metalniObjekat.roznjaca.visina);

            glutcpp::pop();



        }
        glutcpp::pop();

    }

};

#endif // DELOVI_H

