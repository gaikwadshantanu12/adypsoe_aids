/*
Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). 
The program should take two operands from user and performs the operation on those two operands depending upon the operator entered by user. 
Use a switch statement to select the operation. Finally, display the result. 
Some sample interaction with the program might look like this : 
    Enter first number, operator, second number : 
        10 / 3 Answer = 3.333333 
        Do another (y/n)? y 
    Enter first number, operator, second number : 
        12 + 100 Answer = 112 
        Do another (y/n)? n (2 & 3).
*/

#include<iostream>
using namespace std;
class calculator {
	int num1,num2;
	float result;
	public:
		void getData();
		void putData();
		void add();
		void sub();
		void mul();
		void div();
		void mod();
};
 
void calculator::getData() {
    cout<<"\nEnter two numbers : " ;
	cin>>num1>>num2;
}
 
void calculator::putData() {
	cout<<"\nNum1 = "<<num1<<"\nNum2 = "<<num2<<"\nResult = "<<result;
}
 
void calculator::add() {
	result=num1+num2;
}
 
void calculator::sub() {
	result=num1-num2;
}

void calculator::mul() {
	result=num1*num2;
}
 
void calculator::mod() {
	result=num1%num2;
}
 
void calculator::div() {
	result=num1/float(num2);
}
 
int main() {
	calculator c;
	char choice,ans;
	do{
		cout<<"\n**********MENU*************\n";
		cout<<"1. +\n2. - \n3. * \n4. / \n5. %\nEnter your operator : ";
		cin>>choice;
		c.getData();
		switch(choice) {
			case '+':
					c.add();
					break;
			case '-':
					c.sub();
					break;
			case '*':
					c.mul();
					break;
			case '/':
					c.div();
					break;
			case '%':
					c.mod();
					break;
		}
		c.putData();
		cout<<"\n\nDo you want to continue(Y/N) : ";
		cin>>ans;
	}while(ans=='Y' || ans=='y');
	return 0;
}