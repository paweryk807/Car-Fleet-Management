#include "Menu.h"
#include <limits>

Menu::Menu() {}


void Menu::load(FileHandler& files) noexcept {
    files.readCars(carList);
    files.loadDrivers(driverList);
    files.loadTrailers(trailerList);
    files.loadTasks(taskList);
}

void Menu::save(FileHandler& files) noexcept {
    files.saveCars(carList);
    files.saveDrivers(driverList);
    files.saveTrailers(trailerList);
    files.saveTasks(taskList);
}

bool Menu::findTrailerByVin(const std::string& vin, Trailer* &tmp) noexcept {
       std::list<Trailer>::iterator it;
       it = trailerList.begin();
       while (it != trailerList.end()) {
           if (it->getVin() == vin) {
                tmp = &(it._Ptr->_Myval);
               return true;
        }
           it++;
       }
       return false;
}

void Menu::deleteTrailerByVin(const std::string& vin) noexcept {
       std::list<Trailer>::iterator it;
       it = trailerList.begin();
       while (it != trailerList.end()) {
           if (it->getVin() == vin) {
               it = trailerList.erase(it);
        }
           it++;
       }
}

Car* Menu::findCarByVin(const std::string& vin) noexcept {
       std::list<Car*>::iterator it;
       it = carList.begin();
       while (it != carList.end()) {
           if ((*it)->getVin() == vin) {
               return *it;
        }
           it++;
       }
       return nullptr;
}

void Menu::deleteCarByVin(const std::string& vin) noexcept {
    std::list<Car*>::iterator it;
    it = carList.begin();
    while (it != carList.end()) {
        if ((*it)->getVin() == vin)
        {
            Car* tmp = *it; 
            it = carList.erase(it);
            delete tmp;
        }
        it++;

    }
}

bool Menu::findTaskById(const int id, Task* &tmp) noexcept {
       std::list<Task>::iterator it;
       it = taskList.begin();
       while (it != taskList.end()) {
           if (it->getId() == id) {
                tmp = &(it._Ptr->_Myval);
               return true;
        }
           it++;
       }
       std::cerr << "Nie znaleziono takiego zlecenia." << std::endl;
       return false; 
}

bool Menu::findDriverById(const int id, Driver* &tmp) noexcept {
       std::list<Driver>::iterator it;
       it = driverList.begin();
       while (it != driverList.end()) {
           if (it->getId() == id) {
                tmp = &(it._Ptr->_Myval);
               return true;
        }
           it++;
       }
       std::cerr << "Nie znaleziono takiego kierowcy." << std::endl;
       return false; 
}

void Menu::deleteDriverById(const int id) noexcept {
       std::list<Driver>::iterator it;
       it = driverList.begin();
       while (it != driverList.end()) {
           if (it->getId() == id) {
               it = driverList.erase(it);
        }
           it++;
       }
}


