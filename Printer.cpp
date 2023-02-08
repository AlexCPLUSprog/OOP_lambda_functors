#include "Printer.h"

using namespace Engine;


Printer::Printer(std::vector<std::shared_ptr<IVehicle>>& veh) : _veh(veh) {}


void Printer::printDefault() {
	std::cout << "Default Print Message\n";
}


void Printer::printAll(std::vector<std::shared_ptr<IVehicle>>& veh) {
	for (const auto el : veh) {
		std::cout << el << '\n';
	}
}



