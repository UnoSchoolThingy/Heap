#include "Heap.h"

using namespace std;

int main() {
  Heap heap;
  for (int i = 1; i <= 20; i++) {
    heap.push(i);
  }
  heap.clear();
  return 0;
}
