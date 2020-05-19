#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include"Car.h"
using namespace std;

class UtilityCar : public Car { /** Klasa przedstawiaj�ca samoch�d u�ytkowy. */
    UtilityType type; /** Typ pojazdu. */
public:

    UtilityCar(); /** Konstruktor domy�lny. */
    
    UtilityCar(UtilityType type); /** Konstruktor parametryczny bior�cy za parametr jedynie typ pojazdu. */
    
    UtilityCar(UtilityCar&& other) noexcept;
    
    UtilityCar(const UtilityCar& other) noexcept;
	
    UtilityCar(UtilityType type, std::string carBrand, std::string model, std::string vin, double weight);
    
    UtilityCar& operator=(UtilityCar& other) noexcept;
    
    const UtilityType getUtype() const noexcept; /**Metoda zwracaj�ca typ pojazdu. */
    void updateType(UtilityType uType);	/** Metoda s�u��ca do aktualizacji typu pojazdu. */
   // friend std::ostream& operator<<(std::ostream& output, const UtilityCar& car);
    std::string print();

    std::ostream& operator<<(std::ostream& output);
    
    ~UtilityCar(); /** Destruktor. */
};
