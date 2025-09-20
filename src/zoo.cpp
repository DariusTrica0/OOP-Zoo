os << "Zoo (" << z.size() << " animale)\n";

#include "Zoo.hpp"
#include "Animal.hpp"
#include <algorithm>
#include <stdexcept>
#include <ostream>

#include "Zoo.hpp"
#include "Animal.hpp"
#include <algorithm>
#include <stdexcept>
#include <ostream>


Zoo& Zoo::operator+=(const Animal& a) {
    animals_.push_back(a.clone());
    return *this;
}


const Animal& Zoo::operator[](std::size_t idx) const {
    if (idx >= animals_.size()) throw std::out_of_range("index invalid");
    return *animals_[idx];
}


Animal& Zoo::operator[](std::size_t idx) {
    if (idx >= animals_.size()) throw std::out_of_range("index invalid");
    return *animals_[idx];
}


std::size_t Zoo::size() const { return animals_.size(); }
bool Zoo::empty() const { return animals_.empty(); }


void Zoo::sortByAge() {
    std::sort(animals_.begin(), animals_.end(),
        [](const auto& a, const auto& b){ return *a < *b; });
}


std::vector<const Animal*> Zoo::filterBySpecies(const std::string& spec) const {
    std::vector<const Animal*> out;
    out.reserve(animals_.size());
    for (const auto& p : animals_) if (p->species() == spec) out.push_back(p.get());
    return out;
}


std::ostream& operator<<(std::ostream& os, const Zoo& z) {
    os << "Zoo (" << z.size() << " animale)\n";
    for (std::size_t i = 0; i < z.animals_.size(); ++i) {
        os << " [" << i << "] " << *z.animals_[i] << "\n";
    }
    return os;
}