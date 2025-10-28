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

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
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

    return 0;
}