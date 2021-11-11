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
            cout << "1) Добавление информации о колесах\n2) Добавление информации о коробке передач\n3) Добавление информации о двигателе\n4) Добавление общей информации\n5) Создание авто\n6) Возврат значений (* | &)\n7) Использование дружественной функции\n8) Перегрузка операторов\n\n0) Выход";
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
            Motor* Motor_Mass = new Motor[3];
            cout << "\n\nДвигатель №1";
            
            
//            Motor_mass[0].new_koleso(225, 55, 17, "Литье");
            Motor_Mass[0].new_motor(100, 10, "FB20", 2, 4, 4);
            Motor_Mass[0].prosmotr_motor();
            cout << "\n\nДвигатель №2";
            Motor_Mass[1].new_motor(249, 16, "2GR-FE", 3.5, 6, 4);
            Motor_Mass[1].prosmotr_motor();
            cout << "\n\nДвигатель №3";
            Motor_Mass[2] = Motor_Mass[0] + Motor_Mass[1];
            Motor_Mass[2].prosmotr_motor();
            /*cout << "\n\nДвигатель №2";
            cout << "\n\nКолесо №2";
            Kolesiko_mass[1].new_koleso(225, 55, 21, "Литье");
            Kolesiko_mass[1].prosmotr_koleso();
            cout << "\n\nКолесо №3";
            Kolesiko_mass[2].new_koleso(225, 55, 0, "Литье");
            Kolesiko_mass[2] = Kolesiko_mass[1] + Kolesiko_mass[0];
            Kolesiko_mass[2].prosmotr_koleso();
            */
            cout << "\n\nНажмите любую клавишу для возврата в меню.";
            _getch();
        }
        if (menu == '9')
        {
        }
    } while (menu != 0);
}
