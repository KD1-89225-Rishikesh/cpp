/*
*  Assignment - 5 : 

*  Q1. Create a class Date with data members day,month and year. 
*  Create a class Person with data members name, address and birthdate. 
*  The birthdate should be of type Date. 
*  Create a class Student with data members id, marks, course and joining date, end date. 
*  The joining date and end date should be of type date. 
*  Implement above classes. Test all functionalities in main(). 
*     (Note - Only Perform the Association in the above case. No need of Inheritance) 
*  
*/

#include <iostream> 
using namespace std; 

class Date {
    int day; 
    int month; 
    int year; 

    public : 
        Date() : Date(1, 1, 1000) {
            // cout << "Date()" << endl; 
        }
        Date(int day, int month, int year) {
            this->day = day; 
            this->month = month; 
            this->year = year; 
        }

        void acceptDate() {
            cout << "Enter day : "; 
            cin >> day; 
            cout << "Enter month : "; 
            cin >> month; 
            cout << "Enter year : "; 
            cin >> year; 
        }
        void displayDate() {
            cout << day << "/" << month << "/" << year << endl; 
        }
};

class Person : Date {
    string name; 
    string address; 
    Date *birthdate = NULL; 

    public : 
        Person() {

        }
        Person(string name, string address) {
            this->name = name; 
            this->address = address; 
        }

        void acceptPerson() {
            cout << "\t<< Enter Person details >>" << endl;
            cout << "Enter name : "; 
            cin >> name; 
            cout << "Enter address : "; 
            cin >> address; 
        }
        void acceptBirthdate() {
            birthdate = new Date();
            cout << "Enter Date of Birth >>" << endl; 
            birthdate -> acceptDate(); 
        }

        void displayPerson() {
            cout << "\t<< Person Details >>" << endl; 
            cout << "Name : " << name << endl; 
            cout << "Address : " << address << endl; 
            cout << "Date of Birth : "; 
            birthdate -> displayDate();
            cout << endl; 
        }

        ~Person() {
            // cout << "~Person()" << endl; 
            delete birthdate; 
            birthdate = NULL; 
        }
};

class Student {
    int id; 
    int marks; 
    string course; 
    Date joiningDate; 
    Date endDate;
    
    public : 
        Student() {

        }
        Student(int id, int marks, string course) {
            this->id = id; 
            this->marks = marks; 
            this->course = course; 
        }

        void acceptStudent() {
            cout << "\t<< Enter Student details >>" << endl;
            cout << "Enter ID : "; 
            cin >> id; 
            cout << "Enter marks : "; 
            cin >> marks; 
            cout << "Enter course : "; 
            cin >> course; 
            cout << "\tEnter Joining Date >> " << endl; 
            joiningDate.acceptDate();
            cout << "\tEnter End Date >> " << endl; 
            endDate.acceptDate();
            cout << endl;  
        }

        void acceptJoiningDate() {
            cout << "\tEnter Joining Date >>" << endl; 
            joiningDate.acceptDate();
        }
        void acceptEndDate() {
            cout << "\tEnter End Date >>" << endl; 
            endDate.acceptDate();
        }

        void displayStudent() {
            cout << "\t<< Student Details >>" << endl; 
            cout << "ID : " << id << endl; 
            cout << "Marks : " << marks << endl; 
            cout << "Course : " << course << endl;
            cout << "Joining Date : ";  
            joiningDate.displayDate(); 
            cout << "End Date : ";
            endDate.displayDate(); 
            cout << endl;  
        }
};

int main() {
    Person p1;
    p1.acceptPerson(); 
    p1.acceptBirthdate();
    p1.displayPerson();

    Student s1; 
    s1.acceptStudent(); 
    s1.displayStudent(); 
    return 0; 
}