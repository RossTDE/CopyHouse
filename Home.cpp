#include "Home.h"
#include <iostream>

void Human::get_value()
{
	cout << "Individual code: " << code << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Human::set_value(int a, string n) //менять имя и возраст можно, а личный код система менять запрещает, глобализация
{
	name = n;
	age = a;
}

void Flat::get_value()
{
	cout << "People in this flat: " << include << endl;
}


void Home::get_value()
{
	cout << "Number of flats: " << include << endl;
	//cout << "Number of people: " << PERSONAL_CODE << endl;
}