void Menu::modifyData(const int action) noexcept {
    int action2{};
    std::string vin{};
    int id{};
    Car* car = nullptr;
    Driver* driver = nullptr;
    Trailer* trailer = nullptr;
    switch (action)
    {
    case 1: {
        std::cout << "Modyfikuj Pojazdy\n";
        std::cout << "Podaj numer Vin pojazdu, ktory chcesz edytowac:\n";
        std::cin >> vin;
        if (vinValidator(vin)) {
            car = findCarByVin(vin);
            if (car) {
                std::cout << "Co uaktualnic?\n0. Powrot\n1. Komentarze\n2. Zuzycie paliwa\n3. Date przegladu\n4. Wynik przegladu\n5. Ilosc koni mechanicznych\n6. Poziom paliwa\n";
                std::cout << "7. Pojemnosc baku\n8. Typ silnika\n9. Typ skrzyni\n10. Przebieg\n11. Usun\n";
                std::cin >> action2;
                switch (action2)
                {
                case 0: break;
                case 1: {
                    std::string com{}; std::cout << "Wprowadz komentarz:\n";
                    std::cin >> com;
                    car->updateComments(com);
                }
                      break;
                case 2: {
                    double con{}; std::cout << "Wprowadz zuzycie paliwa:\n";
                    std::cin >> con;
                    if (con > 0) {
                        car->updateFuelConsumption(con);
                    }
                }
                      break;
                case 3: {
                    string date{}; std::cout << "Wprowadz date przegladu:\n";
                    std::cin >> date;
                    car->updateLastTechnicalExamDate(date);
                }
                      break;
                case 4: {
                    bool res{}; std::cout << "Wprowadz wynik przegladu:\n";
                    std::cin >> res;
                    car->updateResult(res);
                }
                      break;
                case 5: {
                    double hp{}; std::cout << "Wprowadz ilosc koni mechanicznych:\n";
                    std::cin >> hp;
                    if (hp > 0) {
                        car->updateHorsepower(hp);
                    }
                }
                      break;
                case 6: {
                    double fuel{}; std::cout << "Wprowadz poziom paliwa:\n";
                    std::cin >> fuel;
                    if (fuel >= 0) {
                        car->updateFuelLevel(fuel);
                    }
                }
                      break;
                case 7: {
                    double fuel{}; std::cout << "Wprowadz pojemnosc baku paliwa:\n";
                    std::cin >> fuel;
                    if (fuel >= 0) {
                        car->updateFuelTank(fuel);
                    }

                }
                      break;
                case 8: {
                    int con{}; std::cout << "Zaktualizuj typ silnika:\n1. benzynowy\2. diesel\n3. elektryczny\n ";
                    std::cin >> con;
                    if (con > 0 && con < 4) car->updateMotorType(static_cast<MotorType>(con));
                }
                      break;
                case 9: {
                    int con{}; std::cout << "Zaktualizuj typ skrzyni biegow:\n1. automatic\n2. semi_automatic\3. manual";
                    std::cin >> con;
                    if (con > 0 && con < 4) car->updateTransmission(static_cast<Transmission>(con - 1));
                }
                      break;
                case 10: {
                    double con{}; std::cout << "Zaktualizuj przebieg:\n";
                    std::cin >> con;
                    if (con >= 0) car->updateMileage(con);
                }
                       break;
                case 11: {
                    deleteCarByVin(vin);
                }
                       break;
                default: break;
                }
            }
            else std::cerr << "Nie ma takiego pojazdu w bazie\n";
        }
    }
          break;
    case 2: {
        std::cout << "Modyfikuj kierowce:\n";
        std::cout << "Podaj numer id kierowcy, ktorego chcesz edytowac:\n";
       // cin >> id;
        if (!(std::cin >> id)) {
            std::cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            findDriverById(id, driver);
            if (driver) {
                std::cout << driver->getData() << "\n";
                std::cout << "Co uaktualnic?\n0. Powrot\n1. Imie\n2. Nazwisko\n3. Dostepnosc\n4. Licencje\n5. Usun";// Maksymalna liczbe pasazerow\n12.Styl nadwozia\n; ";
                std::cin >> action2;
                switch (action2)
                {
                case 0: break;
                case 1: {
                    std::string con{}; std::cout << "Wprowadz imie kierowcy:\n";
                    std::cin >> con;
                    if (!con.empty()) driver->updateName(con);
                }
                      break;
                case 2: {
                    std::string con{}; std::cout << "Wprowadz nazwisko kierowcy:\n";
                    std::cin >> con;
                    if (!con.empty()) driver->updateName(con);
                }
                      break;
                case 3: {
                    bool res{}; std::cout << "Wprowadz dostepnosc kierowcy:\n";
                    std::cin >> res;
                    driver->updateAvailable(res);
                }
                      break;
                case 4: {
                    string lc{}; std::cout << "Wprowadz licencje kierowcy (-> A AB BA CBA ABC <-) :\n";
                    std::cin >> lc;
                    if (!lc.empty()) driver->updateLicenses(lc);
                }
                      break;
                case 5: {
                    deleteDriverById(id);
                }

                      break;
                default: break;
                }
            }
            else std::cerr << "Nie ma kierowcy o takim id w bazie\n";
        }
    }

          break;
    case 3: {
        std::cout << "Modyfikuj przyczepe:\n"; 
        std::cout << "Podaj numer Vin przyczepy, ktora chcesz edytowac:\n";
        std::cin >> vin;
            findTrailerByVin(vin, trailer);
            if (trailer) {
                std::cout << "Co uaktualnic?\n0. Powrot\n1. Komentarze\n2. Date przegladu\n3. Wynik przegladu\n";
                std::cout << "4. Pojemnosc\n5. Mase pojazdu\n6. Przebieg\n7. Dlugosc ostatniego kursu\n8. Usun\n";
                std::cin >> action2;
                switch (action2)
                {
                case 0: break;
                case 1: {
                    std::string comment{}; std::cout << "Wprowadz komentarz:\n";
                    std::cin >> comment;
                    if (!comment.empty()) trailer->updateComments(comment);
                }
                      break;
                case 2: {
                    std::string date{}; std::cout << "Wprowadz date przegladu:\n";
                    std::cin >> date;
                    if (!date.empty()) trailer->updateLastTechnicalExamDate(date);
                }
                      break;
                case 3: {
                    bool result{}; std::cout << "Wprowadz wynik przegladu:\n";
                    std::cin >> result;
                    trailer->updateResult(result);
                }
                      break;
                case 4: {
                    double cap{}; std::cout << "Wprowadz pojemnosc:\n";
                   std::cin >> cap;
                    trailer->updateCapacity(cap);
                }
                      break;
                case 5: {
                    double x{}; std::cout << "Wprowadz nowa wage:\n";
                    std::cin >> x;
                    trailer->updateWeight(x);
                }
                      break;
                case 6: {
                    double x{}; std::cout << "Wprowadz przebieg:\n";
                    std::cin >> x;
                    trailer->updateMileage(x);
                }
                      break;
                case 7: {
                    double x{}; std::cout << "Wprowadz dlugosc ostatniego kursu:\n";
                    std::cin >> x;

                }
                      break;
                case 8: {
                    deleteTrailerByVin(vin);
                }
                      break;
                default: break;
                }
            }
            else std::cerr << "Nie ma przyczepy o takim numerze Vin w bazie\n";
            system("pause");

    }
          break;
    case 4: {
        std::cout << "Modyfikuj zlecenie:\n";
    }
          break;
    default: break;

    }
}
void Menu::addData(int& action) noexcept {
    int action2;
    switch (action)
    {
    case 0: break;
    case 1 :
        std::cout << "Dodawanie :: pojazd dostawczy\n";
        if(menuOptionsCargo(action2)){
            action2 -= 1;
            addCar(carList,action, action2);
        }
        break;
    case 2 :
        std::cout << "Dodawanie :: pojazd uzytkowy\n";
        if(menuOptionsUtility(action2)){
            action2 -= 1;
            addCar(carList,action, action2);
        }
        break;
    case 3:
        std::cout << "Dodawanie :: pojazd osobowy\n";
        if(menuOptionsPassenger(action2)){
             action2 -= 1;
             addCar(carList,action, action2);
        }
        break;
    case 4:
        std::cout << "Dodawanie :: przyczepa\n";
        if(menuOptionsTrailer(action2)){
            action2 -= 1;
             addTrailer(trailerList, action2);
        }
  
        break;
    case 5: {  cout << "Dodawanie :: kierowca\n";
            addDriver(driverList);
      //  driverList.push_back(*(new Driver(bufor)));
    }

          break;
    default:
      //  std::cerr << "opcja jeszcze nie zaimplementowana !!!";
        break;
    }

}

