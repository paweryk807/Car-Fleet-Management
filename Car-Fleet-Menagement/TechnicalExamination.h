#pragma once
#include<string>
#include<iostream>
#include"Functions.h"
#include"Utils.h"
using namespace std;

class TechnicalExamination  /** Klasa odwzorowuj�ca badanie techniczne. */
{
private:

	string date; /** Termin badania technicznego. */
	string comments; /** Komentarze do badania technicznego. */
	bool result;	/** Wynik badania technicznego. */

public:
	TechnicalExamination(const string& date = "01-01-1900", const string& comments = "", const bool result = false); /** Konstruktor parametryczny. */
	//TechnicalExamination(TechnicalExamination&& other) = default;
	const bool getResult() const noexcept; /** Metoda zwracaj�ca informacj� czy przegl�d si� uda�. */
	const string getComments() const noexcept; /** Metoda zwracaj�ca komentarze do badania. */
	const string getLastTechnicalExamDate() const noexcept; /** Metoda pobieraj�ca dat� ostatniego badania technicznego. */
	const string getNextTechnicalExamDate() const noexcept; /** Metoda zwracaj�ca dat�, kiedy musi odby� si� nast�pne badanie techniczne. */
	const bool isValid(const string& dLiczba) const noexcept; /** Metoda sprawdzaj�ca czy data podana jako parametr, mie�ci si� w terminie wa�no�ci ostatniego przegl�du. */

	void updateResult(const bool res) noexcept;	/** Metoda aktualizuj�ca wynik badania. */
	void updateComments(const string& com) noexcept; /** Metoda aktualizuj�ca komentarz do badania. */
	void updateLastTechnicalExamDate(const string& xdate) noexcept; /** Metoda aktualizuj�ca dat� ostatniego badania technicznego. */
	friend ostream& operator<<(ostream& output, const TechnicalExamination& e);
	~TechnicalExamination();	/** Destruktor. */
};
