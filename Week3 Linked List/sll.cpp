#include <iostream>
#include "sll.hpp"

using namespace std;

int main () {

    List *L1;
    L1 = createEmptyList();

    insertBegin(L1, "reach");
    insertBegin(L1, "dara");
    // loading();
    insertBegin(L1, "dara");
    insertBegin(L1, "dara");
    insertBegin(L1, "jack");
    insertEnd(L1, "john");
    search(L1, "dara");
    displayInfoList(L1);
    

    cout<<"size of list: "<<L1 -> size<<endl;

    return 0;
}