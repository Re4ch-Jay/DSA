#include <iostream>
using namespace std;

float sumSuite(float n){
    int sum = 0;
    cout<<"(";
    for (int i = 0; i <= n; i++){
        cout<<i;
        sum = sum + i;
        i == n ? cout<<") / "<<n<<" = " : cout<<"+";
    }
    return sum / n;
}

int main() {
    float number;
    cout<<"Enter number: "; cin>>number;
    cout<<"Sum is: "<<sumSuite(number)<<endl;
    return 0;
}