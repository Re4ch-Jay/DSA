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

// insertBegin
void enqueue (Queue * q, int newData) { 
    Element * e;
    e = new Element();
    e->data = newData;
    e->next = q->front;
    q->front = e;

    if(q->size == 0) {
        q->front = e;
        q->rear = e;

    }
    q->size++;
}

// deleteBegin 
void dequeueFromBegin(Queue * q) {
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
    
// deleteEnd
void dequeue(Queue * q) {
    Element * tmp;
    if(q->size == 1){
        dequeueFromBegin(q);
    }else if (q->size == 0) {
        cout<<"Data underflow, cannot delete"<<endl;
    }
    else {
        tmp = q->front;
        for (int i = 1; i <= q->size - 2; i++)
        {
            tmp = tmp->next;
        }

        q->rear = tmp;
        tmp = tmp->next;
        q->rear->next = NULL;
        delete tmp;
        q->size--;
        
    }
}
    

void displayData(Queue * q) {
    Element * tmp;
    tmp = q->front;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
}

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
    dequeue(myQueue);
    return 0;
}