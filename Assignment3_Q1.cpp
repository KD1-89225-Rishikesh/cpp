#include <iostream> 
using namespace std;

class box {

    int l,w,h;
public:
    box () {
        l = 10;
        w = 10;
        h = 10;
    }

    box (int l,int w,int h) {
        this-> l = l;
        this-> w = w;
        this-> h = h;

    }

    box (int l) {
        this-> l = l;
        this-> w = l;
        this-> h = l;

    }

    int getVolumn(){
        return l*w*h;
    }

    // int getVolumn3P(int l,int w,int h){
    //     return l*w*h;
    // }

    // int getVolumn1P(int l){
    //     return l*l*l;
    // }
};

int menu(){
int choice;

cout << "1 Calculate Volume with default values  "<< endl;
cout << "2 Calculate Volume with length,breadth and height with same value  "<< endl;
cout << "3 Calculate Volume with different length,breadth and height values."<< endl;
cout << "0 exit  "<< endl;
cout << "Enter the number  "<< endl;
cin >> choice;
return choice;
}

int main () {
  int number;
  box b1;
box b2(5,6,7);
box b3(65);

  while((number = menu()) != 0){
    
    switch(number){

        case 1 : 
        cout<< b1.getVolumn() << endl;
        break;

        case 2 :
        cout<< b2.getVolumn() << endl;
        break;

        case 3:
        cout << b3.getVolumn() << endl;
        break;

        default :
        cout <<  "Invalid number" << endl;
        break;
    }
// break;   this will only run 1 time loop


  }


    return 0;

}