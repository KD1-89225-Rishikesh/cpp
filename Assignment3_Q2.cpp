#include <iostream>
using namespace std;

class tollbooth {

private:
unsigned int totalCars;
double totalAmount;
unsigned int payingCars;
unsigned int nonPayingCars;

public:

tollbooth() {
totalCars = 0;
totalAmount = 0.0;
payingCars = 0;
nonPayingCars = 0;

}


void payingCar() {
    payingCars++;
    totalAmount = totalAmount + 0.50; 
    totalCars++;
}

void nopayCar(){
    nonPayingCars++; 
    totalCars++;
    
}

void printOnConsole() {
    cout << "Total Cars Passed: " << totalCars << endl;
    cout << "Total Amount Collected: $" << totalAmount << endl;
    cout << "Paying Cars: " << payingCars << endl;
    cout << "Non-Paying Cars: " << nonPayingCars 
    << endl;
}

};

int menu() {
    int choice;
    cout << "Tollbooth Menu:" << endl;
    cout << "0. EXIT" << endl;
    cout << "1. Paying Car" << endl;
    cout << "2. Non-Paying Car" << endl;
    cout << "3. Display Tollbooth Status" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}



int main () {

 int number;
    tollbooth booth;

    while ((number = menu()) != 0) {
        switch (number) {
            case 1:
                booth.payingCar();
                break;
            case 2:
                booth.nopayCar();
                break;
            case 3:
                booth.printOnConsole();
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

 
    return 0;
}