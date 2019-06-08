#include <iostream>
#include "NodeList.h"
#include <list>
#include <cstdlib>
#include <vector>
#include <algorithm>
void nodeList_example() {
    NodeList nl = NodeList();
    nl.insertFront(8);
    std::cout << *nl.begin() << std::endl;
    NodeList::Iterator p = nl.begin();
    nl.insertBack(5);
    std::cout << *--nl.end() << std::endl;
    if (p == nl.begin()) std::cout << "true" << std::endl;
}

int list_sum(std::list<int> lst) {
    //note: this list is passed by value, very inefficient
    int sum = 0;
    for (std::list<int>::iterator tranv = lst.begin(); tranv != lst.end(); ++tranv) {
        sum += *tranv;
    }
    return sum;
}

int list_sum_by_reference(const std::list<int>& lst) {
    //note: this list is passed by reference, save space and time of copying
    //but we can't declare iterator of constant list
    //iterator, in many cases, change content of list
    //solution: declare constant read-only iterator
    int sum = 0;
    for (std::list<int>::const_iterator tranv = lst.begin(); tranv != lst.end(); ++tranv) {
        sum += *tranv;
    }
    return sum;
}
void stl_list_example() {
    std::list<float> myList(9);
    std::cout << myList.size() <<std::endl;
    std::cout << myList.front() <<std::endl;
    myList.push_front(2.3);
    std::cout << myList.size() <<std::endl;
    std::cout << myList.front() <<std::endl;
    std::cout << *myList.begin() <<std::endl;
    std::cout << *myList.end() <<std::endl;
    std::list<int> intList = {};
    intList.push_front(5);
    intList.push_front(6);
    std::cout << list_sum(intList) << std::endl;
    std::cout << list_sum_by_reference(intList) << std::endl;
    //end returns iterator with position just beyond last element
}
int stl_iterator_example() {
    int a[] = {17, 22, 33, 15, 62, 45};
    std::vector<int> v(a, a+6);
    //pointer arithmetic
    std::cout << v.size() << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;
    v.push_back(19);
    std::cout << v.front() << " " << v.back() << std::endl;
    std::sort(v.begin(), v.begin() + 4);
    v.erase(v.end() - 4, v.end() - 2);
    std::cout << v.size() << std::endl;

    char b[] = {'b','r','a','v','o'};
    std::vector<char> w(b, b + 5);
    std::random_shuffle(w.begin(), w.end());
    w.insert(w.begin(), 's');

    for (std::vector<char>::iterator p = w.begin(); p != w.end(); ++p) {
        std::cout << *p << " ";
    }
    std::cout << std::endl;
    return EXIT_SUCCESS;
}
int main() {
    nodeList_example();
    std::cout << "---------------" << std::endl;
    stl_list_example();
    std::cout << "---------------" << std::endl;
    stl_iterator_example();
    return 0;
}