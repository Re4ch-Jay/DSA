// 3. Create a queue that can schedule some tasks in order. Each task is to display a message on the screen.
// Table 1 shows about tasks and their descriptions (used for displaying message).
// Suppose that, the queue contains Task 2, Task 1, Task 4, and Task 3 (Task 2 is the first task in the
// queue, Task 1 is the second task in the queue, …).
// Write a program to ask user “Do you want to perform a task in your queue now?”. When the user
// say ‘yes’, perform the task by calling to dequeue function of the queue. Keep asking user until no
// task is remained in the queue.

#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct Queue {
    int size;
    Element *front, *rear;
};

Queue * createEmptyQueue() {
    Queue * q;
    q = new Queue();
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

// insertEnd
void enqueue (Queue * q, int data) { 
    Element * e;
    e = new Element();
    e->data = data;
    e->next = NULL;
    if(q->size == 0) {
        q->front = e;
        q->rear = e;

    }else {
        q->rear->next = e;
        q->rear = e;
    }
    q->size++;
}

    
void displayData(Queue * q) {
    Element * tmp;
    tmp = q->front;
   
    while (tmp != NULL)
    {
        cout<<"Task...Done"<<endl;
        tmp = tmp->next;
    }
}

// deleteBegin
bool isEmpty = false;

void dequeue(Queue * q) {
    Element * tmp;
    if(q->size == 0) {
        cout<<"You are completed all the task, There are no task rignt now"<<endl;
    }else {
        tmp = q->front;
        q->front = q->front->next;
        delete tmp;
        if(q->size == 1) q->rear = NULL;
        q->size--;  
        displayData(q);
    }
}

int main () {
    Queue * myQueue;
    myQueue = createEmptyQueue();
    char answer;
    int choice, task;
    int count = 0;


    cout<<"There are 4 task remaining!!!"<<endl;
    for (int i = 1; i <= 4; i++)
    {
        enqueue(myQueue, i);
        cout<<"Do you want to perform task right now?"<<endl; cin>>answer;

        if(answer == 'y' || answer == 'Y'){
            displayData(myQueue);
            dequeue(myQueue);
        }else{
            dequeue(myQueue);
            i--;
        }
    }    
    return 0;
}