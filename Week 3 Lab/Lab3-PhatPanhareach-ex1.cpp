// 1. We want to store a list of all student citizens’ ID (more students are added every year thus the list should be able to
// store unlimited number of student IDs). Define a linked list data structure for this kind of problem.
// Hint: Create a structure element and list. Data in element is student ID.

#include <iostream>
using namespace std;

struct Element {
    int ID;
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

int main () {

    List *myList;
    myList = createEmptyList();

    return 0;
}