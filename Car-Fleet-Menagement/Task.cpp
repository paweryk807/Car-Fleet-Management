#include<iostream>
#include"Task.h"
using namespace std;

Task::Task():route() {
	id = 0;
	driverId = 0;
	carVin = "";
	trailerVin = "";
	value = 0;
}

Task::Task(const int id, const int dId, const string& cVin, const string& tVin, const double distance, const std::string start, const std::string destination, const string& date, const double value)
	:id(id), driverId(dId), value(value), carVin(cVin), trailerVin(tVin) {
	route.setDate(date);
	route.setDistance(distance);
	route.setStart(start);
	route.setDestination(destination);
}

Task::Task(const int id, const int dId, const std::string& cVin, const string& tVin, const Route& route, const double& value) : route(route), id(id), driverId(dId), value(value),
carVin(cVin), trailerVin(tVin) {};

Task::Task(Task&& other) noexcept {
	this->id = other.id;
	this->driverId = other.driverId;
	this->carVin = other.carVin;
	this->trailerVin = other.trailerVin;
	this->value = other.value;
	this->route = other.route;
}

const string Task::getData() const noexcept {  // Na bazie tej funkcji potrzebuje serializacji 
	string data = "t;" +
		to_string(id) + ";" +
		to_string(driverId) + ";" +
		carVin + ";" +
		trailerVin + ";" +
		route.getStart() + ";" +
		to_string(route.getDistance()) + ";" +
		route.getDestination() + ";" +
		to_string(value) + ";" +
		route.getDate() +"\n";
	return data;
}

std::string Task::print() const noexcept {
	std::stringstream out;
	out << "ID Zlecenia : " << id << endl;
	out << "Wykona Kierowca o ID : " << driverId << endl;
	out << "Numer VIN przyczepy : " << trailerVin << endl;
	out << "Szacowany przychod ze zlecenia : " << value << endl;
	out << route;
	return out.str();
}

const int Task::getId() const noexcept { return id; }

const int Task::getDriverId() const noexcept { return driverId; }

const std::string Task::getCarVin() const noexcept
{
	return carVin;
}
const std::string Task::getDate() const noexcept
{
	return route.getDate();
}
const std::string Task::getStart() const noexcept
{
	return route.getStart();
}
const std::string Task::getDestination() const noexcept
{
	return route.getDestination();
}
double Task::getDistance() const noexcept
{
	return route.getDistance();
}
const std::string Task::getTrailerVin() const noexcept
{
	return trailerVin;
}
const double Task::getValue() const noexcept
{
	return value;
}

void Task::updateId(const int Id) noexcept {
	this->id = Id;
}

void Task::updateDriverId(const int Id) noexcept {
	this->driverId = Id;
}

void Task::updateValue(const double value) noexcept {
	this->value = value;
}

Task::~Task() {}

ostream& operator<<(ostream& output, const Task& t)
{
	output << "ID zlecenia : "   << t.id << std::endl
		   << "ID kierowcy : "   << t.driverId << std::endl
		   << "VIN samochodu : " << t.carVin << std::endl;
	if (!(t.trailerVin == "00000000000000000")) {
		output << "VIN przyczepy : " << t.getTrailerVin() <<std::endl;
	}
	output << t.route
		   << "Koszt : "<< t.value << std::endl;
	return output; 
}
