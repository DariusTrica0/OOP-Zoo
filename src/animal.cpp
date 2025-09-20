#include "animal.hpp"
#include <ostream>

animal::animal(std::string name , int age) name_(std::move(name)) , age_(age)

const std::string& animal::name() const {return name_; }
int animal::age() const {return age_; }


void animal::print(std::ostream& os) const {

    os << species() << " \"" << name_ << "\" (" << age_ << " ani)"
        << " | sunet: " << sound();

}

bool animal::operator<(const animal& other) const {

    if(age_ != other.age) return age_ < other.age;
    if(species() != other.species() ) return species() < other.species();
    return name_ < other.name_;

}

bool animal::operator==(const animal& other ) const {

    return species() == other.species() && name_ == other.name_ && age_ == other.age;

}

animal& animal::operator++() {
    ++age_; 
    return.this;
}


std::ostream& operator<<(std::ostream& os, const animal& a){
    a.print(os);
    return os;
}







