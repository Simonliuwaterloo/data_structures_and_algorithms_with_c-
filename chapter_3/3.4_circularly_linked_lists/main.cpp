#include <iostream>
typedef std::string Elem;
class CNode{
private:
    Elem elem;
    CNode* next;
    friend class CLinkedList;
};

class CLinkedList{
private:
    CNode* cursor;
public:
    CLinkedList();
    ~CLinkedList();
    CNode* front() const;
    CNode* back() const;
    void advance();
    void add(Elem e);
    void remove();
};

CLinkedList::CLinkedList() {
    cursor = nullptr;
}

CLinkedList::~CLinkedList() {
    while(cursor != nullptr) remove();
}

CNode* CLinkedList::front() const {
    if (cursor == nullptr) throw 1;
    return cursor->next;
}

CNode* CLinkedList::back() const {
    if (cursor == nullptr) throw 1;
    return cursor;
}

void CLinkedList::advance() {
    cursor = cursor->next;
}

void CLinkedList::add(Elem e) {
    if(cursor != nullptr) {
        CNode* next_node = front();
        cursor->next = new CNode;
        cursor->next->elem = e;
        cursor->next->next = next_node;
    } else {
        cursor = new CNode;
        cursor->elem = e;
        cursor->next = cursor;
    }
}

void CLinkedList::remove() {
    CNode* old = cursor->next;
    if (old != cursor) {
        cursor->next = old->next;
    } else {
        cursor = nullptr;
    }
    delete old;
    old = nullptr;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}