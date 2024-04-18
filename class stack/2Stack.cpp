#include <iostream>
#include <stack>
#include "2Stack.h"

#define SIZE 10

Stack::Stack(){
    stackArray = new int[SIZE];
    capacity = SIZE;
    top = -1;
}

Stack::Stack(int size) {
    stackArray = new int[size];
    capacity = size;
    top = -1;
}

Stack::Stack(Stack& s) : capacity(s.capacity), top(s.top){
    stackArray = new int[capacity]();
    for (int i = 0; i < top; i++) {
        stackArray[i] = s.stackArray[i];
    }
}

Stack::Stack(std::stack<int> in) {
    capacity = in.size();
    stackArray = new int[capacity];
    top = capacity-1;
    for(int i = 0; i < capacity; ++i) {
        stackArray[i] = in.top();
        in.pop();
    }
}

Stack::~Stack() {
    delete[] stackArray;
}

void Stack::push(int element) {
    if (top == capacity - 1) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }
    stackArray[++top] = element;
}

int Stack::pop() {
    if (top == -1) {
        std::cout << "Stack Underflow!" << std::endl;
        return -1;
    }
    return stackArray[top--];
}

bool Stack::isEmpty() {
    return (top == -1);
}

int Stack::peek() {
    if (!isEmpty()) {
        return stackArray[top];
    }
}

int Stack::stack_size() {
    return top + 1;
}

void Stack::display() {
    for (int ix = top; ix >= 0; ix--){
        std::cout << stackArray[ix] << " ";
    }

}
