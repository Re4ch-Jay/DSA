// 2. Write a C++ program to process letter in a given text below. A letter means to add that letter into the queue
// while an asterisk means to remove data from queue. Perform the following text with an empty queue.
// E A S * Y * Q U E * * * S T * * * I O * N * * *

#include <iostream>
using namespace std;

struct Element {
    string data;
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

// deleteBegin

void dequeue(Queue * q) {
    Element * tmp;

    if(q->size == 0) {
        cout<<"Data underflow, cannot delete"<<endl;
    }else {
        tmp = q->front;
        q->front = q->front->next;
        delete tmp;
        if(q->size == 1) q->rear = NULL;
        q->size--;
    }
    
}

// insertEnd
void enqueue (Queue * q, string newData) { 
    Element * e;
    e = new Element();
    e->data = newData;
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
        if(tmp->data == "*") {
            dequeue(q);
        }else{
            cout<<" "<<tmp->data;
           
        }
        tmp = tmp->next;
     
    }
}


int main() {

    Queue * myQueue;
    myQueue = createEmptyQueue();

    // string text = "E A S * Y * Q U E * * * S T * * * I O * N * * *";
    // for (int i = 0; i < text.length(); i++)
    // {
    //     if(text[i] == '*'){

    //     }else{
    //         cout<<" "
    //     }
    // }
    
    enqueue(myQueue, "E");
    enqueue(myQueue, "A");
    enqueue(myQueue, "S");
    enqueue(myQueue, "*");
    enqueue(myQueue, "Y");
    enqueue(myQueue, "*");
    enqueue(myQueue, "Q");
    enqueue(myQueue, "U");
    enqueue(myQueue, "E");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
    enqueue(myQueue, "S");
    enqueue(myQueue, "T");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
    enqueue(myQueue, "I");
    enqueue(myQueue, "O");
    enqueue(myQueue, "*");
    enqueue(myQueue, "N");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
    enqueue(myQueue, "*");
   
    displayData(myQueue);

   

    return 0;
}