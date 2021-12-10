    #define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "Koleso.h"
#include "Obchee.h"
#include "Avto.h"
#include "Motor.h"
#include "Korobka.h"
#include "Koleso_Zapaska.h"
#include <locale.h>
#include <string>

void table_print(Koleso Kol_Mass[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        cout << "*************************************************\n";
        for (int j = 0; j < 4; j++)
        {
            if (Kol_Mass[i][j].diametr_info() != -1)
            {
                cout << "* " << Kol_Mass[i][j].dannii() << " ";
            }
            else
            {
                cout << "*           ";
            }
        }
        cout << "*\n";
    }
    cout << "*************************************************\n";
}


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int menu;
    int podmenu;
    Obchee Obchie;
    Motor Motorik;
    Korobka Korobas;
    Avto Avtomobil;
    do
    {
        do
        {
            system("cls");
            cout << "1) Добавление информации о колесах\n2) Добавление информации о коробке передач\n3) Добавление информации о двигателе\n4) Добавление общей информации\n5) Создание авто\n6) Вызов конструктора базового класса через конструктор производного класса\n7) Перегрузка метода базового класса в производном классе\n8) Перегрузка оператора присваивания объекту производного класса объектов базового класса\n9) Виртуальные функции\n0) Абстрактный класс";
            menu = _getch();
        } while (menu < '0' && menu > '9');
        if (menu == '1')
        {
            Koleso Kolesiko;
            do
            {
                
                system("cls");
                
                cout << "Последний уникальный ID: " << setw(6) << setfill('0') << Koleso::id_return()  << endl;		//вывод не несущих нулей до числа
                cout << "\nОбщее количество созданных колес: " << Koleso::kolvo_return();
                cout << "\n\n1) Создание колеса со своими данными\n2) Создание колеса по конструктору\n";
                podmenu = _getch();
            } while (podmenu < '1' || podmenu > '3');
            if (podmenu == '1')
            {
                Kolesiko.new_koleso_info();
            }
            else if (podmenu == '2')
            {
                Kolesiko.new_koleso(225, 55, 17, "Литье");
            }
            system("cls");
            cout << "Новое колесо:\n\n";
            cout << Kolesiko;
            //(*Kolesiko).prosmotr_koleso();
            _getch();
            int zap;
            cout << "\n\nВведите тип запасного колеса\n\n1) Полноразмерное\n2) Докатка\n3) Отсутствует";
            do
            {
                zap = _getch();
            } while (zap < '1' || zap > '3');
            Koleso_Zapaska Zapaska;
            if (zap == '1') //копирование параметров из основного колеса
            {
                Zapaska.deep_copy(Kolesiko);
                Zapaska.set_vid("Полнормазмерное");
            }
            else if (zap == '2')
            {
                Zapaska.new_koleso_info();
                Zapaska.set_vid("Докатка");
            }
            else if (zap == '3')
            {
                Zapaska.set_vid("Отсутствует");
            }
            system("cls");
            if (zap == '1' || zap == '2')
            {
                cout << "Введите количество проколов в запасной шине: ";
                int prokol;
                do
                {
                    cin >> prokol;
                } while (prokol < 0);
                Zapaska.prokol_zapaska(prokol);
            }
            system("cls");
            (Kolesiko).prosmotr_koleso();
            cout << "\n\nЗапасное колесо: ";
            if (zap != '3')
            {
                Zapaska.Koleso_print();
            }
            else
            {
                cout << Zapaska.vid;
            }
            
            
            cout << "\n\nНажмите любую клавишу для возврата в меню.";
            _getch();
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
            Koleso_Zapaska* Zapaska = new Koleso_Zapaska(12);
            Zapaska->Koleso_print();
            cout << "\n\nНажмите любую клавишу для возврата в меню";
            _getch();
            
        }
            /*
        {
            system("cls");
            Koleso* kol1 = new Koleso();
            Koleso* kol2 = new Koleso(12);
            cout << "Конструктор без параметров: \n\n";
            kol1->prosmotr_koleso();
            cout << "\n\nКонструктор с одним параметром: \n\n";
            kol2->prosmotr_koleso();
            cout << "\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }*/
        /*
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
        */
        
        if (menu == '7')
        {
            
            Koleso_Zapaska Zapaska;
            Koleso kol1;
            system("cls");
            kol1.set(17, 55, 225, "Литье");
            Zapaska.set(13, 75, 145, "Литье", "Докатка");
            
            
            cout << "Вид запасного колеса: ";
            Zapaska.Koleso_print();
            
            cout << "\n\n\n";
            kol1.prosmotr_koleso();

            
            /*
            system("cls");
            Koleso *kol_mass = new Koleso[3];
            for (int i = 0; i < 3; i++)
            {
                kol_mass[i] = *new Koleso(12);
                cout << "\n\n";
                kol_mass[i].prosmotr_koleso();
            }*/
            
            
            
           /* system("cls");
            
            Koleso *kol = new Koleso[3];
            for (int i = 0; i < 3; i++)
            {
                kol[i] = *new Koleso(12);
                cout << "\n\nЭлемент № " << (i + 1) << "\n\n";
                kol[i].prosmotr_koleso();
            }
            */
            cout << "\n\nНажмите любую клавишу для возврата в меню";
            _getch();
        }

        /* {
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
        */
if (menu == '8')
{
    system("cls");
    Koleso_Zapaska* Zapaska = new Koleso_Zapaska(14);
    Zapaska->prokol_zapaska(3);
    
    Koleso_Zapaska* Zapaska1 = new Koleso_Zapaska(13);
    Zapaska1->prokol_zapaska(1);
    Zapaska1->new_koleso(110, 30, 15, "Штамп");

    Zapaska->set_vid("Докатка");
    Zapaska1->set_vid("Полноразмерное");

    cout << "Колесо №1:";
    Zapaska->Koleso_print();
    
    cout << "\n\nКолесо №2:";
    Zapaska1->Koleso_print();
    cout << "\n\n*************************************************";
    Zapaska1 = Zapaska;

    cout << "\n\nКолесо №1 после внесения изменений:";
    Zapaska->Koleso_print();

    cout << "\n\nКолесо №2 после внесения изменений:";
    Zapaska1->Koleso_print();


    /*
    cout << "Введите количество комплектов колес для добавления в одномерный массив: ";
    int n;
    cin >> n;
    Koleso Koleso_Mass[10];



    for (int i = 0; i < n; i++)
    {
        Koleso_Mass[i].new_koleso(180 + i * 7, 30 + i * 3, 13 + i * 2, "Japan Enkei №" + (i + 1));
    }
    for (int i = 0; i < n; i++) 
    {
        Koleso_Mass[i].prosmotr_koleso();
        cout << "\n\n";
    }*/
    cout << "\n\nНажмите любую клавишу для возврата в меню.";
    _getch();
}
/* {
    Koleso* kol = new Koleso(15);

    Koleso* kol2 = new Koleso(*kol);    //глубокое копирование
    Koleso kol3;
    Koleso& kol1 = *kol; //поверхностное копирование

    kol->dia_izm();

    cout << "\n\n\nОригинал: ";
    kol->prosmotr_koleso();

    cout << "\n\n\nПоверхностное копирование: ";
    kol1.prosmotr_koleso();

    cout << "\n\n\nГлубокое копирование: ";
    kol2->prosmotr_koleso();
    cout << "\n\nНажмите любую клавишу для возврата в меню";
    _getch();
}
*/
/*
{
    /do
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
*/
if (menu == '9')
{
    
    
    system("cls");



    Koleso kol;
    Koleso_Zapaska kol_zap;
    

    Koleso* kolesik = &kol;
    kol.new_koleso(110, 30, 15, "Штамп");
    

    kol_zap.new_koleso(110, 30, 20, "Штамп");

    cout << kolesik->get_tip();
    kolesik = &kol_zap;
    cout << kolesik->get_tip();


    cout << "\n\nНажмите любую клавишу для возврата в меню.";
    _getch();

    

    /*
    Koleso Kol_Mass[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Kol_Mass[i][j] = Koleso(-1);
        }
    }
    do
    {
        Koleso temp;
        temp.new_koleso_info();
        system("cls");

        table_print(Kol_Mass);

        temp.prosmotr_koleso();
        int m, k;
        do
        {
            cout << "\n\nВведите номер строки: ";
            cin >> m;
        } while (m < 1 || m > 4);

        do
        {
            cout << "\n\nВведите номер столбца: ";
            cin >> k;
        } while (k < 1 || k > 4); 
        Kol_Mass[m - 1][k - 1].deep_copy(temp);
        system("cls");
        table_print(Kol_Mass);
        cout << "0 - Выход\nЛюбая клавиша - ввод нового колеса ";
        podmenu = _getch();
    } while (podmenu != '0');
    */
}
        /*
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
        */
if (menu == '0')
{
    system("cls");
    Koleso *kol= new Koleso();
    kol->prosmotr_koleso();


    cout << "\n\nПериметр колеса: " << kol->perimetr() << "мм";
    
    cout << "\n\nОбъем колеса: " << kol->obem() << "м^3";
    cout << "\n\nНажмите любую клавишу для возврата в меню.";
    _getch();
}
    } while (TRUE);
}