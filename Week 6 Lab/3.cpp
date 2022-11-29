// (Parentheses balancing) Write a program that analyzes a pieces of symbols, and determines whether its
// parentheses, braces, and curly braces are "balanced."
// Hint: for left delimiters, push onto stack; for right delimiters, pop from stack and check whether popped
// element matches right delimiter.

#include <iostream>
using namespace std;

struct Element {
    char symbols;
    Element * next;
};

struct Stack {

    int size;
    Element * top;
};

Stack * createEmptyStack() {
    Stack * s;
    s = new Stack();

    s->size = 0;
    s->top = NULL;
    return  s;
}

//insertEnd
void push(Stack * s, char symbols) {
    Element *e;
    e = new Element();
    e->symbols = symbols;
    e->next = s->top;
    if(s->size == 0) s->top = e;
    s->size++;
}

void pop(Stack *s) {
    Element * tmp;
    if(s->size == 0){
        cout<<"Balanced"<<endl;
    }
    else{
        tmp = s->top;
        s->top = s->top->next;
        delete tmp;
        s->size--;
    }
}

void displayStack(Stack *s) {
    Element *tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->symbols<<endl;
        tmp = tmp->next;
    }
}

int main() {

    Stack * myStack;
    myStack = createEmptyStack();
    string symbol = "()";


    for (int i = 0; i < symbol.length(); i++)
    {
        if((symbol[i] == '(' && symbol[i] == ')') || (symbol[i] == '[' && symbol[i] == ']') || (symbol[i] == '{' && symbol[i] == '}')){
            pop(myStack);
        }else{
            push(myStack, symbol[i]);
        }
    }

    displayStack(myStack);
    

    return 0;
}