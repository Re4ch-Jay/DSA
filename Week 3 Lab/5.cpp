// Create a singly linked list for storing information of citizen. Each citizen has person ID, name, gender and monthly
// income. Then write a program that is be able to do the following operations. Create 4 functions for these operations.
// a. Ask for information (person ID, name, gender and monthly income) for a citizen then add her/him to list. The
// program does not add the citizen to list when the input person ID is already exist in the list.
// b. Display information of all citizen in the list.
// c. Search for a citizen by his/her ID or name
// d. Display the top 3 citizens that have the highest monthly income

#include <iostream>
#include "linkedList.hpp" // all function of this program is in linkedList.hpp
using namespace std;

int main () {

    List * myList;  
    Element * head;
    string ID, name, gender;
    int salary, choice;
    myList = createEmptyList();


    while(choice != 5){
        cout<<"1. Add citizens: "<<endl;
        cout<<"2. Display all citizens: "<<endl;
        cout<<"3. Search citizens by ID or Name: "<<endl;
        cout<<"4. Display the top 3 citizens that have the highest monthly income: "<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choice: "; cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter citizens ID: "; cin>>ID;
            cout<<"Enter citizens name: "; cin>>name;
            cout<<"Enter citizens gender: "; cin>>gender;
            cout<<"Enter citizens salary: "; cin>>salary;
            if(isIdExist(myList, ID) == 1) break;
            if(isIdExist(myList, ID) == 0) insertBegin(myList, ID, name, gender, salary);
            break;
        case 2:
            displayInfoList(myList);
            break;
        case 3:
            int choice2;
            cout<<"Search by ID = 1 or Name = 2: "; cin>>choice2;
            if(choice2 == 1) {
                cout<<"Input citizens ID: "; cin>>ID;
                cout<<endl;
                searchCitizensById(myList, ID);
            }else if (choice2 == 2){
                cout<<"Input citizens name: "; cin>>name;
                cout<<endl;
                searchCitizensByName(myList, name);
            }else{
                cout<<"\tPlease input the valid choice"<<endl;
                break;
            }
            break;
        case 4:
            cout<<"\n\tOn maintenance"<<endl;
            // findLargestAndSecondLargest(head);
            break;
        default:
            cout<<"Thank you for using our program.\n";
            break;
        }
    }

    return 0;
}