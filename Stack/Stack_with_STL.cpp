#include<iostream>
#include<stack>

using namespace std;

void display(stack<int> S){
stack<int> tmp = S;
while(!tmp.empty()){
   cout << '\t' << tmp.top();
   tmp.pop();
}//pop and show the elements
cout << '\n';
}


int main(){
     stack<int> stk;
     stk.push(10);
     stk.push(20);
     stk.push(30);
     stk.pop();
     display(stk);
     cout << stk.size()  << endl;
     cout << stk.top() << endl;
     return 0;
}//main
