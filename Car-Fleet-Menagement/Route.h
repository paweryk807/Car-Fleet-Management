#pragma once
#include <string>
#include <cmath>
#include<iomanip>
#include"Functions.h"
#include "Utils.h"
/** Klasa  odpowiedzialna za przechowywanie tras z datami kiedy zostaly odbyte */
class Route {
	std::string start;
	std::string destination;
	std::string date; 
	double distance;
public:
	Route(std::string start = " ", std::string destination = " ", std::string date = " ", double distance = 0);

	Route(const Route& other);

	void setStart(const std::string& d);
	void setDestination(const std::string& d);
	void setDate(const std::string& d);
	void setDistance(const double d);

	const std::string getStart() const noexcept;
	const std::string getDestination() const noexcept;
	const std::string getDate() const noexcept;
	const double getDistance() const noexcept;
	int calculateFinalization() const noexcept;
	friend ostream& operator<<(ostream& output, const Route &r);
};