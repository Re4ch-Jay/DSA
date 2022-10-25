#include <iostream>
using namespace std;

int factorial (int number) {
    if(number == 0 || number == 1)
        return 1;
    else 
        return number * factorial(number-1);
}

void displayOneToN (int number) {
    if(number == 1){
        cout<<" "<<number;
    }else{
        cout<<" "<<number;
        displayOneToN(number - 1);
    }
}

int main () {
    displayOneToN(10);
    int result, number;
    cout<<"\n\nEnter number: "; cin>>number;
    if(number < 0) cout<<"Cannot below zero";
    else {
        result = factorial(number);
        cout<<number<<" fatorial: "<<result<<endl;
    }

    
}