#include "heap.h"
#include <iostream>
using namespace std;

int main(){

  Heap<int> a(3);
  a.push(5);
  a.push(6);
  a.push(7);
  a.push(4);
  a.push(3);
  a.push(2);
  a.push(1);
  a.push(8);
  for (int i=0; i < 8; i++){
    cout << a.get(i) << " ";
  }
  cout << endl;
  cout << a.top() << endl;
  a.pop();
  cout << a.top() << endl;

  a.pop();
  cout << endl << a.empty() << endl;
  a.pop();
  cout << a.empty() << endl;


  return 0;
}