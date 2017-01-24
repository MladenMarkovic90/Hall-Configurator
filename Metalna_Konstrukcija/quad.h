#ifndef QUAD
#define QUAD

#include <glutcpp/glutcpp.h>

class quad
{
public:
    quad(){}
    ~quad(){}

    double X1=0;
    double Y1=0;
    double X2=0;
    double Y2=0;
    bool exists=true;

    void podaci(double x1,double y1,double x2,double y2)
    {
        X1=x1;Y1=y1;X2=x2;Y2=y2;
    }

    void crtaj()
    {
        if(exists)
            glutcpp::color(0,0,0,1);
        else
            glutcpp::color(1,1,0,1);
        glutcpp::pravougaonik_z(X1,Y1,X2,Y2);
    }

    bool kolizija(double curX,double curY)
    {
        if(curX > X1 && curX < X2 && curY < Y1 && curY > Y2)
        {
            //std::cout << "Postoji kandidat" << std::endl;
            exists=!exists;
            return true;
        }
        return false;
    }

    void ispisi(std::string s)
    {
        std::cout << s << " X1: "<<X1<<" Y1: "<<Y1<<" X2 "<<X2<<" Y2: "<<Y2<<std::endl;
    }
};

#endif // QUAD

