#include"PassengerCar.h"
#include <ostream>
#include "Utils.h"

PassengerCar::PassengerCar(const PassengerCar&& other) noexcept{
    this->bodytype = other.bodytype;
    this->maxPassengers = other.maxPassengers;
    this->setBrand(other.getCarBrand());
    this->available = other.available;
	this->weight = other.weight;
    this->currentMileage = other.currentMileage;
    this->date = other.date;
    if(other.engine){
        this->gotEngine = true;
        this->engine = new Engine(move(*other.engine));
    }
    this->updateFuelLevel(other.getFuelLevel());
    this->updateFuelTank(other.getFuelTank());
    this->lastCourse = other.lastCourse;
    this->setModel(other.getModel());
    this->setNumOfDoors(other.getNumOfDoors());
    this->tType = other.tType;
    this->setVin(other.getVin());

}

PassengerCar::PassengerCar():Car(),maxPassengers(0), bodytype(BodyType::passenger){};

PassengerCar::PassengerCar(const int maxPassengers, BodyType bodytype, 
    std::string carBrand, std::string model, std::string vin, double weight) :
   Car(carBrand, model, vin, weight), maxPassengers(maxPassengers), bodytype(bodytype){};

BodyType PassengerCar::getBodyType() const noexcept{
    return bodytype;
}

int PassengerCar::getMaxPassengers() const noexcept {
    return maxPassengers;
}

void PassengerCar::setMaxPassengers(const int passengers) noexcept {
    if (passengers >= 0)
        maxPassengers = passengers;
}

void PassengerCar::setBodyType(BodyType type) noexcept {
    bodytype = type;
}

std::string PassengerCar::print()
{
    ostringstream output;
    output << "Samochod osobowy: \n"
        << "VIN : " << getVin() <<"\n"
        << "marka : " << getCarBrand() << "\n"
        << "model : " << getModel() << "\n"
        << "typ nadwozia : ";

    switch (static_cast<int>(bodytype)) {
    case 1: output << "sedan\n";
        break;
    case 2: output << "liftback\n";
        break;
    case 3: output << "hatchback\n";
        break;
    case 4: output << "kombi\n";
        break;
    case 5: output << "kabriolet\n";
        break;
    case 6: output << "minivan\n";
        break;
    default: output << "osobowy\n";
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
        << "dopuszczalna ilosc pasazerow : "
        << to_string(getMaxPassengers()) << "\n"
        << "pojemnosc silnika : " << setprecision(1) << getMotorCapacity() << "\n"
        << "moc silnika : " << getHorsepower() << "\n"
        << "pojemnosc baku paliwa : " << getFuelTank() << "\n"
        << "ilosc paliwa : " << getFuelLevel() << "\n"
        << "srednie zuzycie paliwa : " << getFuelConsumption() << "\n"
        << "przebieg : " << getCurrentMileage() << "\n"
        << "ostatnio przejechany dystans : " << getLastCourse() << "\n\n";
    return output.str();
}

std::istream& PassengerCar::put(std::istream& in) {
    Car::put(in);
    int maxPassengers;
    int style;

    std::cout << "Ilosc pasazerow: ";
    in >> maxPassengers;

    std::cout << "typ nadwozia: ";
    in >> style;


    this->setMaxPassengers(maxPassengers);
    this->setBodyType(static_cast<BodyType>(style));
    return in;
}
std::string PassengerCar::getString() const
{
    std::ostringstream out;
    out << Car::getString() << std::endl;
    out << ", ilosc pasazerow: " << getMaxPassengers()
        << ", typ nadwozia: " << utils::toString(getBodyType());
    return out.str();
}

std::ostream& PassengerCar::operator << (std::ostream& out)
{
    out << Car::getString() << std::endl;
    out <<", ilosc pasazerow: "          << getMaxPassengers()
        <<", typ nadwozia: "             << utils::toString(getBodyType());
    return out;
}

std::ostream& operator << (std::ostream& out, const PassengerCar& car)
{
    out << car.getString();
    return out;
}

std::istream& operator >> (std::istream& in, PassengerCar& c) {
    return c.put(in);
}
