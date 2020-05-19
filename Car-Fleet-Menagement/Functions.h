#pragma once
#include<string>
#include<sstream>
#include<list>
#include<iostream>
#include "Utils.h"
//#include "Serializer.hpp"
using namespace std;

bool vinValidator(const string& vin);					/** Funkcja sprawdzaj�ca poprawno�� VIN'u, bazuje na og�lnych, podstawowwych zasadach, kt�rych musz� si� trzyma� producenci przy nadawaniu tego numeru. */
bool dateValidator(const string& date);					/** Funkcja odpowiedzialna za sprawdzanie poprawno�ci podawanej jej jako argument daty.*/	
bool isValidAction(const int firstOption, const int lastOption, const int option);
DrivingLicense drivingLicenseCargo(double weight, bool trailer, double tr_weight);
DrivingLicense drivingLicensePassenger(int passengers);

bool getActionFromUser(const int firstAction, const int lastAction, int& action);
bool menuOptionsCargo(int &action);
bool menuOptionsPassenger(int &action);
bool menuOptionsUtility(int &action);
 bool menuOptionsTrailer(int &action);