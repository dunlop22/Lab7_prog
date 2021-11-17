#define _CRT_SECURE_NO_WARNINGS
#include "Koleso.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

int Koleso::kolvo_koles = 0;
int Koleso::id_kolesa = 0;


Koleso::Koleso()
{
	id = -1;
	visota = -1;
	shirina = -1;
	diametr = -1;
	tip_diska[0] = '\0';
}

Koleso::~Koleso()
{
	kolvo_koles = kolvo_koles - 1;
}
void Koleso::new_koleso_info()
{
	system("cls");
	cout << "���������� ���������� � ������� ����������\n\n������� ������ ������: ";
	while (scanf("%lf", &shirina) != 1 || shirina < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ������ ������: ";
	while (scanf("%lf", &visota) != 1 || visota < 0)
	{
		printf("������� ������� �������� ������ ������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ������� ������ � ������: ";
	while (scanf("%lf", &diametr) != 1 || diametr < 0)
	{
		printf("������� ������� �������� �������� ������, ���������� ���: ");
		while (getchar() != '\n');
	}
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

