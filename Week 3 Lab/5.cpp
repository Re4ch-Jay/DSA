// Create a singly linked list for storing information of citizen. Each citizen has person ID, name, gender and monthly
// income. Then write a program that is be able to do the following operations. Create 4 functions for these operations.
// a. Ask for information (person ID, name, gender and monthly income) for a citizen then add her/him to list. The
// program does not add the citizen to list when the input person ID is already exist in the list.
// b. Display information of all citizen in the list.
// c. Search for a citizen by his/her ID or name
// d. Display the top 3 citizens that have the highest monthly income

#include <iostream>
using namespace std;


struct Element{
    string ID;
    string name;
    string gender;
    int salary;
    Element *next;
};

struct List {
    int size;
    Element *head, *tail;

};

List* createEmptyList() {
    List *ls;
    ls = new List;

    ls -> size = 0;
    ls -> head = NULL;
    ls -> tail = NULL;

    return ls;
}

void insertBegin(List *ls, string newID, string newName, string newGender, int newSalary) {
    Element *e;
    e = new Element;
    List * myList;

    e -> ID = newID;
    e -> name = newName;
    e -> gender = newGender;  
    e -> salary = newSalary;    

    e -> next = ls->head;
    ls -> head = e;
    
    if(ls-> size == 0) {
        ls -> tail = e;
        
    }
    
    // increase size of data
    ls -> size++;
}

// Returns true if the value exists in the list.
int isIdExist(List * ls, string checkID) {
      Element * e;
      e = ls -> head;
      int result = 0;
      while(e != NULL)
      {
            if(e->ID == checkID)
            {
                    result = 1;
                    cout<<"This ID is already existed"<<endl;
                    break;
            }
            e = e -> next;
      }
      return result;
}

// Returns true if the value exists in the list.
int isNameExist(List * ls, string checkName) {
      Element * e;
      e = ls -> head;
      int result = 0;
      while(e != NULL)
      {
            if(e->name == checkName)
            {
                    result = 1;
                    cout<<"This name is already existed"<<endl;
                    break;
            }
            e = e -> next;
      }
      return result;
}

void displayInfoList(List *ls){
    Element *tmp;
    tmp = ls -> head;

    if(tmp == NULL) cout<<"There is no citizens right now."<<endl;
    while (tmp != NULL)
    {
        cout<<"\n\tCitizens ID: "<<tmp->ID<<endl;
        cout<<"\n\tCitizens name: "<<tmp->name<<endl;
        cout<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
        cout<<"\n\tCitizens Salary "<<tmp->salary<<endl;
    
        tmp = tmp -> next;
    }
}

void searchCitizensById(List *ls, string newID){

    Element *tmp;
    int counter = 0;

    tmp = ls -> head;
    while (tmp != NULL)
    {
        if(tmp -> ID == newID){
            cout<<"\n\tCitizens ID: "<<tmp->ID<<endl;
            cout<<"\n\tCitizens name: "<<tmp->name<<endl;
            cout<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
            cout<<"\n\tCitizens Salary "<<tmp->salary<<endl;
            counter++;
        }
        tmp = tmp -> next;
       
    }
    if(counter == 0) {
        cout<<"No data found"<<endl;
    }
}


void searchCitizensByName(List *ls, string newName){

    Element *tmp;
    int counter = 0;

    tmp = ls -> head;
    while (tmp != NULL)
    {
        if(tmp -> name == newName){
            cout<<"\n\tCitizens ID: "<<tmp->ID<<endl;
            cout<<"\n\tCitizens name: "<<tmp->name<<endl;
            cout<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
            cout<<"\n\tCitizens Salary "<<tmp->salary<<endl;
            counter++;
        }
        tmp = tmp -> next;
       
    }
    if(counter == 0) {
        cout<<"No data found"<<endl;
    }
}

// Function to print the largest
// and second largest element
void findLargestAndSecondLargest(Element* head)
{
    // initialise max and second max using
    // first two nodes of linked list
    int val1 = head->salary,
        val2 = head->next->salary,
        max = std::max(val1, val2),
        second_max = std::min(val1, val2);
 
    // move the head pointer to 3rd node
    head = head->next->next;
 
    // iterate over rest of linked list
    while (head != NULL) {
 
        if (head->salary > max) {
 
            
            second_max = max;
            max = head->salary;
        }
        else if (head->salary > second_max) {
 
            second_max = head->salary;
        }
 
        // move the head pointer to next node
        head = head->next;
    }
 
    // Print the largest
    // and second largest value
    cout << "Largest = "
         << max << endl;
    cout << "Second Largest = "
         << second_max << endl;
}
 

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
                cout<<"Input the valid choice"<<endl;
            }
            break;
        case 4:
            findLargestAndSecondLargest(head);
            break;
        default:
            cout<<"Thank you for using our program.\n";
            break;
        }
    }

    return 0;
}