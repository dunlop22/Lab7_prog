#pragma once
using namespace std;
#include <string>

class Korobka
{
	
public:
	Korobka();

	Korobka& operator ++()
	{
		kolvo_peredach++;
		return *this;
	}
	Korobka& operator ++(int dop)
	{
		Korobka novii = *this;
		kolvo_peredach++;
		return novii;

	}
	void new_korobka_info();
	void new_korobka_peredach(double kolvo_peredach_1, string tip_korobki_1);
	void prosmotr_korobka_peredach();
private:
	string tip_korobki;
	double kolvo_peredach;

};

