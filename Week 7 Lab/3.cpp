#include <iostream>
using namespace std;

struct Element {
    int data;
    string name;
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

void addEnd(List *ls, string name) {
    Element * e;
    e= new Element();
    e->next = NULL;
    e->name = name;

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


int convertToASCII(string name)
{
    int sum = 0;
    for (int i = 0; i < name.length(); i++)
    {
        //cout << (int)s[i]<< endl;
        sum+=(int)name[i];
    }
    return sum;
}

int hashFunction(string name) {
    int code = convertToASCII(name);
    return code % SIZE;
}

void insertData(string name) {
    int index;
    index = hashFunction(name);
    addEnd(table[index], name);
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
    insertData("Reach");
    insertData("Reach");
    insertData("Reach");
    insertData("Reach");
    insertData("Reach");

    displayTable();
   

    return 0;
}