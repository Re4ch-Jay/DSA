// Store 20 random numbers in double linked list. Ask a user for a number then add to the linked list. 
// Keep asking user for a new number until the user input 0.
// a. Create a function that can find the maximum and minimum numbers in the linked list.
// b. Computer a simple statistic of data in the linked list. We want to know: average, min, max, and 
// those numbers that are lower than 25.
// c. Display all data in the linked list from the head to the tail and vice versa

#include <iostream>
using namespace std;

struct Element {
    int data;
    Element *next, *previous;
};

struct List {
    Element *head, *tail;
    int size;
};

List * createEmptyList(){
    List * ls;
    ls = new List();
    
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
}

void insertBegin(List *ls , int newData) {
    Element * e;
    e = new Element();

    e->data = newData;
    e->previous = NULL;
    e->next = ls->head;

    

    if(ls->size == 0) {
        ls->tail = e;
    }
    if(ls->size != 0){
        ls->head->previous = e;
    }
    ls->head = e;
    ls->size ++;
}

void insertEnd(List *ls , int newData) {
    Element * e;
    if(ls->size == 0){
        insertBegin(ls, newData);
    }else {
        e = new Element();
        e->data = newData;
        e->next = NULL;
        e->previous = ls->tail;

        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

void displayFromHead(List *ls){
    Element *tmp;
    tmp = ls->head;
    if(tmp == NULL) cout<<"\n\tThere is no data"<<endl;
    else cout<<"\n\tAll data in the list"<<endl;
    while (tmp != NULL)
    {
        
         cout<<"\n\tNumber: "<<tmp->data<<endl;
        tmp = tmp->next;
    }
}


void displayFromTail(List *ls){
    Element *tmp;
    tmp = ls->tail;
    if(tmp == NULL) cout<<"\n\tThere is no data"<<endl;
    else cout<<"\n\tAll data in the list"<<endl;
    while (tmp != NULL)
    {
        cout<<"\n\tNumber: "<<tmp->data<<endl;
        tmp = tmp->previous;
    }   
}

float findMax(List *ls){
    float max = -9999999999; //make assumption
    Element *t;
    t = ls->head;
    while (t != NULL)
    {
        if(t->data > max) {
            max = t->data;
        }
        t = t->next;
    }
    return max;
}

float findMin(List *ls) {
    float min = 9999999999;
    Element *t;
    t = ls->head;
    while (t != NULL)
    {
        if(t->data < min){
            min = t->data;
        }
        t = t->next;
    }
    return min;
}

void findLower25(List *ls){
    float lower = 9999999999;
    Element *t;
    t = ls->head;
    while (t != NULL)
    {   
        if(t->data < 25) {
            lower = t->data;
            cout<<"\tLower than 25 are: "<<lower<<endl;
        }
        t = t->next;
    }
}

float findAverage(List *ls){
    float average = 0;
    Element *t;
    t = ls->head;
    while (t != NULL)
    {   
        average = (t->data + t->next->data) / ls->size;
        t = t->next;
    }
    return average;
}

int main () {

    List * ls;
    ls = createEmptyList();
    int max, min, average, lower, choice, number;
    while (choice != 5)
    {
        cout<<"\t1. Add some number"<<endl;
        cout<<"\t2. Find the maximum and minimum numbers in the linked list"<<endl;
        cout<<"\t3. Find average, min, max, and those numbers that are lower than 25"<<endl;
        cout<<"\t4. Display all data in the linked list"<<endl;
        cout<<"\t5. Exit"<<endl;
        cout<<"\tChoice: "; cin>>choice;

        switch(choice){
            case 1:
                while (number != 0)
                {
                    cout<<"\tEnter number: "; cin>>number;
                    if(number == 0) continue;
                    insertEnd(ls, number);      
                }
                break;
            case 2:
                max = findMax(ls);
                min = findMin(ls);
                cout<<"\n\tMax = "<<max<<endl;
                cout<<"\n\tMin = "<<min<<endl;

                break;
            case 3:
                
                max = findMax(ls);
                min = findMin(ls);
                cout<<"\n\tMax = "<<max<<endl;
                cout<<"\n\tMin = "<<min<<endl;
                findLower25(ls);
    	        cout<<"\n\tAverage is under maintenance, come back later"<<endl;
                break;
            case 4:
                int code;
                cout<<"\t1. Display from head"<<endl;
                cout<<"\t2. Display from tail"<<endl;
                cout<<"\tCode: "; cin>>code;
                if(code == 1) {
                    cout<<"\tAll numbers from head"<<endl;
                    displayFromHead(ls);
                }
                else if(code == 2) {
                    cout<<"\tAll numbers from tail"<<endl;
                    displayFromTail(ls);
                }else{
                    cout<<"\n\tThere is no code you just input"<<endl;
                }
                break;
            default:
                cout<<"\n\tThank for using our program.\n"<<endl;
                break;
        }
       
    }

    return 0;
}