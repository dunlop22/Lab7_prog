#include "Avto.h";
#include <iostream>
using namespace std;
Avto::Avto()
{
}

void Avto::new_danii_kolesa(double diametr, double visota)
{
    Kolesik.diametr = diametr;
    Kolesik.visota = visota;
}

void Avto::new_avto()
{
    Motor Mot;
    Koleso Kol;
    Korobka Korob;
    Obchee Obch;
    
    Obch.new_obchee(5, 1500, "Toyota", 7, "4WD", "Бензин", 65);
    Mot.new_motor(100, 10, "FB20", 2, 4, 4);
    Korob.new_korobka_peredach(5, "АКПП");
    //Kol.new_koleso(225, 55, 17, "Литье");

    Obchie = Obch;
    Motorik = Mot;
    Kolesik= Kol;
    Koroba = Korob;
}


void Avto::prosmotr_avto()
{
    Avto::Obchie.prosmotr_obchee();
    Avto::Motorik.prosmotr_motor();
    Avto::Kolesik.prosmotr_koleso();
    Avto::Koroba.prosmotr_korobka_peredach();
}
