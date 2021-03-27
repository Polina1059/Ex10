// Copyright 2021 PolinaPanina
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_
#include <iostream>

template <class T>
class MyStack {
 private:
  int size;
  T* st_value;
  int point = 0;

 public:
  explicit MyStack(int Size) {
    size = Size;
    st_value = new T[size];
  }
  MyStack(const MyStack& ST) {
    size = ST.size;
    st_value = new T[size];
    for (int i = 0; i < size; ++i) {
      st_value[i] = ST.st_value[i];
    }
    point = ST.point;
  }
  ~MyStack() {
      delete[] st_value;
  }
  T& get() {
      return st_value[point - 1];
  }
  int getSize() { return size; }
  T& pop() {
    point--;
    return st_value[point];
  }
  void push(double x) {
    if (point < size) {
      st_value[point] = x;
      point++;
    }
  }
  bool isEmpty() {
    if (point == 0) return true;
    return false;
  }
  bool isFull() {
    if (point == size) return true;
    return false;
  }
};
#endif  // INCLUDE_MYSTACK_H_
