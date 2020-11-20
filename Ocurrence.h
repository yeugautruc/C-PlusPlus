#pragma once
#include <string>

class Ocurrence
{
private:
    std::string value;
    int amount;
public:
    Ocurrence(/* args */);
    Ocurrence(std::string value, int amount);
    void setValue(std::string value);
    void setAmount(int amount);
    const std::string getValue();
    const int getAmount();
    ~Ocurrence();
};
