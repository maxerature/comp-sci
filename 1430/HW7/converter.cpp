#include "converter.h"


Converter::Converter() {
    exchange_rate = 1.0;
}

double Converter::GetExchangeRate() {
    return exchange_rate;
}

void Converter::SetExchangeRate(string newRate) {
    //exchange_rate = newRate;
}
