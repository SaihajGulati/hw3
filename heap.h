#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>

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
  std::size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> data;
  int mary;
  PComparator comp;
  
  //heapify/trickle down function with default index of 0
  void heapify(std::size_t index = 0);

  void trickleUp(std::size_t index = data.size()- 1);
};

// Add implementation of member functions here

//constructor sets mary and comp, using initalization list as that is preferred
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m=2, PComparator c = PComparator()) :
  mary(m), comp(c)
{
}

/**
* @brief Destroy the Heap object
* do not need anything explicit done here as it will destroy data members, and underlying vector will destroy it's data
*/
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

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
    throw std::underflow_error("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return data[0];

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
    throw std::underflow_error("heap is empty");
  }
    //put bottom (worst value on top), also removes top value effectively
    data[0] = data[data.size()-1]
    
    //pop back, which was where the current top was before
    data.pop_back();

    //heapify/trickle-down to make sure heap property is maintained
    //no parameter needed as default is 0
    heapify()
}

/**
 * @brief Push an item to the heap
 * 
 * @param item item to heap
 */
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  //if expanded past max size of vector
  if(data.size() == data.max_size()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::overflow_error("heap container is at it's max size");
  }

  //add the item to the end of the tree
  data.push_back(item);

  //trickle it up
  //don't need parameter since will call the end by default
  trickleUp();
}

/**
 * @brief Returns true if the heap is empty
 * 
 */
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return data.size() == 0;
}

/**
 * @brief Returns size of the heap
 * 
 */
template <typename T, typename PComparator>
std::size_t Heap<T,PComparator>::size() const
{
  return data.size();
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::heapify(std::size_t index)
{
  std::size_t child = 2 * curr + 1;
  //vector to store all indexes of children this index node has
  vector<std::size_t> children;
  std::size_t child = 2 * index + 1;

  //run until get to a child value that is not valid (either no children left, or have maximum amount of children), 
  //filling children vector with valid child indexes
  while (child < data.size() && children.size() <= mary)
  {
    children.push_back(child);
    child += 1;
  }
  
  //if has no children (and thus index is a leaf node), return (base case of recursion)
  if (children.size() == 0)
  {
    return;
  }

  //gets bestChild's index
  std::size_t bestChild = data[childIndexes[0]];
  for (std::size_t i = 0; i < childIndexes.size(); i++)
  {
    //if this child is better than the bestChild, set best child index to this's index
    if (comp(data[childIndexes[i]], data[childIndexes[bestChild]]))
    {
      bestChild = childIndexes[i];
    }
  }

  //if the best child is better than this index (so this index is worse) swap so that this index value has trickled down
  //call heapify again, now with the index to which my original index's value has been placed
  if (comp(childIndexes[bestChild], childIndexes[index]))
  {
    std::swap(childIndexes[i], childIndexes[bestChild])
    heapify(bestChild);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(std::size_t index)
{

  std::size_t parentIndex = (index - 1) / 2;

  //setting variables to simplify syntax, but need to be references for swap to work
  T& current = data[index];
  T& parent = data[parentIndex];

  //are done promoting once either index is the top, or the current is not better than parent
  if (index == 0 || !comp(current, parent))
  {
    return;
  }

  std::swap(current, parent);
  trickleUp(parentIndex);
}

#endif

