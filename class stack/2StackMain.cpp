
#include <iostream>
#include <stack>
#include "2Stack.h"

int main(){

    std::stack<int> b;
    b.push(1);
    b.push(2);
    b.push(3);

    Stack st(4);
    Stack s(b);

    st.push(2);
    st.push(54);
    st.push(255);
    st.push(23);

    std::cout << "Stack size: " << st.stack_size() << std::endl;

    std::cout << "Print Stack: ";
    st.display();
    std::cout << std::endl;

    std::cout << st.pop() << " is removed from stack" << std::endl;

    std::cout << st.pop() << " is removed from stack " << std::endl;

    std::cout << "Top element is " << st.peek() << std::endl;

    std::cout << "Stack size: " << st.stack_size() << std::endl;

    std::cout << "Print Stack: ";
    st.display();
    std::cout << std::endl;


    return 0;
}

