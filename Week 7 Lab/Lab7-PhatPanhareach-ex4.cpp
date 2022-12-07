// 4. Create a hash table to store key-value data for 15 students.
// A student has ID, name, sex, phone and major.
// • A student’s ID will be taken as a key which is used as a parameter for the hash
// function. The value to be inserted to an array slot at the position defined by the hash
// function is a student info of that ID.
// • To avoid collision, you have to apply collision resolution technique called chaining
// (implement hash table as array of linked list).
// • The hash function of this hash table is to generate the ID into an index of the array.
// Since ID can be a string, this hash function may be the same as hash function in
// Exercise #3.
// To test this program, enter information of 5 students (your friends) then
// a. Insert their information to the hash table.
// b. Finally, display all data in hash table.
// c. Study the case that has duplicate data so that your program is still working well
// since we apply collision resolution technique.

#include <iostream>

using namespace std;


struct Element {
    string ID, name, sex, major;
    int phone;
    Element * next;
};

struct List {
    int size;
    Element * head, *tail;
};

const int SIZE = 15;
List * ht[SIZE];

List * createEmptyList(){
    List * ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;

    return ls;
}

void initializeAllList() {
    for (int i = 0; i < SIZE; i++)
    {
        ht[i] = createEmptyList();
    }
    
}

void addEnd(List *ls, string ID, string name, string major, int phone, string sex){
    Element * e;
    e = new Element();
    e->next = NULL;

    e->ID = ID;
    e->name = name;
    e->major = major;
    e->phone = phone;
    e->sex = sex;

    if(ls->size == 0) {
        ls->head = e;
        ls->tail = e;
        ls->size++;
    }else{
        ls->tail->next = e;
        ls->tail = e;
        ls->size++;
    }
}

int convertToASCII(string ID) {
    int sum = 0;
    for (int i = 0; i < ID.length(); i++)
    {
        sum += (int)ID[i];
    }
    return sum;
}


int hashFunction(string ID) {
    int code = convertToASCII(ID);
    return code % SIZE;
}

void insertData(string ID, string name, string major, int phone, string sex) {
    int index;
    index = hashFunction(ID);
    addEnd(ht[index], ID, name, major, phone, sex);
}

void displayData() {
    Element * tmp;
    for (int i = 0; i < SIZE; i++)
    {
        cout<<i<<"->";
        if (ht[i] != NULL)
        {
            tmp = ht[i]->head;
            while (tmp != NULL)
            {
                cout<<"\tID: "<<tmp->ID<<"\tName: "<<tmp->name<<"\tMajor: "<<tmp->major<<"\tPhone: "<<tmp->phone<<"Sex: "<<tmp->sex;
                tmp = tmp->next;
            }
        }
        cout<<endl;
    }
}

void search(string ID) {
    int find = hashFunction(ID);
    if(ht[find]->head->ID == ID){
        cout<<"\tID: "<<ht[find]->head->ID<<"\tName: "<<ht[find]->head->name<<"\tMajor: "<<ht[find]->head->major<<"\tPhone: "<<ht[find]->head->phone<<"\tSex: "<<ht[find]->head->sex<<endl;
    }else{
        cout<<"Data not found with this ID "<<ID<<endl;
    }
}



int main () {
    
    initializeAllList();

    cout<<"Insert search"<<endl;
    insertData("001", "Reach", "CS", 12345678, "M");
    insertData("002", "Reach", "CS", 12345678, "M");
    insertData("002", "Reach", "CS", 12345678, "M");

    displayData();
    cout<<"After search"<<endl;
    search("001");


    return 0;
}