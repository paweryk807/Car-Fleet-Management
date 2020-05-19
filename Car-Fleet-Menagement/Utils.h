#pragma once
#pragma once
#include <string>

enum class MotorType {		/** Klasa numeryczna przechowujuca typy silnikow */
    none, petrol, diesel, electric
};

enum class Transmission {	/** Klasa numeryczna przechowujaca typy skrzyn biegow */
    none, automatic, semi_automatic, manual
};

enum class TrailerType {	/** Klasa numeryczna przechowujaca typy przyczep */
    trailer, bicycle_trailer, full_trailer, semi_trailer, horse_trailer, travel_trailer, boat_trailer
};

enum class BodyType {	/** Klasa numeryczna przechowujaca typy samochod�w osobowych */
    passenger, sedan, liftback, hatchback, combi, cabriolet, minivan
};

enum class CargoType {		/** Klasa numeryczna przechowujaca typy samochod�w dostawczych */
    cargo, truck, pickup, van
};

enum class UtilityType {	/** Klasa numeryczna przechowujaca typy samochod�w uzytkowych */
    utility, tow_truck, garbage_truck, ambulance, plow_truck
};

enum class DrivingLicense
{
    A, A1, B, BE, C1, C1E, C, CE, D1, D1E, D, DE
};

namespace utils
{
    std::string toString(const bool& t);
    std::string toString(const BodyType& t);
    std::string toString(const MotorType& t);
    std::string toString(const TrailerType& t);
    std::string toString(const Transmission& t);
    std::string toString(const UtilityType& t);
    std::string toString(const CargoType& t);
    std::string toString(const DrivingLicense& t);
    DrivingLicense toDrivingLicense(const int t);
    Transmission toTransmission(const int t);
    CargoType toCargoType(const int t);
    MotorType toMotorType(const int t);
    UtilityType toUtilityType(const int t);
    Transmission toTransmission(const int t);
    TrailerType toTrailerType(const int t);
    BodyType toPassengerType(const int t);
}


