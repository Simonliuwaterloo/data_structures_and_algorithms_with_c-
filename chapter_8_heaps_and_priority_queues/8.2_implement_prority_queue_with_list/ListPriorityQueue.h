#include <list>
template <typename E, typename C>
class ListPriorityQueue {
  //we use a sorted List to implement this adt
  public:
    int size() const;
    bool empty() const;
    void insert(const E& e);
    const E& min() const;
    void removeMin();
  private:
    std::list<E> L;
    C isLess;
    //With what criteria should we
    //tell which element is with 
    //higher priority? We certainly
    //cannot put the criteria in 
    //this class-- as this class 
    //should be as generaic as
    //possible for re-use
};

template<typename E, typename C>
int ListPriorityQueue<E, C>::size() const {
  return L.size();
}


template<typename E, typename C>
bool ListPriorityQueue<E, C>::empty() const {
  return L.empty();
}


template<typename E, typename C>
void ListPriorityQueue<E, C>::insert(const E& e) {
  typename std::list<E>::iterator smaller;
  smaller = L.begin();
  while( smaller != L.end() && !isLess(e, *smaller)) ++smaller;
  L.insert(smaller, e);
}

template<typename E, typename C>
const E& ListPriorityQueue<E, C>::min() const {
  return L.front();
}

template<typename E, typename C>
void ListPriorityQueue<E, C>::removeMin() {
  L.pop_front();
}
