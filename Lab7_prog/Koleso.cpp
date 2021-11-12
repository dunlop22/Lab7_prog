#define _CRT_SECURE_NO_WARNINGS
#include "Koleso.h"
#include <iostream>
#include <conio.h>
using namespace std;

Koleso::Koleso()
{
	visota = -1;
	shirina = -1;
	diametr = -1;
	tip_diska[0] = '\0';
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
}

//������� �������� ������
void Koleso::new_koleso(double shirina_1, double visota_1, double diametr_1, string tip_diska_1)
{
	tip_diska = tip_diska_1;
	shirina = shirina_1;
	visota = visota_1;
	diametr = diametr_1;
}

//������� ������ ���������� � ������
void Koleso::prosmotr_koleso()
{
	cout << "\n\n������ � �������:\n������ ������ : " << shirina;
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