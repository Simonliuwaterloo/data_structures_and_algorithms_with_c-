#ifndef _DLinkedList_
#define _DLinkedList_
typedef std::string Elem;
class DNode{
private:
    Elem elem;
    DNode* prev;
    DNode* next;
    friend class DLinkedList;
public:
    const Elem& get_elem();
    const DNode* get_next() const;
    const DNode* get_prev() const;
};

const Elem& DNode::get_elem() {
    return elem;
}

const DNode* DNode::get_next() const {
    return next;
}

const DNode* DNode::get_prev() const {
    return prev;
}
class DLinkedList{
private:
    DNode* header;
    DNode* trailer;
public:
    DLinkedList();
    ~DLinkedList();
    bool empty();
    void remove_front();
    void remove_back();
    void add_front(const Elem& e);
    void add_back(const Elem& e);
    DNode* front() const;
    DNode* back() const;

protected:
    void insert_after(DNode* prev_node, const Elem& e);
    void remove(DNode* node);
};

DLinkedList::DLinkedList() {
    header = new DNode;
    trailer = new DNode;
    header->next = trailer;
    trailer->prev = header;
}

DLinkedList::~DLinkedList() {
    while (!empty()) remove_front();
    delete header;
    header = nullptr;
    delete trailer;
    trailer = nullptr;
}

bool DLinkedList::empty() {
    { return (header->next == trailer);}
}

void DLinkedList::remove_front() {
    remove(header->next);
}

void DLinkedList::remove_back() {
    remove(trailer->prev);
}

void DLinkedList::add_front(const Elem& e) {
    insert_after(header, e);
    if (trailer->prev == nullptr) trailer ->prev = header->next;
}

void DLinkedList::add_back(const Elem& e) {
    insert_after(trailer->prev, e);
    if (header->next == nullptr) header ->next = trailer->prev;
}

DNode* DLinkedList::front() const {
    if (header != nullptr) {
        return header->next;
    }
    else {
        return nullptr;
    }
}

DNode* DLinkedList::back() const{
    if (trailer != nullptr) {
        return trailer->prev;
    }
    else {
        return nullptr;
    }
}

void DLinkedList::remove(DNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    node = nullptr;
}
void DLinkedList::insert_after(DNode *prev_node, const Elem& e) {
    DNode* inserted_node = new DNode();
    inserted_node->elem = e;
    if (prev_node == nullptr) throw 1;
    prev_node->next->prev = inserted_node;
    inserted_node->next = prev_node->next;
    inserted_node->prev = prev_node;
    prev_node->next = inserted_node;
}

#endif