void Menu::browseData(const int option) noexcept {
    switch (option)
    {
    case 1: {
        for (auto& item : carList) {
            std::cout << *item << std::endl;
        }

    }
     break;

    case 2: {
        for (auto& item : driverList) {
            std::cout << item << std::endl;
        }
    }
     break;

    case 3: {
        for (auto& item : trailerList) {
            std::cout << item << std::endl;
        }
    }
        break;

    case 4: {
        for (auto& item : taskList) {
            std::cout << item << std::endl;
        }
    }
        break;

    case 5: {
        cout << "\nPojazdy majace malo paliwa :\n\n";
        std::list<Car*>::iterator it;
        it = carList.begin();
        while (it != carList.end()) { 
            if (((*it)->getFuelLevel() / (*it)->getFuelTank()) <= 0.15) {
                cout << "Pojazd : " << std::endl
                     << **it << " Aktualny poziom paliwa to : " << (*it)->getFuelLevel() << ", pojemnosc baku : " << (*it)->getFuelTank() << std::endl;
            }
            it++;
        }
		cout << std::endl;

        it = carList.begin();
        cout << "\nPojazdy majace problemy techniczne :\n\n";
        while (it != carList.end()) {
            if ((*it)->getResult() == 0)
            {
                cout << "Pojazd : " << std::endl << **it
                     << "Dane o przegladzie :" << std::endl
                     << (*it)->getDate() << std::endl;
            }
            it++;
        }
        cout << std::endl;
        
        cout << "\nPrzyczepy :\n\n";
        std::list<Trailer>::iterator t_it;
        t_it = trailerList.begin();
        while (t_it != trailerList.end()) {
            if (t_it->getResult() == 0)
            {
                cout << "Pojazd : " << std::endl << *t_it
                     << "Dane o przegladzie :" << std::endl
                     << t_it->getDate() << std::endl;
            }
            t_it++;
        }
    }break;
    case 6:{
        int action{};
        std::string tmp;
        const int firstAction = 0;
        const int lastAction = 4;
        Driver* driver=nullptr;
        Task* task=nullptr;
        Trailer* trailer=nullptr;
        Car* car=nullptr;
        std::cout<<"Przegladaj historie: " << std::endl
        << "1. Pojazd" << std::endl
        << "2. Kierowca" << std::endl
        << "3. Przyczepa" << std::endl
        << "4. Zlecenie" << std::endl
        << "0. Powrot" << std::endl;
        if (getActionFromUser(firstAction, lastAction, action))
        {
            switch(action){
                case 1:{
                    std::cout<<"Podaj vin pojazdu: "<<std::endl;
                    cin>>tmp;
                    if(vinValidator(tmp)){
                        car = findCarByVin(tmp);
                        if(car){
                            std::cout << car->print() <<std::endl;
                            std::cout << "Historia zlecen : "<<std::endl;
                            for( auto& item : taskList)
                            {
                                if(item.getCarVin() == car->getVin()){
                                    std::cout<<item<<std::endl;
                                }
                            }
                        }
                    }
                    else{
                        std::cout<<"Podano nieprawidlowy vin"<<std::endl;
                    }
                }break;
                case 2:{
                    std::cout<<"Podaj id kierowcy: "<<std::endl;
                    cin>>tmp;
                    if(findDriverById(stoi(tmp),driver)){
                        std::cout << *driver <<std::endl;
                        std::cout << "Historia zlecen : "<<std::endl;
                        for( auto& item : taskList)
                        {
                            if(item.getDriverId() == driver->getId()){
                                std::cout<<item<<std::endl;
                            }
                        }
                    }
                    
                }break;
                case 3:{
                    std::cout<<"Podaj vin przyczepy: "<<std::endl;
                    cin>>tmp;
                    if(vinValidator(tmp)){
                        if(findTrailerByVin(tmp,trailer)){
                            std::cout << *trailer <<std::endl;
                            std::cout << "Historia zlecen : "<<std::endl;
                            for( auto& item : taskList)
                            {
                                if(item.getTrailerVin() == trailer->getVin()){
                                    std::cout<<item<<std::endl;
                                }
                            }
                        }
                    }
                    else{
                        std::cout<<"Podano nieprawidlowy vin"<<std::endl;
                    }
                }break;
                case 4:{
                    std::cout<<"Podaj id zlecenia: "<<std::endl;
                    cin>>tmp;
                    if(findTaskById(stoi(tmp),task)){
                        std::cout << *task <<std::endl;
                        std::cout << "Dane kierowcy : "<<std::endl;
                        for( auto& item : driverList)
                        {
                            if(item.getId() == task->getDriverId()){
                                std::cout<<item<<std::endl;
                            }
                        }
                        std::cout << "Dane pojazdu : "<<std::endl;
                        for( auto& item : carList)
                        {
                            if(item->getVin() == task->getCarVin()){
                                std::cout<<item<<std::endl;
                            }
                        }
                        std::cout << "Dane przyczepy : "<<std::endl;
                        for( auto& item : trailerList)
                        {
                            if(item.getVin() == task->getTrailerVin()){
                                std::cout<<item<<std::endl;
                            }
                        }
                    }
                }break;
            }
        }
    }break;
    default: break;
    }
}




