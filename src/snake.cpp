#include "snake.h"
#include <iostream>

snake::snake(std::string name, int age, bool is_venomous)
    : animal(std::move(name), age), is_venomous_(is_venomous) {}


void snake::print(std::ostream& os) const {
    animal::print(os);
    os << " | veninos: " << (is_venomous_ ? "da" : "nu");
}


std::string snake::species() const { return "sarpe"; }
std::string snake::sound() const { return "ssssss"; }
std::unique_ptr<animal> snake::clone() const {
    return std::make_unique<snake>(*this);
}