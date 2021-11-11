#define _CRT_SECURE_NO_WARNINGS
#include "Korobka.h"
#include <iostream>
#include <conio.h>
using namespace std;

Korobka::Korobka()
{
	kolvo_peredach = -1;
	tip_korobki[0] = '\0';
}

void Korobka::new_korobka_info()
{
	system("cls");
	cout << "���������� ���������� � ������� ������� ����������\n\n������� ��� ������� ������� (����/����): ";

	std::getline(std::cin, tip_korobki);
	while (tip_korobki.length() == 0)
	{
		printf("������� ������ ��� ������� �������, ���������� ���: ");
		std::getline(std::cin, tip_korobki);
	}


	cout << "������� ���������� ������� �������: ";
	while (scanf("%lf", &kolvo_peredach) != 1 || kolvo_peredach < 0)
	{
		printf("������� ������� �������� ���������� �������, ���������� ���: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
}

void Korobka::new_korobka_peredach(double kolvo_peredach_1, string tip_korobki_1)
{
	tip_korobki = tip_korobki_1;
	kolvo_peredach = kolvo_peredach_1;
}

void Korobka::prosmotr_korobka_peredach()
{
	if (kolvo_peredach >= 0)
	{
		cout << "\n\n���������� � ������� ������������ �������\n��� ������� ������������ �������: " << tip_korobki;
		cout << "\n���������� ������� �������: " << kolvo_peredach;
	}
	else
	{
		cout << "���������� � �������� ������� �����������";
	}
}