/*

Goal
The goal of this exercise is to add two lengths with given metric units.
To calculate it properly you first need to convert them to the same unit.
Present the result using the smaller unit.

For instance:
4cm + 2dm
must convert 2dm to 20cm:
4cm + 20cm
it then results to:
24cm

If you like to challenge yourself a little more...
Try to limit the number of ifs and switches as much as possible in your code.
Input
Line 1: the expression to calculate valueunit+valueunit
Output
valueunit

value should be a sum of two given values after units conversion to the smaller one.

unit should be the smaller unit of the two parameters.
Constraints
value is a real number:
0 <= value <= 1000
with precision <= 0.00001

unit can be one of the following:
- um (micrometer)
- mm (millimeter) where 1mm = 1000um
- cm (centimeter) where 1cm = 10mm
- dm (decimeter) where 1dm = 10cm
- m (meter) where 1m = 10dm
- km (kilometer) where 1km = 1000m
Example
Input
1m + 1cm
Output
101cm

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class UnitCalculator {
  private:
    double n1;
    double n2;
    const long int um = 1;
    const long int mm = 1000;
    const long int cm = 10000;
    const long int dm = 100000;
    const long int m = 1000000;
    const long int km = 1000000000;

    bool is_digit(char c) {
      int ascii = c - '0';
      return (ascii >= 0) && (ascii < 10);
    }

    void parse(string input) { // function did the conversion
      for (int i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (!is_digit(c)) {

        }
      }
    }
  public:
    UnitCalculator(string expression) {
      char str[expression.length()+1];
      strcpy(str,expression.c_str());
      char *token = strtok(str, " + ");
      while (token != NULL) {
        parse(token);
        token = strtok(NULL, " + ");
      }
      cerr << "expect true " << is_digit('9');
      cerr << "expect false " << is_digit('c');
    }
};

int main()
{
    string expression;
    getline(cin, expression); // the expression to calculate
    UnitCalculator u = UnitCalculator(expression);
    cout << "1cm" << endl;
}