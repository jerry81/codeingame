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
#include <unordered_map>

using namespace std;

class UnitCalculator {
  private:
    vector<double> n;
    vector<string> u;
    const long int UM = 1;
    const long int MM = 1000;
    const long int CM = 10000;
    const long int DM = 100000;
    const long int M = 1000000;
    const long int KM = 1000000000;
    unordered_map<string, const long int> lookup;


    bool is_digit_or_period(char c) {
      if (c == '.') return true;

      int ascii = c - '0';
      return (ascii >= 0) && (ascii < 10);
    }

    void parse(string input) { // function did the conversion
      int unit_index = 0;
      for (int i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (!is_digit_or_period(c)) {
          unit_index = i;
          break;
        }
      }
      string value = input.substr(0, unit_index);
      string unit = input.substr(unit_index); // no second param - to the end.
      n.push_back(stod(value));
      u.push_back(unit);
    }
    void init() {
      lookup.insert({"um", UM});
      lookup.insert({"mm", MM});
      lookup.insert({"cm", CM});
      lookup.insert({"dm", DM});
      lookup.insert({"M", M});
      lookup.insert({"km", KM});
    }
  public:
    UnitCalculator(string expression) {
      init();
      char str[expression.length()+1];
      strcpy(str,expression.c_str());
      char *token = strtok(str, " + ");
      while (token != NULL) {
        parse(token);
        token = strtok(NULL, " + ");
      }
    }
};

int main()
{
    string expression;
    getline(cin, expression); // the expression to calculate
    UnitCalculator u = UnitCalculator(expression);
    cout << "1cm" << endl;
}