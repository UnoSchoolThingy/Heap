#include <iostream>
#include <cstring>
#include <algorithm>

class Heap {
 private:
  int currentSize;
  int data[100];
 public:
  Heap();
  int size();
  bool empty();
  bool full();
 private:
  void printHelperOrSomething(int idx, int depth); // I wanna use this order 
 public:
  void print();
  bool push(int num);
  bool pop();
  void clear();
};
