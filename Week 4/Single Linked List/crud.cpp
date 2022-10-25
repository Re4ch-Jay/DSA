#include <iostream>
#include "singleLikedList.hpp"
using namespace std;


int main () {

    List * myList;
    myList = createEmptyList();

    insertBegin(myList, 1000);
    insertBegin(myList, 1001);
    insertBegin(myList, 1002);
    insertBegin(myList, 1000);
    insertBegin(myList, 1001);
    insertBegin(myList, 1002);

    displayData(myList);
    saveData(myList);
    return 0;
}