//
// Created by jianyan on 5/24/19.
//
#include "../../chapter_3/3.4_circularly_linked_lists/CLinkedList.h"
#include <iostream>
#ifndef INC_5_2_QUEUES_LINKEDQUEUE_H
#define INC_5_2_QUEUES_LINKEDQUEUE_H
//queue and circular linked list are a perfect match
typedef std::string Elem;
class LinkedQueue{
public:
    LinkedQueue();
    int size() const;
    bool empty() const;
    const  Elem front() const;
    void enqueue( const Elem& e);
    void dequeue();
private:
    CLinkedList this_queue;
    int queue_size;
};

LinkedQueue::LinkedQueue() {
    queue_size = 0;
}
//we don't need to specify a destructor, just let
//destructor of CList handle that

int LinkedQueue::size() const {
    return queue_size;
}

bool LinkedQueue::empty() const {
    return queue_size == 0;
}
const  Elem LinkedQueue::front() const {
    if (empty()) {throw std::runtime_error("queue is empty");}
    return this_queue.front()->get_elem();
}

void LinkedQueue::enqueue(const Elem &e) {
    this_queue.add(e);
    this_queue.advance();
    ++queue_size;
}
//note, in the implementation, node in front of cursor is front in queue,
//while cursor is rear in queue, why is that?
//We want to delete front when dequeuing, but we cannot delete the node
//that cursor points to, otherwise we will lose track of the list!

void LinkedQueue::dequeue() {
    if (empty()) {throw std::runtime_error("queue is empty");}
    this_queue.remove();
    --queue_size;
}
#endif //INC_5_2_QUEUES_LINKEDQUEUE_H
