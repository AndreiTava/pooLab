#include "PunctInformare.h"

std::shared_ptr<PunctInformare> PunctInformare::instance = nullptr;

Statie* PunctInformare::findStatie(std::string nume)
{
	for (auto st : statii)
	{
		if (st->getNume() == nume)
			return st;
	}
	return nullptr;
}

void PunctInformare::run()
{
}

std::shared_ptr<PunctInformare> PunctInformare::getInstance()
{
	if (instance == nullptr)
		instance.reset(new PunctInformare);
	return instance;
}

void PunctInformare::addStatie(Statie* st)
{
	statii.push_back(st);
}

int PunctInformare::estimarePret(std::string statia1, std::string statia2)
{
	return 0;
}

PunctInformare::~PunctInformare()
{
	for(auto st : statii)
	{
		delete st;
	}
	statii.clear();
}
