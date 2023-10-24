/*
A book shop maintains the inventory of books that are being sold at the shop. 
The list includes details such as author, title, price, publisher and stock position. 
Whenever a customer wants a book, the sales person inputs the title and author and the system searches the list and displays whether it is available or not. 
If it is not, an appropriate message is displayed. 
If it is, then the system displays the book details and requests for the number of copies required. 
If the requested copies book details and requests for the number of copies required. 
If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message “Required copies not in stock” is displayed. 
Design a system using a class called books with suitable member functions and Constructors. 
Use new operator in constructors to allocate memory space required. Implement C++ program for the system.
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class book {
    char author[20]; 
    char title[20];
    char publisher[20];
    double price;
    int stock;
    public:
        book();    
        void insertdata();
        void display();
        int search(char[],char[]);
        void nocopies(int);     
};
  
book::book() {
    char *author=new char[50];
    char * title=new char[50];
    char *publisher=new char[50];
    price=0;
    stock=0;
}

void book::insertdata() {
    cout<<"\nEnter The Name Of Book : ";
    cin>>title;
    cout<<"Enter The Name Of Author : ";
    cin>>author;
    cout<<"Enter The Name Of Publisher : ";
    cin>>publisher;
    cout<<"Enter The Price Of Book : ";
    cin>>price;
    cout<<"Enter Stock Of Book : ";
    cin>>stock;
}

void book::display() {
    cout<<title<<"\t\t\t"<<author<<"\t\t\t"<<publisher<<"\t\t\t"<<price<<"\t\t\t"<<stock;
}

int book::search(char t[],char a[]) {
    if(strcmp(title,t)&&(strcmp(author,a))) {
        return 0;
    }
    else {
        return 1;
    }
}

void book::nocopies(int num) {
    if(stock>=num) {
        cout<<"Title is available";
        cout<<"\nCost of "<<num<<" Books is Rs. "<<(price*num);
    }
    else {
        cout<<"\nRequired copies not in stock" << endl;
    }
}

int main() {
    int ch,n,i,flag=0,copies,key=0;
    book b[100];
    char bname[50];
    char key_title[50],key_author[50];
   
   do{
        cout<<"\n************Book Store*******************";
        cout<<"\n1. Insert Details of book \n2. Display \n3. Search \n4. Exit";
        cout<<"\nEnter Your Choice : ";
        cin>>ch;
        
        switch(ch) {
            case 1:
                cout<<"\nHow many books data you want to enter ? ";
                cin>>n;
                for(i=0;i<n;i++) {
                       b[i].insertdata();
                }
                break;
            case 2:
                cout<<"\n"<<"TITLE"<<"\t\t\t"<<"AUTHOR"<<"\t\t\t"<<"PUBLISHER"<<"\t\t\t"<<"PRICE"<<"\t\t\t"<<"STOCK";
                for(i=0;i<n;i++) {
                    cout<<"\n";
                    b[i].display();   
                }
                cout << "\n";
                break;           
            case 3:
                cout<<"\nEnter title of required book : ";
                cin>>key_title;
                cout<<"Enter author of required book : ";
                cin>>key_author;             
                for(i=0;i<n;i++) {
                    if(b[i].search(key_title,key_author)) {
                        flag=1;
                        cout<<"\n"<<"TITLE"<<"\t\t\t"<<"AUTHOR"<<"\t\t\t"<<"PUBLISHER"<<"\t\t\t"<<"PRICE"<<"\t\t\t"<<"STOCK" << endl;
                        b[i].display();                        
                        //break;
                        key=i;
                    }
                }
                if(flag==1)                          
                    cout<<"\n\nBook is available !";
                else {
                    cout<<"\n\nBook is not available !";
                    break;
                }        
                if(flag==1) {
                    cout<<"\n\nPlease enter the required number of copies of the book : ";
                    cin>>copies;
                    b[key].nocopies(copies);
                }   
                break;
            case 4: 
                exit(EXIT_SUCCESS);
                break;
            default :
                cout<<"\nWrong Choice !";
                    break;
        }   
    }while(ch!=5);
    return 0;
}
