#pragma once
#include<iostream>
#include"Serializer.h"

void addTrailer(std::list<Trailer>& list, int& action);  /** Funkcja dodajaca przyczepe do listy pobierajac dane od uzytkownika */
void addCar(std::list<Car*>& list, int& action, int& type); /** Funkcja odpowiedzialna za pobranie danych od uzytkownika w celu dodawania samochodu do lisy */
void addDriver(std::list<Driver>& list); /** Funkcja pobierajaca dane od uzytkownika w celu dodania Kierowcy do listy */