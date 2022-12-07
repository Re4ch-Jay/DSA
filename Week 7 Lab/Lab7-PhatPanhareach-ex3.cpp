#include <iostream>
using namespace std;

struct Element {
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
    ls->head = e;
    if(ls->size == 0) {
        
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

void search(string searchValue) {
    int find;
    find = hashFunction(searchValue);
    if(table[find]->head->name == searchValue) {
        cout<<searchValue<<" found at index "<<find<<endl;
    }
    else {
        cout<<searchValue<<"Not found"<<endl;
    }
}

void searchAndDelete(string searchValue) {
    int find;
    find = hashFunction(searchValue);
    if(table[find]->head->name == searchValue) {
        table[find]->head->name = "";
    }
    else {
        cout<<searchValue<<"Not found"<<endl;
    }
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
                cout<<" "<<e->name;
                e = e->next;
            }
        }
        cout<<endl;
    }
}


int main () {

    initializeAllLists();

    string Reach = "Reach";
    string Dara = "Dara";
    cout<<"Before search"<<endl;

    insertData("Bob");
    insertData(Reach);
    insertData(Dara);
    insertData("Pisey");
    displayTable();

    cout<<"After search "<<Reach<<endl;    
    search(Reach);

    cout<<"After delete "<<Dara<<endl;  
    searchAndDelete(Dara);
    displayTable();

    return 0;
}