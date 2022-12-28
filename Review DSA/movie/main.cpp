#include <iostream>
#include "hash.hpp"
using namespace std;

int main() {
    Movie movie;
    initializeList();
    char choice;

    do
    {
        cout<<"1. Add movie to table"<<endl;
        cout<<"2. View movies in the table"<<endl;
        cout<<"3. Search movies in the table"<<endl;
        cout<<"4. Delete movies by id"<<endl;
        cout<<"0. Exit"<<endl;   
        cout<<"Choice: "; cin>>choice;
        switch (choice)
        {
        case '1':
            insert(movie);
            break;
        case '2':
            displayTable();
            break;
        case '3':
            search(movie);
            break;
        case '4':
            searchAndDelete(movie);
            break;
        case '0':
            break;
        default:
            cout<<"Wrong inpuit"<<endl;
            break;
        }
    } while (choice != '0');
    

    return 0;
}