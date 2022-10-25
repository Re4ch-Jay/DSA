#include <iostream>
#include "sll2.hpp"
using namespace std;

int main () {

    List *l1;

    l1 = createEmptyList();
    

    // loading();
    cout<<"\n";
    insertBegin(l1, "Dara", 19);
    insertBegin(l1, "Jack", 11);
    insertBegin(l1, "Jill", 22);
    insertBegin(l1, "John", 10);
    // insertEnd(l1, "lak", 30);
    displayInfoList(l1);
    search(l1, "Jack", 11);
    
    return 0;
}