#include <iostream>
using namespace std;

int main() {
   //Display numbers 1 to 1000 on the screen except the numbers 100, 200, 300, 400 and 500.
    int number = 1000;
    for (int i = 0; i <= number; i++)
    {
        if(i == 100) continue;
        if(i == 200) continue;
        if(i == 300) continue;
        if(i == 400) continue;
        if(i == 500) continue;
        cout<<i<<endl;
    }
    return 0;
}