#include <iostream>
using namespace std;
struct Element {
    string data;
    Element * next;
};

struct Queue {
    int size;
    Element *front, *rear;
};

Queue * createEmptyQueue () {
    Queue * q;
    q = new Queue();
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(Queue * q, string newData) {
    Element * e;
    e = new Element();
    e->data = newData;
    e->next = NULL;
    if(q->size == 0) {
        q->front = e;
        q->rear = e;
    }
    else {
        q->rear->next = e;
        q->rear = e;
    }
    q->size++;
} 

void insertEnd (Queue * q, string newData) {
    Element * e;
    e = new Element();
    e->data = newData;
    e->next = NULL;
    if(q->size == 0) {
        q->front = e;
        q->rear = e;
    }
    else {
        q->rear->next = e;
        q->rear = e;

    }
    q->size++;
}

void deleteBegin (Queue * q) {
    Element *tmp;
    if(q->size == 0) {
        cout<<"Queue underflow"<<endl;
    }
    else {
        tmp = q->front;
        q->front = q->front->next;
        delete tmp;
        if(q->size == 1) q->rear = NULL;
        q->size--;
    }
}

void dequeue(Queue *q) {
    Element *t;
    if(q->size == 0){
        cout<<"Data underflow"<<endl;
    }else{
        t = q->front;
        q->front = q->front->next;
        delete t;
        if(q->size == 1) q->rear = NULL;
        q->size--;
    }
}


// displayData 

void display(Queue * q){
    Element *tmp;
    tmp = q->front;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
    
}

int main () {
    return 0;
}