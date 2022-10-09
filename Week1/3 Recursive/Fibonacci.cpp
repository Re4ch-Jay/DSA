#include <iostream>
using namespace std;

int fibonacci (int number) {
    if(number == 1 || number == 2){
        return 1;
    } else{
        return fibonacci(number-1) + fibonacci(number-2);   
    }
}

int main () {
    int result = fibonacci(10);
    cout<<result<<endl;
}