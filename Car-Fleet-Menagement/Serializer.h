#pragma once
#pragma once
#include "PassengerCar.h"
#include "CargoCar.h"
#include "UtilityCar.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include "Driver.h"
#include "Trailer.h"
#include "Task.h"
using namespace std;
template <class T>
/** Serializer wykorzystywany jest w programie do odczytu oraz zapisu danych do plikow.
    Uzywany jest rowniez do dodawania obiektow do list po pobraniu danych od uzytkownika 
*/
struct Serializer{
};
template<>
struct Serializer<Driver> {
    static Driver deserialize(std::string& input)
    {
        const char driver_delimiter[] = ";";
        char* next_token1 = nullptr;
        std::ostringstream os;
        std::string id =            strtok_s(const_cast<char*>(input.c_str()), driver_delimiter, &next_token1);
        std::string name =          strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string secondName =    strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string available =     strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string licenses =      strtok_s(nullptr, driver_delimiter, &next_token1);

        return Driver(std::stoi(id), name, secondName, std::stoi(available), licenses);
    };
    static std::string serialize(const Driver& c)
    {
        const char delimiter[] = ";";
        std::ostringstream os;
        os << c.getId() << delimiter
            << c.getName() << delimiter
            << c.getSecondName() << delimiter
            << c.getAvailable() << delimiter
            << c.getLicenses();
        return os.str();
    };
};

template<>
struct Serializer<Task> {
    static Task deserialize(std::string& input)
    {
        const char driver_delimiter[] = ";";
        char* next_token1 = nullptr;
        std::ostringstream os;
        std::string id =                strtok_s(const_cast<char*>(input.c_str()), driver_delimiter, &next_token1);
        std::string driverId =          strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string carVin =            strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string trailerVin =        strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string start =             strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string destination =       strtok_s(nullptr, driver_delimiter, &next_token1);
		std::string distance =          strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string date =              strtok_s(nullptr, driver_delimiter, &next_token1);
        std::string value =             strtok_s(nullptr, driver_delimiter, &next_token1);

        return Task(std::stoi(id),std::stoi(driverId),carVin,trailerVin,std::stod(distance),start,destination,date,std::stod(value));
    };
    static std::string serialize(const Task& c)
    {
        const char delimiter[] = ";";
        std::ostringstream os;
        os << c.getId()             << delimiter
            << c.getDriverId()      << delimiter
            << c.getCarVin()        << delimiter
            << c.getTrailerVin()    << delimiter
            << c.getStart()         << delimiter
			<< c.getDestination()   <<delimiter
            << c.getDistance()      << delimiter
            << c.getDate()          << delimiter
            << c.getValue();
        return os.str();
    };
};

template<>
struct Serializer<Trailer> {
    static Trailer deserialize(std::string& input)
    {
        const char trailer_delimiter[] = ";";
        char* next_token1 = nullptr;
        std::ostringstream os;
        std::string brand =         strtok_s(const_cast<char*>(input.c_str()), trailer_delimiter, &next_token1);
        std::string cargoV =        strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string capacity =      strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string weight =        strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string result =        strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string date =          strtok_s(nullptr, trailer_delimiter, &next_token1);
		std::string comments =      strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string trailerType =   strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string vin =           strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string currentMileage =strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string lastCourse =    strtok_s(nullptr, trailer_delimiter, &next_token1);
        std::string available =     strtok_s(nullptr, trailer_delimiter, &next_token1);
        Trailer tmp(std::stod(cargoV), std::stod(capacity), utils::toTrailerType(std::stoi(trailerType)), brand, vin, std::stod(weight));
        // setter center 
        tmp.updateBrand(brand);
        tmp.updateCargoV(std::stod(cargoV));
        tmp.updateCapacity(std::stod(capacity));
        tmp.updateWeight(std::stod(weight));
        tmp.updateResult(std::stoi(result));
        tmp.updateLastTechnicalExamDate(date);
        tmp.updateComments(comments);
        tmp.updateTrailerType(static_cast<TrailerType>(stoi(trailerType)));
        tmp.updateMileage(std::stod(currentMileage));
        tmp.updateLastCourse(std::stod(lastCourse));
        tmp.updateAvailable(std::stoi(available));
        return tmp;
    };
    static std::string serialize(const Trailer& c)
    {
        const char delimiter[] = ";";
        std::ostringstream os;
        os << c.getBrand() << delimiter
            << c.getCargoV() << delimiter
            << c.getCapacity() << delimiter
            << c.getWeight() << delimiter
            << c.getResult() << delimiter
            << c.getLastTechnicalExamDate() << delimiter
            << c.getComments() << delimiter
            << static_cast<int>(c.getType()) << delimiter
            << c.getVin() << delimiter
            << c.getCurrentMileage() << delimiter
            << c.getLastCourse() << delimiter
            << static_cast<int>(c.getAvailable());
        return os.str();
    };
};

