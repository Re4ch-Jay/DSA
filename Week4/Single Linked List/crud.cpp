#include <iostream>
#include "singleLikedList.hpp"
using namespace std;


int main () {

    List * myList;
    myList = createEmptyList();

    insertBegin(myList, 1000);
    insertBegin(myList, 1001);
    insertBegin(myList, 1002);
    displayData(myList);

    cout<<"Delete Begin"<<endl;
    deleteBegin(myList);
    displayData(myList);
    cout<<"Delete Last"<<endl;
    deleteLast(myList);
    displayData(myList);

    cout<<"Add more data"<<endl;
    insertBegin(myList, 1000);
    insertBegin(myList, 1001);
    insertBegin(myList, 1002);

    displayData(myList);

    deleteAll(myList);
    displayData(myList);
    cout<<"Delete All"<<endl;
    return 0;
}