#include <iostream>
#include "NodeList.h"
#include <list>
void nodeList_example() {
    NodeList nl = NodeList();
    nl.insertFront(8);
    std::cout << *nl.begin() << std::endl;
    NodeList::Iterator p = nl.begin();
    nl.insertBack(5);
    std::cout << *--nl.end() << std::endl;
    if (p == nl.begin()) std::cout << "true" << std::endl;
}

void stl_list_example() {
    std::list<float> myList(9);
    std::cout << myList.size() <<std::endl;
    std::cout << myList.front() <<std::endl;
    myList.push_front(2.3);
    std::cout << myList.size() <<std::endl;
    std::cout << myList.front() <<std::endl;
}
int main() {
    nodeList_example();
    std::cout << "---------------" << std::endl;
    stl_list_example();
    return 0;
}