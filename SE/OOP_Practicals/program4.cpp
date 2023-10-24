/*
Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file.
*/

#include<iostream>
#include<fstream>

using namespace std;

class Employee {
    string Name;
    int ID;
    double salary;
    public:
    void accept() {
        cout<<"Name : ";
        cin.ignore();
        getline(cin,Name);
        cout<<"Id : ";
        cin>>ID;
        cout<<"Salary : ";
        cin>>salary;
    }
    void display() {
        cout<<"Name : "<<Name << endl;
        cout<<"Id : "<<ID << endl;
        cout<<"Salary : "<<salary<<endl;
    }
};

int main() {
    Employee o[5];
    fstream f;
    int i,n;
    f.open("demo.txt",ios::out);
    cout<<"\nEnter the number of employees you want to store : ";
    cin>>n;
    for(i=0;i<n;i++) {
        cout<<"\nEnter information of Employee "<<i+1<<"\n";
        o[i].accept();
        f.write((char*)&o[i],sizeof o[i]);
    }
    f.close();
    f.open("demo.txt",ios::in);
    cout<<"\nInformation of Employees is as follows : \n";
    for(i=0;i<n;i++) {
        cout<<"\nEmployee "<<i+1<<"\n";
        f.write((char*)&o[i],sizeof o[i]);
        o[i].display();
    }
    f.close();
    return 0;
}
