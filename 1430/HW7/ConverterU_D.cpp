#include "ConverterU_D.h"

ConverterU_D::ConverterU_D() {
    exchange_rate = 1.0;
}

double ConverterU_D::GetExchangeRate(string first, string last) {
    if (first == "U" && last == "D") {
        return exchange_rate;
    }
    else if (first == "D" && last == "U") {
        return 1/exchange_rate;
    }
}
