/*
Experiment No. 23 :
Write C++ program for storing binary number using doubly linked lists. Write functions -
a) To compute 1‘s and 2‘s complement
b) Add two binary numbers
*/

#include<iostream>
using namespace std;

struct node {  
    int x;
    node *next,*prev;
};

class binary {    
    node *head=NULL,*temp=NULL, *head1=NULL,*temp1=NULL, *head2=NULL,*temp2=NULL,*temp3=NULL,*head3=NULL;
    int c,i;
    public:
        node *create();
        void insert();
        void binary1();
        void binary2();
        void add();
        void com();
        void comp();
        void display();
};

node *binary::create() {   
    node *p = new(struct node);
    cout << "Enter Binary : ";
    cin >> c;
    p->x = c;
    p->next = NULL;
    p->prev = NULL;
    return  p;
}
  
void binary::insert() {
    node *p = create();
    if(head == NULL) {    
        head = p;
    }
    else {      
        temp = head;
        while(temp->next != NULL) {    
            temp = temp->next;   
        }
        temp->next = p;
        p->prev = temp; 
    }     
}
   
void binary:: binary1() { 
    int a;
    cout << "\nEnter The No. of Bits : ";
    cin >> a;
    head = NULL;
    for(i=0;i<a;i++) {  
        insert();      
    }
    head1 = head;
    cout << "\nBinary 1 : ";
    display();
    head = NULL;
    temp1 = head1;
}
      
void binary:: binary2() {     
    int a;
    cout << "\nEnter The No. of Bits : ";
    cin >> a;
    head = NULL;
    for(i=0;i<a;i++) {  
        insert();      
    }
    head2 = head;
    cout << "\nBinary 2 : ";
    display();
    head = NULL;
}

void binary::add() {   
    int carry = 0;
    temp1 = head1;
    while(temp1->next != NULL) {   
        temp1 = temp1->next;     
    }
    temp2 = head2;
    while(temp2->next != NULL) {   
        temp2 = temp2->next;     
    }
    while(temp1 != NULL) {      
        node *p = new(struct node);
        p->next = NULL;
        p->prev = NULL;
        if(temp1->x == 0 && temp2->x == 0) {      
            p->x = 0+carry;  
            carry = 0;      
        }
        
        if(temp1->x == 0 && temp2->x == 1) {      
            if(carry == 0) {
                p->x = 1;     
                carry = 0; 
            }
            else {  
                p->x = 0;  
                carry = 1;
            }
        }
        
        if(temp1->x == 1 && temp2->x == 0) {       
            if(carry == 0) {
                p->x = 1;     
                carry = 0; 
            }
            else {  
                p->x = 0;  
                carry = 1;
            }
        }
        
        if(temp1->x == 1 && temp2->x == 1) {        
            if(carry == 0) {
                p->x = 0;     
                carry = 1; 
            }
            else {  
                p->x = 1;  
                carry = 1; 
            }
        }
               
        if(temp3 == NULL) {   
            temp3 = p;     
        }
        else {
            p->next = temp3;
            temp3 = p;
        }
          
        temp1 = temp1->prev;
        temp2 = temp2->prev;   
    }
    
    node *p = new(struct node);
    p->x = carry;
    p->next = NULL;
    p->prev = NULL;
    
    if(temp3 == NULL) {   
        temp3 = p;     
    }
    else {
        p->next = temp3;
        temp3 = p;
    }
    
    head3 = temp3;
    temp3 = head3;  
    cout << "\n";
    cout << "Addition of Binary 1 & Binary 2 : ";
    while(temp3->next != NULL) { 
        cout << temp3->x << "\t";
        temp3 = temp3->next;
    } 
    
    cout << temp3->x << "\t" << "\n"; 
}

void binary::com() { 
    while(temp1 != NULL) {  
        node *p = new(struct node);
        p->next = NULL;
        p->prev = NULL;
        if(temp1->x == 0)
            p->x = 1;
        else
            p->x = 0;
       
        if(head == NULL) {    
            head = p;
        }
        else {      
            temp = head;
            while(temp->next != NULL) {    
                temp = temp->next;   
            }
            temp->next = p;
            p->prev = temp;
        }    
        temp1 = temp1->next;
    }  
    
    cout << "\n1's Compliment of  Binary No. : ";
    display();
    int f = 0;
    
    while(temp != NULL) {   
        if(temp->x == 1) {   
            temp->x = 0;   
        }
        else {   
            temp->x = 1;   
            f = 1;
            break;
        } 
        temp = temp->prev;
    }
    
    if(f == 0) {  
        node *p = new(struct node);
        p->next = NULL;
        p->prev = NULL;
        p->x = 1;
        temp = head;
        head = p;
        head->next = temp;
        temp->prev = head;
    }
    
    cout << "\n2's Compliment of  Binary No. : ";
    display();
}

void binary::comp() {
    cout<<"\nFor First Binary No. : ";
    temp1 = head1;
    com();
    head = NULL;
    cout<<"\nFor Second Binary No. : ";
    temp1 = head2;
    com();
}
           
void binary::display() {  
    temp = head;
    while(temp->next != NULL) { 
        cout << temp->x << "\t";
        temp = temp->next;
    } 
    cout << temp->x << "\t" << "\n";
}

int main() {  
    binary b;
    int m;
    char ch;
    do {    
        cout << "\n1. Insert Binary1";
        cout << "\n2. Insert Binary 2";
        cout << "\n3. Add Binary Nos.";
        cout << "\n4. 1's & 2's Compliment of Binary Nos.";
        cout << "\nEnter The Choice : ";
        cin>>m;
        
        switch(m) {   
            case 1:   
                b.binary1();
                break;
            case 2:   
                b.binary2();
                break;
            case 3:   
                b.add();
                break;
            case 4:   
                b.comp();
                break;
            default: 
                cout << "Unknown Choice" << endl;
        }
        
        cout<<"\nDo you want to continue press (Y/N) ? ";                
        cin>>ch;
    } while(ch == 'y' || ch == 'Y');
    
    return 0;
}