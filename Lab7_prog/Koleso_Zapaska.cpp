#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include <conio.h>
#include "Koleso_Zapaska.h"

void Koleso_Zapaska::set_vid(string vidok)
{
	this->vid = vidok;
}

void Koleso_Zapaska::deep_cop(const Koleso& source)
{
	this->deep_copy(source);
}


void Koleso_Zapaska::Koleso_print()
{
	cout << "\n\n" << this->vid << "\n\n";
	Koleso::prosmotr_koleso();
}
