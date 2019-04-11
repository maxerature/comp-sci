#include "ConverterU_G.h"

ConverterU_G::ConverterU_G() {
    exchange_rate = 1.0;
}

double ConverterU_G::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "G") {
        return exchange_rate;
    }
    else if (first == "G" && last == "U") {
        return 1/exchange_rate;
    }
}
