#include <iostream>
#include <fstream>
using namespace std;

//create Element

struct Element {
  int data;
  Element * next;
};

// create struck list 

struct List {
    int size;
    Element * head, *tail;
};

List * createEmptyList () {
    List *ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void insertBegin(List *ls, int data) {
    Element * e;
    e = new Element();

    e->data = data;
    e->next = ls->head;
     ls->head = e;    
    if(ls->size == 0){
       
        ls->tail = e;
    }
    ls->size++;
}

void insertEnd(List *ls, int data) {
    Element * e;
    e = new Element();

    if(ls->size == 0) {
        insertBegin(ls, data);
    }else{
        
        e->data = data;
        e->next = NULL;

        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

void deleteBegin(List *ls) {
    Element * tmp;
    tmp = ls->head;
    if(ls->size == 0) cout<<"There is no data to delete"<<endl; 

    ls->head = ls->head->next;

    delete tmp;

    if(ls->size == 1) ls->tail = NULL;
    ls->size--;
}


void deleteAll(List *ls) {
    while (ls->size > 0)
    {
        deleteBegin(ls);
        cout<<"Delete data"<<endl;
    }
}


void displayData(List *ls) {
    Element *tmp;
    tmp = ls->head;
    if(tmp == NULL) cout<<"There is no data right now"<<endl;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }    
    
}


void saveData(List *ls, int data) {
    Element * tmp;
    tmp = ls->head;
    fstream saveFile;
    saveFile.open("data.txt", ios::app);
    while (tmp != NULL)
    {
        saveFile<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    } 
    saveFile.close();
}