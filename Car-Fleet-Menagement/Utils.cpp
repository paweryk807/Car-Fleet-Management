#include "Utils.h"
#include <string>

namespace utils
{
    std::string toString(const bool& t) {
	if (t) {
		return "tak";
	}
	else {
		return "nie";
	}
}
std::string toString(const BodyType& t)
{
    switch (t)
    {
        case BodyType::passenger:
            return "osobowy";
        case BodyType::sedan:
            return "sedan";
        case BodyType::liftback:
            return "liftback";
        case BodyType::hatchback:
            return "hatchback";
        case BodyType::combi:
            return "kombi";
        case BodyType::cabriolet:
            return "kabriolet";
        case BodyType::minivan:
            return "minivan";
        default:
            return "";
     }
}

std::string toString(const MotorType& t)
{
    switch (t)
    {   
         case MotorType::none:
            return "brak";
        case MotorType::petrol:
            return "benzynowy";
        case MotorType::diesel:
            return "diesel";
        case MotorType::electric:
            return "elektryczny";
        default:
            return "";
     }
}

std::string toString(const TrailerType& t)
{
    switch (t)
    {   
         case TrailerType::trailer:
            return "przyczepa";
        case TrailerType::bicycle_trailer:
            return "przyczepa do przewozu rowerow";
        case TrailerType::full_trailer:
            return "przyczepa zabudowana";
        case TrailerType::semi_trailer:
            return "naczepa";
        case TrailerType::horse_trailer:
            return "przyczepa do przewozu koni";
        case TrailerType::travel_trailer:
            return "kempingowa";
        case TrailerType::boat_trailer:
            return "przyczepa do przewozu lodzi";
        default:
            return "";
     }
}

std::string toString(const Transmission& t)
{
    switch (t)
    {   
         case Transmission::automatic:
            return "automatic";
        case Transmission::semi_automatic:
            return "semi_automatic";
        case Transmission::manual:
            return "manual";
        default:
            return "";
     }
}

std::string toString(const UtilityType& t)
{
    switch (t)
    {   
         case UtilityType::utility:
            return "uzytkowy";
        case UtilityType::tow_truck:
            return "holownik";
        case UtilityType::garbage_truck:
            return "smieciarka";
         case UtilityType::ambulance:
            return "ambulans";
        case UtilityType::plow_truck:
            return "plug";
        default:
            return "";
     }
}

std::string toString(const CargoType& t)
{
    switch (t)
    {   
         case CargoType::cargo:
            return "dostawczy";
        case CargoType::truck:
            return "ciezarowy";
        case CargoType::pickup:
            return "pickup";
        case CargoType::van:
            return "furgonetka";
        default:
            return "";
     }
}

std::string toString(const DrivingLicense& t) //A, A1, B, BE, C1, C1E, C, CE, D1, D1E, D, DE
{
    switch(t)
    {
        case DrivingLicense::A: 
            return "A";
        case DrivingLicense::A1: 
            return "A1";
        case DrivingLicense::B: 
            return "B";
        case DrivingLicense::BE: 
            return "BE";
        case DrivingLicense::C1: 
            return "C1";
        case DrivingLicense::C1E: 
            return "C1E";
        case DrivingLicense::C: 
            return "C";
        case DrivingLicense::CE: 
            return "CE";
        case DrivingLicense::D1: 
            return "D1";
        case DrivingLicense::D: 
            return "D";
        case DrivingLicense::DE: 
            return "DE";
    }
}

DrivingLicense toDrivingLicense(const int t) 
{
    return static_cast<DrivingLicense>(t);
}

BodyType toPassengerType(const int t)
{
    return static_cast<BodyType>(t);
}

MotorType toMotorType(const int t)
{
    return static_cast<MotorType>(t);
}

CargoType toCargoType(const int t)
{
    return static_cast<CargoType>(t);
}
TrailerType toTrailerType(const int t)
{
    return static_cast<TrailerType>(t);
}
Transmission toTransmission(const int t)
{
    return static_cast<Transmission>(t);
}
UtilityType toUtilityType(const int t)
{
    return static_cast<UtilityType>(t);
}
}
