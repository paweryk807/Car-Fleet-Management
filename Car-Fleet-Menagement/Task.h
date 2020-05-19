#pragma once
#include<string>
#include"Route.h"


class Task /** Klasa odwzorowuj¹ca zadanie. */
{
	int id;			
	int driverId;	
	std::string carVin;	
	std::string trailerVin;	
	Route route;		
	double value;	

public:
	Task();
	Task(const int id, const int dId, const string& cVin, const string& tVin, const double distance, const std::string start, const std::string destination, const string& date, const double value);
	Task(const int id, const int dId, const std::string& cVin, const string& tVin, const Route& route, const double& value);
	Task(Task&& other) noexcept;


	const std::string getData() const noexcept; 
	const int getId() const noexcept;      
	const int getDriverId() const noexcept; 
	const std::string getCarVin() const noexcept;
	const std::string getDate() const noexcept;
	const std::string getStart() const noexcept;
	const std::string getDestination() const noexcept;
	double getDistance() const noexcept;
	const std::string getTrailerVin() const noexcept;
	std::string print() const noexcept;			  
	const double getValue() const noexcept;   
	void updateId(const int Id) noexcept;		
	void updateDriverId(const int Id) noexcept; 
	void updateValue(const double value) noexcept;
	friend std::ostream& operator<<(std::ostream& output, const Task& t);

	~Task(); 
};