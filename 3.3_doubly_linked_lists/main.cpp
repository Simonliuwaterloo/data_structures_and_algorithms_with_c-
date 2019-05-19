#include <iostream>
//this is not a copy of code from textbook
//it is my own implementation without looking at book
//3.2 was copied from textbook, that's why I was using both
//camelback and underline naming convention in that :)
class StringNode{
private:
    std::string elem;
    StringNode* prev;
    StringNode* next;
    friend class StringLinkedList;
public:
    const std::string& get_elem();
    const StringNode* get_next() const;
    const StringNode* get_prev() const;
};

const std::string& StringNode::get_elem() {
    return elem;
}

const StringNode* StringNode::get_next() const {
    return next;
}

const StringNode* StringNode::get_prev() const {
    return prev;
}
class StringLinkedList{
private:
    StringNode* header;
    StringNode* trailer;
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty();
    void remove_front();
    void remove_back();
    void add_front(const std::string& e);
    void add_back(const std::string& e);
    StringNode* front();
    StringNode* back();

protected:
    void insert_after(StringNode* prev_node, const std::string& e);
    void remove(StringNode* node);
};

StringLinkedList::StringLinkedList() {
    header = new StringNode;
    trailer = new StringNode;
    header->next = trailer;
    trailer->prev = header;
}

StringLinkedList::~StringLinkedList() {
    while (!empty()) remove_front();
    delete header;
    header = nullptr;
    delete trailer;
    trailer = nullptr;
}

bool StringLinkedList::empty() {
    { return (header->next == trailer);}
}

void StringLinkedList::remove_front() {
    remove(header->next);
}

void StringLinkedList::remove_back() {
    remove(trailer->prev);
}

void StringLinkedList::add_front(const std::string& e) {
    insert_after(header, e);
    if (trailer->prev == nullptr) trailer ->prev = header->next;
}

void StringLinkedList::add_back(const std::string& e) {
    insert_after(trailer->prev, e);
    if (header->next == nullptr) header ->next = trailer->prev;
}

StringNode* StringLinkedList::front() {
    if (header != nullptr) {
        return header->next;
    }
    else {
        return nullptr;
    }
}

StringNode* StringLinkedList::back() {
    if (trailer != nullptr) {
        return trailer->prev;
    }
    else {
        return nullptr;
    }
}

void StringLinkedList::remove(StringNode* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    node = nullptr;
}
void StringLinkedList::insert_after(StringNode *prev_node, const std::string& e) {
    StringNode* inserted_node = new StringNode();
    inserted_node->elem = e;
    if (prev_node == nullptr) throw 1;
    prev_node->next->prev = inserted_node;
    inserted_node->next = prev_node->next;
    inserted_node->prev = prev_node;
    prev_node->next = inserted_node;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}