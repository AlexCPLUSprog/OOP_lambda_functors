#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include "Printer.h"
#include <memory>

using namespace Engine;

// Функторы и лямбды

// Функтор - класс, у которого перегружен оператор ()
class Incrementer {
public:
	Incrementer(int x) : _x(x){}

	int operator()(int y) {
		return _x + y;
	}

	int operator()(int y, double z) {
		return _x + y + z;
	}

	int myFunc(int y) {
		const auto add = [y, this](int a) {	// _x  поле надо вписывать через "this". Просто "this" передается по ссылке, а "*this" - это копирование
			return _x + y + a;
		};
		return add(5);
	}

private:
	int _x;
};

int main() {

	// функтор
	/*Incrementer inc(50);
	int a = inc(5);
	std::cout << a << '\n';

	// лямбда
	// [] - capture clause
	const auto myinc = [=, &a](int number) -> int {	// копия "а" сохранится в функции. Можно определить захват по умолчанию, например [=] - захват копированием, [&] - берем все по ссылке
		return number + 5 + a;
	};
	
	// [&total, factor]
	// [factor, &total]
	// [&, factor]
	// [=, &total]
	
	std::cout << myinc(6) << '\n';

	std::cout << inc.myFunc(3) << '\n';
	std::cout << "=====================\n";

	std::vector<int> vec { 1, -4, 3, -2 };

	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	std::sort(vec.begin(), vec.end());

	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	std::sort(vec.begin(), vec.end(), [](int a, int b) {
		return std::abs(a) > std::abs(b);	// abs берет число по модулю
		});

	for (const auto el : vec) {
		std::cout << el << " ";
	}
	std::cout << '\n';

	// namespace
	Printer p;
	p.printDefault();
	std::cout << "=====================\n";*/

	//
	std::shared_ptr<IVehicle> c = std::make_shared<Car>(50);
	std::cout << "Vehicle speed: " << c->getSpeed() << '\n';
	c->printType();

	std::cout << "=====================\n";

	std::shared_ptr<IVehicle> m = std::make_shared<Motorcycle>(40);
	std::shared_ptr<IVehicle> v = std::make_shared<Van>(30);

	std::vector<std::shared_ptr<IVehicle>> veh;
	veh.push_back(c);
	veh.push_back(m);
	veh.push_back(v);

	Printer tr(veh);
	
	tr.printAll(veh);


}