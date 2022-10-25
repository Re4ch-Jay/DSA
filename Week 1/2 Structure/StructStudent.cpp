#include <iostream>
#include <string>
using namespace std;
  struct Student {
        string ID;
        string name;
        int age;
    };
int main () {
    Student student[30];

    for (int i = 0; i <= 2; i++)
    {
        cout<<"Student NO "<<i + 1<<endl;
        cout<<"Enter ID: "; cin>>student[i].ID;
        cout<<"Enter name: "; cin>>student[i].name;
        cout<<"Enter age: "; cin>>student[i].age;

    }
    
    for (int i = 0; i <= 2; i++)
    {
        cout<<"\tStudent NO "<<i + 1<<endl;
        cout<<"\n\tStudent ID"<<student[i].ID<<endl; 
        cout<<"\tStudent name"<<student[i].name<<endl; 
        cout<<"\tStudent age"<<student[i].age<<endl; 
    
    }
    
}