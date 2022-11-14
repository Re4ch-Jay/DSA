#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next;
};

struct Stack {
    int size;
    Element *first, *top; // first same as head and top same as tail in sll
};

Stack * createEmptyStack () {
    Stack * s;
    s = new Stack();
    s->size = 0;
    s->first = NULL;
    s->top = NULL;

    return s;
}

// insertBegin
void push(Stack * s, int newData) {
    Element *e;
    e = new Element();
    e->data = newData;
    e->next = s->first;
    s->first = e;
    if(s->size == 0) {
        s->first = e;
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
        tmp = s->first;
        s->first = s->first->next;
        delete tmp;
        if(s->size == 1) s->top = NULL;
        s->size--;
    }
}

void displayData(Stack *s) {
    Element * tmp;
    tmp = s->first;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
}


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