#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include "Koleso.h"
#include "Obchee.h"
#include "Motor.h"
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
    do
    {
        system("cls");
        cout << "1) Добавление информации о колесах\n2) Добавление информации о коробке передач\n3) Добавление информации о двигателе\n4) Добавление общей информации\n5) Создание авто\n\n0) Выход";
        menu = _getch();
    } while (menu < '0' && menu > '5');
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
    }
    if (menu == '4')
    {

    }
    if (menu == '5')
    {

    }

}
