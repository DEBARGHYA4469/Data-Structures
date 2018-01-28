#include <iostream>

using namespace std;

#define MAX 3

class Circular{	
	private:
		int cq[MAX];
		int front;
		int rear;
		int population;
	
	public:
	Circular(){
		front=rear=-1;
		population=0;
	}


	void enqueue(int payload){	
		if(population==MAX){
			cout << "Queue overflow!" << endl;
			return;
		}
		if(population==0){
			front=rear=0;
			cq[rear]=payload;
			population++;
			return;
		}
		rear =(rear+1)%MAX;
		cq[rear]=payload;
		population++;
	}

	void dequeue(){
		if(population == 0){
			cout << "Queue underflow!" << endl;
			return;
		}

		if(population == 1){
			front=rear=-1;//reset the pointers
			population--;
			return;
		}
		front =(front+1)%MAX;
		population--;
		return;
	}

	void printQueue(){
		if(population==0){
			cout << "Queue is empty" ;
			return;
		}
		if(front <= rear){
			for(int i=front;i<=rear;i++)
				cout << cq[i] << " ";
		}
		else{
			for(int i=front;i<MAX;i++)
				cout << cq[i] << " ";
			for(int i=0;i<=rear;i++)
				cout << cq[i] << " "; 
		}
	}

};

int main(){
	Circular cq;
	cout << "Press 1 for enquing,2. dequing, 3.display "<<endl;
    while(true){
    	int btn;
    	cin >> btn;
    	switch(btn){
    		case 1:	cout << "Enter payload" << endl;
    				int payload;
    				cin >> payload;
    				cq.enqueue(payload);
    				break;
    		case 2: cq.dequeue();
    				break;
    		case 3: cq.printQueue();
    				break;    				
    	}
    }
	return 0;
}
