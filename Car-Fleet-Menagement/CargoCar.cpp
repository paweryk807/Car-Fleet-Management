#include"CargoCar.h"
using namespace std;

CargoCar::CargoCar() { capacity = 0; type = static_cast<CargoType>(0); cargoV = 0; }

CargoCar::CargoCar(const int cpct,const double cV, CargoType type) :capacity(cpct), cargoV(cV), type(type) {}

CargoCar::CargoCar(double CargoV, double Capacity, CargoType Type, std::string carBrand, std::string model, std::string vin, double weight) :
          Car(carBrand, model, vin, weight), cargoV(CargoV), capacity(Capacity), type(Type){};

CargoCar::CargoCar(CargoCar&& other) noexcept {
    this->cargoV = other.cargoV;
    this->capacity = other.capacity;
    this->type = other.type;
    this->weight = other.weight;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
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

CargoCar::CargoCar(const CargoCar& other) noexcept {
    this->cargoV = other.cargoV;
    this->capacity = other.capacity;
    this->type = other.type;
    this->weight = other.weight;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
    if (other.engine) {
        this->setEngine(other.engine->getCapacity(), other.engine->getHorsepower(), other.engine->getFuelConsumption(), other.engine->getMotorType());
    }
    this->updateFuelLevel(other.getFuelLevel());
    this->updateFuelTank(other.getFuelTank());
    this->lastCourse = other.lastCourse;
    this->setModel(other.getModel());
    this->setNumOfDoors(other.getNumOfDoors());
    this->tType = other.tType;
    this->setVin(other.getVin());
}
CargoCar& CargoCar::operator=(CargoCar& other) noexcept {
    this->cargoV = other.cargoV;
    this->capacity = other.capacity;
    this->type = other.type;
    this->weight = other.weight;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
    if (other.engine) {
        this->setEngine(other.engine->getCapacity(), other.engine->getHorsepower(), other.engine->getFuelConsumption(), other.engine->getMotorType());
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
std::string CargoCar::print(){
    std::ostringstream output;
 output << "Samochod dostawczy: \n"
        << "VIN : " << getVin() << "\n"
        << "marka : " << getCarBrand() << "\n"
        << "model : " << getModel() << "\n"
        << "typ nadwozia : ";

    switch (static_cast<int>(type)) {
    case 1: output << "ciezarowy\n";
        break;
    case 2: output << "pickup\n";
        break;
    case 3: output << "furgonetka\n";
        break;
    default: output << "dostawczy\n";
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

    if ( available == 1) output << "wynik przegladu : pozytywny\n";
    else output << "wynik przegladu : negatywny\n";
    output << "data ostatniego przegladu : " << getLastTechnicalExamDate() << "\n"
        << "komentarze do przegladu : " << getComments() << "\n"
        << "ilosc drzwi : " << getNumOfDoors() << "\n"
        << "dopuszczalna waga ladunku : "
        << to_string( capacity ) << "\n"
        << "dopuszczalna objetosc ladunku : "
        << to_string( cargoV ) << " m^3\n"
        << "pojemnosc silnika : " << setprecision(1) << getMotorCapacity() << "\n"
        << "moc silnika : " << getHorsepower() << "\n"
        << "pojemnosc baku paliwa : " << getFuelTank() << "\n"
        << "ilosc paliwa : " << getFuelLevel() << "\n"
        << "srednie zuzycie paliwa : " << getFuelConsumption() << "\n"
        << "przebieg : " << getCurrentMileage() << "\n"
        << "ostatnio przejechany dystans : " << getLastCourse() << "\n\n";
    return output.str();
}

ostream& CargoCar::operator<<(ostream& output)
{
    output << "Samochod dostawczy: \n"
        << "VIN : " << getVin() <<"\n"
        << "marka : " << getCarBrand() << "\n"
        << "model : " << getModel() << "\n"
        << "typ nadwozia : ";

    switch (static_cast<int>(getType())) {
    case 1: output << "ciezarowy\n";
        break;
    case 2: output << "pickup\n";
        break;
    case 3: output << "furgonetka\n";
        break;
    default: output << "dostawczy\n";
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
        << "dopuszczalna waga ladunku : "
        << to_string(getCapacity()) << "\n"
        << "dopuszczalna objetosc ladunku : "
        << to_string(getCargoV()) << " m^3\n"
        << "pojemnosc silnika : " << setprecision(1) << getMotorCapacity() << "\n"
        << "moc silnika : " << getHorsepower() << "\n"
        << "pojemnosc baku paliwa : " << getFuelTank() << "\n"
        << "ilosc paliwa : " << getFuelLevel() << "\n"
        << "srednie zuzycie paliwa : " << getFuelConsumption() << "\n"
        << "przebieg : " << getCurrentMileage() << "\n"
        << "ostatnio przejechany dystans : " << getLastCourse() << "\n\n";
    return output;
}

const CargoType CargoCar::getType() const noexcept {
    return type;
}
const double CargoCar::getCapacity() const noexcept {
    return capacity;
}

void CargoCar::updateCapacity(const double nCapacity) noexcept {
    if (capacity >= 0)
    {
        capacity = nCapacity;
    }
}

void CargoCar::updateType(const CargoType cType) noexcept {
    type = cType;
}
const double CargoCar::getCargoV() const noexcept {
    return cargoV;
}

void CargoCar::updateCargoV(const double cV) noexcept {
    cargoV = cV;
}

CargoCar::~CargoCar() {};



