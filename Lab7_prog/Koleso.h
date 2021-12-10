#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>  
#include <string>
#include "Koleso_inf.h";
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

class Koleso : public Koleso_inf
//class Koleso
{
	
protected:
	int kolvo_prokolov = 0;
public:
	int diametr = -1;
	int shirina = -1;
	int visota = -1;
	string tip_diska = "Литье";

	friend class Avto;
public:
	void set(int diametr, int vusota, int shirina, string tip_diska);
	Koleso();
	Koleso(int diametr);
	Koleso(const Koleso& koleso);

	int get_tip();
	//virtual int get_tip();	//виртуальная функция!!!


	Koleso& operator=(const Koleso& source)
	{
		deep_copy(source);
		return *this;
	}
	void dia_izm();
	void prosmotr_koleso();
	void new_koleso(double shirina_1, double visota_1, double diametr_1, string tip_diska_1);
	void new_koleso_info();
	void Diametr_inf(double& diametr_inf);
	void Visota_inf(double* visota_inf);
	static int id_return();
	static void id_new(int &id);
	static int kolvo_return();
	int auto_otnoshenie();
	int diametr_info();
	void deep_copy(const Koleso& source);
	string dannii();
	~Koleso();
	void izm_prokol(int kolvo);

	double perimetr() override
	{
		double duim = 25.375;
		return (((this->diametr / 2 * duim) + this->visota * this->shirina / 100) * 2 * M_PI);
	}
	double obem() override
	{
		double duim = 25.375;
		return (M_PI * pow((diametr * duim / 1000), 2) * shirina / 1000);
	}
	

private:
	static int id_kolesa;
	static int kolvo_koles;
	//int diametr = -1;
	int othoshenie;
	int id;
	
};

