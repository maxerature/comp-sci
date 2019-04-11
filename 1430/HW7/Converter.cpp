#include "converter.h"


Converter::Converter() {
    exchange_rate = 1.0;
}

double Converter::GetExchangeRate() {
    return exchange_rate;
}

void Converter::SetExchangeRate(string newRate) {

    for(int i=0; i<newRate.length(); i++) {
        if (!isdigit(newRate[i]) && (newRate[i] != '.')) {
            newRate[i] = ' ';
        }
    }

    istringstream istr(newRate);
    double baseRate, comparedRate;
    istr >> baseRate;
    istr >> comparedRate;
}
