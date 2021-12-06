#pragma once
using namespace std;
#include <string>
#include "Koleso.h"

class Koleso_Zapaska : public Koleso
{
public:
	using Koleso::Koleso;
	string vid;


public:
	Koleso_Zapaska(int diametr) : Koleso(diametr){}	//конструктор производного класса с спарметром в конструктор базового класса с параметром

	Koleso_Zapaska& operator=(const Koleso_Zapaska& other)	//перегрузка оператора присваивания объекту производного класса объектов базового класса
	{
		Koleso::operator=(other);
		return *this;
	}
	int get_tip();
	Koleso_Zapaska();
	void Koleso_print();
	void set_vid(string vidok);
	void deep_cop(const Koleso& source);
	void prokol_zapaska(int kolvo);
};

