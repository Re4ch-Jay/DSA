// Write a function to return the roots of a quadratic equation via function parameter by
// passing as pointer. Here is the prototype of this function:
// void solveQuadratic(int a, int b, int c, float *x1, float *x2);
#include <iostream>
#include <cmath>
using namespace std;

void solveQuadratic(int a, int b, int c, float *x1, float *x2){
    float discriminant, realPart, imaginaryPart;
    discriminant = b*b - 4*a*c;
    
    if (discriminant > 0) {
        *x1 = (-b + sqrt(discriminant)) / (2*a);
        *x2 = (-b - sqrt(discriminant)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "x1 = " << *x1 << endl;
        cout << "x2 = " << *x2 << endl;
    }
    
    else if (discriminant == 0) {
        cout << "Roots are real and same." << endl;
        *x1 = -b/(2*a);
        cout << "x1 = x2 =" << *x1 << endl;
    }

    else {
        realPart = -b/(2*a);
        imaginaryPart =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
        cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
    }
}

int main() {

    float a, b, c, x1, x2;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;
    solveQuadratic(a, b, c, &x1, &x2);
  

    return 0;
}