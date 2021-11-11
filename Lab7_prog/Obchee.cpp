#define _CRT_SECURE_NO_WARNINGS
#include "Obchee.h"
#include <iostream>
#include <conio.h>
using namespace std;


Obchee::Obchee()
{
	name[0] = '\0';
	tip_privoda[0] = '\0';
	tip_topliva[0] = '\0';
	kolvo_mest = -1;
	razgon_do_100 = -1;
	massa = -1;
	obem_benzobaka = -1;
}

void Obchee::new_obchee_info()
{
	cout << "���������� ����� ���������� �� ����������\n\n������� ������ ����������: ";
	std::getline(std::cin, name);
	while (name.length() == 0)
	{
		printf("������� ������� ������ ����������, ���������� ���: ");
		std::getline(std::cin, name);
	}
	
	cout << "������� ��� ������� (2WD/4WD): ";
	std::getline(std::cin, tip_privoda);
	while (tip_privoda.length() == 0)
	{
		printf("������� ������ ��� �������, ���������� ���: ");
		std::getline(std::cin, tip_privoda);
	}
	
	cout << "������� ��� ������� (������/������/�������): ";
	std::getline(std::cin, tip_topliva);
	while (tip_topliva.length() == 0)
	{
		printf("������� ������ ��� �������, ���������� ���: ");
		std::getline(std::cin, tip_topliva);
	}


	cout << "������� ���������� ���������� ����: ";
	while (scanf("%lf", &kolvo_mest) != 1 || kolvo_mest < 0)
	{
		printf("������� �������� �������� ���������� ���������� ����, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ����� ������� �� 100��/�: ";
	while (scanf("%lf", &razgon_do_100) != 1 || razgon_do_100 < 0)
	{
		printf("������� �������� �������� ������� �� 100��/�, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ����� ����������: ";
	while (scanf("%lf", &massa) != 1 || massa < 0)
	{
		printf("������� �������� �������� �����, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "������� ����� ��������� � ������: ";
	while (scanf("%lf", &obem_benzobaka) != 1 || obem_benzobaka < 0)
	{
		printf("������� �������� �������� ������ ���������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
}

void Obchee::new_obchee(double kolvo_mest_1, double massa_1, string name_1, double razgon_do_100_1, string tip_privoda_1, string tip_topliva_1, double obem_benzobaka_1)
{
	name = name_1;
	tip_privoda = tip_privoda_1;
	tip_topliva = tip_topliva_1;
	massa = massa_1;
	obem_benzobaka = obem_benzobaka_1;
	razgon_do_100 = razgon_do_100_1;
	kolvo_mest = kolvo_mest_1;
}

void Obchee::prosmotr_obchee()
{
	if (obem_benzobaka >= 0)
	{
		cout << "\n\n����� ����������:\n������: " << name;
		cout << "\n��� �������: " << tip_privoda;
		cout << "\n��� �������: " << tip_topliva;
		cout << "\n���������� ���������� ����: " << kolvo_mest;
		cout << "\n����� ������� �� 100��/�: " << razgon_do_100;
		cout << "\n����� ���������: " << obem_benzobaka;
		cout << "\n�����: " << massa;
	}
	else
	{
		cout << "����� ���������� �����������";
	}

}