#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

  T get(int loc) const;

private:
  /// Add whatever helper functions and data members you need below
  void heapify(int idx);
  void trickleUp(int loc);
  std::vector<T> data;
  PComparator c_;
  int m_;



};

// Add implementation of member functions here
template <typename T, typename PComparator>
T Heap<T,PComparator>::get(int loc) const
{
  return data[loc];
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  m_ = m;
  c_ = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{

}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return data.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.empty();
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc)
{
  int parent = (loc-1)/m_;
  if (parent >= 0 && c_(data[loc], data[parent])){
    swap(data[loc], data[parent]);
    trickleUp(parent);
  }
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(int idx)
{
  int betterchild = m_ * idx + 1; //left child
  int datasize = size();
  if (betterchild >= datasize){
    // idx is leaf node
    return;
  }

  int curr_child;
  // find the best child among all children
  for (int i=1; i < m_; i++){
    curr_child = m_ *idx + 1 + i;
    // check if curr_child exist:
    if (curr_child < datasize){
      // child exists
      if (c_(data[curr_child] , data[betterchild])){
        betterchild = curr_child; //curr_child  is the "better"child
      }
    }
    else{
      // child does not exist
      break;
    }
  }

  if (c_(data[betterchild], data[idx])){ //child is better than parent
    std::swap(data[betterchild], data[idx]);
    heapify(betterchild);
  }
}


// push()
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  data.push_back(item);
  trickleUp(data.size() - 1);
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data.front();


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::out_of_range("heap is empty");

  }

  data[0] = data.back();
  data.pop_back();
  heapify(0);



}



#endif

