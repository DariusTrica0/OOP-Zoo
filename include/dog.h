#pragma once
#include <string>
#include <memory>
#include <animal.h>

class dog : public animal {
    std::string breed_;
protected:
    void print(std::ostream& os) const override;

public:
    dog(std::string name, int age, std::string breed);
    std::string species() const override;
    std::string sound() const override;
    std::unique_ptr<animal> clone() const override;
};


