// Create a double linked list that can store integer numbers. Then initialize the list with these values 
// [1, 2, 3, 5, 0, -1]. Ask a user for n which represents the number of integer numbers then ask the user 
// to input each of those n numbers. Display the data in double linked list and write those data in a text 
// file Output-Ex1-YourName.txt.

#include <iostream>
#include <fstream>
using namespace std;

struct Element {
    int data;
    Element *next;
    Element *previous;
};

struct List {
    int size;
    Element * head, *tail;

};

List * createEmptyList(){
    List *ls;
    ls = new List();

    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;
}

void insertBegin(List *ls , int newData) {
    Element * e;
    e = new Element();

    e->data = newData;
    e->previous = NULL;
    e->next = ls->head;

    if(ls->size == 0) {
        ls->tail = e;
    }
    if(ls->size != 0){
        ls->head->previous = e;
    }
    ls->head = e;
    ls->size ++;
}

void displayFromTail(List *ls){
    Element *tmp;
    tmp = ls->tail;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->previous;
    }
    
}

void saveData (List *ls) {
    fstream f;
    f.open("Ex1-phatpanhareach.txt", ios::out);
    Element *tmp;
    tmp = ls->tail;
    while (tmp != NULL)
    {
        f<<" "<<tmp->data<<endl;
        tmp = tmp->previous;
    }

    f.close();
}

int main () {

    List *myList;
    myList = createEmptyList();
    int choice, number;
    
    while (choice != 2)
    {
        cout<<"Press [1] To continue: ";
        cout<<"Press [2] To exit: ";
        cin>>choice;
        switch(choice){
            case 1: 
                cout<<"Please input [1, 2, 3, 5, 0, -1] these number one by one: ";
                cin>>number;
                insertBegin(myList, number);
                displayFromTail(myList);
                saveData(myList);
                break;
            default:
                cout<<"Thank you"<<endl;
                break;
        }
    }
  
    return 0;
}