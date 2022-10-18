#include <iostream>

using namespace std;

int sumSuite(int n){
    int sum = 0;
    for (int i = 0; i <= n; i++){
        cout<<i;
        sum = sum + i;
        if(i == n){
            cout<<"=";
        }else{
            cout<<"+";
        }
    }
    cout<<sum<<"\n\n";
    return sum;
}

float convertCelsuis(float celsuis){
    float fahrenheit;
    // Celsius to fahrenheit
    fahrenheit = (celsuis * 9.0) / 5.0 + 32;
    
    // Display result
    return fahrenheit;
}
float convertFarenheit(float farenheit){
    float celsuis;
    celsuis=(farenheit - 32) * 5/9;
    return celsuis;
}
int sumDigit(int n){
    int sum = 0, m;
    while(n > 0) {    
        m = n % 10;    
        sum = sum + m;    
        n = n / 10;    
    }    
    return sum;    
}