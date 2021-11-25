#pragma once
using namespace std;
#include <string>
#include "Koleso.h"

class Koleso_Zapaska : public Koleso
{
public:
	string vid;


public:
	void Koleso_print();
	void set_vid(string vidok);
	void deep_cop(const Koleso& source);
};

