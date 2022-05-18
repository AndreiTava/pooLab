#include "Statie.h"


int Statie::nr_crt = 0;

Statie::address::address(std::string p_strada, int p_numar, int p_sector) :
	strada(std::move(p_strada)), numar(p_numar), sector(p_sector)
{
	++nr_crt;
}

Statie::Statie(std::string p_nume, std::string p_strada, int p_numar, int p_sector) :
	nume(std::move(p_nume)), adresa(p_strada, p_numar, p_sector),obiectiv("") {}

void Statie::afis(std::ostream& out) const
{
	std::string tip = cod[1] == 'U' ? "Urbana" : "Extraurbana";
	out << "Statie " << tip<<": "<<this->cod
		<< "\nNume: " << this->nume
		<< "\nAdresa: Sector " << this->adresa.sector
		<< ", Strada " << this->adresa.strada
		<< ", Numarul " << this->adresa.numar<<"\n";
	if (obiectiv != "")
		out << "\n Obiectiv de interes " << obiectiv;
}

std::string Statie::getNume() const
{
	return nume;
}

std::string Statie::getAdresa() const
{
	return std::to_string(adresa.sector) + " " + adresa.strada + " " + std::to_string(adresa.numar);
}

std::string Statie::cod1() const
{
	return cod;
}


void Statie::addAutobuz(int nr)
{
	transporturi.push_back(nr);
}

Extraurbana::Extraurbana(std::string p_nume, std::string p_strada, int p_numar, int p_sector) :
	Statie(p_nume, p_strada, p_numar, p_sector)
{
	cod = std::string("SE-") + std::to_string(nr_crt);
}

Urbana::Urbana(std::string p_nume, std::string p_strada, int p_numar, int p_sector) :
	Statie(p_nume, p_strada, p_numar, p_sector)
{
	cod = std::string("SU-") + std::to_string(nr_crt);
}


std::ostream& operator<<(std::ostream& out, const Statie& st)
{
	st.afis(out);
	return out;
}
