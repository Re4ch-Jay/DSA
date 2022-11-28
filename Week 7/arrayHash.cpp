#include <iostream>
using namespace std;

const int SIZE = 7;
int table[SIZE];

int hashFunction(int n) {
    return n % SIZE;
}

void insertData(int value) {
    int index;
    index = hashFunction(value);
    table[index] = value;
}


void displayTable() {
    for (int i = 0; i < SIZE; i++)
    {
        cout<<i<<"->";
        cout<<table[i]<<endl;
    }
    
}

void search(int searchValue) {
    int find;
    find = hashFunction(searchValue);
    if(table[find] == searchValue) {
        cout<<searchValue<<" found"<<endl;
    }
    else {
        cout<<"Not found"<<endl;
    }

}
int main () {

    insertData(1);
    insertData(2);
    insertData(3);
    insertData(10);

    displayTable();

    search(10);
    
    return 0;
}