// Write a C++ program to store data and perform statistical analysis for a class of 20 students.
// The information of each student contains ID, Name, Sex, quizzes score (20), mid-term
// score (40), final score (40), and total score (quiz + midterm + final). The program asks the
// user to choose an operation from a menu as shown below. The program keeps running
// never stop.

#include <iostream>
#include<stdio.h>
#include<string.h>
#include <unistd.h>

using namespace std;

struct Student {
    string ID;
    string name;
    string sex;
    int age;
    int quiz;
    int midterm;
    int finalScore;
    int total;
};

int loading(){
    const int trigger = 500; // ms
    const int numDots = 4;
    const char prompt[] = "  Loading";
    long long k = 0;
    while (1 && k < 1) {
        // Return and clear with spaces, then return and print prompt.
        printf("\r%*s\r%s", sizeof(prompt) - 1 + numDots, "", prompt);
        fflush(stdout);

        // Print numDots number of dots, one every trigger milliseconds.
        for (int i = 0; i < numDots; i++) {
            usleep(trigger * 1000);
            fputc('.', stdout);
            fflush(stdout);
        }
        k += 1;
    }
}

int main() {

    Student student[20];

    int length = 0;
    int choice;
    string findId; int i;
    float average;
    int min, max;

    
    while (choice != 6)
    {
        loading();
        cout<<"\n***********************"<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"***********************"<<endl;
        cout<<"1. Add 2 students"<<endl;
        cout<<"2. Display all student information"<<endl;
        cout<<"3. Show students who gets the max total score"<<endl;
        cout<<"4. Display a student information by ID (search by an ID)"<<endl;
        cout<<"5. Find min, max, and average scores for this class."<<endl;
        cout<<"**********************"<<endl;
        cout<<"6. Exit Program."<<endl;
        cout<<"Choose your option 1-6:"; cin>>choice;
        
        switch(choice){
            case 1:
                
                for (int i = 0; i < 2; i++){
                    
                    cout<<"INPUT CAR NO:" << i + 1 <<endl;
                    cout<<"Enter ID: "; cin>>student[i].ID; 
                    cout<<"Enter name: "; cin>>student[i].name;
                    cout<<"Enter sex: "; cin>>student[i].sex; 
                    cout<<"Enter age: "; cin>>student[i].age; 
                    cout<<"Enter quiz: "; cin>>student[i].quiz; 
                    cout<<"Enter midterm: "; cin>>student[i].midterm; 
                    cout<<"Enter final score: "; cin>>student[i].finalScore; 
                    length++;
                    student[i].total = student[i].quiz + student[i].midterm + student[i].finalScore;
                    
                }
                loading();
                break;
            case 2:
                loading();
                for (int i = 0; i < length; i++){
                    cout<<"INPUT Student NO:" << i + 1 <<endl;
                    cout<<"\tID "<<student[i].ID<<endl; 
                    cout<<"\tName "<<student[i].name<<endl; 
                    cout<<"\tSex "<<student[i].sex<<endl; 
                    cout<<"\tAge "<<student[i].age<<endl; 
                    cout<<"\tQuiz "<<student[i].quiz<<endl; 
                    cout<<"\tMidterm "<<student[i].midterm<<endl; 
                    cout<<"\tFinal "<<student[i].finalScore<<endl; 
                }
                
                break;
            case 3:
                for (int i = 1; i < length; ++i) {
                    if (student[0].total < student[i].total) student[0] = student[i];
                    
                }
                cout<<"Student with highest score is: "<<student[0].name<<endl;
                break;
            case 4:
                
                cout<<"Enter student ID: "; cin>>findId;
                for ( i = 0; i < length; i++){
                    if(student[i].ID == findId){
                        cout<<"Student with this id "<<findId<<endl;
                        cout<<"\tName "<<student[i].name<<endl; 
                        cout<<"\tSex "<<student[i].sex<<endl; 
                        cout<<"\tAge "<<student[i].age<<endl; 
                        cout<<"\tQuiz "<<student[i].quiz<<endl; 
                        cout<<"\tMidterm "<<student[i].midterm<<endl; 
                        cout<<"\tFinal "<<student[i].finalScore<<endl;
                        break;
                    }
                }
                if (i == length) cout<<"ID of "<<findId<<" isn't present in the array."<<endl;
                break;
            case 5: 
                max = student[0].total;
                min = student[0].total;
                for(int i=0; i < length; i++)
                {
                    if(student[i].total > max) max = student[i].total;
                    
                    if(student[i].total < min) min = student[i].total;
                    
                    average = min + max;
                }
                cout<<"Max = "<<max<<endl;
                cout<<"Min = "<<min<<endl;
                cout<<"Average = "<<average / length<<endl;
                break;
            default:
                cout<<"\n\nThank for using our program\n"<<endl;
                break;
            }
    
    }

    return 0;

}