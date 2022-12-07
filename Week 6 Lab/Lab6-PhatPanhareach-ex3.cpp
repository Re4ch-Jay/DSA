// 3. (Parentheses balancing) Write a program that analyzes a pieces of symbols, and determines whether its
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

//insertBegin
void push(Stack * s, char symbols) {
    Element *e;
    e = new Element();
    e->symbols = symbols;
    if(s->size == 0) {
        s->top = e;
        s->size++;
    }else{
        e->next = s->top;
        s->top = e;
        s->size++;
    }
    
}

void pop(Stack *s) {
    Element * tmp;
    if(s->size == 0){
        cout<<"Cannot delete"<<endl;
    }
    else{
        tmp = s->top;
        s->top = s->top->next;
        delete tmp;
        if(s->size == 1) s->top = NULL;
        s->size--;
    }
}


bool areSymbolsBalanced(Stack * s, string expr){
    Element *tmp;
    tmp = new Element();
    // Declare a stack to hold the previous brackets.
    
    for (int i = 0; i < expr.length(); i++) {
        if (s->size == 0) {
             
            // If the stack is empty
            // just push the current bracket
            push(s, expr[i]);
        }
        else if ((s->top->symbols == '(' && expr[i] == ')')
                 || (s->top->symbols == '{' && expr[i] == '}')
                 || (s->top->symbols == '[' && expr[i] == ']')) {
            // If we found any complete pair of bracket
            // then pop
            pop(s);
        }
        else {
            push(s, expr[i]);
        }
    }
    if (s->size == 0) {
         
        // If stack is empty return true
        return true;
    }
    return false;
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
    string symbol = "[](){}";

    cout<<"Your symbols: "<<symbol<<endl;
    
    cout<<"Result of checking is: ";
    if (areSymbolsBalanced(myStack, symbol))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}