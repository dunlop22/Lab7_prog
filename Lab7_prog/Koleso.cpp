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
	tip_diska = "Литье";
	kolvo_koles = kolvo_koles + 1;
}

Koleso::Koleso(int diametr)
{
	id = 045450 + kolvo_koles;
	visota = 55;
	shirina = 225;
	this->diametr = diametr;
	tip_diska = "Литье";
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
void Koleso::new_koleso_info()
{
	system("cls");
	cout << "Добавление информации о колесах автомобиля\n\nВведите ширину колеса: ";
	while (scanf("%lf", &shirina) != 1 || shirina < 0)
	{
		printf("Неверно введено значение ширины колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите высоту колеса: ";
	while (scanf("%lf", &visota) != 1 || visota < 0)
	{
		printf("Неверно введено значение высоты колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите диаметр колеса в дюймах: ";
	while (scanf("%lf", &diametr) != 1 || diametr < 0)
	{
		printf("Неверно введено значение диаметра колеса, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите тип колесного диска (штамповка/литье/ковка): ";
	std::getline(std::cin, tip_diska);
	while (tip_diska.length() == 0)
	{
		printf("Неверно введен тип колесного диска, попробуйте еще: ");
		std::getline(std::cin, tip_diska);
	}
	kolvo_koles = kolvo_koles + 1;
	id_new(id);
}


//функция создания колеса
void Koleso::new_koleso(double shirina_1, double visota_1, double diametr_1, string tip_diska_1)
{
	id_new(id);
	tip_diska = tip_diska_1;
	shirina = shirina_1;
	visota = visota_1;
	diametr = diametr_1;
	kolvo_koles = kolvo_koles + 1;
}

//функция вывода информации о колесе
void Koleso::prosmotr_koleso()
{
	cout << "ID: " << setw(6) << setfill('0') << id << endl;		//вывод не несущих нулей до числа
	cout << "\nШирина колеса : " << shirina;
	cout << "\nДиаметр колеса: " << diametr;
	cout << "\nВысота колеса: " << visota;
	cout << "\nТип диска: " << tip_diska;
}

//возврат через ссылку &
void Koleso::Diametr_inf(double& diametr_inf)
{
	diametr_inf += this->diametr;
}

//возврат через указатель
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

