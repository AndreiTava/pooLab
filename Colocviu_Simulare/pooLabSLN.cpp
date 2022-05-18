#include <iostream>
#include "PunctInformare.h"


//Am uitat sa mai scriu comentariu cu toate chestiile cerute
int main()
{

	Statie * x = new Extraurbana("Statia1","Leilor", 27, 6);
	Statie* y = new Urbana("Statia2", "Marcilor", 69, 5);
	auto pi = PunctInformare::getInstance();
	pi->addStatie(x);
	pi->addStatie(y);

	//Am reusit sa fac fix 0 cerinte... am zis ca las finalizarea pe final :P


}

