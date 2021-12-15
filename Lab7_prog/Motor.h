#pragma once
using namespace std;
#include <string>

class Motor
{
	
public:
	Motor();
	Motor& operator +(Motor& other)
	{
		koni = koni + other.koni;
		rab_obem = rab_obem + other.rab_obem;
		return *this;
	}
	bool operator > (Motor Motorik)
	{
		if ((*this).koni > Motorik.koni)
		{
			return(1);
		}
		else
		{
			return (0);
		}
	}
	bool operator < (Motor Motorik)
	{
		if ((*this).koni < Motorik.koni)
		{
			return(1);
		}
		else
		{
			return (0);
		}
	}


	void new_motor_info();
	void new_motor(double koni_1, double rasxod_1, string name_1, double rab_obem_1, double kol_vo_cilindr_1, double klapan_1);
	void prosmotr_motor();
private:
	string name;
	double rab_obem;
	double koni;
	double rasxod;
	double kol_vo_cilindr;
	double klapan;
	
};

