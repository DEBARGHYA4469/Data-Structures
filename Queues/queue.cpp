#include <iostream>
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
	}

	void del(){  // deletion at the front end
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
	cout << "Press 1 for insert,2. deletion,3.display"<<endl;
    while(true){
    	int btn;
    	cin >> btn;
    	switch(btn){
    		case 1:	cout << "Enter payload" <<endl;
    				int pay;
    				cin >> pay;
    				Q.insert(pay);
    				break;
    		case 2: Q.del();
    				break;
    		case 3: Q.display();
    				break;    				
    	}
    }
	return 0;
}
