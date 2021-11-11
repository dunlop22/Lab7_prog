#pragma once
using namespace std;
#include <string>

class Koleso
{
	friend class Avto;
public:

	Koleso();

	void prosmotr_koleso();
	void new_koleso(double shirina_1, double visota_1, double diametr_1, string tip_diska_1);
	void new_koleso_info();
	void Diametr_inf(double& diametr_inf);
	void Visota_inf(double* visota_inf);
	
private:
	double shirina = 225;
	double visota = 55;
	double diametr = 17;
	string tip_diska = "Литье";
};

