#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include"Car.h"
using namespace std;
/** Klasa przedstawiajaca samochod dostawczy */
class CargoCar : public Car { 
    double cargoV; 
    double capacity;
    CargoType type;
public:
    CargoCar();							

    CargoCar(const int cpct, const double cV, CargoType type);

    CargoCar(double CargoV, double Capacity, CargoType type, std::string carBrand, std::string model, std::string vin, double weight);

    CargoCar(CargoCar&& other) noexcept;

    CargoCar(const CargoCar& other) noexcept;

    CargoCar& operator=(CargoCar& other) noexcept;

	std::string print();

    const CargoType getType() const noexcept;					

    const double getCapacity() const noexcept;

    std::ostream& operator<<(std::ostream& output);

    const double getCargoV() const noexcept;

    void updateCargoV(const double cV) noexcept;

    void updateCapacity(const double nCapacity) noexcept;	

    void updateType(const CargoType cType) noexcept;			

    friend ostream& operator<<(ostream& output, const CargoCar& car);
    ~CargoCar();												
};

