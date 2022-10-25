#include <iostream>
#include <fstream>
using namespace std;


struct Element {
    int data;
    Element * next;
};

struct List {
    int size;
    Element * head, *tail;
};

List * createEmptyList() {
    List *ls;
    ls = new List();
    ls->size = 0;
    ls-> head = NULL;
    ls-> tail = NULL;
}

void insertBegin(List *ls, int newData){
    Element * e;
    e = new Element();
    e->data = newData;

    e->next = ls->head;
    ls->head = e;
    if(ls->size == 0){
        ls->tail = e;
    }
    ls->size++;
}

void insertEnd(List *ls, int newData){
    Element * e;
    if(ls->size == 0){
        insertBegin(ls, newData);
    }else{
        e = new Element();
        e->data = newData;
        e->next = NULL;

        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

void displayData(List *ls){
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
    
}

void deleteBegin(List *ls){
    Element *tmp;
    tmp = ls->head;
    ls->head = ls->head->next;

    delete tmp;
    if(ls->size == 1) ls->tail = NULL;
    ls->size--;
}

void deleteLast(List *ls){
    Element * tmp;
    int i;
    if(ls->size == 1){
        deleteBegin(ls);
    }
    else{
        tmp = ls->head;
        for ( i = 1; i <= ls->size - 2; i++)
        {
            tmp = tmp->next;
        }
        ls->tail = tmp;
        tmp = tmp->next;
        ls->tail->next = NULL;
        delete(tmp);
        ls->size--;
    }
}

void deleteAll(List *ls){
    while(ls->size > 0){
        deleteBegin(ls);
    }
}

void saveData(List *ls){
    fstream f1;
    f1.open("data.txt", ios::app);
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        f1<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
    

    f1.close();
}
