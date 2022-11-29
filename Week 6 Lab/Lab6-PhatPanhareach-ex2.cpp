// 2. (Reverse string) Write a program ask a user for a string then display the reverse of the input string using Stack

#include <iostream>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
using namespace std;

struct Element {
    string data;
    Element *next;
};

struct Stack {
    int size;
    Element *top; // top same as same as tail in sll
};

Stack * createEmptyStack() {
    Stack *s;
    s = new Stack();

    s->size = 0;
    s->top = NULL;
    s->top = NULL;

    return s;
}

void push(Stack * s, string newData) {
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

void pop(Stack *s) {
    Element *tmp;

    if(s->size == 0){
        cout<<"Stack underflow"<<endl;
    }else{
        tmp = s->top;
        s->top = s->top->next;
        delete tmp;
        if(s->size == 1) s->top = NULL;
        s->size--;
    }
}

void displayStack(Stack *s) {
    Element *tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        cout<<tmp->data;
        tmp = tmp->next;
    }
}

int main () {

    Stack * myStack;
    myStack = createEmptyStack();

    string text;
    cout<<"Please input your name: "; cin>>text;
    string tmp;
    cout<<"***Default***"<<endl;
    cout<<text<<endl;
    for (int i = 0; i < text.length(); i++)
    {
        tmp = text[i];
        push(myStack, tmp);
    }
    cout<<"***Reversed***"<<endl;
    displayStack(myStack);
    
    return 0;
}