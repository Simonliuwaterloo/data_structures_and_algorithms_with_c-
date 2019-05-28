//
// Created by jianyan on 5/27/19.
//
#ifndef INC_6_1_VECTORS_ARRAYVECTOR_H
#define INC_6_1_VECTORS_ARRAYVECTOR_H

typedef int Elem;
class ArrayVector {
public:
    ArrayVector();
    ~ArrayVector();
    int size() const;
    bool empty() const;
    Elem& operator[](int i);
    Elem& at(int i) throw(std::runtime_error);
    void erase(int i);
    void insert(int i, const Elem& e);
    void reserve(int N);

private:
    int capacity;
    int n;
    Elem* A;
};

ArrayVector::ArrayVector() {
    capacity = 0;
    n = 0;
    A = NULL;
}

ArrayVector::~ArrayVector() {
    delete[] A;
    A = nullptr;
}
int ArrayVector::size() const {
    return n;
}

bool ArrayVector::empty() const {
    return size() == 0;
}

Elem& ArrayVector::operator[](int i) {
    return A[i];
}

Elem& ArrayVector::at(int i) throw(std::runtime_error){
    if (i >= n || i < 0) {
        throw("vector index out of range");
    }
    return A[i];
}

void ArrayVector::erase(int i) {
    for (int index = i + 1; index < n; ++i) {
        A[index - 1] = A[index];
    }
    --n;
}

void ArrayVector::insert(int i, const Elem &e) {
    if (n >= capacity) {
        reserve(std::max(1, 2*capacity));
    }
    for (int index = n - 1; index >= i; --i) {
        A[index + 1] = A[index];
    }
    A[i] = e;
    ++n;
}

void ArrayVector::reserve(int N) {
    if (capacity >= N) return;
    Elem* B = new Elem[N];
    for (int index = 0; index < n; ++index) {
        A[index] = B[index];
    }
    if (A != nullptr) delete[] A;
    A = nullptr;
    A = B;
    capacity = N;
}
#endif //INC_6_1_VECTORS_ARRAYVECTOR_H
