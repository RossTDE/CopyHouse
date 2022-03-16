#pragma once

#include <iostream>
#include <string>
using namespace std;

static int PERSONAL_CODE(0);

/* Создайте программу, имитирующую многоквартирный
дом. Необходимо иметь классы “Человек”, “Квартира”,
“Дом”. Класс “Квартира” содержит динамический массив
объектов класса “Человек”. Класс “Дом” содержит массив
объектов класса “Квартира”.
Каждый из классов содержит переменные-члены и функции-члены,
которые необходимы для предметной области класса.
Например, для ФИО в классе “Человек”.
Не забывайте обеспечить классы различными конструкторами, деструкторами.
В main протестировать работу полученного набора классов. */

class Human {
	int age;
	string name;
	int code = 0; //коммунизм
public:
	Human() {
		PERSONAL_CODE++;
		code = PERSONAL_CODE;
		age = 0; //неизвестно
		name = "unknown"; //неизвестно
	}
	Human(string n, int a) {
		PERSONAL_CODE++;
		code = PERSONAL_CODE;
		age = a;
		name = n;
	}
	Human(const Human& h) { //почему бы не клонировать людей(копирующий конструктор)
		PERSONAL_CODE++; //ну это надо по любому делать, чтоб вести счет
		code = PERSONAL_CODE++; //не можем копировать, тк если переданный обьект не последний номер - нарушится счет
		age = h.age;
		name = h.name;
	}
	//деструктор не требуется
	void get_value();
	void set_value(int, string);
};

class Flat {
	Human* flat;
	int include = 1;
public:
	Flat() : Flat(1){} // если не передано, строим однокомнатную
	Flat(int i) {
		include = i;
		flat = new Human[include];
	}
	Flat(const Flat& fl) { // копирующий конструктор
		include = fl.include;
		flat = new Human[include];
	}
	~Flat() {
		delete[] flat;
	}

	void get_value();
	// сеттеры не нужны, тк значение определяется при создании
};

class Home {
	Flat* home;
	int include;
public:
	Home() : Home(100) {}
	Home(int i) {
		include = i;
		home = new Flat[include];
	}
	Home(const Home& h) { //создает такой же дом
		include = h.include;
		home = new Flat[include];
	}
	~Home() {
		delete[] home;
	}

	void get_value();
	// сеттеры не нужны, тк значение определяется при создании
};