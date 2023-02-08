#pragma once
#include <iostream>
#include <vector>


namespace Engine {

	
	class Printer
	{
	public:
		Printer(std::vector <std::shared_ptr<IVehicle>>& veh);
		void printDefault();
		void printAll(std::vector <std::shared_ptr<IVehicle>>& veh);
		
	private:
		std::vector<std::shared_ptr<IVehicle>> _veh;
	};

}


class IVehicle {
public:
	virtual int getSpeed() const = 0;
	virtual void printType() const = 0;
	virtual ~IVehicle() {}
};


class Car : public IVehicle {
public:
	Car(int speed) : _speed(speed) {}

	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Car\n";
	}
private:
	int _speed;
};

class Motorcycle : public IVehicle {
public:
	Motorcycle(int speed) : _speed(speed) {}

	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Motorcycle\n";
	}
private:
	int _speed;
};

class Van : public IVehicle {
public:
	Van(int speed) : _speed(speed) {}

	int getSpeed() const override {
		return _speed;
	}
	void printType() const override {
		std::cout << "Van\n";
	}
private:
	int _speed;
};


