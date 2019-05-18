#include <iostream>

class StringNode{
private:
    std::string elem;
    StringNode* next;

    friend class StringLinkedList;

public:
    const std::string& get_elem() const;
    const StringNode* get_next() const;
};

const std::string& StringNode::get_elem() const {
    return elem;
}

const StringNode* StringNode::get_next() const {
    return next;
}
class StringLinkedList{
public:
    StringLinkedList();
    ~StringLinkedList();
    bool empty() const;
    const StringNode* front() const;
    void addFront(const std::string& e);
    void removeFront();

private:
    StringNode* head;
};

StringLinkedList::StringLinkedList() {
    head = NULL;
}

StringLinkedList::~StringLinkedList() {
    while (!empty()) removeFront();
}

bool StringLinkedList::empty() const {
    return head == NULL;
}

const StringNode* StringLinkedList::front() const {
    return head;
}

void StringLinkedList::addFront(const std::string &e) {
    StringNode* v = new StringNode;
    v->elem = e;
    v->next = head;
    head = v;
}

void StringLinkedList::removeFront() {
    StringNode* old = head;
    head = old->next;
    delete old;
}

//generic nodelist
template <typename E> class SLinkedList;
template <typename E>
class SNode {
private:
    E elem;
    SNode<E>* next;
    friend class SLinkedList<E>;
};

template <typename E>
class SLinkedList {
public:
    SLinkedList();
    ~SLinkedList();
    bool empty()const;
    const E& front() const;
    void addFront(const E& e);
    void removeFront();

private:
    SNode<E>* head;
};

template <typename E>
SLinkedList<E>::SLinkedList() {
    head = NULL;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty()) removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E &e) {
    SNode<E>* v = new SNode<E>;
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E>* old = head;
    head = old->next;
    delete old;
}

int main() {
    StringLinkedList* test_list = new StringLinkedList();
    test_list->addFront("World");
    test_list->addFront("Hello");
    std::cout << test_list->front()->get_elem() << std::endl;
    std::cout << test_list->front()->get_next()->get_elem() << std::endl;
    test_list->removeFront();
    std::cout << test_list->front()->get_elem() << std::endl;
    return 0;
}