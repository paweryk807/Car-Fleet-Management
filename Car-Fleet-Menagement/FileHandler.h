#pragma once
#include<fstream>
#include<string>
#include<list>
#include "Serializer.h"



class FileHandler /** Klasa maj�ca za zadanie obs�ug� plik�w, �adowanie danych z plik�w oraz zapisywanie ich tam */
{
    string drivers;		/** Parametr przechowuj�cy nazw� pliku z kierowcami */
    string cars;		/** Parametr przechowuj�cy nazw� pliku z samochodami */
    string trailers;	/** Parametr przechowuj�cy nazw� pliku z przyczepami */
    string tasks;		/** Parametr przechowuj�cy nazw� pliku z zadaniami */
public:

    FileHandler() : drivers(""), cars(""), trailers(""), tasks("") {}  /** Konstruktor domy�lny */
    FileHandler(const string& cars, const string& drivers, const string& trailers, const string& tasks) : cars(cars), drivers(drivers), trailers(trailers), tasks(tasks) {} /** Konstruktor parametryczny przyjmujacy nazwy poszczeg�lnych plik�w za parametry */

    
    bool readCars(std::list<Car*>& container) {
       return this->load(cars, container);
    }

    bool saveCars(std::list<Car*>& container) {
       return this->save(cars, container);
    }

    bool loadDrivers(std::list<Driver>& container) {
        return this->load(drivers, container);
    }

    bool saveDrivers(std::list<Driver>& container) {
        return this->save(drivers, container);
    }
    
    bool loadTasks(std::list<Task>& container) {
        return this->load(tasks, container);
    }

    bool saveTasks(std::list<Task>& container) {
        return this->save(tasks, container);
    }
    
    bool loadTrailers(std::list<Trailer>& container)
    {
        return this->load(trailers, container);
    }
    bool saveTrailers(std::list<Trailer>& container) {
        return this->save(trailers, container);
    }

    template <class T>
    bool load(const std::string& fileName, std::list<T>& container)
    {
        try {
            std::ifstream ifs;
            ifs.open(fileName, std::ifstream::in);
            std::string line;
            if (ifs.is_open()) {
                while (std::getline(ifs, line)) {
                    T item((std::move(Serializer<T>::deserialize(line))));
                    container.push_back(move(item));
                }
                ifs.close();
            }
            else {
                std::cerr << "Plik " << fileName << " nie zosta� otwarty!" << std::endl;
            }
        }
        catch (exception e) {
            std::cerr << e.what();
            return false;
        }
        return true;
    }

    template <class T>
    bool save(const string& fileName, std::list<T>& container)
    {
        try {
            std::ofstream ofs;
            ofs.open(fileName, std::ifstream::out);
            if (ofs.is_open()) {
                for (auto& item : container) {
                    ofs << Serializer<T>::serialize(item) << std::endl;
                }
                ofs.close();
            }
            else {
                std::cerr << "Plik " << fileName << " nie zosta� otwarty!" << std::endl;
            }
        }
        catch (exception e) {
            std::cerr << e.what();
            return false;
        }
        return true;
    }


    ~FileHandler() {};
};
