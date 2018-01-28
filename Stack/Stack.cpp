#include<iostream>
using namespace std;

#define MAX 10

class Stack{
   private:
 	int stk[MAX]; // the stack
	int top;
   public :
	Stack()//constructor to initialise the stack
        {  
           top = -1;
        }
 
        void push(int item)// to push elements to the stack
        {
             if(top == MAX-1){
		cout << "Stack overflow" << endl;
 		return;
                }
             top++;
             stk[top] = item;
        }

        int pop(){
	if(top == -1){
		cout << "Stack underflow" << endl;
		return 0;
         }
        int data =stk[top];
        top--;//pop the element
        return data;
    }//pop
         void display(){
      
       for(int h=top;h>=0;h--)
       cout << "| " << stk[h] << " |" << endl << "------" << endl;       
     }
};//class Stack


int main()
{
Stack S;//initialise the stack 
bool run = true;
int choice;
int item;
while(run){
  cout << "Enter 1 to push an element and the element or 2 to  pop the element"<<endl;
  cin >> choice ;
  if(choice ==1){
  cin >> item;
  S.push(item);
}
  if(choice ==2){
  cout << S.pop() << endl;
}
  else if(choice==0) {
  cout << " Terminating the stack operations ... " <<endl;
  run = false;
}
S.display();
}//while
return 0;
}
