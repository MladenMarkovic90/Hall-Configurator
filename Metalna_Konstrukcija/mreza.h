#ifndef MREZA
#define MREZA

#include "glutcpp/glutcpp.h"
#include "konstrukcija.h"

class mreza
{
public:
    static void draw(konstrukcija & metalniObjekat,int index)
    {

        glutcpp::push();

            //#######################################################################################
            //STUB LEVO
            //#######################################################################################

            bool stub=metalniObjekat.Materijal.StuboviLevo[index].exists;

            //glutcpp::color(0,0,1,1);
            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.donjaAnkerPloca.duzina,metalniObjekat.donjaAnkerPloca.sirina,metalniObjekat.donjaAnkerPloca.visina);

            glutcpp::translate(0,metalniObjekat.donjaAnkerPloca.visina/2.0+metalniObjekat.stub.visina/2.0,0);

            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.stub.sirina,metalniObjekat.stub.duzina,metalniObjekat.stub.visina);

            glutcpp::translate(0,metalniObjekat.stub.visina/2.0 + metalniObjekat.gornjaAnkerPloca.visina/2.0,0);

            //glutcpp::color(0,0,1,1);
            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.gornjaAnkerPloca.duzina,metalniObjekat.gornjaAnkerPloca.sirina,metalniObjekat.gornjaAnkerPloca.visina);


            //#######################################################################################
            //LEVO STREHA I CELO
            //#######################################################################################


            glutcpp::push();
            {

                glutcpp::color(0.5,0.5,0.5,1);

                glutcpp::translate(- (int)metalniObjekat.stub.sirina/2.0 - (int)metalniObjekat.strehaLevo.duzina/2.0,metalniObjekat.gornjaAnkerPloca.visina/2.0 + metalniObjekat.strehaLevo.visina/2.0,0);

                glutcpp::kvadar(metalniObjekat.strehaLevo.duzina,metalniObjekat.strehaLevo.sirina,metalniObjekat.strehaLevo.visina);

                glutcpp::translate(-(int)metalniObjekat.strehaLevo.duzina/2.0 + (int)metalniObjekat.celoStrehe.sirina/2.0 , metalniObjekat.strehaLevo.visina/2.0 + metalniObjekat.celoStrehe.visina/2.0,0);

                glutcpp::kvadar(metalniObjekat.celoStrehe.duzina,metalniObjekat.celoStrehe.sirina,metalniObjekat.celoStrehe.visina);

            }
            glutcpp::pop();

            glutcpp::color(0.5,0.5,0.5,1);
            glutcpp::translate(metalniObjekat.binderDonjiLeviPojas.duzina/2.0 - metalniObjekat.stub.sirina/2.0 ,metalniObjekat.gornjaAnkerPloca.visina/2.0 + metalniObjekat.binderDonjiLeviPojas.visina/2.0,0);

            glutcpp::kvadar(metalniObjekat.binderDonjiLeviPojas.duzina,metalniObjekat.binderDonjiLeviPojas.sirina,metalniObjekat.binderDonjiLeviPojas.visina);


            glutcpp::push();


                //#######################################################################################
                //GREDA
                //#######################################################################################

                //glutcpp::color(0,1,0,1);
                glutcpp::color(0.5,0.5,0.5,1);
                double tmp=metalniObjekat.binderDonjiLeviPojas.duzina+metalniObjekat.binderDonjiDesniPojas.duzina;
                tmp+=metalniObjekat.strehaLevo.duzina + metalniObjekat.strehaDesno.duzina;
                tmp/=2;

                double visinaGredeBezCela=metalniObjekat.visinaSrednjeGredeBezCelaStrehe;
                double visinaGredeSaCelom=metalniObjekat.visinaSrednjeGredeSaCelomStrehe;


                glutcpp::translate(metalniObjekat.binderDonjiLeviPojas.duzina/2.0,metalniObjekat.binderDonjiLeviPojas.visina/2.0 + visinaGredeSaCelom/2.0,0);

                glutcpp::kvadar(metalniObjekat.grede.sirina,metalniObjekat.grede.duzina,visinaGredeSaCelom);

                glutcpp::translate(0,-visinaGredeSaCelom/2.0,0);


                //#######################################################################################
                //GREDICE LEVO
                //#######################################################################################

                glutcpp::push();

                    int duzinaLevo=metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.strehaLevo.duzina - metalniObjekat.celoStrehe.sirina;

                    int num=duzinaLevo/1000;

                    if(duzinaLevo%1000 < 100)
                        num--;

                    double sirinaGrede = metalniObjekat.grede.sirina / 2.0;
                    double visina = 2 * metalniObjekat.koseGrede.sirina;
                    double duzina = metalniObjekat.koseGrede.duzina / 2.0;

                    double trenutnaVisina=visinaGredeSaCelom + visinaGredeBezCela*sirinaGrede/duzinaLevo;

                    glutcpp::color(0.5,0.5,0.5,1);

                    for(int i=0;i<num;i++)
                    {

                        trenutnaVisina=trenutnaVisina - (double)visinaGredeBezCela*1000.0/duzinaLevo;

                        //Kose Gredice
                        glutcpp::color(0.5,0.5,0.5,1);
                        glutcpp::kvadar(Tacka(-sirinaGrede,0,-duzina),Tacka(-sirinaGrede,0,duzina),Tacka(-sirinaGrede,visina,duzina),Tacka(-sirinaGrede,visina,-duzina),
                                        Tacka(sirinaGrede-1000,trenutnaVisina-visina,-duzina),Tacka(sirinaGrede-1000,trenutnaVisina-visina,duzina),
                                        Tacka(sirinaGrede-1000,trenutnaVisina,duzina),Tacka(sirinaGrede-1000,trenutnaVisina,-duzina));

                        visina = visina - (double)metalniObjekat.koseGrede.sirina / num;

                        glutcpp::translate(-1000,trenutnaVisina/2.0,0);

                        //Prave Gredice
                        glutcpp::color(0.5,0.5,0.5,1);
                        glutcpp::kvadar(metalniObjekat.grede.duzina,metalniObjekat.grede.sirina,trenutnaVisina);

                        glutcpp::translate(0,-trenutnaVisina/2.0,0);
                    }

                glutcpp::pop();

                //#######################################################################################
                //GREDICE DESNO
                //#######################################################################################


                visina = 2 * metalniObjekat.koseGrede.sirina;

                glutcpp::push();

                    int duzinaDesno=metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.strehaDesno.duzina - metalniObjekat.celoStrehe.sirina;

                    num=duzinaDesno/1000;

                    if(duzinaDesno%1000 < 100)
                        num--;


                    trenutnaVisina=visinaGredeSaCelom + visinaGredeBezCela*sirinaGrede/duzinaDesno;

                    glutcpp::color(0.5,0.5,0.5,1);

                    for(int i=0;i<num;i++)
                    {

                        trenutnaVisina=trenutnaVisina - (double)visinaGredeBezCela*1000.0/duzinaDesno;


                        //Kose Gredice
                        glutcpp::kvadar(Tacka(sirinaGrede,0,duzina),Tacka(sirinaGrede,0,-duzina),Tacka(sirinaGrede,visina,-duzina),Tacka(sirinaGrede,visina,duzina),
                                        Tacka(-sirinaGrede+1000,trenutnaVisina-visina,duzina),Tacka(-sirinaGrede+1000,trenutnaVisina-visina,-duzina),
                                        Tacka(-sirinaGrede+1000,trenutnaVisina,-duzina),Tacka(-sirinaGrede+1000,trenutnaVisina,duzina));

                        visina = visina - (double)metalniObjekat.koseGrede.sirina / num;

                        glutcpp::translate(1000,trenutnaVisina/2.0,0);

                        //Prave Gredice
                        glutcpp::kvadar(metalniObjekat.grede.duzina,metalniObjekat.grede.sirina,trenutnaVisina);

                        glutcpp::translate(0,-trenutnaVisina/2.0,0);
                    }

                glutcpp::pop();


                //#######################################################################################
                //BINDER GORNJI LEVI POJAS
                //#######################################################################################


                duzinaLevo = metalniObjekat.binderDonjiLeviPojas.duzina + metalniObjekat.strehaLevo.duzina - metalniObjekat.celoStrehe.sirina;

                double sirina = metalniObjekat.binderGornjiLeviPojas.sirina / 2.0;
                visina = metalniObjekat.binderGornjiLeviPojas.visina;

                glutcpp::translate(0,visinaGredeSaCelom,0);



                double X=duzinaLevo;
                double Y=visinaGredeBezCela;



                tmp=std::sqrt(X*X + Y*Y);

                double tmpX=-((double)duzinaLevo*(double)metalniObjekat.binderGornjiLeviPojas.duzina/(double)tmp);
                double tmpY=-((double)visinaGredeBezCela*(double)metalniObjekat.binderGornjiLeviPojas.duzina/(double)tmp);

                //glutcpp::color(0,1,0,1);
                glutcpp::color(0.5,0.5,0.5,1);

                // stavljamo +1 i -1 da se ne bi videlo presecanje elemenata

                glutcpp::kvadar(Tacka(tmpX,tmpY,sirina +1),
                                Tacka(tmpX,tmpY,-sirina -1),
                                Tacka(tmpX,tmpY+visina,-sirina -1),
                                Tacka(tmpX,tmpY+visina,sirina +1),
                                Tacka(0,0,sirina +1),
                                Tacka(0,0,-sirina -1),
                                Tacka(0,visina,-sirina -1),
                                Tacka(0,visina,sirina +1));


                //#######################################################################################
                //BINDER GORNJI DESNI POJAS
                //#######################################################################################



                duzinaDesno = metalniObjekat.binderDonjiDesniPojas.duzina + metalniObjekat.strehaDesno.duzina - metalniObjekat.celoStrehe.sirina;;

                sirina = metalniObjekat.binderGornjiDesniPojas.sirina / 2.0;
                visina = metalniObjekat.binderGornjiDesniPojas.visina;


                X=duzinaDesno;
                Y=visinaGredeBezCela;

                tmp=std::sqrt(X*X + Y*Y);

                tmpX=((double)duzinaDesno*(double)metalniObjekat.binderGornjiDesniPojas.duzina/(double)tmp);
                tmpY=-((double)visinaGredeBezCela*(double)metalniObjekat.binderGornjiDesniPojas.duzina/(double)tmp);

                //glutcpp::color(0,1,0,1);
                glutcpp::color(0.5,0.5,0.5,1);

                // stavljamo +1 i -1 da se ne bi videlo presecanje elemenata

                glutcpp::kvadar(Tacka(tmpX,tmpY,-sirina -1),
                                Tacka(tmpX,tmpY,sirina +1),
                                Tacka(tmpX,tmpY+visina,sirina +1),
                                Tacka(tmpX,tmpY+visina,-sirina -1),
                                Tacka(0,0,-sirina -1),
                                Tacka(0,0,sirina +1),
                                Tacka(0,visina,sirina +1),
                                Tacka(0,visina,-sirina -1));

            glutcpp::pop();

            glutcpp::color(0.5,0.5,0.5,1);

            glutcpp::translate(metalniObjekat.binderDonjiLeviPojas.duzina/2.0 + metalniObjekat.binderDonjiDesniPojas.duzina/2.0 ,0,0);

            glutcpp::kvadar(metalniObjekat.binderDonjiDesniPojas.duzina,metalniObjekat.binderDonjiDesniPojas.sirina,metalniObjekat.binderDonjiDesniPojas.visina);

            glutcpp::translate(metalniObjekat.binderDonjiDesniPojas.duzina/2.0 - metalniObjekat.stub.sirina/2.0,- (metalniObjekat.binderDonjiDesniPojas.visina/2.0 + metalniObjekat.gornjaAnkerPloca.visina/2.0),0);


            //#######################################################################################
            //DESNO STREHA I CELO
            //#######################################################################################

            glutcpp::push();
            {

                glutcpp::color(0.5,0.5,0.5,1);

                glutcpp::translate((int)metalniObjekat.stub.sirina/2.0 + (int)metalniObjekat.strehaDesno.duzina/2.0,metalniObjekat.gornjaAnkerPloca.visina/2.0 + metalniObjekat.strehaDesno.visina/2.0,0);

                glutcpp::kvadar(metalniObjekat.strehaDesno.duzina,metalniObjekat.strehaDesno.sirina,metalniObjekat.strehaDesno.visina);

                glutcpp::translate((int)metalniObjekat.strehaDesno.duzina/2.0 - (int)metalniObjekat.celoStrehe.sirina/2.0 , metalniObjekat.strehaDesno.visina/2.0 + metalniObjekat.celoStrehe.visina/2.0,0);

                glutcpp::kvadar(metalniObjekat.celoStrehe.duzina,metalniObjekat.celoStrehe.sirina,metalniObjekat.celoStrehe.visina);


            }
            glutcpp::pop();


            //#######################################################################################
            //STUB DESNO
            //#######################################################################################

            stub=metalniObjekat.Materijal.StuboviDesno[index].exists;

            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.gornjaAnkerPloca.duzina,metalniObjekat.gornjaAnkerPloca.sirina,metalniObjekat.gornjaAnkerPloca.visina);

            glutcpp::translate(0,-(metalniObjekat.stub.visina/2.0 + metalniObjekat.gornjaAnkerPloca.visina/2.0),0);

            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.stub.sirina,metalniObjekat.stub.duzina,metalniObjekat.stub.visina);

            glutcpp::translate(0,-(metalniObjekat.donjaAnkerPloca.visina/2.0 + metalniObjekat.stub.visina/2.0),0);

            //glutcpp::color(0,0,1,1);
            glutcpp::color(0.5,0.5,0.5,1);

            if(stub)
                glutcpp::kvadar(metalniObjekat.donjaAnkerPloca.duzina,metalniObjekat.donjaAnkerPloca.sirina,metalniObjekat.donjaAnkerPloca.visina);


        glutcpp::pop();
        return;
    }
};


#endif // MREZA

