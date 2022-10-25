#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
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

// Function to push the node at the
// beginning of the linked list
void push(struct Element** head_ref, int newSalary)
{
    struct Element* new_node = (struct Element*)malloc(sizeof(struct Element));
 
    new_node->salary = newSalary;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void findLargestAndSecondLargest(List *ls, Element *head)
{
    Element *tmp;
    tmp = ls -> head;
    if(tmp == NULL) cout<<"There is no citizens right now."<<endl;

    int val1 = head->salary,
        val2 = head->next->salary,
        val3 = head->next->next->salary,
        max = std::max(val1, val2),
        second_max = std::min(val1, val2),
        third_max = std::min(val2, val3);

    head = head->next->next;
    
    // iterate over rest of linked list
    while (head != NULL) {
 
        if (head->salary > max) {
 
            second_max = max;
            max = head->salary;
        }
        else if (head->salary > second_max) {
            second_max = head->salary;
        }else{
            third_max = head->salary;
        }
 
        // move the head pointer to next node
        head = head->next;
    }
    cout<<"List of 1s and 2nd largest salary"<<endl;
    cout << "Largest salary = "
         << max <<endl;
    cout << "Second Largest salary = "
         << second_max << endl;
    cout<<"Smallest salary = "<<third_max<<endl;
}


float findMax1(List *ls){
    float max1 = -99999999; //make assumption
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max1) {
            max1 = t->salary;
        }
        t = t->next;
    }
    return max1;
}


float findMax2(List *ls){
    float max2 = -99999999; //make assumption
    float max1 = findMax1(ls);
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max1 && t->salary != max1) {
            max2 = t->salary;
        }
        t = t->next;
    }
    return max2;
}



float findMax3(List *ls){
    float max3 = -99999999; //make assumption
    float max2 = findMax2(ls);
    Element *t;

    t = ls->head;
    while (t != NULL)
    {
        if(t->salary > max3 && t->salary != max3) {
            max3 = t->salary;
        }
        t = t->next;
    }
    return max3;
}

int counter = 0;

void displayMax(List *ls, float max1){
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        if(tmp->salary == max1){
            cout<<"\n\tCitizens ID: "<<tmp->ID<<endl;
            cout<<"\n\tCitizens name: "<<tmp->name<<endl;
            cout<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
            cout<<"\n\tCitizens Salary "<<tmp->salary<<endl;
            counter++;
            if(counter == 3){
                break;
            } 
        }
        tmp = tmp -> next;
    }
    
}


void saveData(List *ls){
    fstream f1;
    f1.open("data.txt", ios::app);
    Element *tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        f1<<"\n\tCitizens ID: "<<tmp->ID<<endl;
        f1<<"\n\tCitizens name: "<<tmp->name<<endl;
        f1<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
        f1<<"\n\tCitizens Salary "<<tmp->salary<<endl;

        
        tmp = tmp->next;
    }
    

    f1.close();
}


void readData(List *ls){
    fstream f;
    int ID;
    string name;
    string gender;
    int salary;

    f.open("data.txt", ios::in);
    Element *tmp;
    tmp = ls->head;
    while (!f.eof())
    {
        f>>ID>>name>>gender>>salary;
        cout<<"\n\tCitizens ID: "<<tmp->ID<<endl;
        cout<<"\n\tCitizens name: "<<tmp->name<<endl;
        cout<<"\n\tCitizens Gender: "<<tmp->gender<<endl;
        cout<<"\n\tCitizens Salary "<<tmp->salary<<endl;
    }
    f.close();    
}