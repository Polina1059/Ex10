// Copyright 2021 PolinaPanina
#include "postfix.h"
#include "MyStack.h"

int def_priority(char symb) {
  if ((symb == '*') || (symb == '/')) { return 3; }
  else if ((symb == '-') || (symb == '+')) { return 2; }
  else if (symb == '(') { return 0; }
  else if (symb == ')') { return 1; }
  else if ( (symb == '.')|| ((symb <= '9') && (symb >= '0'))) { return 5; }
  else { return 9; }
}

std::string infix2prefix(std::string infix) {

  MyStack<char> operand(infix.size());
  std::string prefix = "";
  for (char s : infix) {
    if (def_priority(s) == 5) {
      prefix += s;
    } else if (s == ')') {
      while ((!operand.isEmpty()) && (operand.get() != '(')) {
        prefix += operand.pop();
      }
      operand.pop();
    } else if (((operand.isEmpty()) && (def_priority(s) != 9)) || (s == '(')) {
      operand.push(s);
    } else if (def_priority(s) == 9) {
      s = s;
    } else {
      if (def_priority(operand.get()) < def_priority(s)) {
        operand.push(s);
      } else {
        while (def_priority(operand.get()) >= def_priority(s)) {
          if (operand.isEmpty()) break;
          prefix += operand.pop();
        }
        operand.push(s);
      }
    }
  }
  while (!operand.isEmpty()) prefix += operand.pop();
  return prefix;
}

