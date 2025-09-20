#include "dog.h"
#include <iostream>

dog::dog(std::string name, int age, std::string breed)
    : animal(std::move(name), age), breed_(std::move(breed)) {}

void dog::print(std::ostream& os) const {
    animal::print(os);
    os << " | rasa: " << breed_;
}

std::string dog::species() const { return "caine"; }
std::string dog::sound() const { return "ham ham"; }
std::unique_ptr<animal> dog::clone() const {
    return std::make_unique<dog>(*this);
}