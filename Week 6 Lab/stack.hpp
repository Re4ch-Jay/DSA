#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct Stack {
    int size;
    Element *top; // top same as head and top same as tail in sll
};

Stack * createEmptyStack () {
    Stack * s;
    s = new Stack();
    s->size = 0;
    s->top = NULL;
    return s;
}

// insertBegin
void push(Stack * s, int newData) {
    Element *e;
    e = new Element();
    e->data = newData;
    e->next = s->top;
    s->top = e;
    if(s->size == 0) {
        s->top = e;
    }
    s->size ++;
}

// deleteFromBegin
void pop(Stack * s) {
    Element *tmp;
    if(s->size == 0) {
        cout<<"Stack underflow"<<endl;
    }else {
        tmp = s->top;
        s->top = s->top->next;
        delete tmp;
        if(s->size == 1) s->top = NULL;
        s->size--;
    }
}

void displayData(Stack *s) {
    Element * tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
}
