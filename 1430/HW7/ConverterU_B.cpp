#include "ConverterU_B.h"

ConverterU_B::ConverterU_B() {
    exchange_rate = 1.0;
}

double ConverterU_B::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "B") {
        return exchange_rate;
    }
    else if (first == "B" && last == "U") {
        return 1/exchange_rate;
    }
}