bool Menu::menuOptionsMain(int &action)
{
    bool result = 0;
    const int firstAction = 0;
    const int lastAction = 4;
    std::ostringstream menu;
    menu << std::endl
        << "Menu: " << std::endl
        << "1. Przegladaj dane" << std::endl
        << "2. Modyfikuj dane" << std::endl
        << "3. Zrealizuj zlecenie" << std::endl
        << "4. Wprowadz dane" << std::endl
        << "0. Wyjdz" << std::endl;
    std::cout << menu.str();

    return getActionFromUser(firstAction, lastAction, action);
}

bool Menu::menuOptionsBrowse(int& action)
{
    const int firstAction = 1;
    const int lastAction = 5;
  //  if()
    return getActionFromUser(firstAction,lastAction,action);
}
bool Menu::menuOptionsDisplay(int &action)
{
    bool result = false;
    const int firstAction = 0;
    const int lastAction = 6;
    std::ostringstream menu;
    menu << "Przegladaj dane: " << std::endl
        << "1. Pojazdy" << std::endl
        << "2. Kierowcy" << std::endl
        << "3. Przyczepy" << std::endl
        << "4. Zlecenia" << std::endl
        << "5. Wymagajace uwagi" << std::endl
        << "6. Historia" << std::endl
        << "0. Powrot" << std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action))
    {
        if (action > 0)
        {
         browseData(action);
        }
        result = true;
    }
    return result;
}

