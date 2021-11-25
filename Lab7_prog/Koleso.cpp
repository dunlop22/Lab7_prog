#define _CRT_SECURE_NO_WARNINGS
#include "Koleso.h"
#include <iostream>
#include <iomanip>
#include <conio.h>


using namespace std;

int Koleso::kolvo_koles = 0;
int Koleso::id_kolesa = 0;

Koleso::Koleso(const Koleso& koleso)
{
	Koleso
	//*this = koleso;
	diametr = koleso.diametr;
	visota = koleso.visota;
	tip_diska = koleso.tip_diska;
	shirina = koleso.shirina;
	id = koleso.id;
	
}

Koleso::Koleso(char asq)
{
	new_koleso_info();
}


Koleso::Koleso()
{
	id = 045450 + kolvo_koles;
	visota = 55;
	shirina = 225;
	diametr = 17;
	tip_diska = "�����";
	kolvo_koles = kolvo_koles + 1;
	othoshenie = 0;
}

Koleso::Koleso(int diametr)
{
	id = 045450 + kolvo_koles;
	visota = 55;
	shirina = 225;
	this->diametr = diametr;
	tip_diska = "�����";
	kolvo_koles = kolvo_koles + 1;
}

Koleso::Koleso(int diametr, int kolvo)
{
	this->diametr = diametr;
}

Koleso::~Koleso()
{
	kolvo_koles = kolvo_koles - 1;
}

void Koleso::izm_prokol(int kolvo)
{
	this->kolvo_prokolov = kolvo_prokolov + kolvo;
}

void Koleso::dia_izm()
{
	this->diametr = this->diametr - 4;
}



void Koleso::deep_copy(const Koleso& source)
{
	diametr = source.diametr;
	diametr = source.diametr;
	visota = source.visota;
	tip_diska = source.tip_diska;
	shirina = source.shirina;
	id = source.id;
} 

int Koleso::auto_otnoshenie()	//����������� ������ � ������
{
	if (visota == 0)
	{
		throw "������ = 0. ���������� ������ ������ � �� ����������";
	}
	return (shirina * visota / 100);

}

int check_param(int min, int max, int &orig)
{
	int temp;
	try
	{
		cin >> temp;
		if (temp < min)
		{
			throw "������� ������������� ��������.";
		}
		else if (temp > max)
		{
			throw "������� ������� ������� ��������.";
		}
		cout << "�������� ������������� �������. \n\n";
		orig = temp;
		return 1;
	}
	catch (const char* exception)
	{
		cerr << "Error: " << exception;
		cout << "\n��������� �������: ";
		return 0;
	}
}

void Koleso::new_koleso_info()
{
	system("cls");
	cout << "���������� ���������� � ������� ����������\n\n������� ������ ������: ";
	
	while (check_param(0, 300, shirina) == 0);

	cout << "������� ������ ������: ";
	while (check_param(0, 80, visota) == 0);


	cout << "������� ������� ������ � ������: ";
	while (check_param(0, 25, diametr) == 0);

	while (getchar() != '\n');
	cout << "������� ��� ��������� ����� (���������/�����/�����): ";
	std::getline(std::cin, tip_diska);
	while (tip_diska.length() == 0)
	{
		printf("������� ������ ��� ��������� �����, ���������� ���: ");
		std::getline(std::cin, tip_diska);
	}

	try
	{
		othoshenie = auto_otnoshenie();
	}
	catch (const char* exception)
	{
		cerr << "\n\nError: " << exception;
	}

	kolvo_koles = kolvo_koles + 1;
	id_new(id);
}


//������� �������� ������
void Koleso::new_koleso(double shirina_1, double visota_1, double diametr_1, string tip_diska_1)
{
	id_new(id);
	tip_diska = tip_diska_1;
	shirina = shirina_1;
	visota = visota_1;
	diametr = diametr_1;
	kolvo_koles = kolvo_koles + 1;
}

//������� ������ ���������� � ������
void Koleso::prosmotr_koleso()
{
	cout << "ID: " << setw(6) << setfill('0') << id << endl;		//����� �� ������� ����� �� �����
	cout << "\n������ ������ : " << shirina;
	cout << "\n������� ������: " << diametr;
	cout << "\n������ ������: " << visota;
	if (othoshenie > 0)
	{
		cout << "\n������ ������ (��): " << othoshenie;
	}
	cout << "\n���������� �������� � ����: " << this->kolvo_prokolov;
}

//������� ����� ������ &
void Koleso::Diametr_inf(double& diametr_inf)
{
	diametr_inf += this->diametr;
}

//������� ����� ���������
void Koleso::Visota_inf(double* visota_inf)
{
	(*visota_inf) += this->visota;
}

int Koleso::id_return()
{
	return id_kolesa;
}


int Koleso::diametr_info()
{
	return this->diametr;
}


string Koleso::dannii()
{
	return (to_string(this->shirina) + "/" + to_string(this->visota) + "/" + to_string(this->diametr));
}

void Koleso::id_new(int &id)
{
	id_kolesa = id_kolesa + 1;
	id = id_kolesa;
}

int Koleso::kolvo_return()
{
	return kolvo_koles;
}

