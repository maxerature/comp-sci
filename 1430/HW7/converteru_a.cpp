#include "converteru_a.h"

ConverterU_A::ConverterU_A() {
    exchange_rate = 1.0;
}

double ConverterU_A::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "A") {
        return exchange_rate;
    }
    else if (first == "A" && last == "U") {
        return 1/exchange_rate;
    }
}
