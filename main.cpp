#include <iostream>
#include <cmath>
#include <string>
#define PI 3.1415

using namespace std;
class Figura {
protected:
    int inaltime;
    double suprafata;
    double volum;
    void calcSup();
public:
    void printInfo()
    {
        cout << suprafata << " " << volum<<endl;
    }

};

class Cerc : public virtual Figura {
private:
    int raza;
public:
    Cerc(int inaltime, int raza)
    {
        this->inaltime = inaltime;
        this->raza = raza;
        calcSup();
    }
    void calcSup()
    {
        volum = raza * raza * PI * inaltime;
        double supBaza = raza * raza * PI;
        suprafata = raza * 2 * PI * inaltime + supBaza; //aria laterala + aria bazei
    }
};

class Dreptunghi : public virtual Figura {
protected:
    int lmic;
    int lmare;
public:
    Dreptunghi(int inaltime, int mic, int mare) 
    {
        this->inaltime = inaltime;
        lmic = mic;
        lmare = mare;
        calcSup();
    }
    void calcSup()
    {
        volum = lmic * lmare * inaltime;
        suprafata = 2 * inaltime * (lmic + lmare) + lmic * lmare; //ditto
    }
};

class Patrat : public Dreptunghi
{
public:
    Patrat(int inaltime, int latura) : Dreptunghi(inaltime, latura, latura) {};
};

class Triunghi : public virtual Figura
{
private:
    int cmic;
    int cmare;
public:
    Triunghi(int inaltime, int mic, int mare)
    {
        this->inaltime = inaltime;
        cmic = mic;
        cmare = mare;
        calcSup();
    }
    void calcSup()
    {
        volum = cmic * cmare * inaltime / 2;
        double ipot = sqrt(cmic * cmic + cmare * cmare);
        suprafata = cmic * cmare / 2 + inaltime * (cmic + cmare + ipot);
    }
};


int main() {
    Figura prajituri[100];
    prajituri[0] = Figura(Triunghi(10, 3, 4));
    prajituri[1] = Figura(Cerc(10, 3));
    prajituri[1].printInfo();
    string command;
    while(command != )

    return 0;
}
