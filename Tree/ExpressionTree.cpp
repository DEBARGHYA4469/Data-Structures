#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <string>
using namespace std;

struct extree{
char value;
extree *left,*right;
};

bool isOperator(char ch){
	if(ch=='+' || ch == '-' || ch =='*' || ch == '/' || ch=='^')
		return true;
	return false;
}
void inorder(extree *T){
		if(T==NULL) {
			cout << "(";
			return;
		}
		inorder(T->left);
		cout << T->value << " ";
		inorder(T->right);
		cout << ")";
}

extree *newNode(int value){
	extree *tmp = new extree;
	tmp->left = tmp->right=NULL;
	tmp->value=value;
	return tmp;
}

extree *constructTree(char postfix[]){
	stack<extree *> yy;
	extree *t,*t1,*t2;
	for(int i=0;i<strlen(postfix);i++){
		if(!isOperator(postfix[i]))
		{
			t=newNode(postfix[i]);
			yy.push(t);
		}
		else{
			t=newNode(postfix[i]);
			t1=yy.top(); yy.pop();
			t2=yy.top(); yy.pop();
			t->right = t1;
			t->left  = t2;
			yy.push(t);
		}
	}
	t=yy.top(); yy.pop();
	return t;
}

int main(){
	char postfix[]="ab+c*";
	extree *r=constructTree(postfix);
    inorder(r);
	return 0;
}