#include "converteru_a.h"
#include "ConverterU_B.h"
#include "ConverterU_C.h"
#include "ConverterU_D.h"
#include "ConverterU_E.h"
#include "ConverterU_F.h"
#include "ConverterU_G.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
	ConverterU_A u2a;
	ConverterU_B u2b;
	ConverterU_C u2c;
	ConverterU_D u2d;
	ConverterU_E u2e;
	ConverterU_F u2f;
	ConverterU_G u2g;
	
	Converter* converters[] = { &u2a, &u2b, &u2c, &u2d, &u2e, &u2f, &u2g };

    cout << converters[0]->GetExchangeRate("U", "A");
	// You are required to use the array converters to complete this homework. 
	// Please DO NOT directly use variables u2a, u2b, u2c, u2d, u2e, u2f, or u2g.
	
	// read exchange_rate_u2a from cin;
	// read exchange_rate_u2b from cin;
	// read exchange_rate_u2c from cin;
	// read exchange_rate_u2d from cin;
	// read exchange_rate_u2e from cin;
	// read exchange_rate_u2f from cin;
	// read exchange_rate_u2g from cin;
	
	// double exchange_rate_a2b = converter[0]->GetExchangeRate("A", "U") * converter[1]->GetExchangeRate("U", "B");

   // print exchange rate between any two in {A, B, C, D, E, F, G};
   
	return 0;
}
