#pragma once
#include <ostream>
#include <string>
#include <vector>
class Statie
{
protected:
	static int nr_crt;
	std::string nume;
	struct address
	{
		std::string strada;
		int numar;
		int sector;
		address(std::string p_strada, int p_numar, int p_sector);
		address(address& other) = default;
		address& operator=(address& other) = default;
	} adresa;
	std::string cod;
	std::vector<int> transporturi;
	std::string obiectiv;

	Statie(std::string p_nume,std::string p_strada, int p_numar, int p_sector);

	Statie(const Statie& other) = delete;

	Statie& operator=(const Statie& other) = delete;

	virtual void afis(std::ostream& out) const;
public:
	virtual ~Statie() = default;

	std::string getNume() const;
	

	std::string getAdresa() const;

	std::string cod1() const;

	void addAutobuz(int nr);

	friend std::ostream& operator<<(std::ostream& out, const Statie& st);
};

class Extraurbana : public Statie
{
public:
	Extraurbana(std::string p_nume="", std::string p_strada = "", int p_numar = 0, int p_sector = 0);

	Extraurbana(const Extraurbana& other) = delete;

	Extraurbana& operator=(const Extraurbana& other) = delete;

};

class Urbana : public Statie
{
public:
	Urbana(std::string p_nume="", std::string p_strada = "", int p_numar = 0, int p_sector = 0);

	Urbana(const Urbana& other) = delete;

	Urbana& operator=(const Urbana& other) = delete;
};