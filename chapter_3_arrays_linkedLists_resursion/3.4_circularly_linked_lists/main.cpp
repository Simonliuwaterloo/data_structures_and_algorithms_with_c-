#include <iostream>
#include "CLinkedList.h"
int main() {
    CLinkedList list;
    char greeting[13] = "Hello, world";
    for (int i = 0; i < 12; ++i) {
        list.add(std::string(1,greeting[i]));
    }
    for (int i = 0; i < 12; ++i) {
        std::cout << list.front()->get_elem();
        list.advance();
    }
    std::cout << std::endl;
    list.reverseList();
    for (int i = 0; i < 12; ++i) {
        std::cout << list.front()->get_elem();
        list.advance();
    }
    return 0;
}