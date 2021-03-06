#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "Koleso.h"
#include "Obchee.h"
#include "Avto.h"
#include "Motor.h"
#include "Korobka.h"
#include <locale.h>
#include <string>

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    int podmenu;
    Koleso Kolesiko;
    Obchee Obchie;
    Motor Motorik;
    Korobka Korobas;
    Avto Avtomobil;
    do
    {
        do
        {
            system("cls");
            cout << "1) Добавление информации о колесах\n2) Добавление информации о коробке передач\n3) Добавление информации о двигателе\n4) Добавление общей информации\n5) Создание авто\n6) Возврат значений (* | &)\n7) Использование дружественной функции\n8) Перегрузка операторов\n9) Строки (string)\n\n0) Выход";
            menu = _getch();
        } while (menu < '0' && menu > '9');
        if (menu == '1')
        {
            do
            {
                system("cls");
                cout << "1) Создание колеса со своими данными\n2) Создание колеса по конструктору";
                podmenu = _getch();
            } while (podmenu < '1' || podmenu > '2');
            if (podmenu == '1')
            {
                Kolesiko.new_koleso_info();
            }
            else
            {
                Kolesiko.new_koleso(225, 55, 17, "Литье");
            }
            Kolesiko.prosmotr_koleso();
        }
        if (menu == '2')
        {
            do
            {
                system("cls");
                cout << "1) Создание коробки со своими данными\n2) Создание коробки по конструктору";
                podmenu = _getch();
            } while (podmenu < '1' || podmenu > '2');
            if (podmenu == '1')
            {
                Korobas.new_korobka_info();
            }
            else
            {
                Korobas.new_korobka_peredach(5, "АКПП");
            }
            Korobas.prosmotr_korobka_peredach();
        }
        if (menu == '3')
        {
            do
            {
                system("cls");
                cout << "1) Создание двигателя со своими данными\n2) Создание двигателя по конструктору";
                podmenu = _getch();
            } while (podmenu < 1 || podmenu > 2);

            if (podmenu == '1')
            {
                Motorik.new_motor_info();
            }
            if (podmenu == '2')
            {
                Motorik.new_motor(100, 10, "FB20", 2, 4, 4);
            }
            Motorik.prosmotr_motor();
        }
        if (menu == '4')
        {
            do
            {
                system("cls");
                cout << "1) Создание общей информации со своими данными\n2) Создание общей информации по конструктору";
                podmenu = _getch();
            } while (podmenu < 1 || podmenu > 2);

            if (podmenu == '1')
            {
                Obchie.new_obchee_info();
            }
            if (podmenu == '2')
            {
                Obchie.new_obchee(5, 1500, "Toyota", 7, "4WD", "Бензин", 65);
            }
            Obchie.prosmotr_obchee();
        }
        if (menu == '5')
        {
            system("cls");
            
            Avtomobil.new_avto();

            cout << "Автомобиль успешно собран!\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }
        if (menu == '6')
        {
            system("cls");
            double diametr_ret = 0;
            double visota_ret = 0;
            
            Kolesiko.new_koleso(225, 55, 17, "Литье");
            Kolesiko.Diametr_inf(diametr_ret);
            cout << "Возврат через ссылку\nДиаметр: " << diametr_ret;
            Kolesiko.Visota_inf(&visota_ret);
            cout << "\n\nВозврат через указатель\nВысота: " << visota_ret;
            cout << "\n\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }
        if (menu == '7')
        {
            system("cls");
            cout << "Данные об автомобиле до внесения изменений: ";
            Avtomobil.new_avto();
            Avtomobil.prosmotr_avto();

            double diametr_new, visota_new;
            cout << "\n\nВведите новый диаметр колеса: ";
            while (scanf("%lf", &diametr_new) != 1 || diametr_new < 0)
            {
                printf("Неверно введено значение диаметра колеса, попробуйте еще: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            
            cout << "Введите новую высоту колеса: ";
            while (scanf("%lf", &visota_new) != 1 || visota_new < 0)
            {
                printf("Неверно введено значение высоты колеса, попробуйте еще: ");
                while (getchar() != '\n');
            }
            while (getchar() != '\n');
            
            Avtomobil.new_danii_kolesa(diametr_new, visota_new);
            cout << "\n\nДанные об автомобиле после внесения изменений: ";
            Avtomobil.prosmotr_avto();

            cout << "\n\nНажмите любую клавишу для возврата в меню.";
            _getch();
        }
        if (menu == '8')
        {
            do
            {
                system("cls");
                cout << "1) +\n2) ++ (префиксный)\n3) ++ (постфиксный)";
                podmenu = _getch();
            } while (podmenu < '1' || podmenu > '3');
            system("cls");
            if (podmenu == '1')
            {
                Motor* Motor_Mass = new Motor[3];
                cout << "\n\nДвигатель №1";
                Motor_Mass[0].new_motor(100, 10, "FB20", 2, 4, 4);
                Motor_Mass[0].prosmotr_motor();
                cout << "\n\nДвигатель №2";
                Motor_Mass[1].new_motor(249, 16, "2GR-FE", 3.5, 6, 4);
                Motor_Mass[1].prosmotr_motor();
                cout << "\n\nДвигатель №3";
                Motor_Mass[2] = Motor_Mass[0] + Motor_Mass[1];
                Motor_Mass[2].prosmotr_motor();
            }
            if (podmenu == '2' || podmenu == '3')
            {
                
                Korobka* Korobchik = new Korobka[2];
                cout << "Информация о коробке передач до:\n\nКоробка №1";
                Korobchik[0].new_korobka_peredach(7, "АКПП");
                Korobchik[0].prosmotr_korobka_peredach();
                cout << "\n\n********************";

                if (podmenu == '2')
                {
                    ++Korobchik[0]; 
                    Korobchik[1] = Korobchik[0];
                }   
                else
                {
                    Korobchik[1] = Korobchik[0]++;
                }
                cout << "\n\nИнформация о коробке передач после:\n\nКоробка №1";
                Korobchik[0].prosmotr_korobka_peredach();
                cout << "\n\nКоробка №2";
                Korobchik[1].prosmotr_korobka_peredach();
            }
            cout << "\n\nНажмите любую клавишу для возврата в меню.";
            _getch();
        }
        if (menu == '9')
        {
            system("cls");
            int n;
            string country = "Japan";
            Koleso* Kolesiko_mass = new Koleso[20];
            do
            {
                cout << "Введите количество создаваемых колес: ";
                cin >> n;
            } while (n <= 0 && n > 20);

            for (int i = 0; i < n; i++)
            {
                Kolesiko_mass[i].new_koleso(185 + i * 10, 30 + i * 2, 13 + i * 1, "Литье №" + to_string(i + 1) + " " + country);
                Kolesiko_mass[i].prosmotr_koleso();
                cout << "\n\n";
            }
            cout << "\n\nНажмите любую клавишу для возврата в меню.";
            _getch();
        }
    } while (menu != 0);
}