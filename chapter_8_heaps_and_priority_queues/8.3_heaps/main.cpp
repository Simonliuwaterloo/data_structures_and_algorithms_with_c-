#include <iostream>
#include "VectorCompleteTree.h"
void VectorCompleteTree_sample() {
  VectorCompleteTree<int> tree = VectorCompleteTree<int>();
  std::cout << tree.size() << std::endl;
  tree.addLast(2);
  tree.addLast(5);
  tree.addLast(7);
  tree.addLast(9);
  std::cout << *tree.last() << std::endl;
  std::cout << *tree.root() << std::endl;
  VectorCompleteTree<int>::Position root = tree.root();
  std::cout << *tree.left(root) << std::endl;
  std::cout << *tree.right(root) << std::endl;
  tree.swap(tree.left(root), tree.right(root));
  std::cout << *tree.left(root) << std::endl;
  std::cout << *tree.right(root) << std::endl;
}
int main() {
  VectorCompleteTree_sample();
}
