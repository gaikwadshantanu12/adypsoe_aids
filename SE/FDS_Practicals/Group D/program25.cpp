/*
Experiment No. 25 : 
A Palindrome is a string of characters that’s the same forward and backward. 
Typically, punctuation, capitalization, and spaces are ignored. 
For example, “Poor Dan is in a droop” is a palindrome, as can be seen by examining the characters “poordanisinadroop” and observing that they are same forward and backward. 
For way to check for palindrome is to reverse the characters in the string and then compare with them the original -in a palindrome, the sequence will be identical. 
Write C++ program with functions –
a)	To print original string followed by reversed string using stack.
b)	To check whether given string is palindrome or not
*/

#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;
#define SIZE 50

class Stack {
    private:
        char input_str[SIZE];
        char stack_data[SIZE];
        int top,length,char_count;
    public:
        Stack() {
        top=-1;
        length=0;
        char_count=0;
    }
        void push(char);
        char pop();
        void input_data();
        void check_palindrome();
        void get_characters_only();
        void display_original();
        void display_reverse();
};

void Stack::push(char temp) {
    if(top==SIZE-1) {
        cout<<"\n Stack Overflow !!!";
        return;
    }
    top++;
    stack_data[top]=temp;
}

char Stack::pop() {
    if(top==-1) {
        cout<<"\n Stack Underflow !!!";
        char ch='\n';
        return ch;
    }
    char temp=stack_data[top];
    top--;
    return temp;
}

void Stack::input_data() {
    cout<<"\nEnter a String : ";
    cin.getline(input_str,SIZE);
    length=strlen(input_str);
}

void Stack::get_characters_only() {
    char temp[SIZE];
    int i,j;
    for(i=0; i<length; i++) {
        temp[i]=input_str[i];
    }
    j=0;
    for(i=0; i<length; i++ ) {
        if(isalpha(temp[i])) {
            input_str[j]=tolower(temp[i]);
            j++;
        }
    }
    length=j;  //on removing spaces,punctuations
                //new length is obtained
}

void Stack::check_palindrome() {
    for(int i=0; i<length; i++)
        push(input_str[i]);
    for(int i=0; i<length; i++) {
        if(input_str[i]==pop())//finding a match
            char_count++;
    }
    if(char_count==length)
        cout<<"\nGiven string is a Palindrome !!!\n";
    else
        cout<<"\nGiven string is not a Palindrome !!!\n";
}

void Stack::display_original() {
    for(int i=0; i<=length-1; i++)
        cout<<input_str[i];
}

void Stack::display_reverse() {
    for(int i=length-1; i>=0; i--)
        cout<<input_str[i];
}

int main() {
    Stack obj;
    obj.input_data();
    obj.get_characters_only();
    cout<<"\nDisplaying the original String :  ";
    obj.display_original();
    cout<<"\n\nDisplaying the reversed string :  ";
    obj.display_reverse();
    cout<<"\n\nChecking for Palindrome....\n";
    obj.check_palindrome();
    return 0;
}
