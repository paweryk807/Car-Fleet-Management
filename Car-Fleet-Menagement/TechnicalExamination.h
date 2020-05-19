#pragma once
#include<string>
#include<iostream>
#include"Functions.h"
#include"Utils.h"
using namespace std;

class TechnicalExamination  /** Klasa odwzorowuj¹ca badanie techniczne. */
{
private:

	string date; /** Termin badania technicznego. */
	string comments; /** Komentarze do badania technicznego. */
	bool result;	/** Wynik badania technicznego. */

public:
	TechnicalExamination(const string& date = "01-01-1900", const string& comments = "", const bool result = false); /** Konstruktor parametryczny. */
	//TechnicalExamination(TechnicalExamination&& other) = default;
	const bool getResult() const noexcept; /** Metoda zwracaj¹ca informacjê czy przegl¹d siê uda³. */
	const string getComments() const noexcept; /** Metoda zwracaj¹ca komentarze do badania. */
	const string getLastTechnicalExamDate() const noexcept; /** Metoda pobieraj¹ca datê ostatniego badania technicznego. */
	const string getNextTechnicalExamDate() const noexcept; /** Metoda zwracaj¹ca datê, kiedy musi odbyæ siê nastêpne badanie techniczne. */
	const bool isValid(const string& dLiczba) const noexcept; /** Metoda sprawdzaj¹ca czy data podana jako parametr, mieœci siê w terminie wa¿noœci ostatniego przegl¹du. */

	void updateResult(const bool res) noexcept;	/** Metoda aktualizuj¹ca wynik badania. */
	void updateComments(const string& com) noexcept; /** Metoda aktualizuj¹ca komentarz do badania. */
	void updateLastTechnicalExamDate(const string& xdate) noexcept; /** Metoda aktualizuj¹ca datê ostatniego badania technicznego. */
	friend ostream& operator<<(ostream& output, const TechnicalExamination& e);
	~TechnicalExamination();	/** Destruktor. */
};