bool Menu::menuOptionsModify(FileHandler& files)
{
    bool result = false;
    int action = 0;
    const int firstAction = 0;
    const int lastAction = 4;
    std::ostringstream menu;
    menu << "Modyfikuj dane:" << std::endl
        << "1. Pojazdy" << std::endl
        << "2. Kierowcy" << std::endl
        << "3. Przyczepy" << std::endl
        << "4. Zlecenia" << std::endl
        << "0. Powrot" << std::endl;
    std::cout << menu.str();
    if(getActionFromUser(firstAction, lastAction, action))
    {
        if(action > 0)
        {
            modifyData(action);
            save(files);
        }
        result = true;
    }
    return result;
}

bool Menu::menuOptionsAdd(int &action)
{
    bool result = 0;
    const int firstAction = 0;
    const int lastAction = 5;
    std::ostringstream menu;
    menu << std::endl
        << "Dodaj: " << std::endl
        << "1. Pojazd dostawczy" << std::endl
        << "2. Pojazd uzytkowy" << std::endl
        << "3. Pojazd osobowy" << std::endl
        << "4. Przyczepe" << std::endl
        << "5. Kierowce" << std::endl
        << "0. Powrot" << std::endl;
    std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if (action == 0) {
            return false;
        }
		addData(action);
        result = true;
    }
    return result;
}

void Menu::start(FileHandler& files) noexcept
{
    load(files);
    bool run = true;
    int actionMainMenu = 0;
    while (run)
    {
        menuOptionsMain(actionMainMenu);
        
        int actionTmp = 0;
        int action = 0;
        switch (actionMainMenu)
        {
        case 0:
            std::cout << "Do widzenia!" << std::endl;
            run = false;
            break;
        case 1:
            menuOptionsDisplay(actionTmp);
            break;
        case 2:
            menuOptionsModify(files);
            break;
        case 3:
            menuOptionsRealization(actionTmp);
            save(files);
            break;
        case 4:
            menuOptionsAdd(actionTmp);
            save(files);
            break;
        default:
		break;
        }
    }
	clean();

}
bool Menu::menuOptionsRealization(int &action)
{
    bool result = false;
    const int firstAction = 0;
    const int lastAction = 3;
    std::ostringstream menu;
    menu << "Wybierz zadanie: " << std::endl
        << "1. Transport ladunku" << std::endl
        << "2. Przewoz osob" << std::endl
        << "3. Wypozyczanie przyczepy" << std::endl
        << "0. Powrot" << std::endl;
	std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action))
    {
        if (action > 0)
        {
            takePreferences(action);
        }
        result = true;
    }
    return result;
}
void::Menu::clean() {
	for (auto& item : carList)
    {
        delete item;
    }
    carList.clear();
    driverList.clear();
    trailerList.clear();
    taskList.clear();
}

