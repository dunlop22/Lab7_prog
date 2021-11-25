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
	Koleso_Zapaska(int diametr) : Koleso(diametr){}	//����������� ������������ ������ � ���������� � ����������� �������� ������ � ����������

	Koleso_Zapaska();
	void Koleso_print();
	void set_vid(string vidok);
	void deep_cop(const Koleso& source);
	void prokol_zapaska(int kolvo);
};

