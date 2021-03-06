#include "Number.hpp"
#include <cmath>

void Number::setNumber(const int new_val)
{
    // your code here
    this->value = new_val;
}

int Number::getNumber() const
{
    // your code here
    return this->value;
}

std::string Number::print() const
{
    // your code here
    return std::string("I'm a Number class with value " + std::to_string(this->value) + ".");
}

bool Number::isNegative() const
{
    // your code here
    return this->value < 0;
}

long Number::getAbsolute() const
{
    // your code here
    // Try to use STL here
    return std::abs(this->value);
}
