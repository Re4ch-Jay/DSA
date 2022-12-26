#include <iostream>
using namespace std;

struct Element {
    int data;
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
    return s;
};

// insert begin
void push(Stack * s, int data){
    Element * e;
    e = new Element();
    e->data = data;
    e->next = s->top;
    s->top = e;
    s->size++;
}

// remove begin
void pop(Stack *s){
    Element * tmp;
    if(s->size == 0) {
        cout<<"There is no element to delete"<<endl;
    }else{
        tmp = s->top;
        s->top = s->top->next;
        delete tmp;
        s->size--;
    }
}

void displayStack(Stack *s){
    Element * tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        cout<<"Data: "<<tmp->data<<endl;
        tmp = tmp->next;
    }
    
}

void displaySearchData(int searchData) {
    cout<<"Data search: "<<searchData<<" is found"<<endl;
}

int searchDataInStack(Stack * s, int searchData) {
    Element * tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        if(tmp->data == searchData) {
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void searchDataInStackAndDelete(Stack * s, int searchData) {
    Element * tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        if(tmp->data == searchData) {
            tmp->data = 0;
        }
        tmp = tmp->next;
    }
    
}

void searchDataInStackAndUpdate(Stack * s, int searchData, int newData) {
    Element * tmp;
    tmp = s->top;
    while (tmp != NULL)
    {
        if(tmp->data == searchData) {
            tmp->data = newData;
        }
        tmp = tmp->next;
    }
    
}

int main () {
    Stack * stack;
    stack = createEmptyStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    displayStack(stack);
    cout<<"----POP----"<<endl;
    pop(stack);
    displayStack(stack);
    int searchData = 11;
    int searchKey = searchDataInStack(stack, searchData);
    if(searchKey == 0) {
        cout<<"Data is not found"<<endl;
    }else{
        displaySearchData(searchData);
    }

    searchDataInStackAndDelete(stack, 2);
    searchDataInStackAndUpdate(stack, 1, 20);
    displayStack(stack);
    return 0;
}