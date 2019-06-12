#include <iostream>
#include <queue>
void stl_priority_queue_sample() {
  std::priority_queue<int> p1;
  p1.push(9);
  p1.push(6);
  std::cout << p1.top() << std::endl;
}
int main() {
  stl_priority_queue_sample();
}
