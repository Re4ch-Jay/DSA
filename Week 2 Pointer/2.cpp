#include <iostream>
using namespace std;

void swapData(int *a, int *b){
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
    cout<<*a<<"\t"<<*b<<endl;
}

int main() {
    int a = 10, b = 20;
    swapData(&a, &b);

    return 0;
}