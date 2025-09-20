#pragma once
#include <memory>
#include <vector>
#include <iosfwd>


class Animal;

class Zoo {
    std::vector<std::unique_ptr<Animal>> animals_;
public:
    Zoo() = default;


    // adăugare cu operator+= (clonează polimorfic ca să nu pierdem tipul)
    Zoo& operator+=(const Animal& a);


    // acces indexat (const & non-const)
    const Animal& operator[](std::size_t idx) const;
    Animal& operator[](std::size_t idx);


    std::size_t size() const;
    bool empty() const;


    void sortByAge();
    std::vector<const Animal*> filterBySpecies(const std::string& spec) const;


    friend std::ostream& operator<<(std::ostream& os, const Zoo& z);
};