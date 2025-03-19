#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    double sal;

public:
    Employee()
    {
    }

    Employee(int id, double sal)
    {
        this->id = id;
        this->sal = sal;
    }

    virtual void accept()
    {
        cout << "Enter id -  " << endl;
        cin >> id;
        cout << "Enter sal -  " << endl;
        cin >> sal;
    }

    virtual void display()
    {
        cout << "id - " << id << endl;
        cout << "sal - " << sal << endl;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return id;
    }
    void setSal(double Sal)
    {
        this->sal = sal;
    }

    int getSal()
    {
        return sal;
    }
};

class Manager : virtual public Employee
{
private:
    double bonus;

 protected:
    void acceptManager()
    {
        cout << "Enter bonus -- " << endl;
        cin >> bonus;
    }

    void displayManager()
    {
        cout << "Manager bonus -   : " << bonus << endl;
    }


public:
    Manager()
    {
    }

    Manager(double bonus, int id, double sal) : Employee(id, sal)
    {
        this->bonus = bonus;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus;
    }

    double getBonus()
    {
        return bonus;
    }
     
    void accept()
    {
        Employee ::accept();
        acceptManager();
    }

    void display()
    {
        Employee ::display();
        displayManager();
    }
     

     
};

class Salesman : virtual public Employee
{
private:
    double commission;

protected:
    void acceptSalesman()
    {
        cout << "Enter commission -- " << endl;
        cin >> commission;
    }

    void displaySalesman()
    {
        cout << "Manager commission -   : " << commission << endl;
    }

public:
    Salesman()
    {
    }

    Salesman(double commission, int id, double sal) : Employee(id, sal)
    {
        this->commission = commission;
    }

    void setCommission(double commission)
    {
        this->commission = commission;
    }

    double getCommission()
    {
        return commission;
    }

    void accept()
    {
        Employee ::accept();
        acceptSalesman();
           
    }

    void display()
    {
        
        Employee ::display();
        displaySalesman();
    }
};

class Salesmanager : public Manager, public Salesman
{
public:
    Salesmanager()
    {}
    
    Salesmanager(int id, double salary, double bonus, double commission) : Employee(id, salary)
    {
        // use the mutators of manager and salesman to
        // add the value bonus and commission inside them
        
    }
    void accept()
    {
        //Manager::accept();
        //Salesman::accept();
        Employee::accept();
        Manager::acceptManager();
        Salesman::acceptSalesman();
    }
    void display()
    {
        Employee::display();
        Manager::displayManager();
        Salesman::displaySalesman();
    }
};

int main()
{
    Salesmanager s;
    s.accept();
    s.display();
}