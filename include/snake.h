#pragma once
#include "Animal.hpp"
#include <memory>


class Snake : public Animal {
    bool venomous_;
protected:
    void print(std::ostream& os) const override;
public:
    Snake(std::string name, int age, bool venomous);
    std::string species() const override;
    std::string sound() const override;
    std::unique_ptr<Animal> clone() const override;
};