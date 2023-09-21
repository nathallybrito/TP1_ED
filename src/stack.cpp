#include "stack.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename S>
Stack<S>::Stack(int size) {
    top = -1;
    length = 1000000;
    if (length <= 0) {
        throw invalid_argument("Stack size must be greater than zero.");
    }
    p = new S[length];
}

template <typename S>
Stack<S>::~Stack() {
    delete[] p;
}

template <typename S>
void Stack<S>::push(S elem) {
    if (top == (length - 1)) {
        throw overflow_error("Can't push onto a full stack");
    } else {
        top++;
        p[top] = elem;
    }
}

template <typename S>
S Stack<S>::pop() {
    if (top == -1) {
        throw underflow_error("Can't pop from an empty stack");
    }
    S ret = p[top];
    top--;
    length--;

    return ret;
}

template <typename S>
void Stack<S>::display() {
    for (int i = 0; i <= top; i++)
        cout << p[i] << " ";
    cout << endl;
}

template <typename S>
bool Stack<S>::isEmpty()const{
    return top== -1;
}

template <typename S>
S Stack<S>::topElement()const{
    if(isEmpty()){
        throw underflow_error("A pilha está cheia");
    }
    return p[top];
}
template class Stack<bool>;
template class Stack<char>;