#include <iostream>
using namespace std;

class Student{
  private :
   
  int roll_No, marks ;
  string  name;

  public :

  void acceptStudentFromConsole() {

      cout << "Enter stud name :" << endl;
      cin >> name ;
      cout << "Enter stud roll no :" << endl;
      cin >> roll_No ;
      cout << "Enter stud marks :" << endl;
      cin >> marks ;
  }

  void  printStudentOnConsole() {
      cout << "Name : " << name << "Roll no: " 
      << roll_No << "Marks : " << marks << endl;
  } 



};


int menu (){
     int choice ;
    cout << "0. EXIT" << endl;
    cout << "1. Accept the employee" << endl;
    cout << "2. Display the employee" << endl;
    cout << "Enter the choice - ";
    cin >> choice;
    return choice;
}



int main(){
    
    int number;

    Student s1;
 while ((number = menu()) !=0){
     
    switch(number){

        case 1: 
        s1.acceptStudentFromConsole();
        break;

        case 2 :
        s1.printStudentOnConsole();
        break;

        default :
        {
            cout << "Invalid number" << endl;
            break; 
        }
         
    }
 }
 


    return 0;
}