#include<bits/stdc++.h>
using namespace std;

// creating a class
class Employee{
    // using private access modifier
    private:    
        double salary;
    // using public access modifier
    public: 
        string name;
        string department;
        string team;
    // setter funnction 
    void insertSalary(double amount){
        salary = amount;
    }
    // getter function 
    void showSalary(){
        cout << salary << "\n";
    }
    // DEFAULT CONSTRUCTOR 
    Employee(){
        cout << "This is a default constructor" << "\n";
    }
    // PARAMETERISED CONSTRUCTOR 
    Employee(string n, string d, string t, double s){
        cout << "This is a parameteised constructor" << "\n";
        name = n;
        department = d;
        team = t;
        salary = s;
    }
    // PARAMETERISED CONSTRUCTOR WITH THIS POINT
    Employee(string name, string department, string team, double salary){
        cout << "This is parameterised constructor with this pointer" << "\n";
        this->name = name;
        this->department =department;
        this->team = team ;
        this->salary = salary ;
    }
    // COPY CONSTRUCTOR 
    Employee( Employee &originalObject){
        this->name = originalObject.name;
        this->department = originalObject.department;
        this->team = originalObject.team;
        this->salary = originalObject.salary;
    }
};

int main(){
    
}