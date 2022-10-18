// 4. Create a singly linked list for storing information of students. Each student has id, name, and average score. Then write
// a program to ….
// • Create a function to ask for information (id, name, average score) for a student then add her/him to the list. The
// program does not add the student to the list when the input id is already exist in the list.
// • Create a function to display information of all students in the list.

#include <iostream>
using namespace std;


struct Element{
    int averageScore;
    string ID;
    string name;
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

void insertBegin(List *ls, string newID, string newName, int newAverageScore) {
    Element *e;
    e = new Element;
    List * myList;

    e -> ID = newID;
    e -> name = newName;
    e -> averageScore = newAverageScore;    

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

void displayInfoList(List *ls){
    Element *tmp;
    tmp = ls -> head;

    if(tmp == NULL) cout<<"There is no student right now."<<endl;
    while (tmp != NULL)
    {
        cout<<"\n\tStudent ID "<<tmp->ID<<"\n Student Name:\t "<<tmp->name<<"\tAverage Score: \t "<<tmp->averageScore<<endl;
        tmp = tmp -> next;
    }
    
    
}


int main () {

    List * myList;
    string ID, name;
    int averageScore, choice;
    myList = createEmptyList();


    while(choice != 3){
        cout<<"1. Add 2 students: "<<endl;
        cout<<"2. Display all students: "<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Choice: "; cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter student ID: "; cin>>ID;
            cout<<"Enter student name: "; cin>>name;
            cout<<"Enter student average score: "; cin>>averageScore;
            if(isIdExist(myList, ID) == 1) break;
            if(isIdExist(myList, ID) == 0) insertBegin(myList, ID, name, averageScore);
            break;
        case 2:
            displayInfoList(myList);
            break;
        default:
            cout<<"Thank you for using our program.\n";
            break;
        }
    }
    

    return 0;
}