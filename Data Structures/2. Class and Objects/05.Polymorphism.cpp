#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    Person(string name, int age) // Method Overloading - Parameterized Constructor - Compile time Polymorphism
    {
        cout<<"Parent Parameterized Constructor Called"<<endl;
        this->name=name;
        this->age=age;
    }

    Person() // Method Overloading - Default Constructor - Compile time Polymorphism
    {
        cout<<"Parent Default Constructor Called"<<endl;
        this->name="Unknown";
        this->age=0;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual void display() // Virtual Function for run-time Polymorphism
    {
        cout << "Person Display Function" << endl;
    }
};

class Student : public Person
{
public:
    int rollNumber;

    Student(string name, int age, int rollNumber) : Person(name, age)
    {
        cout<<"Child Default Constructor Called"<<endl;
        this->rollNumber = rollNumber;
    }

    void getInfo() // Method Overriding - run-time Polymorphism
    {
        Person::getInfo(); // Call base class method
        cout << "Roll Number: " << rollNumber << endl;
    }
    void display() override // Overriding base class virtual function
    {
        cout << "Student Display Function" << endl;
    }
};

int main()
{
    Person person1("John", 30);
    person1.getInfo();
    cout << "------------------------" << endl;
    Person person2; // Calls default constructor
    person2.getInfo();
    cout << "------------------------" << endl;
    Student student1("Alice", 20, 101);
    student1.getInfo();
    cout << "------------------------" << endl;
    Student student2("Bob", 22, 102);
    student2.getInfo();
    student2.display(); // Calls overridden method
    cout << "------------------------" << endl;
    return 0;
}