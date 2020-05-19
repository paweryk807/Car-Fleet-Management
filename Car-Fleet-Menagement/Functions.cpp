#include"Functions.h"
using namespace std;

bool dateValidator(const string& date) {
	if (date != "" && date.length() == 10)
		if (date[2] == '-' && date[5] == '-')
		{
			for (int i = 0; i < 10; i++)
			{
				if (i != 2 && i != 5)
				{
					if (!isdigit(date[i]))
					{
						return false;
					}
				}
			}
			int day = static_cast <int>(date[0]) % 48 * 10 + static_cast <int>(date[1]) % 48;
			int month = static_cast <int>(date[3]) % 48 * 10 + static_cast <int>(date[4]) % 48;
			int year = static_cast <int>(date[6]) % 48 * 1000 + static_cast <int>(date[7]) % 48 * 100 + static_cast <int>(date[8]) % 48 * 10 + static_cast <int>(date[9]) % 48;
			if (year < 0 || year > 3000)
				return false;
			if (month < 0 || month > 12)
				return false;
			switch (month)
			{
			case 4:
			case 6:
			case 9:
			case 11:
			{
				if (day > 30) return false;
			}
			case 2:
			{
				if (year % 4 == 0 && day > 29) return false;
				if (day > 28) return false;
			}
			default:
			{
				if (day > 31) return false;
			}
			}
			return true;
		}
	return false;
}

bool vinValidator(const string& vin) {
	if (vin.length() == 17)
	{
		for (int i = 0; i < vin.length(); i++)
		{
			if (vin[i] == 'I' || vin[i] == 'O' || vin[i] == 'Q')
			{
				return 0;
			}
		}
		return 1;
	}
	else return 0;
}

DrivingLicense drivingLicenseCargo(double weight, bool trailer, double tr_weight){ // weight to waga auta + waga ladunku
	if(weight <= 3500){
		if(!trailer){
			return DrivingLicense::B;
		}
		else if(tr_weight <= 750) {
		 	return DrivingLicense::B;
		}
		else {
			return DrivingLicense::BE;
		}
	}
	if(weight > 3500 && weight <= 7500){
		if(!trailer){
			return DrivingLicense::C1;
		}
		else if(tr_weight <= 750) {
			return DrivingLicense::C1;
		}
	}
	if(weight+tr_weight <= 12000){ // tr_weight 0 if !trailer 
		return DrivingLicense::C1E;
	}
	if(weight >= 3500){
		if(!trailer){
			return DrivingLicense::C;
		}
		else if(tr_weight <= 750) {
			return DrivingLicense::C;
		}
		else {
			return DrivingLicense::CE;
		}
	}

}

DrivingLicense drivingLicensePassenger(int passengers)
{
	if(passengers<=9){
		return DrivingLicense::B;
	}
	else if(passengers<=17){
		return DrivingLicense::D1;
	}
	else return DrivingLicense::D;
}

bool isValidAction(const int firstOption, const int lastOption, const int option)
{
    return firstOption <= option && option <= lastOption;
}

bool getActionFromUser(const int firstAction, const int lastAction, int& action)
{
    action = 0;
    bool result = false;
    int chosenAction = 0;
    std::cin >> chosenAction;
    if (!cin.fail())
    {
        if(isValidAction(firstAction, lastAction, chosenAction))
        {
            action = chosenAction;
            result = true;
        }
        else
        {
            std::cerr << "Parametr: "<<action<< " jest  poza zakresem." << std::endl;
            std::cerr << "Dozwolony zakres argumentow(" << firstAction << " - " << lastAction << ")." << std::endl;
            result = false;
        }
    }
    else
    {
        std::cerr << "Nieprawidlowy parametr: " << chosenAction << std::endl;
        std::cerr << "Dozwolony zakres argumentow(" << firstAction << " - " << lastAction << ")." << std::endl;
        result = false;
    }
    return result;
}

 bool menuOptionsCargo(int &action)
{
    const int firstAction = 0;
    const int lastAction = 4;
    std::ostringstream menu;
    menu << std::endl
        << "Wybierz typ samodchodu : "            <<std::endl
        <<"1. Dostawczy"                        <<std::endl
        <<"2. Ciezarowy"                        <<std::endl
        <<"3. Pickup"                           <<std::endl
        <<"4. Furgonetka"                       <<std::endl
        <<"0. Anuluj"                           <<std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if (action == 0) {
            return false;
        }
        else return true;
    }
    return false;
}
 bool menuOptionsPassenger(int &action)
{
    const int firstAction = 0;
    const int lastAction = 7;
    std::ostringstream menu;
    menu << std::endl
        << "Wybierz typ samochodu : "            <<std::endl
        <<"1. Osobowy"                          <<std::endl
        <<"2. Sedan"                            <<std::endl
        <<"3. Liftback"                         <<std::endl
        <<"4. Hatchback"                        <<std::endl
        <<"5. Kombi"                            <<std::endl
        <<"6. Kabriolet"                        <<std::endl
        <<"7. Minivan"                          <<std::endl
        <<"0. Anuluj"                           <<std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if (action == 0) {
            return false;
        }
        else return true;
    }
    return false;
}
 bool menuOptionsUtility(int &action)
{
    const int firstAction = 0;
    const int lastAction = 5;
    std::ostringstream menu;
    menu << std::endl
        << "Wybierz typ samochodu : "            <<std::endl
        <<"1. Uzytkowy"                         <<std::endl
        <<"2. Holownik"                         <<std::endl
        <<"3. Smieciarka"                       <<std::endl
        <<"4. Ambulans"                         <<std::endl
        <<"5. Plug"                             <<std::endl
        <<"0. Anuluj"                           <<std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if (action == 0) {
            return false;
        }
        else return true;
    }
    return false;
}
 bool menuOptionsTrailer(int &action)
{
    bool result = 0;
    const int firstAction = 0;
    const int lastAction = 7;
    std::ostringstream menu;
    menu << std::endl
        << "Wybierz typ przyczepy: "            <<std::endl
        <<"1. Przyczepa"                        <<std::endl
        <<"2. Przyczepa do przewozu rowerow"    <<std::endl
        <<"3. Przyczepa zabudowana"             <<std::endl
        <<"4. Naczepa"                          <<std::endl
        <<"5. Przyczepa do przewozu koni"       <<std::endl
        <<"6. Kempingowa"                       <<std::endl
        <<"7. Przyczepa do przewozu lodzi"      <<std::endl
        <<"0. Anuluj"                           <<std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if (action == 0) {
            return false;
        }
        else return true;
    }
    return false;
}