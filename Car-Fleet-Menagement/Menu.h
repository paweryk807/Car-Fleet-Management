#pragma once
#include<string>
#include<iostream>
#include<stdio.h>
#include<list>
#include"FileHandler.h"
#include"ItemAdders.h"
using std::string;

class Menu {	/** Funkcja odpowiedzialna za obsługę działania całego programu. Wywołuje ona odpowiednie metody, obsługuje użytkownika, oraz przechowuje listy z danymi oraz obiekt odpowiedzialny za obsługę plików.*/
    friend class FileHandler;
private:
    std::list<Car*> carList;
    std::list<Driver> driverList;						/** Lista kierowców zatrudnionych w firmie. */
    std::list<Trailer> trailerList;					/** Lista przyczep zawartych w bazie. */
    std::list<Task> taskList;			/** Lista zrealizowanych zadań.*/		/** Obiekt odpowiedzialny za obsługę plików z danymi. */

    bool menuOptionsMain(int &action);
    bool menuOptionsBrowse(int& action);
    bool menuOptionsDisplay(int &action);
    bool menuOptionsModify(FileHandler& files);
    bool menuOptionsAdd(int& action);
public:
    Menu();
    /** Konstruktor parametryczny, przyjmujący za parametry nazwy plików z danymi. */
    void load(FileHandler& files) noexcept;	/** Metoda wczytująca wszystkie dane z plików o podanych do parametru nazwach. */
    void save(FileHandler& files) noexcept;
    bool findTrailerByVin(const string& vin, Trailer* &tmp) noexcept;
    void deleteTrailerByVin(const string& vin) noexcept;
    /** Metoda zapisująca aktualne zawartości list do plików o podanych wcześniej nazwach. */
    Car* findCarByVin(const string& vin) noexcept;
    void deleteCarByVin(const string& vin) noexcept;
    bool findDriverById(const int id, Driver* &tmp) noexcept;
    bool findTaskById(const int id, Task* &tmp) noexcept;
    void deleteDriverById(const int id) noexcept;
    void start(FileHandler& files) noexcept;		/** Metoda obsługująca podstawowe menu dostępne dla użytkownika, umożliwiająca wybór czynności, która chce on wykonać. */
	bool menuOptionsRealization(int& action);
    Car* CarShipSearcher(const double v, const double c);
    Car* CarPassengerSearcher(const int p);
    bool TrailerSearcher(TrailerType type,double v,double c, Trailer* &tr);
    void takePreferences(int& action) noexcept;
   // void takePreferences() noexcept;  /** Metoda pobierająca informacje o tym jakie parametry ma pojazd, którego żąda klient, ile ma w planach przebyć dystansu i jaka stawka za to zlecenie została mu przekazana. Na podstawie ostatniej informacji szacowany jest przychód ze zlecenia.*/
    void modifyData(const int action) noexcept;	/** Metoda, której zadaniem jest umożliwić użytkownikowi modyfikowanie danych, ktorych typ podawany jests jako parametr. */
    void addData(int& action) noexcept;		/** Metoda umożliwiająca dodawanie danych do bazy programu. */
    void browseData(const int option) noexcept;
    /** Metoda wywoływana w celu wyświetlania użytkownikowi danych. */
    bool findDriverByCategory(DrivingLicense license, Driver*& tmp) noexcept;
    bool advancedShipment(int &action,double v, double c) noexcept;
    bool menuAddRoute(int action, Driver* tmp1, Car* cmp1, Trailer* rmp, Driver* tmp2, Car* cmp2);

    Route takeRoute();
    void addTask(Route& way, Driver*& driver1, Car*& car, Trailer*& trailer);
    bool trailerShipSearcher(const double v, const double c, Trailer* &tmp) noexcept;
 
    ~Menu();
    void clean();
    /** Destruktor */
};
