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
    e->data = data;
    e->next = NULL;
    if(q->size == 0){
        q->front = e;
        q->rear = e;
    }else{
        q->rear->next = e; // ls->tail->next = e; ls->tail = e;
        q->rear = e;
    }
    q->size++;
}


int isEmpty(Queue * q) {
    if(q->size == 0) {
        return 1; // isEmpty
    }
    return 0;
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

void peek(Queue * q){
    Element * tmp;
    tmp = q->front;
    cout<<"Peek first element: "<<tmp->data<<endl;
}

void displayQueue(Queue * q) {
    Element * tmp;
    tmp = q->front;
    int empty = isEmpty(q);
    if(empty == 1) {
        cout<<"It is empty queue"<<endl;
    }else{
        while (tmp != NULL)
        {
            cout<<"Data: "<<tmp->data<<endl;
            tmp=tmp->next;
        }
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
    peek(q);
    return 0;
}