#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include"Car.h"
/** Klasa przedstawiajaca samochod osobowy */
class PassengerCar : public Car {
public:
    PassengerCar();
    PassengerCar(const int maxPassengers, BodyType bodytype, std::string carBrand, std::string model, std::string vin, double weight);

    PassengerCar(const PassengerCar&& other) noexcept;// = default;
    PassengerCar(const PassengerCar& other)  = default;
    PassengerCar& operator=(PassengerCar& other)  = default;

    std::ostream& operator << (std::ostream& os);
    friend std::ostream& operator << (std::ostream& os, const PassengerCar& cr);
    friend std::istream& operator >> (std::istream& in, PassengerCar& c);
    std::istream& put(std::istream& is);
    std::string getString() const;

    void setBodyType(const BodyType bodytype) noexcept;
	std::string print();

    BodyType getBodyType() const noexcept;
    void setMaxPassengers(const int passengers) noexcept;
    int getMaxPassengers() const noexcept;

    virtual ~PassengerCar() = default;
private:
    int maxPassengers;
    BodyType bodytype;
};
