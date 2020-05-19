#pragma once
#include<iostream>
#include<sstream>
#include"Utils.h"
class Engine
{
	double motorCapacity;   /** Parametr przechowuj¹cy pojemnoœæ silnika pojazdu. */
    double horsepower;		/** Parametr mówi¹cy o iloœæi koni mechanicznych pojazdu. */
	double fuelConsumption; /** Informacja o statystycznym zu¿yciu paliwa na 100 kilometrów. */
	MotorType mtType;		/** Obiekt klasy MotorType przechowujacy informacje o typie silnika pojazdu. */
public:

Engine(double mCap = 0, double hP = 0, double fCon = 0, MotorType mT = MotorType::none);

Engine(const Engine&& e) noexcept;

std::string showParameters();

double getCapacity();

double getHorsepower();

double getFuelConsumption();

MotorType getMotorType();

void setMotorCapacity(double capacity);

void setHorsepower(double hP);

void setFuelConsumption(double fCon);

void setMotorType(MotorType mt);

Engine();

};

