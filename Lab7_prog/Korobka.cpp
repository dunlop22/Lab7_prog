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
	cout << "Добавление информации о коробке передач автомобиля\n\nВведите тип коробки передач (АКПП/МКПП): ";

	std::getline(std::cin, tip_korobki);
	while (tip_korobki.length() == 0)
	{
		printf("Неверно введен тип коробки передач, попробуйте еще: ");
		std::getline(std::cin, tip_korobki);
	}


	cout << "Введите количество передач коробки: ";
	while (scanf("%lf", &kolvo_peredach) != 1 || kolvo_peredach < 0)
	{
		printf("Неверно введено значение количества передач, попробуйте еще: ");
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
		cout << "\n\nИНФОРМАЦИЯ О КОРОБКЕ ПЕРЕКЛЮЧЕНИЯ ПЕРЕДАЧ\nТип коробки переключения передач: " << tip_korobki;
		cout << "\nКоличество передач коробки: " << kolvo_peredach;
	}
	else
	{
		cout << "Информации о коробках передач отсутствует";
	}
}