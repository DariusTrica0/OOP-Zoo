#pragma once
#include <string>
#include <memory>
#include <iosfwd>

class animal {
protected:
    std::string name_;
    int age_{0};
    virtual void print(std::ostream& os) const;

public:
    animal(std::string name, int age);
    virtual ~animal() = default;

    const std::string& name() const;
    int age() const;

    virtual std::string species() const = 0;
    virtual std::string sound() const = 0;
    virtual std::unique_ptr<animal> clone() const = 0;

    bool operator<(const animal& other) const;
    bool operator==(const animal& other) const;

    animal& operator++(); // prefix

    friend std::ostream& operator<<(std::ostream& os, const animal& a);
};  

