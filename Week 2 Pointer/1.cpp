#include <iostream>
using namespace std;

int main() {

    int n = 10;
    int *p;
    p = &n;

    cout<<p<<endl;
    cout<<&n<<endl;
    cout<<&p<<endl;

    cout<<*p<<endl;
    cout<<n<<endl;
    n = n + 10;
    cout<<*p<<endl;
    return 0;
}