#ifndef CONVERTERU_C_H
#define CONVERTERU_C_H

#include "converter.h"

class ConverterU_C : public Converter{
public:
    ConverterU_C() ;

    double GetExchangeRate(string, string);

protected:
private:

};


#endif
