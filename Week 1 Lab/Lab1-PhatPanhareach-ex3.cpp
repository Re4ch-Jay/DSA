#include <iostream>
using namespace std;

int main() {
    //Ask a user to input a number. Keep asking the user for more numbers until the user inputs -1. Display
    //the total summation of all input numbers except -1. 

    int number, sum = 0;
    
    int i = 0;
    while (number != -1){
        cout<<"Enter number: "; cin>>number;
        
        if(number == -1){
            break;
        }
        sum = sum + number;
        
    }
    cout<<"Answer of sumation: "<<sum<<endl;
    return 0;
}