#pragma once
#include<iostream>
#include"TechnicalExamination.h"
#include"Engine.h"
#include"Vin.h"

class Vehicle /** Klasa odzwieciedlajaca obiekt typu pojazd. */
{
protected:
	Vin vin;
	double weight;
	double currentMileage; /** Aktualny przebieg. */
	double lastCourse; /** Ostatnio przejechana odleg�o��. */
	bool available; /** Informacja czy dost�pny. */
	TechnicalExamination date; 
	bool gotEngine;
	Engine* engine;
	Transmission tType;
//	Vehicle() = default;
public:




	Vehicle(std::string vin, double weight);
	const double getWeight() const noexcept;
	const double getLastCourse() const noexcept; /** Metoda zwracaj�ca ostatnio przejechany dystans.*/
	const double getCurrentMileage() const noexcept; /** Metoda zwracaj�ca aktualny stan przebiegu. */
	const bool getAvailable() const noexcept;
	void updateLastCourse(const double lC) noexcept;
	/** Metoda informuj�ca czy pojazd jest dost�pny. */
	void updateMileage(const double mileage) noexcept; /** Metoda odpowiedzialna za aktualizowanie przebiegu i ostatnio przejechanego dystansu. */
	void updateAvailable(const bool av) noexcept; /** Metoda pozwalaj�ca na zmian� informacji o dost�pno�ci pojazdu. */
	void setEngine(double motorCapacity, double horsepower, double fuelConsumption, MotorType motorType);		
	double getLatestCost(const double fuelCost) noexcept;  
	const std::string getVin() const noexcept;
    double getFuelConsumption() const noexcept;	   
    const double getHorsepower() const noexcept;		   
    const MotorType getmtType() const noexcept;			   
    const Transmission getTransmission() const noexcept;   
    const double getMotorCapacity() const noexcept;		   
    const std::string getLastTechnicalExamDate() const noexcept;
    const std::string getNextTechnicalExamDate() const noexcept;
    const bool technicalExamIsValid(const string& sdate) const noexcept; 
    const bool getResult() const noexcept;		
    const std::string getComments() const noexcept;  
	const bool haveEngine() const noexcept;
	TechnicalExamination getDate() noexcept;

	void updateWeight(double w);
	void updateLastTechnicalExamDate(const std::string& xdate) noexcept;
    void updateResult(bool res) noexcept;							 
    void updateComments(const std::string& com) noexcept;					
    void updateHorsepower(const double hp) ;					
    void updateMotorType(const MotorType type) ;				
    void updateTransmission(const Transmission type) noexcept;			
    void updateFuelConsumption(const double fuelCnsmptn) ;		
    void updateMotorCapacity(const double mCapacity) ;			
    void updateTechnicalExamResult(bool result) noexcept;
	bool operator<(Vehicle const& object) noexcept;


	 ~Vehicle();
};
