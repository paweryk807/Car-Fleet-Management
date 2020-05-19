#pragma once
#include<string>
#include<iostream>
#include<iomanip>
#include<sstream>
#include"Car.h"
using namespace std;

class UtilityCar : public Car { /** Klasa przedstawiaj¹ca samochód u¿ytkowy. */
    UtilityType type; /** Typ pojazdu. */
public:

    UtilityCar(); /** Konstruktor domyœlny. */
    
    UtilityCar(UtilityType type); /** Konstruktor parametryczny bior¹cy za parametr jedynie typ pojazdu. */
    
    UtilityCar(UtilityCar&& other) noexcept;
    
    UtilityCar(const UtilityCar& other) noexcept;
	
    UtilityCar(UtilityType type, std::string carBrand, std::string model, std::string vin, double weight);
    
    UtilityCar& operator=(UtilityCar& other) noexcept;
    
    const UtilityType getUtype() const noexcept; /**Metoda zwracaj¹ca typ pojazdu. */
    void updateType(UtilityType uType);	/** Metoda s³u¿¹ca do aktualizacji typu pojazdu. */
   // friend std::ostream& operator<<(std::ostream& output, const UtilityCar& car);
    std::string print();

    std::ostream& operator<<(std::ostream& output);
    
    ~UtilityCar(); /** Destruktor. */
};
