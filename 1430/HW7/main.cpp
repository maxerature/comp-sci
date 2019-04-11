#include "ConverterU_A.h"
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

    //cout << converters[0]->GetExchangeRate("U", "A");
	// You are required to use the array converters to complete this homework. 
	// Please DO NOT directly use variables u2a, u2b, u2c, u2d, u2e, u2f, or u2g.
	
	// read exchange_rate_u2a from cin;
    string input;
    cout << endl;
    getline(cin, input);
    converters[0]->SetExchangeRate(input);
	// read exchange_rate_u2b from cin;
    getline(cin, input);
    converters[1]->SetExchangeRate(input);
	// read exchange_rate_u2c from cin;
    getline(cin, input);
    converters[2]->SetExchangeRate(input);
	// read exchange_rate_u2d from cin;
    getline(cin, input);
    converters[3]->SetExchangeRate(input);
	// read exchange_rate_u2e from cin;
    getline(cin, input);
    converters[4]->SetExchangeRate(input);
	// read exchange_rate_u2f from cin;
    getline(cin, input);
    converters[5]->SetExchangeRate(input);
	// read exchange_rate_u2g from cin;
    getline(cin, input);
    converters[6]->SetExchangeRate(input);
	
    cout << endl;

    double exchange_rate_a2b = converters[0]->GetExchangeRate("A", "U") * converters[1]->GetExchangeRate("U", "B");
    double exchange_rate_a2c = converters[0]->GetExchangeRate("A", "U") * converters[2]->GetExchangeRate("U", "C");
    double exchange_rate_a2d = converters[0]->GetExchangeRate("A", "U") * converters[3]->GetExchangeRate("U", "D");
    double exchange_rate_a2e = converters[0]->GetExchangeRate("A", "U") * converters[4]->GetExchangeRate("U", "E");
    double exchange_rate_a2f = converters[0]->GetExchangeRate("A", "U") * converters[5]->GetExchangeRate("U", "F");
    double exchange_rate_a2g = converters[0]->GetExchangeRate("A", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_b2a = converters[1]->GetExchangeRate("B", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_b2c = converters[1]->GetExchangeRate("B", "U") * converters[2]->GetExchangeRate("U", "C");
    double exchange_rate_b2d = converters[1]->GetExchangeRate("B", "U") * converters[3]->GetExchangeRate("U", "D");
    double exchange_rate_b2e = converters[1]->GetExchangeRate("B", "U") * converters[4]->GetExchangeRate("U", "E");
    double exchange_rate_b2f = converters[1]->GetExchangeRate("B", "U") * converters[5]->GetExchangeRate("U", "F");
    double exchange_rate_b2g = converters[1]->GetExchangeRate("B", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_c2a = converters[2]->GetExchangeRate("C", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_c2b = converters[2]->GetExchangeRate("C", "U") * converters[1]->GetExchangeRate("U", "C");
    double exchange_rate_c2d = converters[2]->GetExchangeRate("C", "U") * converters[3]->GetExchangeRate("U", "D");
    double exchange_rate_c2e = converters[2]->GetExchangeRate("C", "U") * converters[4]->GetExchangeRate("U", "E");
    double exchange_rate_c2f = converters[2]->GetExchangeRate("C", "U") * converters[5]->GetExchangeRate("U", "F");
    double exchange_rate_c2g = converters[2]->GetExchangeRate("C", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_d2a = converters[3]->GetExchangeRate("D", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_d2b = converters[3]->GetExchangeRate("D", "U") * converters[1]->GetExchangeRate("U", "C");
    double exchange_rate_d2c = converters[3]->GetExchangeRate("D", "U") * converters[2]->GetExchangeRate("U", "D");
    double exchange_rate_d2e = converters[3]->GetExchangeRate("D", "U") * converters[4]->GetExchangeRate("U", "E");
    double exchange_rate_d2f = converters[3]->GetExchangeRate("D", "U") * converters[5]->GetExchangeRate("U", "F");
    double exchange_rate_d2g = converters[3]->GetExchangeRate("D", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_e2a = converters[4]->GetExchangeRate("E", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_e2b = converters[4]->GetExchangeRate("E", "U") * converters[1]->GetExchangeRate("U", "C");
    double exchange_rate_e2c = converters[4]->GetExchangeRate("E", "U") * converters[2]->GetExchangeRate("U", "D");
    double exchange_rate_e2d = converters[4]->GetExchangeRate("E", "U") * converters[3]->GetExchangeRate("U", "E");
    double exchange_rate_e2f = converters[4]->GetExchangeRate("E", "U") * converters[5]->GetExchangeRate("U", "F");
    double exchange_rate_e2g = converters[4]->GetExchangeRate("E", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_f2a = converters[5]->GetExchangeRate("F", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_f2b = converters[5]->GetExchangeRate("F", "U") * converters[1]->GetExchangeRate("U", "C");
    double exchange_rate_f2c = converters[5]->GetExchangeRate("F", "U") * converters[2]->GetExchangeRate("U", "D");
    double exchange_rate_f2d = converters[5]->GetExchangeRate("F", "U") * converters[3]->GetExchangeRate("U", "E");
    double exchange_rate_f2e = converters[5]->GetExchangeRate("F", "U") * converters[4]->GetExchangeRate("U", "F");
    double exchange_rate_f2g = converters[5]->GetExchangeRate("F", "U") * converters[6]->GetExchangeRate("U", "G");

    double exchange_rate_g2a = converters[6]->GetExchangeRate("G", "U") * converters[0]->GetExchangeRate("U", "A");
    double exchange_rate_g2b = converters[6]->GetExchangeRate("G", "U") * converters[1]->GetExchangeRate("U", "C");
    double exchange_rate_g2c = converters[6]->GetExchangeRate("G", "U") * converters[2]->GetExchangeRate("U", "D");
    double exchange_rate_g2d = converters[6]->GetExchangeRate("G", "U") * converters[3]->GetExchangeRate("U", "E");
    double exchange_rate_g2e = converters[6]->GetExchangeRate("G", "U") * converters[4]->GetExchangeRate("U", "F");
    double exchange_rate_g2f = converters[6]->GetExchangeRate("G", "U") * converters[5]->GetExchangeRate("U", "G");

    // print exchange rate between any two in {A, B, C, D, E, F, G};


    cout << "1A = " << fixed << setprecision(2) <<  exchange_rate_a2b << "B" << endl;
    cout << "1A = " << fixed << setprecision(2) << exchange_rate_a2c << "C" << endl;
    cout << "1A = " << fixed << setprecision(2) << exchange_rate_a2d << "D" << endl;
    cout << "1A = " << fixed << setprecision(2) << exchange_rate_a2e << "E" << endl;
    cout << "1A = " << fixed << setprecision(2) << exchange_rate_a2f << "F" << endl;
    cout << "1A = " << fixed << setprecision(2) << exchange_rate_a2g << "G" << endl;

    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2a << "B" << endl;
    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2c << "C" << endl;
    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2d << "D" << endl;
    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2e << "E" << endl;
    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2f << "F" << endl;
    cout << "1B = " << fixed << setprecision(2) << exchange_rate_b2g << "G" << endl;

    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2a << "A" << endl;
    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2b << "B" << endl;
    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2d << "D" << endl;
    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2e << "E" << endl;
    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2f << "F" << endl;
    cout << "1C = " << fixed << setprecision(2) << exchange_rate_c2g << "G" << endl;

    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2a << "A" << endl;
    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2b << "B" << endl;
    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2c << "C" << endl;
    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2e << "E" << endl;
    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2f << "F" << endl;
    cout << "1D = " << fixed << setprecision(2) << exchange_rate_d2g << "G" << endl;

    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2a << "A" << endl;
    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2b << "B" << endl;
    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2c << "C" << endl;
    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2d << "D" << endl;
    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2f << "F" << endl;
    cout << "1E = " << fixed << setprecision(2) << exchange_rate_e2g << "G" << endl;

    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2a << "A" << endl;
    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2b << "B" << endl;
    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2c << "C" << endl;
    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2d << "D" << endl;
    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2e << "E" << endl;
    cout << "1F = " << fixed << setprecision(2) << exchange_rate_f2g << "G" << endl;

    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2a << "A" << endl;
    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2b << "B" << endl;
    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2c << "C" << endl;
    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2d << "D" << endl;
    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2e << "E" << endl;
    cout << "1G = " << fixed << setprecision(2) << exchange_rate_g2f << "F" << endl;


   
	return 0;
}
