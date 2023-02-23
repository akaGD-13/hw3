#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
using namespace std;

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  // if smaller and larger are garbage
  if (smaller != NULL && smaller->val == NULL){
    smaller = NULL;
  }
  if (larger != NULL && larger->val == NULL){
    larger = NULL;
  }
  
  // base case
  if (head == nullptr){
    return;
  }

  // head recursion, process after recursing
  llpivot(head->next, smaller, larger, pivot);
  if (head->val > pivot){
    
    //push_front
    head->next = larger;
    larger = head;
  }
  else{ // <=

    //push_front
    head->next = smaller;
    smaller = head;
  }

}