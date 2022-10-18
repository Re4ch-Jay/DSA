// 3. Create a singly linked list that can store integer numbers. Create 4 functions i) create list, ii) add data to end of list, iii)
// add data to beginning of list, and iv) display data in list. Then …
// • Create an empty list
// • Add the number 7 to the beginning of the list
// • Add 1 to the beginning of the list
// • Display all numbers in the list 1 7
// • Add 0 to the end of the list
// • Add the number 4 to the end of the list
// • Display all numbers in the list 1 7 0 4

#include <iostream>
using namespace std;


struct Element{
    int number;
    Element *next;
};

struct List {
    int size;
    Element *head, *tail;

};

List* createEmptyList() {
    List *ls;
    ls = new List;

    ls -> size = 0;
    ls -> head = NULL;
    ls -> tail = NULL;

    return ls;
}

void insertBegin(List *ls, int newNumber) {
    Element *e;
    e = new Element;
    e -> number = newNumber;

    e -> next = ls->head;
    ls -> head = e;
    
    if(ls-> size == 0) {
        ls -> tail = e;
    }
    // increase size of data
    ls -> size++;
}

void insertEnd(List *ls, int newNumber) {
    if(ls->size == 0) {
        insertBegin(ls, newNumber);
    }else{
        // create a new element
        Element * e;
        e = new Element();
        e -> number = newNumber;
        e -> next = NULL;

        // update a new element

        ls -> tail -> next = e;
        ls -> tail = e;
        ls -> size++;

    }
}


void displayInfoList(List *ls){
    Element *tmp;
    tmp = ls -> head;

    while (tmp != NULL)
    {
        cout<<tmp->number<<" ";
        tmp = tmp -> next;
    }
    
}


int main () {

    List * myList;
    myList = createEmptyList();

    insertBegin(myList, 7);
    insertBegin(myList, 1);
    displayInfoList(myList);
    cout<<"\n";
    insertEnd(myList, 0);
    insertEnd(myList, 4);
    displayInfoList(myList);
    cout<<"\n";

    return 0;
}