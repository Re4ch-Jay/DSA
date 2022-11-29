// 4. (Binary representation using Stack) Write a program that reads a positive integer from a user. Store the binary
// representation of that integer into a stack. Finally, display the binary
// representation from the stack.
// Hint: Divide the integer by 2 (see the right image)

#include <iostream>
using namespace std;

struct Element {
    int number;
    Element * next;
};

struct Stack {
    int size;
    Element *first, *top;
};

Stack * createEmptyStack() {
    Stack * s;
    s = new Stack();

    s->size = 0;
    s->first = NULL;
    s->top = NULL;

    return s;
}

int converter(int number) {
    int binary = 0, remainder, product = 1;
    while (number != 0){
        remainder = number % 2;
        binary = binary + (remainder * product);
        number = number / 2;
        product *= 10;      
    }
    return binary;
}

// insert begin
void push(Stack * s, int newNumber) {
    Element *e;
    e = new Element();
    int convertNum = converter(newNumber);
    e->number = convertNum;
    e->next = s->first;
    s->first = e;
    if(s->size == 0) {   
        s->top = e;
    }
    s->size ++;
    
}

void displayStack(Stack * s) {  
    Element * tmp;
    tmp = s->first;
    while (tmp!=NULL)
    {
        cout<<" "<<tmp->number;
        tmp = tmp->next;
    }
}

int main() {

    Stack * myStack;
    myStack = createEmptyStack();
    
    int number, binary = 0, remainder, product = 1;
    cout<<"Please input a number: "; cin>>number;
    push(myStack, number);
    displayStack(myStack);

    return 0;
}
