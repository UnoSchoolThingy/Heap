#include "Heap.h"

using std::cout;
using std::pair;

Heap::Heap() {
  memset(this, 0x0, sizeof(Heap));
}

int Heap::size() {
  return this->currentSize;
}

bool Heap::empty() {
  return this->currentSize == 0;
}

bool Heap::full() {
  return this->currentSize >= 100; // Should never exceed 100 anyway tho 
}

// Does the actual printing. This prints the tree with the head at the bottom 
void Heap::printHelperOrSomething(int idx, int depth) {
  depth++;
  // Get L and R
  int l = idx * 2 + 1;
  if (l >= currentSize) {
    for (int i = 0; i < depth; i++) {
      cout << "       ";
    }
    cout << data[idx] << "\n";
    return;
  }
  printHelperOrSomething(l, depth);
  int r = l + 1;
  if (r >= currentSize) {
    for (int i = 0; i < depth; i++) {
      cout << "       ";
    }
    cout << data[idx] << "\n";
    return;
  }
  printHelperOrSomething(r, depth);
  for (int i = 0; i < depth; i++) {
    cout << "       ";
  }
  cout << data[idx] << "\n";
}

void Heap::print() {
  printHelperOrSomething(0, 0);
}

int Heap::front() {
  return this->data[0];
}

bool Heap::push(int num) {
  if (this->full()) return false;
  // Insert at da end
  int idx = currentSize++;
  data[idx] = num;
  // Do insane sorting
  while (idx != 0) {
    int parentIdx = (idx - 1) / 2;
    if (data[parentIdx] < data[idx]) {
      std::swap(data[parentIdx], data[idx]);
      idx = parentIdx;
    }
    else break;
  }
  return true;
}

bool Heap::pop() {
  if (this->empty()) return false;
  cout << "Removing " << data[0] << " from the list!\n";
  currentSize--;
  if (this->empty()) return true;
  // Get the last element and stick it at the top
  int idx = 0;
  data[idx] = data[currentSize]; // Remember, we already decremented currentSize
  // Do insane sorting
  while (true) {
    int l = idx * 2 + 1;
    if (l >= currentSize) return true;
    int r = l + 1;
    if (data[idx] < data[l] && (r >= currentSize || data[l] >= data[r])) {
      std::swap(data[l], data[idx]);
      idx = l;
      continue;
    }
    if (r < currentSize && data[idx] < data[r]) {
      std::swap(data[r], data[idx]);
      idx = r;
      continue;
    }
    break;
  }
  return true;
}

void Heap::clear() {
  while (!this->empty()) this->pop();
}
