#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include <conio.h>
#include "Koleso_Zapaska.h"




void Koleso_Zapaska::set(int diametr, int visota, int shirina, string tip_diska, string vid)
{
	this->diametr = diametr;
	this->visota = visota;
	this->shirina = shirina;
	this->tip_diska = tip_diska;
	this->vid = vid;
}

int Koleso_Zapaska::get_tip()
{
	cout << "\n\nCass: Koleso_Zapaska\n";
	return (this->diametr);
}

Koleso_Zapaska::Koleso_Zapaska()
{
}


void Koleso_Zapaska::set_vid(string vidok)
{
	this->vid = vidok;
}


void Koleso_Zapaska::deep_cop(const Koleso& source)
{
	this->deep_copy(source);
}

void Koleso_Zapaska::prokol_zapaska(int kolvo)
{
	this->kolvo_prokolov = kolvo;
}



void Koleso_Zapaska::Koleso_print()
{
	cout << "\n\n" << this->vid << "\n\n";
	Koleso::prosmotr_koleso();
}

