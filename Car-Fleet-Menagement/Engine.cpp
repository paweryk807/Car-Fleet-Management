#include"Engine.h"

Engine::Engine(double mCap, double hP, double fCon, MotorType mT) {
	this->motorCapacity = mCap;
	this->horsepower = hP;
	this->fuelConsumption = fCon;
	this->mtType = mT;
}

Engine::Engine(const Engine&& e) noexcept {
	this->fuelConsumption = e.fuelConsumption;
	this->horsepower = e.horsepower;
	this->motorCapacity = e.motorCapacity;
	this->mtType = e.mtType;
}

std::string Engine::showParameters() {
	std::stringstream as;
	as << "Parametry silnika :\n"
		<< "Pojemnosc : " << motorCapacity << "\n"
		<< "Ilosc koni mechanicznych : " << horsepower << "\n"
		<< "Srednie spalanie : " << fuelConsumption << "\n"
		<< "Typ silnika : " << utils::toString(mtType) << "\n";
	return as.str();
}

double Engine::getCapacity(){
	return motorCapacity;
}

double Engine::getHorsepower() {
	return horsepower;
}

double Engine::getFuelConsumption() {
	return fuelConsumption;
}

MotorType Engine::getMotorType() {
	return mtType;
}

void Engine::setMotorCapacity(double capacity) {
	this->motorCapacity = capacity;
}

void Engine::setHorsepower(double hP) {
	this->horsepower = hP;
}

void Engine::setFuelConsumption(double fCon) {
	this->fuelConsumption = fCon;
}

void Engine::setMotorType(MotorType mt) {
	this->mtType = mt;
}
Engine::Engine() {}