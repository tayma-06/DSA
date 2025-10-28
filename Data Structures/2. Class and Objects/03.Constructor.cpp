#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    // attributes or data members
    string name;
    string dept;
    string subject;
    double salary;

    // non-parameterized constructor (default constructor)
    Teacher()
    {
        cout << "Teacher default constructor called" << endl;
        dept = "Computer Science"; // default value for dept
    }

    // parameterized constructor
    Teacher(string newName, string newDept, string newSubject, double newSalary)
    {
        name = newName;
        dept = newDept;
        subject = newSubject;
        salary = newSalary;
    }

    //parameterized constructor using this keyword

    Teacher(string name, string dept, string subject)
    {
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary = 60000; // default salary
    }

    //copy constructor
    Teacher(Teacher &obj) // pass by reference
    {
        cout << "Teacher copy constructor called" << endl;
        this->name = obj.name;
        this->dept = obj.dept;
        this->subject = obj.subject;
        this->salary = obj.salary;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Student
{
public: 
    string name;
    double* cgpaPtr;

    Student(string name, double cgpa)
    {
        this->name = name;
        cgpaPtr = new double; // dynamically allocate memory
        *cgpaPtr = cgpa;
    }

    Student(const Student &obj) // copy constructor
    {
        this->name = obj.name;
        cgpaPtr = new double; // allocate new memory
        *cgpaPtr = *obj.cgpaPtr; // deep copy
        //this->cgpaPtr = obj.cgpaPtr; // shallow copy
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << *cgpaPtr << endl;
    }
};

int main()
{
    Teacher t1; // default constructor is called here
    Teacher t2; // default constructor is called here
    t1.name = "Khadiza";
    t1.subject = "OOP";
    t1.salary = 50000;

    Teacher t3("Alice", "Mathematics", "Calculus", 60000); // parameterized constructor is called here

    cout << "Teacher Name: " << t1.name << endl;
    cout << "Teacher Dept: " << t1.dept << endl;
    cout << "Teacher Dept: " << t2.dept << endl;

    cout << "Teacher Name: " << t3.name << endl;
    cout << "Teacher Dept: " << t3.dept << endl;
    cout << "Teacher Subject: " << t3.subject << endl;
    cout << "Teacher Salary: " << t3.salary << endl;

    t1.displayInfo();
    t3.displayInfo();

    Teacher t4("Bob", "Physics", "Quantum Mechanics"); // parameterized constructor using this keyword is called here
    t4.displayInfo();

    Teacher t5(t1); //  copy constructor is called here
    t5.displayInfo();

    Student s1("John", 3.8);
    s1.displayInfo();
    Student s2(s1);
    *(s2.cgpaPtr)=3.9; // copy constructor is called here
    s2.displayInfo();
    //s1.displayInfo(); // shows the effect of shallow copy
    s1.displayInfo(); // shows the effect of deep copy

    return 0;
}