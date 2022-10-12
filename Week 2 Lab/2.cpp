// Write a C++ program to get a number, say n, from a user. Then modify the value of n
// indirectly to n+7 using a pointer variable.
// Note: We don’t use: n = n + 7 (this is a direct way of modifying n)

#include <iostream>

using namespace std;

int main() {

    int n;
    int *p;
    p = &n;
   
    cout<<"Enter number: "; cin>>n;
    *p = *p + 7;
    cout<<*p;

    return 0;
}