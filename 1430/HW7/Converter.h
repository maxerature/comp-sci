#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Converter{
public:
    Converter() ;

    double GetExchangeRate();

    virtual double GetExchangeRate(string, string) = 0;

    void SetExchangeRate(string);
protected:
    double exchange_rate;
};


#endif
