#include <iostream>
#include <deque>
#include "LinkedDeque.h"
void standard_deque_sample() {
    std::deque<std::string> my_deque;
    my_deque.push_front("darkness");
    my_deque.push_back("my");
    my_deque.push_back("old");
    my_deque.push_back("friend");
    my_deque.push_front("hello");
    std::cout << my_deque.front() << std::endl;
    my_deque.pop_front();
    std::cout << my_deque.front() << std::endl;
    my_deque.pop_front();
    std::cout << my_deque.front() << std::endl;
    my_deque.pop_front();
    std::cout << my_deque.front() << std::endl;
    my_deque.pop_front();
    std::cout << my_deque.front() << std::endl;
}
int main() {
    standard_deque_sample();
    std::cout << "------------" << std::endl;
    return 0;
}