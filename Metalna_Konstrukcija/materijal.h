#ifndef MATERIJAL
#define MATERIJAL

#include "metalniDeo.h"
#include "quad.h"
#include <vector>


class materijal
{
public:
    materijal(){}
    ~materijal(){}


    std::vector<quad> StuboviLevo;
    std::vector<quad> StuboviDesno;
    std::vector<quad> StuboviNapred;
    std::vector<quad> StuboviNazad;

    std::vector<quad> IspunaLevo;
    std::vector<quad> IspunaDesno;


    metalniDeo stub;
    metalniDeo donjiBinder;
    metalniDeo gornjiBinder;
    metalniDeo vertikale;
    metalniDeo kosnici;
    metalniDeo ispuna;
    metalniDeo roznjacaUkupno;

    int brojMreza;
    int brojIspuna;
    int duzina_Stuba;

    void initVector(int duzina,int stuboviNapred,int stuboviNazad)
    {

        int num=duzina/4500+2;

        brojMreza=num;

        for(int i=0;i<num;i++)
        {
            IspunaLevo.push_back(quad());
            IspunaDesno.push_back(quad());
            StuboviDesno.push_back(quad());
            StuboviLevo.push_back(quad());
        }

        for(int i=0;i<stuboviNapred;i++)
            StuboviNapred.push_back(quad());

        for(int i=0;i<stuboviNazad;i++)
            StuboviNazad.push_back(quad());


        return;
    }


    void initIspuna(int duzinaObjekta,int sirina,int visina,int stubDuzina)
    {
        ispuna.sirina=sirina;
        ispuna.visina=visina;
        duzina_Stuba=stubDuzina;

        int num=duzinaObjekta;

        //std::cout << "duz" << duzinaObjekta << std::endl;
        //std::cout << "num" << num << std::endl;

        num=num-(brojMreza*stubDuzina);

        //std::cout << "broj" << brojMreza*stubDuzina << std::endl;

        //std::cout << "num" << num << std::endl;

        num=num/(brojMreza-1);

        //std::cout << "num" << num << std::endl;

        ispuna.duzina=num;

        //std::cout << "Ispuna duzina" << ispuna.duzina << std::endl;
    }


    int DuzinaStubova()
    {
        int sum=0;
        for(unsigned int i=0;i<StuboviDesno.size();i++)
            if(StuboviDesno[i].exists)
                sum++;
        for(unsigned int i=0;i<StuboviLevo.size();i++)
            if(StuboviLevo[i].exists)
                sum++;
        for(unsigned int i=0;i<StuboviNapred.size();i++)
            if(StuboviNapred[i].exists)
                sum++;
        for(unsigned int i=0;i<StuboviNazad.size();i++)
            if(StuboviNazad[i].exists)
                sum++;
        return sum*stub.duzina;
    }

    int DuzinaDonjiBinder()
    {
        return brojMreza*donjiBinder.duzina;
    }

    int DuzinaGornjiBinder()
    {
        return brojMreza*gornjiBinder.duzina;
    }

    int DuzinaVertikale()
    {
        return brojMreza*vertikale.duzina;
    }

    int DuzinaKosnici()
    {
        return brojMreza*kosnici.duzina;
    }

    int DuzinaIspuna()
    {
        int sumStub=0;
        int sumIspuna=0;

        for(unsigned int i=0;i<StuboviDesno.size();i++)
            if(StuboviDesno[i].exists)
                sumStub++;

        for(unsigned int i=0;i<StuboviLevo.size();i++)
            if(StuboviLevo[i].exists)
                sumStub++;

        for(unsigned int i=0;i<IspunaDesno.size();i++)
            if(IspunaDesno[i].exists)
                sumIspuna++;

        for(unsigned int i=0;i<IspunaLevo.size();i++)
            if(IspunaLevo[i].exists)
                sumIspuna++;

        //std::cout <<"Ispuna: "<<sumIspuna << " " << ispuna.duzina << std::endl;

        return (sumStub*duzina_Stuba+sumIspuna*ispuna.duzina)*brojIspuna;
    }


};



#endif // MATERIJAL

