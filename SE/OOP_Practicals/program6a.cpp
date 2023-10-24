/*
Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone numbers, etc) using vector container.
*/

#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>

using namespace std;

typedef struct rec {
    char name[20];
    char BirthDt[20];
    char phone[11];
} node;

node temp;

vector<node> rec;
vector <node> :: iterator ptr;

bool compare(node &r1, node &r2){
    if(strcmp(r1.name, r2.name) < 0)
        return true;
    else
        return false;
}

void Create(){
    int n, i;
    cout << "\nHow many elements you want to insert ? ";
    cin >> n;
    cout << "\nEnter the elements in the database - " << endl;
    for(i=0; i<n; i++){
        cout << "Name : ";
        cin >> temp.name;
        cout << "Birth Date : ";
        cin >> temp.BirthDt;
        cout << "Phone : ";
        cin >> temp.phone;
        rec.push_back(temp);
        cout << "\n";
    }
}

void Display(){
    cout << "\nThe contents of the database are - " << endl;
    cout << "Name       Birth Date      Phone" << endl;
    for(ptr=rec.begin(); ptr!=rec.end(); ptr++){
        cout << "\n";
        cout << "" << (*ptr).name;
        cout << "       " << (*ptr).BirthDt;
        cout << "       " << (*ptr).phone;
    }
    cout << "\n";
}

void Searching(){
    char key[20];
    int flag = 0;
    cout << "\nEnter the name which you want to search : ";
    cin >> key;
    for(ptr=rec.begin(); ptr!=rec.end(); ptr++){
        if(strcmp((*ptr).name, key) == 0){
            flag = 1;
            break;
        }
        else
            flag = 0;
    }
    if(flag == 1)
        cout << "The desired element is present in the database" << endl;
    else
        cout << "The desired element is not present in the database" << endl;
}

void Sorting(){
    sort(rec.begin(), rec.end(), compare);
    cout << "\n\nRecord is sorted !" << endl;
}

int main(){
    char ans = 'y';
    int choice;
    cout << "Program for Searching & Sorting : " << endl;

    do{
        cout << "\nMain Menu - " << endl;
        cout << "1. Create a database\n2. Display a database\n3. Search particular element\n4. Sort the database(based on name)" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                Create();
                break;
            case 2:
                Display();
                break;
            case 3:
                Searching();
                break;
            case 4:
                Sorting();
                break;
            default:
                cout << "\nInvalid choice !" << endl;
                break;
        }

        cout << "\nDo you want to go back to Main Menu ? ";
        cin >> ans;
    } while(ans == 'y');
}
