#include "home.h" // все нужное уже в этом файле

int main() {
	Human p1, p2("sereja", 35), p3(p2);

	p1.get_value();
	p2.get_value();
	p3.get_value();
	p3.set_value(30, "Alex");
	p3.get_value();

	Flat f1, f2(3), f3(f2);

	f1.get_value();
	f2.get_value();
	f3.get_value();

	Home h1, h2(10), h3(h2);

	h1.get_value();
	h2.get_value();
	h3.get_value();
}