#include "eagle.h"
#include <iostream>
#include <iomanip>

eagle::eagle(std::string name, int age, double wingspan)
    : animal(std::move(name), age), wingspan_(wingspan) {}

void eagle::print(std::ostream& os) const {
    animal::print(os);
    auto f = os.flags();
    auto prec = os.precision();
    os.setf(std::ios::fixed, std::ios::floatfield);
    os << std::setprecision(2);
    os << " | anvergura: " << wingspan_ << " m";
    os.flags(f);
    os << std::setprecision(prec);
}


std::string eagle::species() const { return "vultur"; }
std::string eagle::sound() const { return "chiuit"; }
std::unique_ptr<animal> eagle::clone() const {
    return std::make_unique<eagle>(*this);
}



