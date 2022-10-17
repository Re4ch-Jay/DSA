// Write a C++ program to ask a user for 7 integer numbers and store in an array. Then write
// a function that returns the min and max values of this array. The prototype of this function
// is void findMinMax(int number[7], int *min, int *max);

#include <iostream>
using namespace std;

void findMinMax(int numbers[7], int length, int *min, int *max)
{

    int i;
    for (i = 1; i <= length; i++)
    {
        if (*min > numbers[i])
        {
            *min = numbers[i];
        }
        if (*max < numbers[i])
        {
            *max = numbers[i];
        }
    }
    cout << "min: " << *min << endl;
    cout << "max: " << *max << endl;    
}
int main() {
    int number[7];
    int max, min, length;
    cout<<"Enter 7 numbers: \n";
    length = sizeof(number) / sizeof(number[0]);

    for (int i = 1; i <= length; i++)
    {
        cin>>number[i];
    }
    findMinMax(number, length, &max, &min);
    
    return 0;
}
