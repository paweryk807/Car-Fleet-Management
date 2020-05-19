#include"Vin.h"
using namespace std;

Vin::Vin(const string& vin):vin(vin){}

void Vin::set(const string& vin) noexcept
{
    this->vin = vin;
}

const string Vin::get() const noexcept
{
    return vin;
}

bool Vin::isValid(const string& vin)
{
    constexpr auto vinMaxLength = 17;
    if (vin.length() != vinMaxLength)
    {
        return false;
    }

    for (unsigned long long i = 0; i < vin.length(); i++)
    {
        if (vin[i] == 'I' || vin[i] == 'O' || vin[i] == 'Q')
        {
            return false;
        }
    }
    return true;
}
