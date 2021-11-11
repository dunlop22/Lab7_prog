#pragma once
using namespace std;
#include <string>

class Korobka
{
	
public:
	Korobka();
	void new_korobka_info();
	void new_korobka_peredach(double kolvo_peredach_1, string tip_korobki_1);
	void prosmotr_korobka_peredach();
	void korobka_peredach_peredacha_plus();
	int korobka_get();
private:
	string tip_korobki;
	double kolvo_peredach;

};

