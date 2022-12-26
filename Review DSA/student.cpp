#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

struct Student {
    int id;
    string name;
    string major;
    char grade;
    double overallScore;
};

struct Element {
    Student student;
    Element * next;
};

struct List {
    int size;
    Element * head, *tail;
};

List * createList() {
    List * ls;
    ls = new List();
    ls->size = 0;
    ls->head = NULL;
    ls->tail = NULL;   

    return ls;
}

void insertEnd(List * ls){
    Student newStudent;
    cout<<"Student name: "; cin>>newStudent.name;
    cout<<"Student grade: "; cin>>newStudent.grade;
    cout<<"Student major: "; cin>>newStudent.major;
    cout<<"Student overall score: "; cin>>newStudent.overallScore;

    Element * e;
    e = new Element();
    e->next = NULL;
    e->student.id = time(NULL);
    e->student.grade = newStudent.grade;
    e->student.major = newStudent.major;
    e->student.name = newStudent.name;
    e->student.overallScore = newStudent.overallScore;

    if(ls->size == 0){
        ls->head = e;
        ls->tail = e;
    }else{
        ls->tail->next = e;
        ls->tail = e;
    }
    ls->size++;
}

void deleteBegin(List *ls) {
    Element * tmp;
    if(ls->size == 0) {
        cout<<"Cannot delete"<<endl;
    }else{
        tmp = ls->head;
        ls->head = ls->head->next;
        delete tmp;
        ls->size--;
    }
}

int search(List *ls) {
    int flag;
    Student student;
    cout<<"Enter student id to search: "; cin>>student.id;
    Element * tmp;
    tmp = ls->head;
    while (tmp != NULL)
    {
        if(tmp->student.id == student.id){
            cout<<"Student id: "<<tmp->student.id<<endl;
            cout<<"Student name: "<<tmp->student.name<<endl;
            cout<<"Student major: "<<tmp->student.major<<endl;
            cout<<"Student grade: "<<tmp->student.grade<<endl;
            cout<<"Student overall score: "<<tmp->student.overallScore<<endl;

            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void searchByIdAndDelete(List *ls){   
    Student student;
    cout<<"Enter student id to search: "; cin>>student.id;
    if(ls->size >= 1) {
        Element *tmp;
        Element *e;
        e = new Element();
        if(ls->head->student.id == student.id)
        {
            tmp = ls->head;   
            ls->head = ls->head->next;
            delete tmp;
        }
        else
        {
            e = ls->head;
            while(e->next != NULL)
            {

                if(e->next->student.id == student.id)
                {   
                    tmp = e->next;
                    e->next = e->next->next;
                    delete tmp;
                    break;
                }
                e = e->next;
            }
        }
    }else{
        cout<<"No data to delete"<<endl;
    }
}

void deleteAll(List *ls) {

    while (ls->size > 0)
    {
        deleteBegin(ls);
    }
    
}

void displayData(List * ls) {
    if(ls->size == 0) {
        cout<<"There is no data"<<endl;
    }else{
        Element * tmp;
        tmp = ls->head;
        
        while (tmp != NULL)
        {
            cout<<endl;
            cout<<"Student id: "<<tmp->student.id<<endl;
            cout<<"Student name: "<<tmp->student.name<<endl;
            cout<<"Student major: "<<tmp->student.major<<endl;
            cout<<"Student grade: "<<tmp->student.grade<<endl;
            cout<<"Student overall score: "<<tmp->student.overallScore<<endl;
            tmp = tmp->next;
        }
    }
}

void readDataFromFile() {
    ifstream read;
    read.open("data.txt");
    std::string myline;
    if ( read.is_open() ) {
        while ( read ) { 
            getline (read, myline);
            cout << myline << '\n';
            getline (read, myline);
            cout << myline << '\n';
            getline (read, myline);
            cout << myline << '\n';
            getline (read, myline);
            cout << myline << '\n';
            getline (read, myline);
            cout << myline << '\n';
            getline (read, myline);
            cout << myline << '\n';
        }
    }
    else {
        cout << "Couldn't open file\n";
    }
}

void displayAverageScore(List * ls) {
    double average;
    double sum = 0;
    if(ls->size == 0) {
        cout<<"There is no data"<<endl;
    }else{
        Element * tmp;
        tmp = ls->head;
        while (tmp != NULL)
        {
            sum += tmp->student.overallScore;
            tmp = tmp->next;
        }
        average = sum / ls->size;
        cout<<"Average overall score: "<<average<<endl;
    }
}

void saveData(List * ls) {
    fstream write;
    write.open("data.txt", ios::app);
    if(ls->size == 0) {
        cout<<"There is no data"<<endl;
    }else{
        Element * tmp;
        tmp = ls->head;
        
        while (tmp != NULL)
        {
            write<<endl;
            write<<"Student id: "<<tmp->student.id<<endl;
            write<<"Student name: "<<tmp->student.name<<endl;
            write<<"Student major: "<<tmp->student.major<<endl;
            write<<"Student grade: "<<tmp->student.grade<<endl;
            write<<"Student overall score: "<<tmp->student.overallScore<<endl;
            tmp = tmp->next;
        }
    }
    write.close();
    cout<<"Data save to file"<<endl;
}


int main() {

    Student student;
    List * list;
    list = createList();
    char choice;
    int flag;
    do
    {
        system("pause");
        cout<<"\n1. Insert student information"<<endl;
        cout<<"2. View all students"<<endl;
        cout<<"3. Search student by id"<<endl;
        cout<<"4. Delete student by id"<<endl;
        cout<<"5. Delete all students"<<endl;
        cout<<"6. Display average score"<<endl;
        cout<<"7. Save data"<<endl;
        cout<<"8. Read data"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Choice: ";
        cin>>choice;
        switch (choice)
        {
        case '1':
            system("cls");
            insertEnd(list);
            break;
        case '2':
            system("cls");
            displayData(list);
            break;
        case '3':
            system("cls");
            flag = search(list);
            if(flag == 0){
                cout<<"There is no data with this id"<<endl;
            }
            break;
        case '4':
            system("cls");
            searchByIdAndDelete(list);
            break;
        case '5':
            deleteAll(list);
            break;
        case '6':
            system("cls");
            displayAverageScore(list);
            break;
        case '7':
            system("cls");
            saveData(list);
            break;
        case '8':
            system("cls");
            readDataFromFile();
            break;
        case '0':
            system("cls");
            cout<<"Thanks"<<endl;
            break;
        default:
            system("cls");  
            cout<<"Wrong input"<<endl;
            break;
        }
    } while (choice != '0');
    return 0;
}