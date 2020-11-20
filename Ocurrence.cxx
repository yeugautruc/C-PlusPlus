#include "Ocurrence.h"
#include <string>

Ocurrence::Ocurrence(){
    value = "";
    amount = 0;
};

Ocurrence::Ocurrence(std::string v, int a)
{
    value = v;
    amount = a;
};

void Ocurrence::setValue(std::string v)
{
    value = v;
};

void Ocurrence::setAmount(int a)
{
    amount = a;
};

const std::string Ocurrence::getValue()
{
    return value;
};

const int Ocurrence::getAmount()
{
    return amount;
};

Ocurrence::~Ocurrence(){};