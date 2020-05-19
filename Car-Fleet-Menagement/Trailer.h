#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include"Vehicle.h"

/** Klasa odwzorowujaca przyczepe */

class Trailer : public Vehicle 
{
    std::string brand; 
    double cargoV; 
    double capacity;  
    TrailerType trailerType;	
public:

    Trailer() = delete; 
    Trailer(Trailer&& other) noexcept;
    const std::string getBrand() const noexcept;
    Trailer(double cargoV, double capacity, TrailerType type, std::string brand, std::string vin, double weight);
    Trailer(Trailer& other) noexcept;
	friend std::ostream& operator<<(std::ostream& output, const Trailer t) noexcept;
    const double getCapacity() const noexcept; 
    const double getCargoV() const noexcept;
    const std::string getLastTechnicalExamDate() const noexcept; 
    const std::string getNextTechnicalExamDate() const noexcept;  
    const bool getResult() const noexcept;
    const TrailerType getType() const noexcept;
    const bool technicalExaminationIsValid(const std::string& sDate) const noexcept;
    void updateBrand(const std::string& brand) noexcept; 
    void updateCapacity(const double capacity) noexcept; 
    void updateCargoV(double v) noexcept;
    void updateTrailerType(const TrailerType type) noexcept;
    void updateLastTechnicalExamDate(const std::string& xdate) noexcept;
    void updateResult(const bool res) noexcept; 
    void updateComments(const std::string& com) noexcept;	
    ~Trailer(); 
};
