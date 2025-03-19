#include <iostream>
using namespace std;

class Product
{

private:
  int id;
  string title;
  double price;

public:
  Product(){};

  Product(int id, string title, double price)
  {
    this->id = id;
    this->title = title;

    this->price = price;
  }

  virtual void accept()
  {
    cout << "enter id ; " << endl;
    cin >> id;
    cout << "enter title ; " << endl;
    cin >> title;
    cout << "enter price ; " << endl;
    cin >> price;
  }

  virtual void display()
  {
    cout << " id :" << id << "   title:   " << title << "   price : "
         << price << endl;
  }

  void setID(int id)
  {
    this->id = id;
  }

  void getID()
  {
    cout << " id ; " << id << endl;
  }

  void setPrice(int price)
  {
    this->price = price;
  }

  int getPrice()
  {
    return price;
  }

  // check in book notes  UPcasting + DMA then only use virtual keyword in desturctor
  virtual ~Product()
  { // Virtual destructor
    cout << "Product Destructor Called" << endl;
  }
};

class Book : public Product
{
private:
  string author;

public:
  Book()
  {
  }
  Book(string author, int id, string title, double price) : Product(id, title, price)
  {
    this->author = author;
  }

  // reusing the base class function by unhiding its implementation

  void accept()
  {
    cout << "Author name : " << endl;
    cin >> author;
    Product ::accept();
  }

  void display()
  {
    cout << "Author name : " << author << endl;
    Product ::display();
  }

  ~Book()
  {
    cout << "Book deleted." << endl;
  }
};

class Tape : public Product
{
private:
  string artist;

public:
  Tape()
  {
  }
  Tape(string artist, int id, string title, double price) : Product(id, title, price)
  {
    this->artist = artist;
  }

  void accept()
  {
    cout << "artist name : " << endl;
    cin >> artist;
    Product ::accept();
  }

  void display()
  {
    cout << "artist name : " << artist << endl;
    Product ::display();
  }

  ~Tape()
  {
    cout << "Tape deleted." << endl;
  }
};

int menu()
{
  int choice;

  cout << "Shop Menu:" << endl;
  cout << "0. EXIT" << endl;
  cout << "1. Enter Book " << endl;
  cout << "2. Enter Tape" << endl;
  cout << "3. Display All" << endl;
  cout << "4. Display Books" << endl;
  cout << "5. Display Tapes" << endl;
  cout << "6. Total Amount" << endl;
  cout << "Enter your choice: ";

  cin >> choice;
  return choice;
}

int main()
{

  // Product p ;
  // p.accept();
  // p.display();

  // Product *p = new Book();   // dynamic allocation of single object of product (book)
  // p->accept();
  // p->display();

  Product *ptr[3]; // Array of pointers{case 3} is used

  int number;
  int totalSum = 0;

  int index = 0;
  while ((number = menu()) != 0)
  {
    switch (number)
    {

    case 1:
      if (index < 3)
      {
        ptr[index] = new Book; // upcasting
        ptr[index]->accept();
        index++;
      }

      else
      {
        cout << "Cannot add more products. Limit reached." << endl;
      }
      break;

    case 2:
      if (index < 3)
      {
        ptr[index] = new Tape;
        ptr[index]->accept();
        index++;
      }
      else
      {
        cout << "Cannot add more Tapes. Limit reached." << endl;
      }
      break;

    case 3:
      for (int i = 0; i < index; i++)
      {
        ptr[i]->display(); // be careful here we have use [i] not [index]
      }
      break;

    case 4:
      for (int i = 0; i < index; i++)
      {

        if (typeid(*ptr[i]) == typeid(Book))
        { // typeid
          ptr[i]->display(); 
        }
      }
      break;

    case 5:
      for (int i = 0; i < index; i++)
      {

        if (typeid(*ptr[i]) == typeid(Tape))
        {
          ptr[i]->display();
        }
      }
      break;

    case 6:
      for (int i = 0; i < index; i++)
      {

        if (typeid(*ptr[i]) == typeid(Book))
        {
          int amt = ptr[i]->getPrice();      // it is same as that *ptr[i].getPrice()
          amt = amt - (amt * 0.10);
          totalSum = totalSum + amt;
        }

        if (typeid(*ptr[i]) == typeid(Tape))
        {
          int amt = ptr[i]->getPrice();
          amt = amt - (amt * 0.05);
          totalSum = totalSum + amt;
        }
      }
      cout << "total amount is ; " << totalSum << endl;
      break;

    default:
      cout << "Wrong number enter " << endl;
      break;
    }
  }

  // **Deallocate Memory Properly**
  for (int i = 0; i < index; i++)
  {
    delete ptr[i];    // Delete the object
    ptr[i] = nullptr; // Set pointer to nullptr
  }

  cout << "Memory successfully deallocated!" << endl;
}