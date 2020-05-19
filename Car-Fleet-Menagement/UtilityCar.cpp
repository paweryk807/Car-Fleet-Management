#include"UtilityCar.h"
using namespace std;

UtilityCar::UtilityCar() { this->type = UtilityType::utility; }

UtilityCar::UtilityCar(UtilityType type) :type(type) {}

UtilityCar::UtilityCar(UtilityCar&& other) noexcept {
    this->type = other.type;
    this->available = other.available;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
    this->weight = other.weight;
    if(other.engine){
     this->setEngine(other.engine->getCapacity(), other.engine->getHorsepower(),other.engine->getFuelConsumption(),other.engine->getMotorType());
    }
    this->updateFuelLevel(other.getFuelLevel());
    this->updateFuelTank(other.getFuelTank());
    this->lastCourse = other.lastCourse;
    this->setModel(other.getModel());
    this->setNumOfDoors(other.getNumOfDoors());
    this->tType = other.tType;
    this->setVin(other.getVin());

}
UtilityCar::UtilityCar(const UtilityCar& other) noexcept {
    this->type = other.type;
    this->available = other.available;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
    this->weight = other.weight;
    if(other.engine){
     this->setEngine(other.engine->getCapacity(), other.engine->getHorsepower(),other.engine->getFuelConsumption(),other.engine->getMotorType());
    }
    this->updateFuelLevel(other.getFuelLevel());
    this->updateFuelTank(other.getFuelTank());
    this->lastCourse = other.lastCourse;
    this->setModel(other.getModel());
    this->setNumOfDoors(other.getNumOfDoors());
    this->tType = other.tType;
    this->setVin(other.getVin());

}

UtilityCar::UtilityCar(UtilityType type, 
    std::string carBrand, std::string model, std::string vin, double weight) :
   Car(carBrand, model, vin, weight), type(type){};


UtilityCar& UtilityCar::operator=(UtilityCar& other) noexcept {
    this->type = other.type;
    this->available = other.available;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
	this->weight = other.weight;
    if(other.engine){
     this->setEngine(other.engine->getCapacity(), other.engine->getHorsepower(),other.engine->getFuelConsumption(),other.engine->getMotorType());
    }
    this->updateFuelLevel(other.getFuelLevel());
    this->updateFuelTank(other.getFuelTank());
    this->lastCourse = other.lastCourse;
    this->setModel(other.getModel());
    this->setNumOfDoors(other.getNumOfDoors());
    this->tType = other.tType;
    this->setVin(other.getVin());
    return *this;
}
const UtilityType UtilityCar::getUtype() const noexcept {
    return type;
}

void UtilityCar::updateType(UtilityType uType) {
    type = uType;
}

std::string UtilityCar::print()
{
    ostringstream output;
output << "Samochod uzytkowy: \n"
        << "VIN : " << getVin() << "\n"
        //<< "wymagana kategoria prawa jazdy : " << car.getDrivingLicenceCategory() << "\n"
        << "marka : " << getCarBrand() << "\n"
        << "model : " << getModel() << "\n"
        << "typ nadwozia : ";

    switch (static_cast<int>(type)) {
    case 1: output << "holownik\n";
        break;
    case 2: output << "smieciarka\n";
        break;
    case 3: output << "ambulans\n";
        break;
    case 4: output << "plug\n";
        break;
    default: output << "uzytkowy\n";
        break;
    }

    output << "typ silnika : ";
    switch (static_cast<int>(getmtType()))
    {
    case 1: output << "benzynowy\n";
        break;
    case 2: output << "diesel\n";
        break;
    case 3: output << "elektryczny\n";
        break;
    default: output << "brak\n";
        break;
    }

    output << "typ skrzyni biegow : ";
    switch (static_cast<int>(getTransmission()))
    {
    case 1: output << "polautomatyczna\n";
        break;
    case 2: output << "manualna\n";
        break;
    default: output << "automatyczna\n";
        break;
    }

    if (available == 1) output << "wynik przegladu : pozytywny\n";
    else output << "wynik przegladu : negatywny\n";
    output << "data ostatniego przegladu : " << getLastTechnicalExamDate() << "\n"
        << "komentarze do przegladu : " << getComments() << "\n"
        << "ilosc drzwi : " << getNumOfDoors() << "\n"
        << "pojemnosc silnika : " << setprecision(1) << getMotorCapacity ()<< "\n"
        << "moc silnika : " << getHorsepower() << "\n"
        << "pojemnosc baku paliwa : " << getFuelTank() << "\n"
        << "ilosc paliwa : " << getFuelLevel() << "\n"
        << "srednie zuzycie paliwa : " << getFuelConsumption() << "\n"
        << "przebieg : " << getCurrentMileage() << "\n"
        << "ostatnio przejechany dystans : " << getLastCourse() << "\n\n";
    return output.str();
}

ostream& UtilityCar::operator<<(ostream& output)
{
    output << "Samochod uzytkowy: \n"
        << "VIN : " << getVin() <<"\n"
     //   << "wymagana kategoria prawa jazdy : "<< getDrivingLicenceCategory() << "\n"
        << "marka : " << getCarBrand() << "\n"
        << "model : " << getModel() << "\n"
        << "typ nadwozia : ";

    switch (static_cast<int>(getType())) {
    case 1: output << "holownik\n";
        break;
    case 2: output << "smieciarka\n";
        break;
    case 3: output << "ambulans\n";
        break;
    case 4: output << "plug\n";
        break;
    default: output << "uzytkowy\n";
        break;
    }

    output << "typ silnika : ";
    switch (static_cast<int>(getmtType()))
    {
    case 1: output << "benzynowy\n";
            break;
    case 2: output << "diesel\n";
            break;
    case 3: output << "elektryczny\n";
            break;
    default: output << "brak\n";
            break;
    }

    output << "typ skrzyni biegow : ";
    switch (static_cast<int>(getTransmission()))
    {
    case 1: output << "polautomatyczna\n";
        break;
    case 2: output << "manualna\n";
        break;
    default: output << "automatyczna\n";
        break;
    }

    if (getResult() == 1) output << "wynik przegladu : pozytywny\n";
    else output << "wynik przegladu : negatywny\n";
    output << "data ostatniego przegladu : " << getLastTechnicalExamDate() << "\n"
        << "komentarze do przegladu : " << getComments() << "\n"
        << "ilosc drzwi : " << getNumOfDoors() << "\n"
        << "pojemnosc silnika : " << setprecision(1) << getMotorCapacity() << "\n"
        << "moc silnika : " << getHorsepower() << "\n"
        << "pojemnosc baku paliwa : " << getFuelTank() << "\n"
        << "ilosc paliwa : " << getFuelLevel() << "\n"
        << "srednie zuzycie paliwa : " << getFuelConsumption() << "\n"
        << "przebieg : " << getCurrentMileage() << "\n"
        << "ostatnio przejechany dystans : " << getLastCourse() << "\n\n";
    return output;
}

UtilityCar::~UtilityCar() {};
