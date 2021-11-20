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
	//*this = koleso;
	diametr = koleso.diametr;
	visota = koleso.visota;
	tip_diska = koleso.tip_diska;
	shirina = koleso.shirina;
	id = koleso.id;
	
}


Koleso::Koleso()
{
	id = 045450 + kolvo_koles;
	visota = 55;
	shirina = 225;
	diametr = 17;
	tip_diska = "�����";
	kolvo_koles = kolvo_koles + 1;
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

Koleso::~Koleso()
{
	kolvo_koles = kolvo_koles - 1;
}

void Koleso::dia_izm()
{
	this->diametr = this->diametr - 4;
}



void Koleso::deep_copy(const Koleso& source)
{
	diametr = source.diametr;
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
	
	do 
	{} while (check_param(0, 300, shirina) == 0);

	/*
	do {
		try
		{
			cin >> temp;
			if (temp < 0)
			{
				throw "������� ������������� ��������.";
			}
			else if (temp > 300)
			{
				throw "������� ������� ������� ��������.";
			}
			cout << "�������� ������������� �������. \n\n";
			shirina = temp;
		}
		catch (const char* exception)
		{
			cerr << "Error: " << exception;
			cout << "\n��������� �������: ";
		}
	} while (shirina != temp);

	/*while (scanf("%lf", &shirina) != 1 || shirina < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
	*/

	cout << "������� ������ ������: ";
	do {} while (check_param(0, 80, visota) == 0);

	/*
	while (scanf("%lf", &visota) != 1 || visota < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');*/

	cout << "������� ������� ������ � ������: ";
	do {} while (check_param(0, 25, diametr) == 0);

	/*while (scanf("%lf", &diametr) != 1 || diametr < 0)
	{
		printf("������� ������� �������� �������� ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');*/

	while (getchar() != '\n');
	cout << "������� ��� ��������� ����� (���������/�����/�����): ";
	std::getline(std::cin, tip_diska);
	while (tip_diska.length() == 0)
	{
		printf("������� ������ ��� ��������� �����, ���������� ���: ");
		std::getline(std::cin, tip_diska);
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
	cout << "\n��� �����: " << tip_diska;
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

void Koleso::id_new(int &id)
{
	id_kolesa = id_kolesa + 1;
	id = id_kolesa;
}

int Koleso::kolvo_return()
{
	return kolvo_koles;
}

