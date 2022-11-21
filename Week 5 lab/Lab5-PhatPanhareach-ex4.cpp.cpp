// At a restaurant, customers are waiting in queue to be served. Create a queue as singly linked list that
// can store customer. Each customer has name, sex and phone number. The program provides a menu
// of choices that a user can use to do some operations on the queue. The operations are enqueue a
// customer (add a customer to queue), dequeue a customer (remove a customer from queue), display
// all customers’ info in the queue and exit the program. Each time the function dequeue is called, also
// display this message “Serving customer, [name]! ”. The program keeps running until the user choose
// choice number 4 to exit

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Element {
    string sex;
    string name;
    double number;
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
void enqueue (Queue * q, string sex, string name, int number) { 
    Element * e;
    e = new Element();
    e->sex = sex;
    e->name = name;
    e->number = number;
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
    
void displayData(Queue * q) {
    Element * tmp;
    tmp = q->front;
    if(tmp == NULL) cout<<"\n\tThere is no data right now"<<endl;
    while (tmp != NULL)
    {
        
        cout<<"Name: "<<tmp->name<<endl;
        cout<<"Phone Number: "<<tmp->number<<endl;
        cout<<"Sex: "<<tmp->sex<<endl;
        tmp = tmp->next;
    }
}

int main () {
    Queue * myQueue;
    myQueue = createEmptyQueue();
    int choice;
    double number;
    string name, sex;

    do
    {
        cout<<"***Welcome to our restuarant****"<<endl;
        cout<<"1. Add customer"<<endl;
        cout<<"2. Remove customer"<<endl;
        cout<<"3. Display customer"<<endl;
        cout<<"4. Exit";
        cout<<"\nChoice: "; cin>>choice;
        system("cls"); // clearing screen
        switch (choice)
        {
        case 1:
            cout<<"***Please input all data****"<<endl;
            cout<<"Customer name: "; cin>>name;
            cout<<"Customer sex: "; cin>>sex;
            cout<<"Customer phone number: "; cin>>number;
            enqueue(myQueue, sex, name, number);
            system("cls");
            break;

        case 2:
            dequeue(myQueue);
            break;
        case 3:
            system("cls");
            cout<<"***All data in the list****"<<endl;
            displayData(myQueue);
            
            break;
        default:
            cout<<"Thank for using our program!"<<endl;
            system("cls");
            break;
        }
    } while (choice != 4);
    
    return 0;
}