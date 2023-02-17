/* Uno Pasadhika 
 * Heap: A max heap thingy 
 * 2/17/2023 
*/

#include "Heap.h"
#include "Utils.h"
#include <fstream>

using namespace std;

// Prompt the user to add a number to the heap 
bool promptAddNumber(Heap& heap) {
  cout << "Enter a number to insert: ";
  int n;
  cin >> n;
  return heap.push(n);
}

// Prompt the user for a file name to load all the numbers from 
void promptLoadFromFile(Heap& heap) {
  char filePath[200];
  cout << "Enter the file path: ";
  cin.ignore();
  cin.getline(filePath, 200);
  ifstream fin(filePath);
  if (!fin.good()) {
    cout << "Invalid file path!\n";
    return;
  }
  int ct = 0;
  int t;
  while (fin >> t) {
    if (!heap.push(t)) {
      cout << "The heap is full now, terminating load from file operation!\n";
      break;
    }
    ct++;
  }
  cout << "Loaded " << ct << " number(s)!\n";
}

int main() {
  Heap heap;
  char in[35];
  while (true) {
    cout << "Enter command (ADD, PRINT, DELETE, LOAD, CLEAR, or QUIT): ";
    cin >> in;
    if (Utils::chkcmd(in, "add")) cout << (promptAddNumber(heap) ? "Added!" : "Couldn't add, heap is full!") << endl;
    else if (Utils::chkcmd(in, "print")) heap.print();
    else if (Utils::chkcmd(in, "delete")) cout << (heap.pop() ? "Deleted!" : "Couldn't delete, that number isn't in the heap!") << endl;
    else if (Utils::chkcmd(in, "load")) promptLoadFromFile(heap);
    else if (Utils::chkcmd(in, "clear")) heap.clear(); 
    else if (Utils::chkcmd(in, "quit")) break;
    else cout << "That command isn't recognized!\n";
  }
  return 0;
}
