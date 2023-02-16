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
  void printHelperOrSomething(int idx, int depth);
  void print();
  int front();
  bool push(int num);
  bool pop();
  void clear();
};
