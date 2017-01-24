#include <cmath>
#include "tacka.h"


Tacka::Tacka() {}


/* Konstruktor koji prima koordinate */
Tacka::Tacka(const float & x,const float & y,const float & z = 0)
{
    this->_x=x;
    this->_y=y;
    this->_z=z;
}


/* Getter za koordinatu x */
float Tacka::get_x() const {return this->_x;}


/* Getter za koordinatu y */
float Tacka::get_y() const {return this->_y;}


/* Getter za koordinatu z */
float Tacka::get_z() const {return this->_z;}


/* Setter za koordinatu x */
void Tacka::set_x(const float x) {this->_x=x;}


/* Setter za koordinatu y */
void Tacka::set_y(const float y) {this->_y=y;}


/* Setter za koordinatu z */
void Tacka::set_z(const float z) {this->_z=z;}


/* Sabiranje Tacke sa koordinatama */
void Tacka::add(const float x,const float y,const float z)
{
    this->_x+=x;
    this->_y+=y;
    this->_z+=z;
}


/* Sabiranje Tacke sa Tackom */
void Tacka::add(Tacka t)
{
    this->_x+=t.get_x();
    this->_y+=t.get_y();
    this->_z+=t.get_z();
}


/* norma vektora */
float Tacka::norm() const
{
    return sqrt(get_x() * get_x() + get_y() * get_y() + get_z() * get_z());
}


/* rastojanje dve tacke */
float Tacka::distance(Tacka &t2)
{
    float dx = this->get_x() - t2.get_x();
    float dy = this->get_y() - t2.get_y();
    float dz = this->get_z() - t2.get_z();
    return sqrt(dx * dx + dy * dy + dz * dz);
}


/* Vektor od 2 tacke */
Tacka Tacka::vek(Tacka t)
{
    Tacka tmp=Tacka(0,0,0);
    tmp.set_x(t.get_x()-this->_x);
    tmp.set_y(t.get_y()-this->_y);
    tmp.set_z(t.get_z()-this->_z);
    return tmp;
}


/* dodela sabiranje za tacku sa tackom */
Tacka& Tacka::operator+= (const Tacka& t2)
{
    this->set_x(this->get_x() + t2.get_x());
    this->set_y(this->get_y() + t2.get_y());
    this->set_z(this->get_z() + t2.get_z());
    return *this;
}


/* dodela oduzimanje za tacku sa tackom */
Tacka& Tacka::operator-= (const Tacka& t2)
{
    this->set_x(this->get_x() - t2.get_x());
    this->set_y(this->get_y() - t2.get_y());
    this->set_z(this->get_z() - t2.get_z());
    return *this;
}


/* dodela mnozenje za tacku sa konstantom */
Tacka& Tacka::operator*= (float k)
{
    this->set_x(this->get_x() * k);
    this->set_y(this->get_y() * k);
    this->set_z(this->get_z() * k);
    return *this;
}


/* dodela delenje za tacku sa konstantom */
Tacka& Tacka::operator/= (float k)
{
    this->set_x(this->get_x() / k);
    this->set_y(this->get_y() / k);
    this->set_z(this->get_z() / k);
    return *this;
}


/* provera ekvivalentnosti tacaka */
bool Tacka::operator== (const Tacka& t2)
{
    if(this->_x!=t2.get_x())
        return false;
    if(this->_y!=t2.get_y())
        return false;
    if(this->_z!=t2.get_z())
        return false;
    return true;
}


/* operacije s tackama */
// tehnicki nisu deo klase


/* Sabiranje  tacaka */
Tacka operator+ (Tacka t1, Tacka t2)
{
    Tacka rez;
    rez.set_x(t1.get_x() + t2.get_x());
    rez.set_y(t1.get_y() + t2.get_y());
    rez.set_z(t1.get_z() + t2.get_z());
    return rez;
}


/* oduzimanje tacaka */
Tacka operator- (Tacka t1, Tacka t2)
{
    Tacka rez;
    rez.set_x(t1.get_x() - t2.get_x());
    rez.set_y(t1.get_y() - t2.get_y());
    rez.set_z(t1.get_z() - t2.get_z());
    return rez;
}


/* mnozenje tacke sa konstantom */
Tacka operator* (Tacka t1, float k)
{
    Tacka rez;
    rez.set_x(t1.get_x() * k);
    rez.set_y(t1.get_y() * k);
    rez.set_z(t1.get_z() * k);
    return rez;
}
/* mnozenje tacke sa konstantom */
Tacka operator* (float k, Tacka t1)
{
    Tacka rez;
    rez.set_x(t1.get_x() * k);
    rez.set_y(t1.get_y() * k);
    rez.set_z(t1.get_z() * k);

    return rez;
}


/* deljenje tacke sa konstantom */
Tacka operator/ (Tacka t1, float k)
{
    Tacka rez;
    rez.set_x(t1.get_x() / k);
    rez.set_y(t1.get_y() / k);
    rez.set_z(t1.get_z() / k);
    return rez;
}
