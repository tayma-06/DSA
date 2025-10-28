#include<iostream>
#include<string>
using namespace std;

class Teacher{
public:
    //attributes or data members
    string name;
    string dept;
    string subject;
    double salary;

    //methods or member functions
    void changeDept(string newDept){
        dept=newDept;
    }
};

class Student{
private:
    string password; //private member
public:
    string name;
    int id;
    string dept;
    double cgpa;
    void updateCgpa(double newCgpa){
        cgpa=newCgpa;
    }
    void setPassword(string pwd){
        password=pwd;
    }
    string getPassword(){
        return password;
    }
};

int main(){
    Teacher t1;
    t1.name="Khadiza";
    t1.dept="CSE";
    t1.subject="OOP";
    t1.salary=50000;

    cout<<"Teacher Name: "<<t1.name<<endl;

    Student s1;
    s1.name="Arif";
    s1.id=101;
    s1.dept="CSE";
    s1.cgpa=3.75;
    cout<<"Student Name: "<<s1.name<<endl;

    s1.setPassword("secure123");
    cout<<"Student Password: "<<s1.getPassword()<<endl;
    
    return 0;
}