#pragma once
using namespace std;
#include <string>

class Koleso
{
	
	friend class Avto;
public:

	Koleso();
	Koleso(int diametr);
	Koleso(const Koleso& koleso);

	void deep_copy(const Koleso& source);

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
	~Koleso();

private:
	static int id_kolesa;
	static int kolvo_koles;
	int shirina = 225;
	int visota = 55;
	int diametr = 17;
	int id;
	string tip_diska = "Литье";
};

