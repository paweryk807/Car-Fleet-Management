#pragma once
#include"Vehicle.h"

class Car : public Vehicle 
{
private:
    std::string carBrand;
    std::string model;                                 
	double fuelLevel;		
    double fuelTank;	
    int numbOfDoors;

public:
    Car(string carBrand = "", std::string model = "",  std::string vin = "", double weight = 0);

    const std::string getVin() const noexcept;

    const std::string getModel() const noexcept;

    const std::string getCarBrand() const noexcept;

    int getNumOfDoors() const noexcept;			   

    void setVin(const std::string& vin) noexcept;

    void setModel(const std::string& model) noexcept;

    void setBrand(const std::string& carBrand) noexcept;  

    void setNumOfDoors(const int doors) noexcept;

    void updateFuelTank(const double tankCapacity) noexcept;

    void updateFuelLevel(const double level) noexcept;		

    const double getFuelTank() const noexcept;			   

    const double getFuelLevel() const noexcept;	

    friend std::ostream& operator << (std::ostream& out, const Car& c);

    friend std::istream& operator >> (std::istream& in, Car& c);

    std::istream& put(std::istream& in);

    virtual std::string getString () const;  

    virtual int getMaxPassengers() const noexcept;

    virtual BodyType getBodyType() const noexcept;

    virtual const CargoType getType() const noexcept;

    virtual const double getCapacity() const noexcept;

    virtual const double getCargoV() const noexcept;

    virtual const UtilityType getUtype() const noexcept;

    virtual std::string print();

    virtual ~Car();
};