Car* Menu::CarShipSearcher(const double v, const double c) {
    std::list<Car*>::iterator it; 
    it = carList.begin();
    while(it != carList.end()){
            if (typeid(**it) == typeid(CargoCar) && (*it)->getAvailable() == 1) {
                if ((*it)->getCargoV() >= v && (*it)->getCapacity() >= c){
                  return *it;   
                }
            }
            it++;
    }
    return nullptr;
}

Car* Menu::CarPassengerSearcher(const int p){
    std::list<Car*>::iterator it; 
    it = carList.begin();
    while(it != carList.end()){
            if (typeid(**it) == typeid(PassengerCar) && (*it)->getAvailable() == 1) {
                if ((*it)->getMaxPassengers() >= p){
                  return *it;
                }
            }
            it++;
    }
    return nullptr;
}

bool Menu::trailerShipSearcher(const double v, const double c, Trailer* &tmp) noexcept{
    std::list<Trailer>::iterator it;
    it = trailerList.begin();
    while(it != trailerList.end()){
        if(it->getAvailable() == 1){
            if (it->getCapacity() >= c && it->getCargoV() >= v) {
                tmp = &(it._Ptr->_Myval);
                return true;
            }
        }
        it++;
    }
    return false;
}
bool Menu::findDriverByCategory(DrivingLicense license, Driver* &tmp) noexcept{
    std::list<Driver>::iterator it;
    it = driverList.begin();
    while(it!=driverList.end()){
        if(it->getAvailable() == 1 ){
            if (it->licenseCheck(license)) {
                tmp = &(it._Ptr->_Myval);
                return true;
            }
         }
        it++;
    }
    return false;
}
bool Menu::advancedShipment(int &action, double v, double c) noexcept{
    double v1{},c1{};
    Car* car1 = nullptr;
    Car* car2 = nullptr;
    Driver* driver1 = nullptr;
    Driver* driver2 = nullptr;
    Trailer* trailer = nullptr;
    Route way;
    std::cout << "Realizacja dla dwoch pojazdow " << std::endl
        << "Podaj ile kg z podanego ladunku ma jechac w pierwszym pojezdzie : " << std::endl;
        std::cin>> c1;
        std::cout<< "Podaj jaka to bedzie objetosc : " << std::endl;
        std::cin>>v1;
        v-=v1;
        c-=c1;
        car1 = CarShipSearcher(v,c);
        if(car1){
            if(trailerShipSearcher(v,c,trailer)){ // wersja pojazd + przyczepa 
                if(findDriverByCategory(drivingLicenseCargo(car1->getWeight() + c + trailer->getWeight() + c1, true, trailer->getWeight() + c1),driver1)){
                   if(menuAddRoute(action, driver1, car1, trailer, nullptr, nullptr)){
                        car1->updateAvailable(0);
                        driver1->updateAvailable(0);
                        trailer->updateAvailable(0);
                        way = takeRoute();
                        addTask(way, driver1, car1, trailer);
                        return true;
                    }
                }   
            }
            else { // wersja dwa pojazdy
                car1->updateAvailable(0); // w celu zapobiegania duplikatom 
                car2 = CarShipSearcher(v1,c1);
                if(car2){
                    if(findDriverByCategory(drivingLicenseCargo(car1->getWeight() + c, 0, 0), driver1)){
                            driver1->updateAvailable(0); 
                        if(findDriverByCategory(drivingLicenseCargo(car2->getWeight() +c1,0,0),driver2)){
                            driver1->updateAvailable(1); // restore default
                            car1->updateAvailable(1);
                            if(menuAddRoute(action, driver1, car1, nullptr, driver2 , car2)){
                             car2->updateAvailable(0);  car1->updateAvailable(0);
                             driver2->updateAvailable(0); driver1->updateAvailable(0);
                             way = takeRoute();
                             Route sway = way;
                             trailer = nullptr;
                             addTask(way, driver1, car1, trailer);
                             addTask(sway, driver2, car2, trailer);
                            return true;
                        }
                    }
                    }  

                } 
                car1->updateAvailable(1);
            }
        }
        std::cout<<"Tego zlecenia nie mozna zrealizowac"<<std::endl;
        return false;
}

