#pragma once
#include<string>
#include"Functions.h"

using std::string;

class Vin
{
private:
    string vin;
public:
    Vin() = default;
    Vin(const string& vin);
    void set(const string& vin) noexcept;
    const string get() const noexcept;
    static bool isValid(const string& vin);
    ~Vin() = default;
};
