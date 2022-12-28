#include <iostream>
using namespace std;

struct Element {
    int data;
    Element * next, * previous;
};

struct List{
    int size;
    Element * head, * tail;
};

List * createList() {
    List * ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void insertBegin(List *ls, int data) {
    Element * e;
    e = new Element();
    e->next = ls->head;
    e->previous = NULL;
    e->data = data;
    if(ls->size == 0) {
        ls->tail = e;
    }   
    if(ls->size != 0){
        ls->head->previous = e;
    }
    ls->head = e;
    ls->size++;
}

void insertEnd(List *ls , int newData) {
    Element * e;
    if(ls->size == 0){
        insertBegin(ls, newData);
    }else {
        e = new Element();
        e->data = newData;
        e->next = NULL;
        e->previous = ls->tail;

        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

// delete

void deleteBegin(List *ls) {
    Element * tmp;
    if(ls->size == 0) {
        cout<<"Cannot delete"<<endl;
    }else{
        tmp = ls->head;
        ls->head = ls->head->next;
        ls->head->previous = NULL;
        delete tmp;
        if(ls->size == 1) {
            ls->tail = NULL;
        }
        ls->size--;
    }
}

void display(List * ls) {
    Element * tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    
}

int main () {

    List * ls;
    ls = createList();

    insertEnd(ls, 1);
    insertEnd(ls, 2);
    insertEnd(ls, 3);
    insertEnd(ls, 4);

    display(ls);

    deleteBegin(ls);
    deleteBegin(ls);
    deleteBegin(ls);
    display(ls);
    return 0;
}

