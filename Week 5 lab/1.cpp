// 1. Create an implementation of Queue as Linked list. Make it as a header file (MyQueue.h) and create a main
// program to test the header. Hint: You can reuse the Single Linked List code and rename the operations
// and variables to the terms used by Queue.

#include <iostream>
#include <MyQueue.hpp>
using namespace std;

int main () {

    Queue * myQueue;
    myQueue = createEmptyQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 11);
    enqueue(myQueue, 12);
    
    displayData(myQueue);
    cout<<"#####################"<<endl;
    dequeue(myQueue);
    displayData(myQueue);
    cout<<"#####################"<<endl;
    dequeue(myQueue);
    displayData(myQueue);
    cout<<"#####################"<<endl;
    dequeue(myQueue);
    displayData(myQueue);
    cout<<"#####################"<<endl;
    dequeue(myQueue);
    displayData(myQueue);
    return 0;
}