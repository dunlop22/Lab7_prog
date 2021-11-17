#pragma once
#include "Motor.h";
#include "Obchee.h";
#include "Korobka.h";
#include "Koleso.h";



class Avto
{

public:
	Avto();
	void new_avto();
	void prosmotr_avto();
	void new_danii_kolesa(double diametr, double visota);
	~Avto() {};
private:
	Obchee Obchie;
	Motor Motorik;
	Koleso Kolesik;
	Korobka Koroba;
};



