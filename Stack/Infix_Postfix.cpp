#include <string>
#include <iostream>
#include <stack>

using namespace std; 

public:
int precedence(char symbol)//return  a precedence no for the operator 
{
	switch(symbol){
		case '+' :   
		case '-' : return  1;
		case '*' : 
		case '/' : return  2;
		case '$' : return  3;
		default  : return -1;
	}
	return -1; // base return 
}//precedence




int main(){
	stack<char> opt; // stack to store the operators
	
	while(true){
	cout << "Enter an expression!" << endl;
	string infix;
	cin >> infix;
			string postfix = "";
		
			opt.push('('); // push  a opening brace at the stack
			int i = 0;
			infix.insert(infix.length(),")");// append a closing brace at the end.
		while(i < infix.length()){
			char symscan =  infix.at(i++);
			

int val = symscan;
    if((val >= 65 && val <=92) || (val >= 97 && val <=122)) { postfix = postfix + symscan; } // variable scanned
	else if(symscan=='(') { opt.push(symscan);}
	else if(symscan==')'){
		while(opt.top()!='('){
			postfix = postfix + opt.top();
			opt.pop();
		}
		opt.pop();//pop the opening brace 
	}
	else if((precedence(symscan) > precedence(opt.top()))|| (opt.top()=='(')) {
			opt.push(symscan);
	}
	else if(precedence(symscan) < precedence(opt.top())){
		    while(precedence(symscan) < precedence(opt.top())){
		    	postfix=postfix + opt.top();
		    	opt.pop();
		    }
		    opt.push(symscan);
	}
	else if(precedence(symscan)==precedence(opt.top())) {
		if(symscan == '$'){
			opt.push(symscan);
		}
		else{
			while(precedence(symscan) == precedence(opt.top())){
		    	postfix=postfix + opt.top();
		    	opt.pop();
		    }
		    opt.push(symscan);
		}
	}




		}
		cout << postfix <<endl;
	}
	return 0;
}