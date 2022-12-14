// Write a C++ program which calculates the sum 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/n, where n is
// a positive integer. The program contains two functions which both calculate the sum. The
// prototypes of these two functions are as follows:
// void sum1(double *sum, unsigned int n);
// double sum2(unsigned int n);


#include <iostream>
using namespace std;

void sum1(double *sum, unsigned int n){

    float sum1 = 0.00;
    for(float i = 1; i <= n; i++){
        sum1 = sum1 + (1 / i);
    }
    cout<<"Sum with poiner: "<<sum1<<endl;
}


double sum2(unsigned int n){
   float sum = 0.00;
   for(float i = 1; i <= n; i++){
      sum = sum + (1 / i);
   }
   return sum;
    
}

int main() {

    unsigned int n;
    double sum;
    cout<<"Enter number: "; cin>>n;

    sum1(&sum, n);
    cout<<"Sum with none pointer: "<<sum2(n)<<endl;
    

    return 0;
}