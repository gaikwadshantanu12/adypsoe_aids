/*
Develop a program in C++ to create a database of student's information system containing the following information: 
Name, Roll number, Class, Division, Date of Birth, Blood group, Contactaddress, Telephone number, Driving license no. and other.
Construct the database with suitable member functions.
Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class PersonClass {
    private:
        char name[40], clas[10],div[2],dob[15], bloodgrp[5];
        int roll;
    public:
        static int count;//static data
        friend class PersonnelClass;
        PersonClass() {
            char *name = new char[40];
            char *dob = new char[15];
            char *bloddgrp = new char[5];
            char *cls = new char[10];
            char *div= new char[2];
            roll = 0;
        }
        static void TotalRecordCount(){
            cout << "\n\nTOTAL NUMBER OF RECORDS CREATED: " << count;
        }
};

class PersonnelClass {
    private:
        char address[30], telephone_no[15], policy_no[10], license_no[10];
    public:
    PersonnelClass(){
        strcpy(address, "");
        strcpy(telephone_no, "");
        strcpy(policy_no, "");
        strcpy(license_no, "");
    }
    void InputData(PersonClass *obj);
    void DisplayData(PersonClass *obj);
    friend class PersonClass;
};

int PersonClass::count = 0;//static data initialized using scope resolution// operator

void PersonnelClass::InputData(PersonClass *obj) {
    cout << "\nROLLNO : ";
    cin >> obj->roll;
    cout << "NAME : ";
    cin >> obj->name;
    cout << "CLASS : ";
    cin >> obj->clas;
    cout << "DIVISION : ";
    cin >> obj->div;
    cout << "DATE OF BIRTH(DD-MM-YYYY) : ";
    cin >> obj->dob;
    cout << "BLOOD GROUP : ";
    cin >> obj->bloodgrp;
    cout << "ADDRESS : ";
    cin >> this->address;
    cout << "TELEPHONE NUMBER : ";
    cin >> this->telephone_no;
    cout << "DRIVING LICENSE NUMBER : ";
    cin >> this->license_no;
    cout << "POLICY NUMBER : ";
    cin >> this->policy_no;
    obj->count++;
}

void PersonnelClass::DisplayData(PersonClass *obj) {
    cout << "\n";
    cout << obj->roll << " " <<obj->name << " " << obj->clas << " " << obj->div << " " << obj->dob << " " << this->address << " " << this->telephone_no << " " << obj->bloodgrp << " " << this->license_no << " " << this->policy_no;
}

int main() {
    PersonnelClass *a[10];
    PersonClass *c[10];
    int n = 0, i, choice;
    char ans;
    do {
        cout << "\nMENU: ";
        cout << "\n\t1.Input Data\n\t2.Display Data";
        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "\n\n\tENTER THE DETAILS";
            cout << "\n--------------------------";
            do {
                a[n] = new PersonnelClass;
                c[n] = new PersonClass;
                a[n]->InputData(c[n]);
                n++;
                PersonClass::TotalRecordCount();
                cout << "\n\nDo you want to add more records ?(y/n): ";
                cin >> ans;
            } while (ans == 'y' || ans == 'Y');
            break;
        case 2:
            cout << "\n--------------------------";
            cout << "\n Roll Name Class Div BirthDate Address Telephone Blood_Gr Licence Policy ";
            cout << "\n--------------------------";
            for (i = 0; i<n; i++)
                a[i]->DisplayData(c[i]);
            PersonClass::TotalRecordCount();
            break;
        }
        cout << "\nDo you want to go to main menu?(y/n): ";
        cin >> ans;
        cin.ignore(1, '\n');
    } while (ans == 'y' || ans == 'Y');
    return 0;
}
