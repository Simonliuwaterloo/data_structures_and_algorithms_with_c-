//
// Created by jianyan on 5/24/19.
//

#ifndef INC_5_2_QUEUES_ARRAYQUEUE_H
#define INC_5_2_QUEUES_ARRAYQUEUE_H

template <typename E>
class ArrayQueue {
public:
    ArrayQueue(int cap = 100);
    ~ArrayQueue();
    int size() const;
    bool empty() const;
    const  E& front() const throw(std::runtime_error);
    void enqueue( const E& e) throw(std::runtime_error);
    void dequeue() throw(std::runtime_error);

private:
    E* array_queue;
    int f;
    int r;
    int n;
    int c;
};

template <typename E>
ArrayQueue<E>::ArrayQueue(int cap) {
    array_queue = new int[cap];
    f = r = n = 0;
    c = cap;
}

template <typename  E>
ArrayQueue<E>::~ArrayQueue() {
    delete array_queue;
    array_queue = nullptr;
}

template  <typename  E>
int ArrayQueue<E>::size() const {
    return n;
}

template  <typename E>
bool ArrayQueue<E>::empty() const{
    return n == 0;
}

template <typename E>
const E& ArrayQueue<E>::front() const throw(std::runtime_error) {
    if (empty()) {throw std::runtime_error("queue is empty");}
    return array_queue[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E &e) throw(std::runtime_error) {
    if (size() == c) {throw std::runtime_error("queue is full");}
    array_queue[r % (c)] = e;
    r = (r + 1) % c;
    //note r-1 points to actual data at rear while r points to
    //memory after that, why do we do this?
    //while we initialized r as 0... so when the first data is
    //inserted, memory[0] is allocated to it and r increments
    ++n;
}

template <typename E>
void ArrayQueue<E>::dequeue() throw(std::runtime_error){
    if (empty()) {throw std::runtime_error("array is empty");}
    f = (f + 1) % (c);
    --n;
}
#endif //INC_5_2_QUEUES_ARRAYQUEUE_H
