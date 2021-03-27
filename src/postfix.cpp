// Copyright 2021 PolinaPanina
#include "postfix.h"
#include "MyStack.h"

int def_priority(char symb) {
  if ((symb == '*') || (symb == '/')) {
      return 3;
  } else if ((symb == '-') || (symb == '+')) {
      return 2;
  } else if (symb == '(') {
      return 0;
  } else if (symb == ')') {
      return 1;
  } else if ((symb == '.') || ((symb <= '9') && (symb >= '0'))) {
      return 5;
  } else {
      return 9;
  }
}

std::string infix2postfix(std::string infix) {
  MyStack<char> operand(infix.size());
  std::string postfix = "";
  for (char s : infix) {
    if (def_priority(s) == 5) {
      postfix += s;
    } else if (s == ')') {
      while ((!operand.isEmpty()) && (operand.get() != '(')) {
        postfix += operand.pop();
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
          postfix += operand.pop();
        }
        operand.push(s);
      }
    }
  }
  while (!operand.isEmpty()) postfix += operand.pop();
  return postfix;
}

