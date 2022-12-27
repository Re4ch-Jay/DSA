#include <iostream>
using namespace std;

struct Book {
    int id;
    int pages;
    string title;
    string author;
    string category;
};

struct Element {
    Book book;
    Element * next;
};

struct Stack {
    int size;
    Element * top;
};

Stack * createStack() {
    Stack * stack;
    stack = new Stack();
    stack->size = 0;
    stack->top = NULL;

    return stack;
}

//insertbegin
void push(Stack * stack, Book newBook) {

    cout<<"Push new book"<<endl;
    cout<<"Enter ID: "; cin>>newBook.id;
    cout<<"Enter title: "; cin>>newBook.title;
    cout<<"Enter author: "; cin>>newBook.author;
    cout<<"Enter pages: "; cin>>newBook.pages;
    cout<<"Enter category: "; cin>>newBook.category;

    Element * e;
    e = new Element();
    e->next = stack->top;
    e->book.id = newBook.id;
    e->book.author = newBook.author;
    e->book.title = newBook.title;
    e->book.category = newBook.category;
    e->book.pages = newBook.pages;
    stack->top = e;
    stack->size++;
}

//removebegin
void pop(Stack * stack){
    Element * tmp;
    if(stack->size == 0){
        cout<<"Stack underflow"<<endl;
    }else{
        tmp = stack->top;
        stack->top = stack->top->next;
        delete tmp;
        stack->size--;
    }
    
}

void displayStack(Stack * stack) {
    Element * tmp;
    tmp = stack->top;
    if(stack->size == 0) {
        cout<<"There is no data in the list"<<endl;
    }else{
        cout<<"ID\tTitle\tAuthor\tCategory\tPage"<<endl;
        while (tmp != NULL)
        {
            cout<<tmp->book.id<<"\t"<<tmp->book.title<<"\t"<<tmp->book.author<<"\t"<<tmp->book.category<<"\t"<<tmp->book.pages<<endl;
            tmp = tmp->next;
        }
    }
}

void search(Stack * stack){
    Book book;
    cout<<"Enter book id: "; cin>>book.id;
    Element * tmp;
    tmp = stack->top; 
    if(stack->size == 0) {
        cout<<"There is no data in the list"<<endl;
    }else{
        cout<<"ID\tTitle\tAuthor\tCategory\tPage\t"<<endl;
        while (tmp != NULL)
        {
            if(tmp->book.id == book.id) {
                cout<<tmp->book.id<<"\t"<<tmp->book.title<<"\t"<<tmp->book.author<<"\t"<<tmp->book.category<<"\t"<<tmp->book.pages<<endl;
                
            }
            tmp = tmp->next;
        }
    }
}
