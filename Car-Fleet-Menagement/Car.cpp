#include"Car.h"
#include <fstream>
#include <sstream>
#include <istream>
#include <ostream>

Car::Car(std::string carBrand, std::string model, std::string vin, double weight)
    : Vehicle(vin, weight), carBrand(carBrand), model(model) {
    this->fuelLevel = 0;
    this->fuelTank = 0;
    this->numbOfDoors = 2;
}; 
  
Car::~Car() { }

const string Car::getVin()        const noexcept { return vin.get(); }

const string Car::getModel()      const noexcept { return model; }

const string Car::getCarBrand()   const noexcept { return carBrand; }

int Car::getNumOfDoors()          const noexcept { return numbOfDoors; }

int Car::getMaxPassengers()       const noexcept { return 0; }

BodyType Car::getBodyType()       const noexcept { return static_cast<BodyType>(0); }

const CargoType Car::getType()    const noexcept { return static_cast<CargoType>(0); }

const double Car::getCapacity()   const noexcept { return 0.0; }

const double Car::getCargoV()     const noexcept { return 0.0; }

const UtilityType Car::getUtype() const noexcept { return static_cast<UtilityType>(0); }

std::string Car::print()
{
	return "";
}

const double Car::getFuelTank()   const noexcept { return fuelTank; }

const double Car::getFuelLevel()  const noexcept { return fuelLevel; }

void Car::setModel(const string& model) noexcept {
    this->model = model; 
}

void Car::setBrand(const string& carBrand) noexcept {
    this->carBrand = carBrand;
}

void Car::setNumOfDoors(const int doors) noexcept {
    if (doors >= 0)
        numbOfDoors = doors;
}

void Car::setVin(const string& vin) noexcept {
    this->vin.set(vin);
}

void Car::updateFuelTank(const double tankCapacity) noexcept {
	fuelTank = tankCapacity;
}

void Car::updateFuelLevel(const double level) noexcept {
	fuelLevel = level;
}

std::istream& Car::put(std::istream& in) {
    std::string carBrand;
    std::string model;
    double weight;
    std::string vin;

    std::cout << "Marka: ";
    in >> carBrand;

    std::cout <<"Model: ";
    in >> model;

    std::cout <<"Waga: ";
    in >> weight;
    
    std::cout <<"Vin: ";
    in >> vin;

    this->setBrand(carBrand);
    this->setModel(model);
    this->updateWeight(weight);
    this->setVin(vin);
    return in;
}

std::string Car::getString() const{
    std::ostringstream os;
    os << *this;
    return os.str();
}

std::ostream& operator << (std::ostream& out, const Car& car) {
    out << "marka: "                    << car.getCarBrand()
        <<", liczba drzwi: "            << car.getNumOfDoors()
        <<", model: "                   << car.getModel()
        <<", Vin: "                     << car.getVin();
    return out;
}

std::istream& operator >> (std::istream& in, Car& c) {
    return c.put(in);
}
