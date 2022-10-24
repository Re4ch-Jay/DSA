#include <iostream>
#include "doubleLinkedList.hpp"
using namespace std;

int main () {
    List *myList;
    myList = createEmptyList();

    insertBegin(myList, 30);
    insertBegin(myList, 60);
    insertBegin(myList, 40);
    insertEnd(myList, 850);
    insertEnd(myList, 50);
    insertEnd(myList, 10);

    cout<<"Display from head"<<endl;
    displayFromHead(myList);
    cout<<"Display from tail"<<endl;
    displayFromTail(myList);
    
    cout<<"Delete from begin"<<endl;
    deleteBegin(myList);
    displayFromHead(myList);

    cout<<"Delete from last"<<endl;
    deleteLast(myList);
    displayFromHead(myList);

    cout<<"Delete All"<<endl;
    deleteAll(myList);
    displayFromHead(myList);
   
    return 0;
}