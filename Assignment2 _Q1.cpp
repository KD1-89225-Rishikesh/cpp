/*
* Assignment 2
* Q1. Write a menu driven program for Date in a CPP language using structure and also using class. 
* Date is having data members day, month, year. Implement the following functions. 
* void initDate(); 
* void printDateOnConsole(); 
* void acceptDateFromConsole(); 
* bool isLeapYear(); 
* 
*/

#include <iostream> 

using namespace std;

struct Date {
    private :
        int day;   
        int month; 
        int year;  

    public : 
        void initDate() {
            day=1, month=1, year=1000;
        }
        
        void printDateOnConsole() {
            cout<<"Date : "<<day<<"-"<<month<<"-"<<year<<endl;
        }

        void acceptDateFromConsole() {
            cout<<"Enter the day : ";
            cin>>day;
            cout<<"Enter the month : ";
            cin>>month;
            cout<<"Enter the year : ";
            cin>>year;
        } 

        bool isLeapYear() {
            if (year%400 == 0) 
                return true;
            else if (year%100 == 0)
                return false;
            else if (year%4 == 0)
                return true;
            else 
                return false;
        }
};

class DateClass {
    private :
        int day;   
        int month; 
        int year;  

    public : 
        void initDate() {
            day=1, month=1, year=1000;
        }
        
        void printDateOnConsole() {
            cout<<"Date : "<<day<<"-"<<month<<"-"<<year<<endl;
        }

        void acceptDateFromConsole() {
            cout<<"Enter the day : ";
            cin>>day;
            cout<<"Enter the month : ";
            cin>>month;
            cout<<"Enter the year : ";
            cin>>year;
        } 

        bool isLeapYear() {
            if (year%400 == 0) 
                return true;
            else if (year%100 == 0)
                return false;
            else if (year%4 == 0)
                return true;
            else 
                return false;
        }
};

void printIsLeapYear(bool *leap) {
    cout<<"Is this leap year? : ";
    if(*leap) 
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
}

int menu() {
    int choice;
    cout << "\n\n0. EXIT" << endl;
    cout << "1. Accept the Date" << endl;
    cout << "2. Display the Date" << endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    return choice;
}
 


int main() {
    int choice;
    bool isLeap;
    struct Date d1; 
    DateClass d2;

    d1.initDate();
    d2.initDate();

    do {
        choice = menu();
        switch(choice) {
            case 0 : 
                cout<<"Thank you!"; 
                break;

            case 1 : 
                d1.acceptDateFromConsole();
                isLeap = d1.isLeapYear();
                printIsLeapYear(&isLeap);

                d2.acceptDateFromConsole();
                isLeap = d2.isLeapYear();
                printIsLeapYear(&isLeap);
                break;

            case 2 : 
                d1.printDateOnConsole();
                isLeap = d1.isLeapYear();
                printIsLeapYear(&isLeap);

                d2.printDateOnConsole();
                isLeap = d2.isLeapYear();
                printIsLeapYear(&isLeap);
                break;

            default:
                cout<<"Wrong choice!";
        }
    }
 while(choice != 0);
    return 0;
}