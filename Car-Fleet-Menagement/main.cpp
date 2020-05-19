#include<iostream>
#include<string>
#include<fstream>
#include"vld.h"
#include<sstream>
#include"FileHandler.h"
#include"Menu.h"
#include <list>



void addCar(const std::string& fileName)
{
    try {


        std::ofstream ofs;
        ofs.open(fileName, std::ifstream::out | std::ofstream::app);
        if (ofs.is_open())
        {
            std::string line;
            Car car;
            std::cin >> car;
            ofs << Serializer<Car>::serialize(car) <<std::endl;
            ofs.close();
        }
        else {
            std::cerr << "Plik " << fileName << " nie zosta³ otwarty!" << std::endl;
        }
    }
    catch (exception e) {
        std::cerr << e.what();
    }
}

template <class T>
void display(const std::list <T>& container)
{
    for (auto& item: container) {
        std::cout << *item << std::endl;
    }
}

int main()
{

	FileHandler files("cars.txt", "drivers.txt","trailers.txt","tasks.txt");
    Menu menu;
    menu.start(files);
}


