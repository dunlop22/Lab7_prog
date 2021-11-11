#pragma once
using namespace std;
#include <string>

class Obchee
{
public:
    Obchee();
    void new_obchee_info();
    void new_obchee(double kolvo_mest_1, double massa_1, string name_1, double razgon_do_100_1, string tip_privoda_1, string tip_topliva_1, double obem_benzobaka_1);
    void prosmotr_obchee();
private:
    string name;
    string tip_privoda;
    string tip_topliva;
    double massa;
    double obem_benzobaka;
    double kolvo_mest;
    double razgon_do_100;
};

