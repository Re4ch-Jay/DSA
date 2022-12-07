#include <iostream>
#include <string>
using namespace std;

int convertToASCII(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        //cout << (int)s[i]<< endl;
        sum += (int)s[i];
    }
    return sum;
}

int main()
{
    string plainText;
    cout << "Enter text to convert to ASCII: ";
    getline(cin,plainText);
    convertToASCII(plainText);
    return 0;
}