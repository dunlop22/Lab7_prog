#define _CRT_SECURE_NO_WARNINGS
#include "Motor.h"
#include <iostream>
#include <conio.h>
using namespace std;

Motor::Motor()
{
	koni = -1;
	name[0] = '\0';
	rab_obem = -1;
	rasxod = -1;
	kol_vo_cilindr = -1;
	klapan = -1;
}


void Motor::new_motor_info()
{
	cout << "Введите маркировку двигателя: ";
	std::getline(std::cin, name);
	while (name.length() == 0)
	{
		printf("Неверно введена маркировка двигателя, попробуйте еще: ");
		std::getline(std::cin, name);
	}
	
	cout << "Введите рабочий объем двигателя в литрах: ";
	while (scanf("%lf", &rab_obem) != 1 || rab_obem < 0)
	{
		printf("Неверно введено значение объема двигателя, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество лошадинных сил: ";
	while (scanf("%lf", &koni) != 1 || koni < 0)
	{
		printf("Неверно введено значение количества лошадиных сил, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите средний расход топлива на 100км в литрах: ";
	while (scanf("%lf", &rasxod) != 1 || rasxod < 0)
	{
		printf("Неверно введено значение расхода на 100км, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество цилиндров: ";
	while (scanf("%lf", &kol_vo_cilindr) != 1 || kol_vo_cilindr < 0)
	{
		printf("Неверно введено значение количества цилиндров, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	cout << "Введите количество клапанов на один цилиндр: ";
	while (scanf("%lf", &klapan) != 1 || klapan < 0)
	{
		printf("Неверно введено значение количества клапанов, попробуйте еще: ");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');
}

void Motor::new_motor(double koni_1, double rasxod_1, string name_1, double rab_obem_1, double kol_vo_cilindr_1, double klapan_1)
{
	name = name_1;
	rab_obem = rab_obem_1;
	koni = koni_1;
	rasxod = rasxod_1;
	kol_vo_cilindr = kol_vo_cilindr_1;
	klapan = klapan_1;
}

void Motor::prosmotr_motor()
{
	if (koni >= 0)
	{
		cout << "\n\nИНФОРАЦИЯ О ДВИГАТЕЛЕ:\nМаркировка двигателя: " << name;
		cout << "\nРабочий объем: " << rab_obem;
		cout << "\nМощность (л.с.): " << koni;
		cout << "\nСредний расход на 100км: " << rasxod;
		cout << "\nКоличество цилиндров: " << kol_vo_cilindr;
		cout << "\nКоличество клапанов на 1 цилиндр: " << klapan;
	}
	else
	{
		cout << "Информация о двигателе отсутствует";
	}
}