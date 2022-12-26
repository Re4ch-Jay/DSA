#include <iostream>
using namespace std;

struct Element
{
    int data;
    Element * next;
};

struct List {
    Element * head, *tail;
    int size;
};

List * createEmptyList() {
    List * ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;
    
    return ls;
}

// insertBegin

void insertBegin(List *ls, int data) {
    Element * e;
    e = new Element();
    e->data = data;
    e->next = ls->head; // next element = head
    ls->head = e;
    ls->tail = e;
    ls->size++;
}

void insertEnd(List *ls, int data) {
    Element * e;
    e = new Element();
    if(ls->size == 0){
        e->data = data;
        ls->head = e;
        ls->tail = e;
        ls->size++;
    }else{
        e->data = data;
        ls->tail->next = e;
        ls->tail =e;
        ls->size ++;
    }
}

void deleteBegin(List * ls) {
    Element * tmp;
    if(ls->size == 0) {
        cout<<"Cannot delete"<<endl;
    }else{
        tmp = ls->head;
        ls->head = ls->head->next;
        delete tmp;
        ls->size--;
    }
}

void displayData(List *ls) {
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        cout<<tmp->data<<" "<<endl;
        tmp = tmp->next;
    }
    
}

int main () {

    List * myList;
    myList =  createEmptyList();

    insertBegin(myList, 10);
    insertBegin(myList, 20);
    insertBegin(myList, 30);

    displayData(myList);
    cout<<"Delete"<<endl;
    deleteBegin(myList);
    displayData(myList);
    return 0;
}