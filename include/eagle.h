#pragma once
#include "Animal.hpp"
#include <memory>


class Eagle : public Animal {
    double wingSpan_; // metri
protected:
    void print(std::ostream& os) const override;
public:
    Eagle(std::string name, int age, double wingSpan);
    std::string species() const override;
    std::string sound() const override;
    std::unique_ptr<Animal> clone() const override;
};