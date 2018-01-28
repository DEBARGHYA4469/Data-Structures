//Evaluating a postfix expression
//operator push on the stack
//operand pop twice evaluate the expression push in onto the stack

#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

bool operators(char symbol) {
	switch(symbol){
		case '+': 
		case '-':
		case '/':
		case '*':
		case '$':return true;
	}
	return false;
}

int operation(int op2,int op1,char symbol){
	switch(symbol){
		case '+': return op2+op1;
		case '-': return op2-op1;
		case '*': return op2*op1;
		case '/': return op2/op1;
		case '$': return pow(op2,op1);
}
}
int main(){
	stack<int> postfix;
	
		cout << "Enter the postfix expression: "<< endl;
		string str;
		cin >> str ;
		int i=0;
		
		while(i<str.length()){
			char ch = str.at(i++);
			if(operators(ch)==true){
				int op1 = postfix.top();
				postfix.pop();
				int op2 = postfix.top();
				postfix.pop();
				int expression = operation(op2,op1,ch);
				postfix.push(expression);
			}
			else
			{
				postfix.push(ch-'0');
			}
		} 
	cout << postfix.top() << endl;
	return 0;	
}

