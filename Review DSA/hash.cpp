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
    List *ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void initializeList() {
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = createList();
    }
    
}

// insert end;

void addEnd(List *ls, int data) {
    Element * e;
    e = new Element();
    e->next = NULL;
    e->data = data;
    if(ls->size == 0){
        ls->head = e;
        ls->tail = e;
    }else{
        ls->tail->next = e;
        ls->tail = e;
    }
    ls->size++;
}

int hashFunction(int data) {
    return data % SIZE;
}

void insertData(int data) {
    int index;
    index = hashFunction(data);
    addEnd(table[index], data);
}

// search

void search(int searchData) {
    int find;
    find = hashFunction(searchData);
    if(table[find]->head->data == searchData || table[find]->head->next->data == searchData ){
        cout<<"Data: "<<searchData<<" found at index: "<<find<<endl;
    }else{
        cout<<"Data: "<<searchData<<" is not found"<<endl;
    }
}

void displayHashTable() {
    Element * tmp;
    for (int i = 0; i < SIZE; i++)
    {
        cout<<i<<"->";
        if(table[i] != NULL){
            tmp = table[i]->head;
            while (tmp != 0)
            {
                cout<<"\t"<<tmp->data;
                tmp = tmp->next;
            }
            
        }
        cout<<endl;
    }
}

int main () {
    initializeList();
    insertData(11);
    insertData(1111);
    insertData(22);
    insertData(20);
    insertData(1);
    insertData(111);
    displayHashTable();

    search(1);
    return 0;
}