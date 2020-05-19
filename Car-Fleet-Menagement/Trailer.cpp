
#include"Trailer.h"
#include "CargoCar.h"

using namespace std;

Trailer::Trailer(double cargoV, double capacity, TrailerType type, std::string brand, std::string vin, double weight) :
	Vehicle(vin, weight), cargoV(cargoV), capacity(capacity), trailerType(type), brand(brand) {};

Trailer::Trailer(Trailer& other) noexcept : Vehicle(other.getVin(), other.weight) {
	this->capacity = other.capacity;
    this->trailerType = other.trailerType;
	this->available = other.available;
	this->currentMileage = other.currentMileage;
    this->date = other.date;
	this->lastCourse = other.lastCourse;
	this->cargoV = other.cargoV;
	this->brand = other.brand;
}
Trailer::Trailer(Trailer&& other) noexcept : Vehicle(other.getVin(), other.weight) {
	this->gotEngine = false;
	this->capacity = other.capacity;
    this->trailerType = other.trailerType;
	this->available = other.available;
	this->currentMileage = other.currentMileage;
	this->lastCourse = other.lastCourse;
	this->lastCourse = other.lastCourse;
	this->cargoV = other.cargoV;
	this->brand = other.brand;
	this->date = other.date;

}

const std::string Trailer::getBrand() const noexcept { return brand; }

const double Trailer::getCapacity() const noexcept { return capacity; }

const double Trailer::getCargoV() const noexcept { return Trailer::cargoV; }

const std::string Trailer::getLastTechnicalExamDate() const noexcept { return date.getLastTechnicalExamDate(); }

const std::string Trailer::getNextTechnicalExamDate() const noexcept { return date.getNextTechnicalExamDate(); }

const bool Trailer::getResult() const noexcept { return date.getResult(); }

const TrailerType Trailer::getType() const noexcept { return trailerType; }

const bool Trailer::technicalExaminationIsValid(const string& sDate) const noexcept { return date.isValid(sDate); };

void Trailer::updateBrand(const string& brand) noexcept {
	this->brand = brand;
}

void Trailer::updateCapacity(double capacity) noexcept {
	this->capacity = capacity;
}

void Trailer::updateCargoV(double v) noexcept {
	this->cargoV = v;
}


void Trailer::updateTrailerType(TrailerType trailerType) noexcept {
    this->trailerType = trailerType;
}

void Trailer::updateLastTechnicalExamDate(const string& xdate) noexcept {
    date.updateLastTechnicalExamDate(xdate);
}

void Trailer::updateResult(bool res) noexcept {
    date.updateResult(res);
}

void Trailer::updateComments(const string& com) noexcept {
   date.updateComments(com);
}



Trailer::~Trailer() {}

ostream& operator<<(ostream& output, const Trailer t) noexcept
{
	output  << "Marka : "							<< t.brand << std::endl
			<< "Dopuszczalna objetosc ladunku : "	<< to_string(t.cargoV) << std::endl
			<< "Dopuszczalna waga ladunku : "		<< to_string(t.capacity) << std::endl
			<< "Typ : "								<< utils::toString(t.trailerType) << std::endl
			<< t.date;
	return output;
}
