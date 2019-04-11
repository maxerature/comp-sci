#include "ConverterU_E.h"

ConverterU_E::ConverterU_E() {
    exchange_rate = 1.0;
}

double ConverterU_E::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "E") {
        return exchange_rate;
    }
    else if (first == "E" && last == "U") {
        return 1/exchange_rate;
    }
}
