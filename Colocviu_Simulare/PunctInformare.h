#pragma once
#include "Statie.h"
#include <memory>
#include <vector>


//puteam avea mai multe puncte de informare
//dar toate au aceeasi informatie, deci are sens
//sa folosesc singleton
//de asemenea reprezinta si meniul
class PunctInformare
{
	static std::shared_ptr<PunctInformare> instance;
	std::vector<Statie*> statii;
	PunctInformare() = default;
	Statie* findStatie(std::string nume);
public:
	static std::shared_ptr<PunctInformare> getInstance();
	void run();
	void addStatie(Statie* st);
	int estimarePret(std::string statia1, std::string statia2);
	~PunctInformare();
};

