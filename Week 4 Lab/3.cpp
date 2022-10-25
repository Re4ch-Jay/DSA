// 3. Create a Double linked list that can stores the English alphabet (A-Z). Display data from A to Z in 
// double linked list. In addition, display data from Z to A in double linked list.


#include <iostream>
#include <fstream>
using namespace std;

struct Element {
    int dataStart, dataLast;
    Element *next;
    Element *previous;
};

struct List {
    int size;
    Element * head, *tail;

};

List * createEmptyList(){
    List *ls;
    ls = new List();

    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;
}

void insertBegin(List *ls , int start, int last) {
    Element * e;
    e = new Element();

    e->dataStart = start;
    e->dataLast = last;
    e->previous = NULL;
    e->next = ls->head;

    if(ls->size == 0) {
        ls->tail = e;
    }
    if(ls->size != 0){
        ls->head->previous = e;
    }
    ls->head = e;
    ls->size ++;
}

void displayFromHead(List *ls){
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        for (int i = tmp->dataLast; i >= tmp->dataStart; i--) {
            cout<<(char) i<<" ";
        }
        tmp = tmp->next;
    }
    
}

void displayFromTail(List *ls){
    Element *tmp;
    tmp = ls->tail;
    while (tmp != NULL)
    {
        
        for (int i = tmp->dataStart; i <= tmp->dataLast; i++) {
            cout<<(char) i<<" ";
        }
        
        tmp = tmp->previous;
    }
    
}

int main () {

    List *myList;
    myList = createEmptyList();
    
    insertBegin(myList, 97, 122);
    displayFromTail(myList);
    cout<<"\n******************************************************************************"<<endl;
    displayFromHead(myList);

    return 0;
}