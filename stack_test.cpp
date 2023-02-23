#include <iostream>
#include "stack.h"
using namespace std;

int main(){

  Stack<int> a;
  a.push(5);
  a.push(4);
  a.push(3);
  a.push(2);
  a.push(1);
  a.push(8);
  a.pop();
  cout << a.top() << endl;

  a.pop();
  cout << a.top() << endl;

  cout << a.empty() << endl;
  a.pop();
  cout << a.empty() << endl;




  return 0;
}