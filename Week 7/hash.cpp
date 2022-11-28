#include <iostream>
using namespace std;

struct Element {
    int data;
    Element * next;
};

struct List {
    int size;
    Element * head, *tail;
};

const int SIZE = 10;
List * table[SIZE];

List * createList() {
    List * ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;
    return ls;
}

void initializeAllLists() {
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = createList();
    }
}

void addEnd(List *ls, int data) {
    Element * e;
    e= new Element();
    e->next = NULL;
    e->data = data;

    if(ls->size == 0) {
        ls->head = e;
        ls->tail = e;
        ls->size++;
    }else{
        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

int hashFunction(int n) {
    return n % SIZE;
}

void insertData(int data) {
    int index;
    index = hashFunction(data);
    addEnd(table[index], data);
}

void displayTable() {
    Element * e;
    for (int i = 0; i < SIZE; i++)
    {
        cout<<i<<"->";
        if (table[i] != NULL)
        {
            e = table[i]->head;
            while (e != 0)
            {
                cout<<" "<<e->data;
                e = e->next;
            }
        }
        cout<<endl;
    }
}


int main () {

    initializeAllLists();
    insertData(1);
    insertData(12);
    insertData(5);
    insertData(14);
    insertData(7);
    insertData(1);
    insertData(1);
    insertData(5);

    displayTable();
   

    return 0;
}