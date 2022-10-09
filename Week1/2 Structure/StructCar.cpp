#include <iostream>
#include <string>
using namespace std;
  struct Car {
        string brand;
        string model;
        string ID;
    };

int main() {

    Car car[30];
  
    // GET Input
    for (int i = 0; i <= 5; i++)
    {
        cout<<"INPUT CAR NO:" << i + 1<<endl;
        cout<<"Enter ID: ";
        cin>>car[i].ID; 
        cout<<"Enter Brand: ";
        cin>>car[i].brand; 
        cout<<"Enter model: ";
        cin>>car[i].model; 
    }
    
    // POST Input
    for (int i = 0; i <= 5; i++)
    {
        cout<<"\tCar NO: "<< i + 1<<endl;
        cout<<"Car ID\t"<<car[i].ID<<endl;
        cout<<"Car brand\t"<<car[i].brand<<endl;
        cout<<"Car model\t"<<car[i].model<<endl;
        
    }
   
    return 0;
}
