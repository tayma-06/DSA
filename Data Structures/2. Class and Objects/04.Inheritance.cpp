#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    string name;
    int age;

    // Person(string name, int age)
    // {
    //     this->name=name;
    //     this->age=age;
    // }
    // Person()
    // {
    //     cout<<"Parent Constructor Called"<<endl;
    // }

    Person(string name, int age)
    {
        cout<<"Parent Parameterized Constructor Called"<<endl;
        this->name=name;
        this->age=age;
    }

    ~Person()
    {
        cout<<"Parent Destructor Called"<<endl;
    }
};

class Student : public Person
{
public:
    int rollNumber;

    // Student()
    // {
    //     cout<<"Child Constructor Called"<<endl;
    // }

    Student(string name, int age, int rollNumber) : Person(name, age)
    {
        cout<<"Child Default Constructor Called"<<endl;
        this->rollNumber = rollNumber;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
    ~Student()
    {
        cout<<"Child Destructor Called"<<endl;
    }
};

class gradStudent : public Student
{
public:
    string thesisTitle; 
    gradStudent(string name, int age, int rollNumber, string thesisTitle) : Student(name, age, rollNumber)
    {
        this->thesisTitle = thesisTitle;
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Thesis Title: " << thesisTitle << endl;
    }
};

class Teacher : public Person
{
public:
    string subject; 
    Teacher(string name, int age, string subject) : Person(name, age)
    {
        this->subject = subject;
    }
    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }
};

class TA : public Student, public Teacher
{
public:
    TA(string name, int age, int rollNumber, string subject) : Student(name, age, rollNumber), Teacher(name, age, subject)
    {

    }
    void display()
    {
        cout << "Name: " << Student::name << endl; // Resolving ambiguity
        cout << "Age: " << Student::age << endl;   // Resolving ambiguity
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Subject: " << subject << endl;
    }
};

int main()
{
    Student student("Alice", 20, 101);
    student.getInfo();
    cout << "------------------------" << endl;
    gradStudent gradStudent1("Bob", 24, 102, "Machine Learning");
    gradStudent1.getInfo();
    cout << "------------------------" << endl;
    Teacher teacher("Dr. Smith", 45, "Mathematics");
    teacher.getInfo();
    cout << "------------------------" << endl;
    TA ta("Charlie", 22, 103, "Physics");
    ta.display();
    
    return 0;
}