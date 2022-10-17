// Write a C++ program to ask a user for 7 integer numbers and store in an array. Display all
// numbers stored in an array by using another pointer variable.

#include <iostream>
using namespace std;

int main() {
    int number[7];
    int *p;
    cout<<"Enter 7 integer numbers: \n";
    int length = sizeof(number) / sizeof(number[1]);
    for (int i = 0; i < length; i++)
    {
        cin>>number[i];
        p = number;
    }
    
    cout<<"From the same variable"<<endl;
    for (int i = 0; i < length; i++)
    {
        cout<<number[i]<<endl;
    }

    cout<<"From another pointer variable\n";
    for (int i = 0; i < length; i++)
    {
        cout<<*(number + i)<<endl;
    }
    
    
    
    return 0;
}
