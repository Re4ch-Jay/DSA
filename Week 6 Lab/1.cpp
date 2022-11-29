// 1. (Stack as Linked List) Create an implementation of Stack as Linked list. Make it as a
// header file. Hint: You can reuse the Single Linked List code and rename the operations
// and variable names to the terms used by Stack. Then create a main program to test your
// Stack using the created header

#include <iostream>
#include "stack.hpp"
using namespace std;

int main () {

    Stack * myStack;
    myStack = createEmptyStack();

    push(myStack, 1);
    push(myStack, 2);
    push(myStack, 3);
    displayData(myStack);
    cout<<"******Pop*******"<<endl;
    pop(myStack);
    displayData(myStack);
    cout<<"******Pop*******"<<endl;
    pop(myStack);
    displayData(myStack);
    cout<<"******Pop*******"<<endl;
    pop(myStack);
    displayData(myStack);
    pop(myStack);

    return 0;
}