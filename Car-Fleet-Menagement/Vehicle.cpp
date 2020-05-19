#include"Vehicle.h"

using namespace std;

Vehicle::Vehicle(string v, double weight) {
	vin.set(v);
	this->weight = weight;
	this->currentMileage = 0;
	this->lastCourse = 0;
	this->available = 0;
	this->gotEngine = false;
	this->engine = nullptr;
	this->tType = Transmission::none;
}

const double Vehicle::getWeight() const noexcept {
	return weight;
}
const double Vehicle::getLastCourse() const noexcept {
	return lastCourse;
}

const double Vehicle::getCurrentMileage() const noexcept {
	return currentMileage;
}
const bool Vehicle::getAvailable() const noexcept { return available; }

void Vehicle::updateLastCourse(const double lC) noexcept {
	lastCourse = lC;
}
void Vehicle::updateMileage(const double mileage) noexcept {
	currentMileage = mileage;
}
	
void Vehicle::updateAvailable(const bool av) noexcept {
	this->available = av;
}

void Vehicle::setEngine(double motorCapacity, double horsepower, double fuelConsumption, MotorType motorType) {
	this->gotEngine = true;
	if (!engine) {
		engine = new Engine(motorCapacity, horsepower, fuelConsumption, motorType);
	}
	else {
		engine->setMotorCapacity(motorCapacity);
		engine->setHorsepower(horsepower);
		engine->setFuelConsumption(fuelConsumption);
		engine->setMotorType(motorType);
	}
}


double Vehicle::getFuelConsumption() const noexcept {
	if (engine)	{
	return engine->getFuelConsumption();
	}
	else return 0;
}

const double Vehicle::getHorsepower() const noexcept {
	if (engine) {
		return engine->getHorsepower();
	}
	else return 0; 
}

const MotorType Vehicle::getmtType() const noexcept {
	if (engine) {
		return engine->getMotorType();
	}
	else return MotorType::none;
}
const Transmission Vehicle::getTransmission() const noexcept {
	 return tType; 
}
const double Vehicle::getMotorCapacity() const noexcept {
	if (engine) {
		return engine->getCapacity();
	}
	else return 0;
}

const string Vehicle::getLastTechnicalExamDate() const noexcept { return date.getLastTechnicalExamDate(); }

const string Vehicle::getNextTechnicalExamDate() const noexcept { return date.getNextTechnicalExamDate(); }

const bool Vehicle::technicalExamIsValid(const string& sdate) const noexcept{ return date.isValid(sdate); }

const bool Vehicle::getResult() const noexcept { return date.getResult(); }

const string Vehicle::getComments() const noexcept { return date.getComments(); }

const bool Vehicle::haveEngine() const noexcept
{
	return gotEngine;
}

TechnicalExamination Vehicle::getDate() noexcept
{
	return date;
}

double Vehicle::getLatestCost(double fuelCost)  noexcept {
	if (engine)
		return ((getLastCourse() / 100) * (this->engine->getFuelConsumption())* fuelCost);
	else return 0;
}

const std::string Vehicle::getVin() const noexcept
{
	return vin.get();
}
	
void Vehicle::updateWeight(double w) {
	if (weight > 0) {
		weight = w;
	}
}
void Vehicle::updateLastTechnicalExamDate(const string& xdate) noexcept {
	date.updateLastTechnicalExamDate(xdate);
}

void Vehicle::updateResult(bool res) noexcept {
	date.updateResult(res);
}

void Vehicle::updateComments(const string& com) noexcept {
	date.updateComments(com);
}

void Vehicle::updateHorsepower(const double hp) {
	if (gotEngine) {
		this->engine->setHorsepower(hp);
	}
}

void Vehicle::updateMotorCapacity(const double mCapacity) {
	if (gotEngine) {
		this->engine->setMotorCapacity(mCapacity);
	}
}

void Vehicle::updateMotorType(const MotorType type) {
	if (gotEngine) {
		this->engine->setMotorType(type);
	}
}

void Vehicle::updateTransmission(const Transmission type) noexcept {
	tType = type;
}

void Vehicle::updateFuelConsumption(const double fuelCnsmptn) {
	if (gotEngine && fuelCnsmptn > 0) this->engine->setFuelConsumption(fuelCnsmptn);
}

void Vehicle::updateTechnicalExamResult(bool result) noexcept {
	date.updateResult(result);
}

bool Vehicle::operator<(Vehicle const& object) noexcept {
	if (gotEngine) {
		if (engine->getFuelConsumption() < object.engine->getFuelConsumption()) return 1;
		else return 0;
	}
	else return 0;
}

Vehicle::~Vehicle() {
	if (gotEngine) {
		delete engine;
	}
};
