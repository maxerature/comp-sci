#include "Converter.h"


Converter::Converter() {
    exchange_rate = 1.0;
}

double Converter::GetExchangeRate() {
    return exchange_rate;
}

void Converter::SetExchangeRate(string newRate) {

    for(unsigned int i=0; i<newRate.length(); i++) {
        if (!isdigit(newRate[i]) && (newRate[i] != '.')) {
            newRate[i] = ' ';
        }
    }

    stringstream istr(newRate);
    double baseRate, comparedRate;
    istr >> baseRate;
    istr >> comparedRate;

    exchange_rate = comparedRate/baseRate;
}
