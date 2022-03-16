#pragma once

#include <iostream>
#include <string>
using namespace std;

static int PERSONAL_CODE(0);

/* �������� ���������, ����������� ���������������
���. ���������� ����� ������ ��������, ����������,
����. ����� ���������� �������� ������������ ������
�������� ������ ��������. ����� ���� �������� ������
�������� ������ ����������.
������ �� ������� �������� ����������-����� � �������-�����,
������� ���������� ��� ���������� ������� ������.
��������, ��� ��� � ������ ��������.
�� ��������� ���������� ������ ���������� ��������������, �������������.
� main �������������� ������ ����������� ������ �������. */

class Human {
	int age;
	string name;
	int code = 0; //���������
public:
	Human() {
		PERSONAL_CODE++;
		code = PERSONAL_CODE;
		age = 0; //����������
		name = "unknown"; //����������
	}
	Human(string n, int a) {
		PERSONAL_CODE++;
		code = PERSONAL_CODE;
		age = a;
		name = n;
	}
	Human(const Human& h) { //������ �� �� ����������� �����(���������� �����������)
		PERSONAL_CODE++; //�� ��� ���� �� ������ ������, ���� ����� ����
		code = PERSONAL_CODE++; //�� ����� ����������, �� ���� ���������� ������ �� ��������� ����� - ��������� ����
		age = h.age;
		name = h.name;
	}
	//���������� �� ���������
	void get_value();
	void set_value(int, string);
};

class Flat {
	Human* flat;
	int include = 1;
public:
	Flat() : Flat(1){} // ���� �� ��������, ������ �������������
	Flat(int i) {
		include = i;
		flat = new Human[include];
	}
	Flat(const Flat& fl) { // ���������� �����������
		include = fl.include;
		flat = new Human[include];
	}
	~Flat() {
		delete[] flat;
	}

	void get_value();
	// ������� �� �����, �� �������� ������������ ��� ��������
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
	Home(const Home& h) { //������� ����� �� ���
		include = h.include;
		home = new Flat[include];
	}
	~Home() {
		delete[] home;
	}

	void get_value();
	// ������� �� �����, �� �������� ������������ ��� ��������
};