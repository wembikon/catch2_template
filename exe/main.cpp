#include <iostream>

#include "calc.h"

int main() {
  Calc calculator;
  const int sum = calculator.add(1, 2);
  std::cout << sum << std::endl;

  return 0;
}