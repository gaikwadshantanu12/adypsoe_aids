/*
Experiment No. 26 :	
In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[]. 
Write C++ program using stack to check whether given expression is well parenthesized or not.
*/

#include<iostream>
#include<string.h>

using namespace std;

#define MAX 50
struct stknode {
    char stack[MAX];
	int top = -1;
} st;

class StClass {
    public:
	    void push(char);
    	char pop();
	    int check(char exp[MAX]);
    	friend int match(char a, char b);
};

int match(char a, char b) {
	if (a == '[' && b == ']')
		return 1;
	if (a == '{' && b == '}')
		return 1;
	if (a == '(' && b == ')')
		return 1;
	return 0;
}

int StClass::check(char exp[]) {
	int i;
	char temp;
	int n = strlen(exp);
	for (i = 0; i<n; i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(exp[i]);
		if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
			if (st.top == -1)    //stack empty
				return 0;
			else {
				    temp = pop();
				    if (!match(temp, exp[i]))
					    return 0;//not
			    }
	}
	if (st.top == -1) //stack empty
		return 1;//well parenthsized
	else
		return 0;
}

void StClass::push(char item) {
	if (st.top == (MAX - 1)) {
		cout << "Stack Overflow\n";
		return;
	}
	st.top = st.top + 1;
	st.stack[st.top] = item;
}

char StClass::pop() {
	if (st.top == -1) {
		cout << "Stack Underflow\n";
		exit(1);
	}
	return(st.stack[st.top--]);
}

int main() {
	char exp[MAX];
	int status;
	StClass obj;
	cout << "Enter a parenthesized expression : ";
	cin >> exp;
	status = obj.check(exp);
	if (status == 1)
		cout << "The expression is well parenthesized!!!\n";
	else
		cout << "The expression is not well parenthesized!!!";
	return 0;
}