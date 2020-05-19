#include"Driver.h"
using namespace std;

Driver::Driver()
{
	id = 0;
	name = "";
	secondName = "";
	available = 0;
	licenses = "";
}
Driver::Driver(const int id, const string& name, const string& secondName, bool available, const string& licenses)
	:id(id), name(name), secondName(secondName), available(available), licenses(licenses) {}

Driver::Driver(Driver& other) noexcept {
	this->id = other.id;
	this->name = other.name;
	this->secondName = other.secondName;
	this->available = other.available;
	this->licenses = other.licenses;
}

const string Driver::getData() const noexcept {
	string data = "d;" +
		to_string(id) + ";" +
		name + ";" +
		secondName + ";" +
		to_string(available) + ";" +
		licenses + "\n";
	return data;
}

ostream& operator<<(ostream& output, const Driver &d) {
	
	output << "ID kierowcy : "			 << to_string(d.id) << std::endl
		   << "Imie : "				   	 << d.name << std::endl
		   << "Nazwisko : "				 << d.secondName << std::endl
		   << "Dostepnosc : "			 << utils::toString(d.available) << std::endl
		   << "Kategorie prawa jazdy : " << d.licenses << std::endl;
	return output;
}

const string Driver::getLicenses() const noexcept {
	return licenses;
}
const int Driver::getId() const noexcept {
	return id;
}

const string Driver::getName() const noexcept {
	return name;
}
const string Driver::getSecondName() const noexcept {
	return secondName;
}
const bool Driver::getAvailable() const noexcept {
	return available;
}
void Driver::updateId(const int id) noexcept {
	this->id = id;
}

void Driver::updateName(const string& name) noexcept {
	this->name = name;
}
void Driver::updateSecondName(const string& secondName) noexcept {
	this->secondName = secondName;
}
void Driver::updateAvailable(bool available) noexcept {
	this->available = available;
}
void Driver::updateLicenses(const string& licenses) noexcept {
	this->licenses = licenses;
}
bool Driver::licenseCheck(DrivingLicense License) noexcept {
	//size_t position = licenses.find(a);
	std::string x = licenses;
    const char license_delimiter[] = ",";
    char* next_token1 = nullptr;
	std::ostringstream os;
    std::string tmpL = strtok_s(const_cast<char*>(x.c_str()), license_delimiter, &next_token1);
	if(tmpL == utils::toString(License))
		return 1;
	while(!x.empty()){
    	tmpL = strtok_s(nullptr, license_delimiter, &next_token1);
		if(tmpL == utils::toString(License))
			return 1;
	}
	return 0;

}
Driver::~Driver() {};

