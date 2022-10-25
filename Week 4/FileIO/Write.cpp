#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream data;
  data.open("data.reach", ios::app);
  data<<"Hello bro"<<endl;

  for (int i = 0; i <= 10; i++)
  {
    data<<"Test "<<i<<endl;
  }
  

  data.close();
}