// 2. In addition to problem #1, create 3 functions:
// • A function to create an empty list,
// • A function to add data to the list,
// • A function to display all data in the list.
// Then in main program, call these three functions to test and see the result. Try to add 10 ID data of students into the list.

#include <iostream>
using namespace std;

struct Element {
    string ID;
    Element *next;
};

struct List {

    int size;
    Element *head, *tail;
};

List * createEmptyList(){
    List *ls;
    ls = new List;

    ls -> size = 0;
    ls -> head = NULL;
    ls -> tail = NULL;

    return ls;
}

void addDataToBegin(List *ls, string newID){
    Element *e;
    e = new Element;
    e -> ID = newID;
    e -> next = ls->head;
    ls -> head = e;
    if(ls->size == 0){
        ls -> tail = e;
    } 
    ls->size ++;
}


void displayAllData(List *ls){
    Element * tmp;
    tmp = ls -> head;

    while (tmp != NULL)
    {
        cout<<tmp->ID<<endl;
        tmp = tmp -> next;
    }
}

int main () {

    List * myList;
    myList = createEmptyList();

    addDataToBegin(myList, "1A");
    addDataToBegin(myList, "2B");
    addDataToBegin(myList, "3C");
    displayAllData(myList);

    return 0;
}