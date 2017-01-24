#include "glutcpp/tacka.h"
#include <cmath>


/*Konstruise vektor AB od tacaka A i B*/
Tacka Vektor3D::vektor(Tacka A, Tacka B)
{
    return B - A;
}

/*Duzina vektora*/
double Vektor3D::duzina(Tacka vektor)
{
    return sqrt(vektor.get_x() * vektor.get_x() + vektor.get_y() * vektor.get_y() + vektor.get_z() * vektor.get_z());
}

/*Duzina vektora AB*/
double Vektor3D::duzina(Tacka A, Tacka B)
{
    return Vektor3D::duzina(B-A);
}

/*Vraca jedinicni vektor*/
Tacka Vektor3D::jedinicni(Tacka vektor)
{
    double tmpDuzina = Vektor3D::duzina(vektor);
    Tacka tmpVektor = Tacka(0, 0, 0);

    tmpVektor.set_x(vektor.get_x()/tmpDuzina);
    tmpVektor.set_y(vektor.get_y()/tmpDuzina);
    tmpVektor.set_z(vektor.get_z()/tmpDuzina);

    return tmpVektor;
}

Tacka Vektor3D::jedinicni(Tacka A, Tacka B)
{
    return Vektor3D::jedinicni(B-A);
}

/*Skalarni proizvod(dot product) vx*ux+vy*uy+vz*uz */
double Vektor3D::skalarniProizvod(Tacka vektor1, Tacka vektor2)
{
    return vektor1.get_x()*vektor2.get_x() + vektor1.get_y()*vektor2.get_y() + vektor1.get_z()*vektor2.get_z();
}

/*Skalarni proizvod vektora AB i CD*/
double Vektor3D::skalarniProizvod(Tacka A, Tacka B, Tacka C, Tacka D)
{
    return Vektor3D::skalarniProizvod(B-A, D-C);
}

/*Ugao izmedju dva vektora*/
double Vektor3D::ugao (Tacka vektor1, Tacka vektor2)
{
    //TODO: zero vectors
    float d1=duzina(vektor1);
    float d2=duzina(vektor2);

    if(d1==0 || d2==0)
        return 0;

    return acos((skalarniProizvod(vektor1, vektor2))/(duzina(vektor1)*duzina(vektor2)));
}

double Vektor3D::cos_fi(Tacka vektor1, Tacka vektor2)
{
    //TODO: zero vectors
    float d1=duzina(vektor1);
    float d2=duzina(vektor2);

    if(d1==0 || d2==0)
        return 0;

    return (skalarniProizvod(vektor1, vektor2))/(duzina(vektor1)*duzina(vektor2));
}

/*Ugao izmedju vektora AB i CD*/
double Vektor3D::ugao (Tacka A, Tacka B, Tacka C, Tacka D)
{
    return Vektor3D::ugao(B-A, D-C);
}

/*Vektorski proizvod(cross product) (iz determinante:) */
Tacka Vektor3D::vektorskiProizvod(Tacka vektor1, Tacka vektor2)
{
    Tacka tmp = Tacka(0, 0, 0);

    tmp.set_x(vektor1.get_y()*vektor2.get_z() - vektor1.get_z()*vektor2.get_y());
    tmp.set_y(vektor1.get_z()*vektor2.get_x() - vektor1.get_x()*vektor2.get_z());
    tmp.set_z(vektor1.get_x()*vektor2.get_y() - vektor1.get_y()*vektor2.get_x());

    return tmp;
}

Tacka Vektor3D::vektorskiProizvod(Tacka A, Tacka B, Tacka C, Tacka D)
{
    return Vektor3D::vektorskiProizvod(B-A, D-C);
}

/*Vraca vektor normalan na ravan koju formiraju zadati vektori*/
Tacka Vektor3D::normala(Tacka vektor1, Tacka vektor2)
{
    return Vektor3D::vektorskiProizvod(vektor1, vektor2);
}

Tacka Vektor3D::normala(Tacka A, Tacka B, Tacka C, Tacka D)
{
    return Vektor3D::vektorskiProizvod(A, B, C, D);
}

Tacka Vektor3D::rotate2D(Tacka v, float ugao) {
    float x = v.get_x();
    float y = v.get_y();
    float z = v.get_z();
    
    return Tacka(x * cos(ugao) - z * sin(ugao), y , x * sin(ugao) + z * cos(ugao));
}
