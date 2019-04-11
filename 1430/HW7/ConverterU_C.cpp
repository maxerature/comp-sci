#include "ConverterU_C.h"

ConverterU_C::ConverterU_C() {
    exchange_rate = 1.0;
}

double ConverterU_C::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "C") {
        return exchange_rate;
    }
    else if (first == "C" && last == "U") {
        return 1/exchange_rate;
    }
}
