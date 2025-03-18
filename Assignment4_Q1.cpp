/*
*  Assignment - 4 : 
*  Q1. Write a class for Time and provide the functionality 
*      Time() 
*      Time(int h,int m,int s) 
*      getHour() 
*      getMinute() 
*      getSeconds() 
*      printTime() 
*      setHour() 
*      setMinute() 
*      setSeconds() 
*  In main create array of objects of Time. 
*  Allocate the memory for the array and the object dynamically.  
*  
*/



#include <iostream>
using namespace std; 

class Time {
    int h; 
    int m; 
    int s; 

    public : 
        Time() : Time(00, 00, 00) {} 
        Time(int h,int m,int s) {
            this->h = h;
            this->m = m; 
            this->s = s; 
        }

        int getHour() {
            return h;
        }
        int getMinute() {
            return m; 
        }
        int getSeconds() {
            return s; 
        }

        void setHour(int h) {
            this->h = h;
        } 
        void setMinute(int m) {
            this->m = m; 
        }
        void setSeconds(int s) {
            this->s = s; 
        }

        void printTime() {
            cout << "Time - " << h << ":" << m << ":" << s << endl; 
        } 
        void acceptTime() {
            cout << "Enter hour : "; 
            cin >> h; 
            cout << "Enter minute : "; 
            cin >> m; 
            cout << "Enter second : "; 
            cin >> s; 
        }

};

int menu() {
    int choice; 
    cout<< "******************************" <<endl; 
    cout << "0. Exit" << endl; 
    cout << "1. Insert Time objects into array" << endl;
    cout << "2. Display all the Time objects" << endl; 
    cout << "Enter your choice : " << endl; 
    cin >> choice; 
    return choice; 
}


int main() {
    int index = 0; 
    int choice = -1; 

    Time **ptr = new Time *[5];

    while((choice = menu()) != 0) {
        switch(choice) {
            case 0 : 
                break; 

            case 1 : 
                if(index < 5) {
                    ptr[index] = new Time();
                    ptr[index] -> acceptTime();
                    index++;  
                    cout << "Value inserted ..." << endl; 
                }
                else
                    cout << "Array got full ..." << endl; 
                break; 
            
            case 2 : 
                for(int i=0; i<index; i++) {
                    ptr[i] -> printTime();
                }
                break; 

            default :
                cout<< "Wrong choice !" << endl; 
                
        }
    }

    // For deallocation 
    for(int i=0; i<5; i++) {
        delete ptr[i]; 
        ptr[i] = NULL; 
    }
    delete[] ptr; 
    ptr = NULL; 

    return 0; 
}

