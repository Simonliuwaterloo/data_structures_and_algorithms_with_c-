//
// Created by jianyan on 5/24/19.
//
#include "../../chapter_3/3.3_doubly_linked_lists/DLinkedList.h"

#ifndef INC_5_3_DOUBLE_ENDED_QUEUES_LINKEDDEQUE_H
#define INC_5_3_DOUBLE_ENDED_QUEUES_LINKEDDEQUE_H
typedef std::string Elem;
class LinkedDeque{
public:
    LinkedDeque();
    int size() const;
    bool empty() const;
    const Elem& front() const throw(std::runtime_error);
    const Elem& back() const throw(std::runtime_error);
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void removeFront() throw(std::runtime_error);
    void removeBack() throw(std::runtime_error);

private:
    DLinkedList dq;
    int n;
};

LinkedDeque::LinkedDeque() {
    n = 0;
}

int LinkedDeque::size() const {
    return n;
}

bool LinkedDeque::empty() const {
    return n == 0;
}

const Elem& LinkedDeque::front() const throw(std::runtime_error){
    if (empty()) {throw std::runtime_error("deque is empty");}
    return dq.front()->get_elem();
}

const Elem& LinkedDeque::back() const throw(std::runtime_error){
    if (empty()) {throw std::runtime_error("deque is empty");}
    return dq.back()->get_elem();
}

void LinkedDeque::insertFront(const Elem& e) {
    dq.add_front(e);
    ++n;
}

void LinkedDeque::insertBack(const Elem &e) {
    dq.add_back(e);
    ++n;
}

void LinkedDeque::removeFront() throw(std::runtime_error) {
    if (empty()) {throw std::runtime_error("list is empty");}
    dq.remove_front();
    --n;
}

void LinkedDeque::removeBack() throw(std::runtime_error) {
    if (empty()) {throw std::runtime_error("list is empty");}
    dq.remove_back();
    --n;
}
#endif //INC_5_3_DOUBLE_ENDED_QUEUES_LINKEDDEQUE_H
