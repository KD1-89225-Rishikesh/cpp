#include <iostream>
#include <string>
using namespace std;

namespace NStudent 
{
    class Student {
        public:
            int rollNo;
            string name;
            float marks;
        
        public:
            
            void acceptStudentFromConsole() {
                cout << "Enter Roll No: ";
                cin >> rollNo;
                cin.ignore(); 
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Marks: ";
                cin >> marks;
            }
        
        
            void printStudentOnConsole() {
                cout << "Roll No: " << rollNo << endl;
                cout << "Name: " << name << endl;
                cout << "Marks: " << marks << endl;
            }
        };
        
        void menu() {
            cout << "1. Accept Student Details\n";
            cout << "2. Print Student Details\n";
            cout << "3. Exit\n";
        }
}

int main() {
    NStudent::Student s;
    int choice;

    while (true) {
        NStudent::menu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.acceptStudentFromConsole();
                break;
            case 2:
                s.printStudentOnConsole();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}