bool Menu::menuAddRoute(int action, Driver *tmp1, Car* cmp1, Trailer* rmp, Driver *tmp2=nullptr, Car* cmp2=nullptr){
    const int firstAction = 0;
    const int lastAction = 1;
    std::ostringstream menu;
    menu << "Dane zostaly znalezione trase : " << std::endl
        << "Znaleziono samochod : " << std::endl
        <<*cmp1;
        if(cmp2){
            menu<<"\noraz samochod : "<<std::endl
            <<*cmp2;
        }
        menu<<"Kierowca wykonujacy zlecenie : "<<std::endl
        <<*tmp1;
        if(tmp2){
            menu<<"\noraz kierowca : "<<std::endl
            <<*tmp2;
        }
        menu << "Chcesz wykonac zlecenie? "<< std::endl
        << "0. Nie" << std::endl
        << "1. Tak" << std::endl;
	std::cout << menu.str();
    if (getActionFromUser(firstAction, lastAction, action)) {
        if(action == 1){
            return true;
        }
    }
    return false;
}

Route Menu::takeRoute(){
    std::string start,destination,date,distance{};
    std::cout << "Wprowadz miasto poczatkowe : "<<std::endl;
    std::cin>>start;
    std::cout << "Wprowadz miasto docelowe : "<<std::endl;
    std::cin>>destination;
    std::cout << "Wprowadz planowana date przejazdu : "<<std::endl;
    std::cin>>date;
    std::cout<< "Wprowadz szacowana odleglosc przejazdu : "<<std::endl;
    std::cin>>distance;
    return Route(start,destination,date,std::stod(distance));
}

void Menu::addTask(Route &way, Driver* &driver,Car* &car, Trailer* &trailer) {
    double cost;
    if (car) {
        if (car->haveEngine()) {
             cost = (way.getDistance()/100)*(18 + car->getFuelConsumption());
        }
    }
    else {
        cost = (way.getDistance() / 100) * 18;
    }
    if (car) {
    if(trailer==nullptr){
        if(taskList.empty()){
            taskList.push_back(Task(1,driver->getId(), car->getVin(),"00000000000000000",way,cost));
        } 
        else{
            taskList.push_back(Task((taskList.size()+1),driver->getId(), car->getVin(),"00000000000000000",way,cost));
        }
    }
    else {
        if (taskList.empty()) {
            taskList.push_back(Task(1, driver->getId(), car->getVin(), trailer->getVin(), way, cost));
        }
        else {
            taskList.push_back(Task((taskList.size() + 1), driver->getId(), car->getVin(), trailer->getVin(), way, cost));
        }
    }
    }
    else if (trailer) {
        if(taskList.empty()){
            taskList.push_back(Task(1, 0, "00000000000000000", trailer->getVin(),way,cost));
        } 
        else{
            taskList.push_back(Task((taskList.size()+1), 0, "00000000000000000", trailer->getVin(),way,cost));
        }
    }

}

bool Menu::TrailerSearcher(TrailerType type,double v,double c, Trailer* &tr){
    std::list<Trailer>::iterator it;
    it = trailerList.begin();
    while(it!=trailerList.end()){
        if(it->getAvailable() == 1 && it->getType()==type && it->getCapacity()>=c && it->getCargoV()>=v){
                tr = &(it._Ptr->_Myval);
                return true;
         }
        it++;
    }
    return false;
}

