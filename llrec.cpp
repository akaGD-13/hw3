#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
using namespace std;

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // if smaller and larger are garbage
  if (smaller == head){
    smaller = nullptr;
  }
  if (larger == head){
    larger = nullptr;
  }
  if (smaller == larger){
    larger = nullptr;
    smaller = nullptr;
  }
  
  // base case
  if (head == nullptr || head->val == NULL){
    return;
  }

  // head recursion, process after recursing
  llpivot(head->next, smaller, larger, pivot);
  if (head->val > pivot){
    
    //larger.push_front
    head->next = larger;
    larger = head;
  }
  else{ // <=

    //push_front
    head->next = smaller;
    smaller = head;
  }
  head = nullptr;

}