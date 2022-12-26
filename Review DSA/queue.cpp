#include <iostream>
using namespace std;

struct Element {
    int data;
    Element * next;
};

struct Queue {
    int size;
    Element * front, * rear;
};

Queue * createEmptyQueue() {
    Queue * q;
    q = new Queue();
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
    return q;
}


// insert end
void enqueue(Queue * q, int data) {
    Element * e;
    e = new Element();
    if(q->size == 0){
        e->data = data;
        q->front = e;
        q->rear = e;
        q->size++;
    }else{
        e->data = data;
        q->rear->next = e;
        q->rear = e;
        q->size++;
    }
}

// remove begin
void dequeue(Queue * q) {
    Element * tmp;
    if(q->size == 0) {
        cout<<"Cannot delete, there is no data to delete"<<endl;
    }else{
        tmp = q->front;
        q->front = q->front->next;
        delete tmp;
        q->size--;
    }
}

void displayQueue(Queue * q) {
    Element * tmp;
    tmp = q->front;
    while (tmp != NULL)
    {
        cout<<"Data: "<<tmp->data<<endl;
        tmp=tmp->next;
    }
    
}

int main () {
    Queue * q;
    q = createEmptyQueue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    displayQueue(q);
    cout<<"----Dequeue----"<<endl;
    dequeue(q);
    displayQueue(q);

    return 0;
}