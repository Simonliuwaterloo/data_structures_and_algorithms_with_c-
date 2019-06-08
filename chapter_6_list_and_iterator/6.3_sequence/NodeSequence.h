//
// Created by jianyan on 6/7/19.
//
#include "../../chapter_3_arrays_linkedLists_resursion/3.3_doubly_linked_lists/DLinkedList.h"
#ifndef INC_6_3_SEQUENCE_NODESEQUENCE_H
#define INC_6_3_SEQUENCE_NODESEQUENCE_H

class NodeSequence: public DLinkedList{
public:
    class Iterator{
        public:
        Elem& operator*();
        bool operator==(const Iterator& p) const;
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();
        Iterator& operator--();
        friend class DLinkedList;

        private:
        DNode* v;
        Iterator(DNode* u);
    };
    Iterator begin();
    Iterator atIndex(int i) const;
    int indexOf(const Iterator& p) const;
};
NodeSequence::Iterator begin() {
    return front();
}
NodeSequence::Iterator NodeSequence::atIndex(int i) const {
    int index = 0;
    NodeSequence::Iterator it =  begin();
}
#endif //INC_6_3_SEQUENCE_NODESEQUENCE_H
