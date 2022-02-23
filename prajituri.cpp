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
        cout << gem << "g Gem si " << frisca << "g Frisca" << endl;
    }
    double gem;
    double frisca;

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
        frisca = suprafata;
        gem = volum * 2;
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
        frisca = suprafata;
        gem = volum * 2;
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
        frisca = suprafata;
        gem = volum * 2;
    }
};


int main() {
    Figura prajituri[100];
    int nrPraji = 0;
    string command = "";
    while (command != string("STOP"))
    {
        cin >> command;

        if (command == string("ADD"))
        {
            string tip = "invalid";
            int inaltime;
            cin >> tip;
            if (tip == string("cerc"))
            {
                int raza;
                cin >> raza >> inaltime;
                prajituri[nrPraji] = Figura(Cerc(inaltime, raza));

            }
            else if (tip == string("dreptunghi"))
            {
                int lmic, lmare;
                cin >> lmic >> lmare >> inaltime;
                prajituri[nrPraji] = Figura(Dreptunghi(inaltime,lmic,lmare));
            }
            else if (tip == string("patrat"))
            {
                int lat;
                cin >> lat >> inaltime;
                prajituri[nrPraji] = Figura(Patrat(inaltime, lat));
            }
            else if (tip == string("triunghi"))
            {
                int cmic, cmare;
                cin >> cmic >> cmare >> inaltime;
                prajituri[nrPraji] = Figura(Triunghi(inaltime, cmic,cmare));
            }
            else {
                cout << "Forma invalida \n";
                continue;
                
            }
            prajituri[nrPraji].printInfo();
            nrPraji++;
        }
        else if (command == string("REMOVE"))
        {
            int x;
            cin >> x;
            if (x >= 1 && x <= nrPraji)
            {
                for (int i = x - 1; i < nrPraji - 1; ++i)
                    prajituri[i] = prajituri[i + 1];
                nrPraji--;
            }
            else
                cout << "Nu exista prajitura";
        }
        else if (command == string("TOTAL"))
        {
            double totalFrisca = 0;
            double totalGem = 0;
            for (int i = 0; i < nrPraji; ++i)
            {
                totalFrisca += prajituri[i].frisca;
                totalGem += prajituri[i].gem;
                
            }
            cout << totalGem << "g Gem si " << totalFrisca << "g Frisca" << endl;
        }
    }

    return 0;
}
