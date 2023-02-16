#include "Heap.h"
#include "Utils.h"
#include <fstream>

using namespace std;

int main() {
  Heap heap;
  for (int i = 1; i <= 25; i++) {
    heap.push(i);
  }
  heap.print();
  for (int i = 0; i < 25; i++) {
    cout << "================================\n";
    heap.pop();
    heap.print();
  }
  return 0;
  /*
  char in[35];
  while (true) {
    cout << "Enter command (ADD, PRINT, DELETE, GEN, or QUIT): ";
    cin >> in;
    if (Utils::chkcmd(in, "add")) cout << (promptAddNumber(heap) ? "Added!" : "Couldn't add, heap is full!") << endl;
    else if (Utils::chkcmd(in, "print")) heap.print();
    else if (Utils::chkcmd(in, "delete")) cout << (promptDeleteNumber(table) ? "Deleted!" : "Couldn't delete, that number isn't in the heap!") << endl;
    else if (Utils::chkcmd(in, "clear")) heap.clear(); 
    else if (Utils::chkcmd(in, "quit")) break;
    else cout << "That command isn't recognized!\n";
  }
  */
  return 0;
}
