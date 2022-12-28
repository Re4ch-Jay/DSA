#include <iostream>
using namespace std;

struct Movie {
    int id;
    string title;
    string category;
    string author;
};

struct Element {
    Movie movie;
    Element * next;
};

struct List {
    Element * head, * tail;
    int size;
};

const int SIZE = 10;
List * table[SIZE];

List * createList() {
    List * ls;
    ls = new List();
    ls->head = NULL;
    ls->tail = NULL;
    ls->size = 0;
    return ls;
}

void initializeList() {
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = createList();
    }
}

void addEnd(List *ls, Movie movie) {
    Element * e;
    e = new Element();
    e->next = NULL;
    e->movie.author = movie.author;
    e->movie.id = movie.id;
    e->movie.title = movie.title;
    e->movie.category = movie.category;
    if(ls->size == 0){
        ls->head = e;
        ls->tail = e;
    }else{
        ls->tail->next = e;
        ls->tail = e;
    }
    ls->size++;
}

int hashFunction(Movie movie){  
    return movie.id % SIZE;
}

void insert(Movie movie) {
    char choice;
    cout<<"1. Input movie id: "; cin>>movie.id;
    cout<<"2. Input movie title: "; cin>>movie.title;
    cout<<"3. Input movie author: "; cin>>movie.author;
    do
    {
        cout<<"4. Input movie category (1. Scifi 2. Horror 3. Adventure 4. History): "; 
        cin>>choice;
        switch(choice){
            case '1':
                movie.category = "Scifi";
                break;
            case '2':
                movie.category = "Horror";
                break;
            case '3':
                movie.category = "Adventure";
                break;
            case '4':
                movie.category = "History";
                break;
            default:
                cout<<"Wrong input"<<endl;
                break;
            if(movie.category  == "Scifi" || movie.category  == "Horror"|| movie.category  == "Adventure" || movie.category  == "History") {
                break;
            }
        }
        
    } while (!(movie.category  == "Scifi" || movie.category  == "Horror"|| movie.category  == "Adventure" || movie.category  == "History"));

    int index; 
    index = hashFunction(movie);
    addEnd(table[index], movie);
}

void displayTable() {
    Element * tmp;
    cout<<"\tID: \tTitle: \tAuthor: \tCategory"<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        if(table[i] != NULL){
            tmp = table[i]->head;
            while (tmp != 0)
            {
                cout<<"\t"<<tmp->movie.id<<"\t"<<tmp->movie.title<<"\t"<<tmp->movie.author<<"\t"<<tmp->movie.category<<endl;
                tmp = tmp->next;
            }
        }
    }
}

void search(Movie movie){
    int index;
    index = hashFunction(movie);
    if(table[index]->head->movie.id == movie.id){
        cout<<"\tID: \tTitle: \tAuthor: \tCategory"<<endl;
        cout<<table[index]->head->movie.id<<"\t";
        cout<<table[index]->head->movie.title<<"\t";
        cout<<table[index]->head->movie.author<<"\t";
        cout<<table[index]->head->movie.category<<"\t\n";
    }else if (table[index]->tail->movie.id == movie.id) {
        cout<<"\tID: \tTitle: \tAuthor: \tCategory"<<endl;
        cout<<table[index]->tail->movie.id<<"\t";
        cout<<table[index]->tail->movie.title<<"\t";
        cout<<table[index]->tail->movie.author<<"\t";
        cout<<table[index]->tail->movie.category<<"\t\n";
    }else{
        cout<<"Could not find any data with this id "<<movie.id<<endl;
    }
}

void searchAndDelete(Movie movie){
    int index;
    index = hashFunction(movie);
    if(table[index]->head->movie.id == movie.id){
        table[index]->head->movie.id = 0;
        table[index]->head->movie.title = '0';
        table[index]->head->movie.author= '0';
        table[index]->head->movie.category = '0';
    }else if (table[index]->tail->movie.id == movie.id) {
        table[index]->tail->movie.id = 0;
        table[index]->tail->movie.title = '0';
        table[index]->tail->movie.author= '0';
        table[index]->tail->movie.category = '0';
    }else{
        cout<<"Could not find any data with this id "<<movie.id<<endl;
    }
}