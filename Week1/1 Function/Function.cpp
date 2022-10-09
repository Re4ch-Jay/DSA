#include <iostream>
#include <string>
using namespace std;
int count (int n) {
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
    cout<<sum<<endl;
    return sum;
};

int main() {

    int number;
    cout<<"enter number: ";
    cin>>number;
    cout<<"Sum is: "<<count(number)<<endl;


    return 0;
}
