#include <iostream>
#include "ArrayVector.h"
#include <vector>
//STL vector
void stl_vector_sample() {
    std::vector<int> stl_vector(100);
    std::cout << stl_vector[2]<< std::endl;
    //initialized to 0
    std::cout << stl_vector.at(2)<< std::endl;
    //member function at, permorms range chacking
    //std::cout << stl_vector.at(2)<< std::endl;
    //throws an error
    stl_vector.at(2) = 3;
    std::cout << stl_vector.at(2)<< std::endl;
    //at returns a reference
    std::cout << stl_vector.size()<< std::endl;
}
int main() {
    stl_vector_sample();
    return 0;
}