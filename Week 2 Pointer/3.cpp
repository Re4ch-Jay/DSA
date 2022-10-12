#include <iostream>
using namespace std;


int main() {

    int arr[] = {2, 3, 4, 5, 6};
    int *p;

    int length = sizeof(arr) / sizeof(arr[0]);

    p = arr;

    cout<<*p<<endl;
    cout<<*(arr + 1)<<endl;

    for (int i = 0; i < length; i++)
    {
        cout<<*(arr + i)<<endl;
    }
    
    
    return 0;
}