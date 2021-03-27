// Copyright 2021 PolinaPanina
#include <iostream>
#include "postfix.h"
#include "MyStack.h"

int main() {
  std::string s1("2 + 6 * 3 / (4 - 2)");
  std::string s2 = infix2prefix(s1);
  std::cout << s2;  
}