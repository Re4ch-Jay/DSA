#include <iostream>
using namespace std;

int summation (int number) {
    if(number > 1) {
        return number + summation(number-1);
    }else{
        return 1;
    }
}

int main () {
    int result = summation(3);
    cout<<result<<endl;
}