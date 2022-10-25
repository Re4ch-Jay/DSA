#include <iostream>
#include <fstream>
using namespace std;

int main () {

    fstream f;
    int data;

    f.open("data.reach", ios::in);

    while (!f.eof())
    {
        f>>data;
        cout<<" "<<data<<endl;
    }
    
    f.close();
    return 0;
}