// Write a program to  create a linked list dynamically which can query any elements
#include <iostream>

using namespace std;

struct node
{
   int payload; // the data to be stored 	
   struct  node* link; // the link part
};

void display(struct node* N){
while(N != NULL){
	if(N->link==NULL)
	cout << N->payload;
    else 
    cout << N->payload << "-->";
	N=N->link;
}//while
}

bool search(struct node* N,int query){
	while(N!=NULL){
		if(N->payload == query)
			return true;
		N=N->link;
	}
	return false;
}

void insert_front(struct node** N,int payload)
{
struct node* blob = (struct node *)malloc(sizeof(struct node)); // node created 
blob->payload =payload;
blob->link = *N;
*N=blob;
} // insert 

void insert_middle(struct node **N,int position,int payload){
    int counter = 1 ; 
    struct node *prev;
    struct node *post; 
    prev=*N;
    while(counter++ < position-1){
        prev=prev->link; // final link got
    }
    post=prev->link;

    struct node* blob = (struct node *)malloc(sizeof(struct node));
    blob->payload=payload;
    
    blob->link = post;
    prev->link = blob;
    //now stiching part

}

int main(){
struct node* head =NULL;
while(true){
	int choice;
        cout << "Enter 1 for insert at front\n 2 for display \n; 3 for query\n;4 for insert at pos ith" ;
        cin >> choice  ;
        switch(choice){
            case 1:cout << "Enter a number to insert"; 
                   int num;
                   cin >>  num ;
                   insert_front(&head,num);
                   break;
            case 2:display(head); 
                   break;
            case 3: cout << "Enter a number to query";
                     int query;
                     cin >> query ;
                     if(search(head,query)) { cout << "Present!";}
                         else {cout << "Absent!";}
                             break;
            case 4:cout << "Enter the position"<<endl;
                   int pos,pl;
                   cin >> pos;
                   cout << "Enter the number to be inserted"<<endl;
                   cin >> pl;
                   insert_middle(&head,pos,pl);
                   break;
    }
    }
}