void Menu::takePreferences(int &action) noexcept {
    double distance{}, capacity{}, horsepower{}, value{}, volume{};
    std::string date{};
    bool trailer = false;
    bool working = true;
    int action2 = 0;
    Driver* driver1 = nullptr;
    Trailer* tr = nullptr;
    Car* car = nullptr;
    Route way;
    int passengers{};
   // int action2{};
    while (working) {
            switch (action) {
            case 1:
                std::cout << "Wprowadz wymiary ladunku (w m3):\n";
                std::cin >> volume;
                std::cout << "Wprowadz wage ladunku:\n";
                std::cin >> capacity;
                if (volume > 0 && capacity > 0)
                {
                    car = CarShipSearcher(volume, capacity);
                    if (!car) {
                        std::cout << "W bazie nie ma samochodu, ktory moze przewiezc taki ladunek" << std::endl
                            << "Czy jest mozliwosc podzialu ladunku na dwa pojazdy?" << std::endl
                            << "1. Tak" << std::endl << "0. Nie" << std::endl;
                        cin >> action2;
                        if (action2 == 1) {
                            advancedShipment(action, volume, capacity);
                        }
                        else {
                            working = false;
                        }

                    }
                    else
                    {
                        double x = car->getWeight() + capacity;
                        DrivingLicense s = drivingLicenseCargo(x, 0, 0);
                        if (findDriverByCategory(s, driver1)) {
                            if (menuAddRoute(action, driver1, car, nullptr, nullptr)) {
                                car->updateAvailable(0);
                                driver1->updateAvailable(0);
                                way = takeRoute();
                                //way.calculateFinalization();
                                addTask(way, driver1, car, tr);
                                working = false;
                            }

                            //  working = false;
                            // taskList.push_back();
                        }
                    }
                }
                break;
            case 2:
                std::cout << "Wprowadz ilosc pasazerow:\n";
                std::cin>>passengers;
                if(passengers>0){
                    car=CarPassengerSearcher(passengers);
                    if(car){
                        if(findDriverByCategory(drivingLicensePassenger(passengers+1),driver1)){
                            car->updateAvailable(0);
                            driver1->updateAvailable(0);
                            way = takeRoute();
                            addTask(way, driver1, car, tr);
                            working = false;
                        }
                    }
                    else{
                        std::cout<<"W bazie nie ma samochodu, ktory moze przewiezc tyle osob"<<std::endl;
                        working=false;
                    }
                }
                break;
            case 3:
                if(menuOptionsTrailer(action2)){
                    switch(action2){
                        case 0: {
                            working = false;
                        }break;
                        case 1:
                        case 3:
                        case 4:{
                            std::cout << "Wprowadz wymiary ladunku (w m3):\n";
                            std::cin >> volume;
                            std::cout << "Wprowadz wage ladunku:\n";
                            std::cin >> capacity;
                            if (volume > 0 && capacity > 0)
                            {
                                if(TrailerSearcher(static_cast<TrailerType>(action2-1),volume,capacity, tr)){
                                    tr->updateAvailable(0);
                                    way = takeRoute();
                                    addTask(way, driver1, car, tr);
                                    working = false;
                                }
                                else{
                                    std::cout<<"W bazie nie ma przyczepy, ktora moze przewiezc taki ladunek"<<std::endl;
                                    working=false;
                                }
                            }
                            else{
                                std::cout<<"Ujemna waga lub wymiary? Co to za haksy?"<<std::endl;
                                working=false;
                            }
                        }break;
                        case 2:
                        case 5:
                        case 6:
                        case 7:{
                            if(TrailerSearcher(static_cast<TrailerType>(action2-1),0,0, tr)){
                                tr->updateAvailable(0);
                                way = takeRoute();
                                addTask(way, driver1, car, tr);
                                working = false;
                            }
                            else{
                                std::cout<<"W bazie nie ma przyczepy, ktora moze przewiezc taki ladunek"<<std::endl;
                                working=false;
                            }
                        }break;
                        default: break;
                    }
                }
                break;
            case 0:
                working=false;
                break;
            }
        }

 }

Menu::~Menu() {} //delete carList; };