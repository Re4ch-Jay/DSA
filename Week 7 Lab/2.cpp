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

int search(int searchValue) {
    int find;
    find = hashFunction(searchValue);
    if(table[find] == searchValue) {
        cout<<searchValue<<" found"<<" at index "<<find<<endl;
        return 1;
    }
    else {
        cout<<"Not found"<<endl;
        return 0;
    }
    return 0;
}

void deleteData(int data) {
    int index;
    index = hashFunction(data);
    if(table[index] == data) {
        table[index] = 0;
    }
    else {
        cout<<"Data not found"<<endl;
    }
}

int main () {

    insertData(2);
    insertData(4);
    insertData(7);
    insertData(10);
    cout<<"Display"<<endl;
    displayTable();

    int number = 10;
    search(number);
    deleteData(number);
    cout<<"\nDisplay after delete number "<<number<<endl;
    displayTable();
    
    return 0;
}