template <>
struct Serializer<Car> {
    static Car deserialize(std::string& input)
    {
        const char car_delimiter[] = ";";
        char* next_token1 = nullptr;
        std::ostringstream os;
        std::string carBrand =                strtok_s(const_cast<char*>(input.c_str()), car_delimiter, &next_token1);
        std::string model =                   strtok_s(nullptr, car_delimiter, &next_token1);
        std::string weight =                  strtok_s(nullptr, car_delimiter, &next_token1);
        std::string vin =                     strtok_s(nullptr, car_delimiter, &next_token1);
        return Car(carBrand, model, vin, std::stod(weight));
    };
    static std::string serialize(const Car& c)
    {
        const char delimiter[] = ";";
        std::ostringstream os;
        os << c.getCarBrand() << delimiter
            << c.getModel() << delimiter
            << c.getWeight() << delimiter
            << c.getVin();
        return os.str();
    };
};
template<>
struct Serializer<Car*> {
    static Car* deserialize(std::string& input)
    {
        std::string type{}, cargoV{}, capacity{}, maxPassengers{};
        const char car_delimiter[] = ";";
        char* next_token1 = nullptr;
        Car* n;
        std::ostringstream os;
        const char carType = input.at(0);
	    input.erase(0,2);

        switch (carType) {
        case 'p' : 
			maxPassengers = strtok_s(const_cast<char*>(input.c_str()), car_delimiter, &next_token1);
            type = strtok_s(nullptr, car_delimiter, &next_token1);
            break;
        case 'u' : 
            type = strtok_s(const_cast<char*>(input.c_str()), car_delimiter, &next_token1);
            break;
        case 'c' :
			cargoV = strtok_s(const_cast<char*>(input.c_str()), car_delimiter, &next_token1);
			capacity = strtok_s(nullptr, car_delimiter, &next_token1);
            type = strtok_s(nullptr, car_delimiter, &next_token1);
            break;
        }
     
        std::string carBrand = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string model = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string fuelLevel = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string fuelTank = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string numbOfDoors = strtok_s(nullptr, car_delimiter, &next_token1);

        //Vehicle
        std::string vin = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string weight = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string currentMileage = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string lastCourse = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string available = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string date = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string comments = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string result = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string tType = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string gotEngine = strtok_s(nullptr, car_delimiter, &next_token1);
        std::string motorCapacity;
        std::string horsepower;
        std::string fuelConsumption;
        std::string mtType;
        if (stoi(gotEngine) == 1)
        {
            motorCapacity = strtok_s(nullptr, car_delimiter, &next_token1);
            horsepower = strtok_s(nullptr, car_delimiter, &next_token1);
            fuelConsumption = strtok_s(nullptr, car_delimiter, &next_token1);
            mtType = strtok_s(nullptr, car_delimiter, &next_token1);

        }

        //setter center
        if (carType == 'u') {
          n = new UtilityCar(utils::toUtilityType(std::stoi(type)), carBrand, model, vin, std::stod(weight)); // Dostosowac tak konsturktor 

        }
        else if (carType == 'p') {
           n = new PassengerCar(std::stoi(maxPassengers), utils::toPassengerType(std::stoi(type)), carBrand, model, vin, std::stod(weight));
          
        }
        else {
            n = new CargoCar(std::stod(cargoV), std::stod(capacity), utils::toCargoType(std::stoi(type)), carBrand, model, vin, std::stod(weight));
        }
        n->updateFuelLevel(std::stod(fuelLevel));
        n->updateFuelTank(std::stod(fuelTank));
        n->setNumOfDoors(std::stoi(numbOfDoors));
        n->updateMileage(std::stod(currentMileage));
        n->updateLastCourse(std::stod(lastCourse));
        n->updateAvailable(std::stoi(available));
        n->updateLastTechnicalExamDate(date);
        n->updateComments(comments);
        n->updateResult(stoi(result));
        n->updateTransmission(static_cast<Transmission>(stoi(tType)));
        if (stoi(gotEngine)) {
            n->setEngine(std::stod(motorCapacity), std::stod(horsepower), std::stod(fuelConsumption), static_cast<MotorType>(std::stoi(mtType)));
        }
   
         return n;
    };
    static std::string serialize(Car* c)
    {
        const char delimiter[] = ";";
        std::ostringstream os;
        if (typeid(*c) == typeid(PassengerCar)) {
            os << "p"<< delimiter 
               << c->getMaxPassengers() << delimiter
               << static_cast<int>(c->getBodyType()) << delimiter;
        }
        else if (typeid(*c) == typeid(CargoCar)) {
            os << "c" << delimiter
                << c->getCargoV() << delimiter
                << c->getCapacity() << delimiter
                << static_cast<int>(c->getType()) << delimiter;
        }
        else if (typeid(*c) == typeid(UtilityCar)) {
            os << "u" << delimiter
                << static_cast<int>(c->getUtype()) << delimiter;
        }
       os  << c->getCarBrand() << delimiter
            << c->getModel() << delimiter
            << c->getFuelLevel() << delimiter
            << c->getFuelTank() << delimiter
            << c->getNumOfDoors() << delimiter
            << c->getVin() << delimiter
            << c->getWeight() << delimiter
            << c->getCurrentMileage() << delimiter
            << c->getLastCourse() << delimiter
            << c->getAvailable() << delimiter
            << c->getLastTechnicalExamDate() << delimiter
            << c->getComments() << delimiter
            << c->getResult() << delimiter
            << static_cast<int>(c->getTransmission()) << delimiter
            << c->haveEngine() << delimiter;
            if(c->haveEngine()){
            os << c->getMotorCapacity() << delimiter
            << c->getHorsepower() << delimiter
            << c->getFuelConsumption() << delimiter
            << static_cast<int>(c->getmtType());
            } else {
                os << "0;0;0;0";
            }

        return os.str();
    };
};
