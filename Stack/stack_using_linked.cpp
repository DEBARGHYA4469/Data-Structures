// ................................... STACK using LINKED LIST.....................................................................

#include <iostream>

using namespace std;

struct node{
   int payload;
   struct node* link;
};

void pop(struct node** head){
	if((*head)->link == NULL) 
		{
		cout << "Stack underflow";
		return;
	}
	struct node *tmp;
	tmp = (*head)->link->link;
	(*head)->link = tmp;
}//pop
void display(struct node *N){
	while(N->link!=NULL){
		cout << "\t" << N->link->payload;
		N=N->link;
	}
}

void push(struct node** head,int payload){
	struct node* blob=(struct node *)malloc(sizeof(struct node));
	blob->payload=payload;
	blob->link=(*head)->link;
	(*head)->link = blob;
}//push

int main(){
	struct node *head ;
	head->link =NULL;
	cout << "Enter 1. Push 2. Pop 3.Display" << endl;
	int choice;
	while(true)
	{	cin >> choice  ;
		switch(choice){
			case 1:cout <<"Enter the number to push";
				   int payload;
				   cin >> payload;
				   push(&head,payload);
				   break;
			case 2:pop(&head);
				   break;
			case 3:display(head);
				   break;
		}
	}//while
	return 0;
}//main