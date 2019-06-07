#include <iostream>

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
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}