/* Priority Queue is a data structure for maintaining a set S of elements,each with a key.It is based on heap structure.
A priority queue has the following operations :
	i> INSERT(S,x) : S <- S U {x}
       ii> MAXIMUM(S) : returns the elements of S with the largest key.
      iii> EXTRACT-MAX(S) : removes and returns the elements of S with largest key.
Application : To schedule jobs based on priority.
Array based implementation.We employ a method called LAZY DELETION.
*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define MAX 10

class Queue{
private:
	int queue[MAX]; // the queue
	int front;
	int rear;
public:
	Queue()//constructor
	{
		front=rear=-1;
	};

	void insert(int payload){  // insertion at the rear end
		if(rear == MAX-1)
			{
				cout << "Queue overflow" <<endl;
				return;
			}
		queue[++rear]=payload;
		front=0;
		int len=rear-front+1;
		int pq[len];
		for(int i=0;i<len;i++)
			pq[i]=queue[i];
		sort(pq,pq+len,greater<int>());
		for(int i=0;i<len;i++)
			queue[i]=pq[i];

	}

	void lazy_del(){  // lazy_deletion at the front end
		if(front==-1) {
			return;
		}
		if(front==rear){
			front=rear=-1;
			cout << "Queue is empty";
			return;
		}
		front++;
	}

	void display(){
		for(int i=front;i <= rear;i++)
			cout << queue[i] << " ";
	}

};

int main(){
	Queue Q;
	cout << "Press 1 for insert,2. lazy_deletion,3.display"<<endl;
    while(true){
    	int btn;
    	cin >> btn;
    	switch(btn){
    		case 1:	cout << "Enter payload" <<endl;
    				int pay;
    				cin >> pay;
    				Q.insert(pay);
    				break;
    		case 2: Q.lazy_del();
    				break;
    		case 3: Q.display();
    				break;    				
    	}
    }
	return 0;
}
