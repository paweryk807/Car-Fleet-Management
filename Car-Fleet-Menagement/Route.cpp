#include "Route.h"

Route::Route(std::string start, std::string destination, std::string date, double distance)
{
	if (dateValidator(date))
	{
		this->date = date;
	}
	else date = "01-01-1900";
	this->start = start;
	this->destination = destination;
	if (distance > 0) {
		this->distance = distance;
	}
}

Route::Route(const Route& other) {
	start = other.start;
	destination = other.destination;
	distance = other.distance;
	date = other.date;
}

void Route::setStart(const std::string& d)
{
	this->start = d;
}

void Route::setDestination(const std::string& d)
{
	this->destination = d;
}

void Route::setDate(const std::string& d)
{
	if (dateValidator(d)) {
		this->date = d;
	}
}

void Route::setDistance(double d)
{
	if (d > 0) {
		distance = d;
	}
}

const std::string Route::getStart() const noexcept
{
	return start;
}

const std::string Route::getDestination() const noexcept
{
	return destination;
}

const std::string Route::getDate() const noexcept
{
	return date;
}

const double Route::getDistance() const noexcept
{
	return distance;
}

int Route::calculateFinalization() const noexcept // wymaga sprawdzenia 
{
	if (distance <= 400) return 1;
	else {
		// Zakladam ze 400 dni na dobe jesli wiecej to dzien +1
		int days = 0;
		days = (static_cast<int>(distance) % 400);
		if ((distance - (days * 400))> 0) {
			days += 1;
		}
		return days;
	}
}

ostream& operator<<(ostream& output, const Route& r)
{
	output << "Miasto poczatkowe : " << r.start << "\n"
		   << "Miasto docelowe : "   << r.destination << "\n"
		   << "Data : "				 << r.date << "\n" 
		   << "Odleglosc : "		 << r.distance << "\n";
	return output;
	// TODO: tu wstawiæ instrukcjê return
}
