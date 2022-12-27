#include <iostream>
#include "stack.hpp"
using namespace std;

int main() {
    Book book;
    Stack * stack;
    stack = createStack();
    char choice;
    do
    {
        system("pause");
        cout<<"1. Push book"<<endl;
        cout<<"2. View books"<<endl;
        cout<<"3. Search book"<<endl;
        cout<<"4. Pop book"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Choice: "; cin>>choice;
        switch (choice)
        {
        case '1':
            system("cls");push(stack, book);
            break;
        case '2':
            system("cls");displayStack(stack);
            break;
        case '3':
            system("cls");search(stack);
            break;
        case '4':
            system("cls"); pop(stack);
            break;
        case '0':
            system("cls");cout<<"Thank"<<endl;
            break;
        default:
            cout<<"Wrong input"<<endl;
            break;
        }
    } while (choice != '0');
    
    return 0;
}