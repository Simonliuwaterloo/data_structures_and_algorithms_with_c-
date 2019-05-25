#include <iostream>
#include <queue>
//c++ standard queue library
#include "ArrayQueue.h"
#include "LinkedQueue.h"
void standard_queue_sample() {
    std::queue<float> my_queue;
    my_queue.push(3);
    std::cout << my_queue.front() << std::endl;
    std::cout << my_queue.back() << std::endl;
    my_queue.push(6);
    std::cout << my_queue.front() << std::endl;
    std::cout << my_queue.back() << std::endl;
    my_queue.pop();
    std::cout << my_queue.front() << std::endl;
    std::cout << my_queue.back() << std::endl;
}

void array_queue_sample() {
    ArrayQueue<int> queue(5);
    //the capacity of this queue is 5
    queue.enqueue(1);
    std::cout << queue.front() << std::endl;
    queue.enqueue(2);
    std::cout << queue.front() << std::endl;
    queue.enqueue(3);
    std::cout << queue.front() << std::endl;
    queue.enqueue(4);
    std::cout << queue.front() << std::endl;
    queue.enqueue(5);
    std::cout << queue.front() << std::endl;
//    queue.enqueue(6);
//    std::cout << queue.front() << std::endl;
// error ! queue is full
    queue.dequeue();
    //1 is poped, now 2 is at front
    std::cout << queue.front() << std::endl;
    queue.enqueue(6);
    std::cout << queue.front() << std::endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.enqueue(7);
    std::cout << queue.front() << std::endl;
    queue.enqueue(8);
    std::cout << queue.front() << std::endl;
    queue.enqueue(9);
    std::cout << queue.front() << std::endl;
    std::cout << "size of queue is " << queue.size() << std::endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    std::cout << "size of queue is " << queue.size() << std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout << "size of queue is " << queue.size() << std::endl;
//    queue.dequeue();
// error ! queue is empty!
}

void linked_queue_sample() {
    LinkedQueue queue;
    //the capacity of this queue is 5
    queue.enqueue("hello");
    queue.enqueue("darkness");
    queue.enqueue("my");
    queue.enqueue("old");
    queue.enqueue("friend");
    std::cout << "the size of queue is " << queue.size() << std::endl;

    std::cout << queue.front() << std::endl;
    queue.dequeue();
    std::cout << queue.front() << std::endl;
    queue.dequeue();
    std::cout << queue.front() << std::endl;
    queue.dequeue();
    std::cout << queue.front() << std::endl;
    queue.dequeue();
    std::cout << queue.front() << std::endl;
    queue.dequeue();
//    queue.dequeue();
//error! queue is empty
}
int main() {
    standard_queue_sample();
    std::cout << "--------------" << std::endl;
    array_queue_sample();
    std::cout << "--------------" << std::endl;
    linked_queue_sample();
    return 0;
}