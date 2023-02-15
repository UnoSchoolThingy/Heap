#include <iostream>
#include <cstring>
#include <algorithm>

class Heap {
 private:
  int currentSize;
  int data[202];
 public:
  Heap();
  int size();
  bool empty();
  bool full();
  int front();
  bool push(int num);
  bool pop();
  void clear();
};
