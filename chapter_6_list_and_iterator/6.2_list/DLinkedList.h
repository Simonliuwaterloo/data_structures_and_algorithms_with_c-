//
// Created by jianyan on 6/6/19.
//

#ifndef INC_6_2_LIST_DLINKEDLIST_H
#define INC_6_2_LIST_DLINKEDLIST_H
typedef int Elem;
struct Node {
    Elem elem;
    Node* prev;
    Node* next;
};

class Iterator {
public:
    Elem& operator*();
    bool operator==(const Iterator& p) const;
    bool operator!=(const Iterator& p) const;
    Iterator& operator++();
    Iterator& operator--();
};
#endif //INC_6_2_LIST_DLINKEDLIST_H
