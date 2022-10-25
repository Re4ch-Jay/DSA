#include <iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <math.h>
#include <unistd.h>


struct Element{
    string name;
    int age;
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

void insertBegin(List *ls, string newName, int newAge) {
    Element *e;
    e = new Element;
    e -> name = newName;
    e -> age = newAge;

    e -> next = ls->head;
    ls -> head = e;
    
    if(ls-> size == 0) {
        e->next = NULL;
        ls->head = e;
        ls->tail = e;
        // increase size of data
        ls -> size++;
    }else if(ls -> size != 0){
        // update a new element

        ls -> tail -> next = e;
        ls -> tail = e;
        ls -> size++;

    }
    
}

void insertEnd(List *ls, string newName, int newAge) {
    Element *e;
    e = new Element;
   
    if(ls->size == 0) {
        insertBegin(ls, newName, newAge);
    }else if(ls -> size != 0){
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
        cout<<tmp->name<<" "<<tmp->age<<"\n";
        tmp = tmp -> next;
    }
    
}

void search(List *ls, string newName, int newAge){
    Element *tmp;
    int counter = 0;

    tmp = ls -> head;
    while (tmp != NULL)
    {
        if(tmp -> name == newName && tmp -> age == newAge) counter++;
        tmp = tmp -> next;
    }
    if(counter == 0) {
        cout<<"No data found"<<endl;
    }else{
        cout<<"Found data "<<counter<<" times"<<endl;
    }
    
}

int loading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "  Loading";
    long long k = 0;
    while (1 && k < 1) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
        k += 1;
    }
}