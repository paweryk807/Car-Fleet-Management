#include"ItemAdders.h"

void addTrailer(std::list<Trailer>& list, int& action){
		std::string data;
		std::string tmp;
        std::cout << "Podaj producenta pojazdu\n";
		std::cin>>data;
        std::cout << "Podaj maksymalne wymiary ladunku w m3\n";
        std::cin >> tmp; data += ";" + tmp;
        std::cout << "Podaj maksymalna wage ladunku\n";
        std::cin >> tmp; data += ";" + tmp;
        std::cout << "Podaj wage przyczepy\n";
        std::cin >> tmp; data += ";" + tmp;
        std::cout << "Czy pojazd przeszedl ostatnie badanie techniczne? 0 - nie, 1 - tak\n";
        std::cin >> tmp; data += ";" + tmp;
        std::cout << "Podaj date ostatniego badania technicznego pojazdu ( dd-mm-rrrr )\n";
		std::cin >> tmp; data += ";" + tmp;
		std::cout << "Komentarz do stanu technicznego\n";
		std::cin >> tmp; data += ";" + tmp;
		//Dodawanie przekazanego typu 
		stringstream type;
		type << action;
		data += ";" + type.str();
		std::cout <<"Podaj VIN przyczepy\n";
		std::cin>>tmp; data += ";" + tmp;
        std::cout << "Podaj aktualny przebieg pojazdu\n";
        std::cin >> tmp; data += ";" + tmp;
        std::cout << "Podaj ostatnio przejechany dystans\n";
        std::cin >> tmp; data += ";" + tmp;
		std::cout << "Czy pojazd jest aktualnie dostepny? 0 - nie, 1 - tak\n";
		std::cin >> tmp; data += ";" + tmp;

		list.push_back(move(Serializer<Trailer>::deserialize(data)));
}

void addCar(std::list<Car*>& list, int& action, int& type) {
	std::string data;
	std::string tmp;	
	stringstream typ;
	switch (action)
	{
	case 1: //Cargo
		data = "c;";
		std::cout << "Podaj maksymalne wymiary ladunku w m3\n";
		std::cin >> tmp; data += tmp;
		std::cout << "Podaj maksymalna wage ladunku\n";
		std::cin >> tmp; data += ";" + tmp;
		typ << type;
		data += ";" + typ.str();
		break;
	case 2: //Utility
		data = "u;";
		typ << type;
		data += typ.str();
		break;
	case 3: //Passenger
		data = "p;";
		std::cout << "Podaj maksymalna liczbe pasazerow\n";
		std::cin >> tmp; data += tmp;
		typ << type;
		data += ";" + typ.str();
		break;
	}
	std::cout << "Podaj producenta pojazdu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj model pojazdu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj poziom paliwa\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj pojemnosc baku\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj liczbe drzwi samochodu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj VIN samochodu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj wage samochodu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj przebieg samochodu\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj ostatnio przejechany dystans\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Czy pojazd jest aktualnie dostepny? 0 - nie, 1 - tak\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj date ostatniego badania technicznego pojazdu ( dd-mm-rrrr )\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Komentarz do stanu technicznego\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Czy pojazd przeszedl ostatnie badanie techniczne? 0 - nie, 1 - tak\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj typ skrzyni biegow : 0 - automatyczna, 1 - polautomatyczna, 2 - manualna\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Czy samochod ma silnik? 0 - nie, 1 - tak\n";
	std::cin >> tmp; data += ";" + tmp;
	if (std::stoi(tmp)) {
		std::cout << "Podaj pojemnosc silnika\n";
		std::cin >> tmp; data += ";" + tmp;
		std::cout << "Podaj ilosc koni mechanicznych\n";
		std::cin >> tmp; data += ";" + tmp;
		std::cout << "Podaj srednia konsumpcje paliwa\n";
		std::cin >> tmp; data += ";" + tmp;
		std::cout << "Podaj typ silnika : 1 - benzynowy, 2 - diesel, 3 - elektryczny\n";
		cin >> tmp; data += ";" + tmp;
	}
	else {
		data += ";0;0;0;0";
	}
	list.push_back(move(Serializer<Car*>::deserialize(data)));
}
void addDriver(std::list<Driver>& list) {
	std::string data;
	std::string tmp;
	std::stringstream id;

	std::cout << "Podaj imie\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj nazwisko\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Czy kierowca jest aktualnie dostepny? 0 - nie, 1 - tak\n";
	std::cin >> tmp; data += ";" + tmp;
	std::cout << "Podaj posiadane kategorie prawa jazdy";
	std::cout << "(wymien po przecinku z pominieciem znaku \'+\', np: \"A,B,BE\") \n";
	std::cin >> tmp; data += ";" + tmp;
	list.push_back(move(Serializer<Driver>::deserialize(data)));
} 