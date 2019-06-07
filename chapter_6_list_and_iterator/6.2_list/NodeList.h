//
// Created by jianyan on 6/6/19.
//

#ifndef INC_6_2_LIST_NODELIST_H
#define INC_6_2_LIST_NODELIST_H

typedef int Elem;
class NodeList {
private:
    struct Node {
        Elem elem;
        Node* prev;
        Node* next;
    };
public:
    class Iterator {
    public:
        Elem& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();
        friend class NodeList;

    private:
        Node* v;
        Iterator(Node* u);
    };

public:
    NodeList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const Elem& e);
    void insertBack(const Elem& e);
    void insert(const Iterator& p, const Elem& e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator& p);

private:
    int n;
    Node* header;
    Node* trailer;
};

NodeList::NodeList() {
    n = 0;
    header = nullptr;
    trailer = nullptr;
}

int NodeList::size() const {
    return n;
}

bool NodeList::empty() const {
    return n == 0;
}

NodeList::Iterator NodeList::begin() const {
    return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const {
    return Iterator(trailer->prev);
}

void NodeList::insertFront(const Elem &e) {
    Node* old_front = header->next;
    Node* new_front;
    new_front->prev = header;
    new_front->next = old_front;
    new_front->elem = e;
    header->next = new_front;
}

void NodeList::insertBack(const Elem &e) {
    Node* old_back = trailer->prev;
    Node* new_back;
    new_back->next = trailer;
    new_back->prev = old_back;
    new_back->elem = e;
    trailer->next = new_back;
}

void NodeList::insert(const NodeList::Iterator &p, const Elem &e) {
    Node* old_back = p.v->prev;
    Node* new_back;
    new_back->prev = old_back;
    new_back->next = p.v;
    new_back->elem = e;
    p.v->prev = new_back;
    old_back->next = new_back;
}

void NodeList::eraseFront() {
    Node* old = header->next;
    header->next = old->next;
    delete old;
    old = nullptr;
}

void NodeList::eraseBack() {
    Node* old = trailer->prev;
    trailer->prev = old->prev;
    delete old;
    old = nullptr;
}

void NodeList::erase(const NodeList::Iterator &p) {
    p.v->prev->next = p.v->next;
    p.v->next->prev = p.v->prev;
    delete p.v;
}

NodeList::Iterator::Iterator(Node* u) {
    v = u;
}

Elem& NodeList::Iterator::operator*() {
    return v->elem;
}

bool NodeList::Iterator::operator==(const NodeList::Iterator &p) const {
    return v == p.v;
}

bool NodeList::Iterator::operator!=(const NodeList::Iterator &p) const {
    return v != p.v;
}

NodeList::Iterator& NodeList::Iterator::operator++() {
    v = v->next;
    return *this;
}

NodeList::Iterator& NodeList::Iterator::operator--() {
    v = v->prev;
    return *this;
}

#endif //INC_6_2_LIST_NODELIST_H
