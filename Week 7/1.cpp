#include <iostream>
#include "dsa.hpp"
using namespace std;

int main()
{

    List *ls;
    ls = createEmptyList();

    insertBegin(ls, 10);
    insertBegin(ls, 10);
    insertBegin(ls, 10);
    insertBegin(ls, 10);

    displayData(ls);

    insertEnd(ls, 20);
    insertEnd(ls, 20);

    displayData(ls);

    deleteBegin(ls);
    cout << "==============" << endl;

    displayData(ls);

    return 0;
}