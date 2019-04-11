#include "ConverterU_F.h"

ConverterU_F::ConverterU_F() {
    exchange_rate = 1.0;
}

double ConverterU_F::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "F") {
        return exchange_rate;
    }
    else if (first == "F" && last == "U") {
        return 1/exchange_rate;
    }
}
