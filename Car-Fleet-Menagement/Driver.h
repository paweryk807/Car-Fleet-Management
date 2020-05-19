#pragma once
#include<string>
#include<iostream>
#include<sstream>
#include"Utils.h"
using namespace std;

class Driver /** Klasa przedstawiaj�ca kierowc�*/
{
	int id;				/** Numer ID kierowcy */
	//double rate;		/** Stawka jak� kierowca pobiera za przejechany kilometr */
	string name;		/** Imie kierowcy */
	string secondName;  /** Nazwisko kierowcy */
	bool available;		/** Informacja o tym czy dany kierowca jest dost�pny */
	string licenses;	/** Informacja o posiadanych kategoriach prawa jazdy */
public:
	Driver();																															/** Konstruktor domy�lny */
	Driver(const int id, const string& name, const string& secondName, bool available, const string& licenses);		/** Konstruktor parametryczny wymagaj�cy ID, stawki, danych osobowych, informacji o dost�pno�ci kierowcy oraz jego uprawnie� */
	Driver(Driver& other) noexcept;
	Driver(Driver&& other) noexcept = default;
	const string getData() const noexcept;							/** Metoda zwracaj�ca wszystkie dane o obiekcie */
	friend ostream& operator<<(ostream& output, const Driver& d);
	const string getLicenses() const noexcept;						/** Metoda zwracaj�ca �a�cuch znak�w zawieraj�cy wszyskie uprawnienia kierwocy */
	const int getId() const noexcept;								/** Metoda zwracaj�ca ID kierowcy */
	const string getName() const noexcept;							/** Metoda zwracaj�ca imie kierowcy */
	const string getSecondName() const noexcept;					/** Metoda zwracaj�ca nazwisko kierowcy */
	const bool getAvailable() const noexcept;						/** Metoda zwracaj�ca informacje o dost�pno�ci danego kierowcy */
	void updateId(const int id) noexcept;							/** Metoda umo�liwiaj�ca zaktualizowanie id kierowcy */
	void updateName(const string& name) noexcept;					/** Metoda umo�liwiaj�ca zaktualizowanie imiona kierowcy */
	void updateSecondName(const string& secondName) noexcept;		/** Metoda umo�liwiaj�ca zaktualizowanie nazwiska kierowcy */
	void updateAvailable(bool available) noexcept;					/** Metoda umo�liwiaj�ca zaktualizowanie dost�pno�ci kierowcy */
	void updateLicenses(const string& licenses) noexcept;			/** Metoda umo�liwiaj�ca zaktualizowanie uprawnie� kierowcy */
	bool licenseCheck(DrivingLicense license) noexcept;						/** Metoda sprawdzaj�ca czy znak przekazany przez parametr zawarty jest w �a�cuchu znak�w m�wi�cym o uprawnieniach kierwocy. Zwraca 1 je�li si� tam znajduje, 0 je�li nie. */
	 ~Driver();														/** Destruktor */
};
