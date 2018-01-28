/* Write a program to generate a doubly linked list and perform some operations */
#include <iostream>

using namespace std;

struct Node {
	int payload;
	struct Node *next; 
	struct Node *prev;
};

void push(struct Node** head,int payload){
	struct Node* newNode =(struct Node *)malloc(sizeof(struct Node));
	newNode->payload = payload;
	newNode->next = *head;
	newNode->prev=NULL;
	if((*head)!=NULL)
		(*head)->prev=newNode;
		(*head)=newNode;
}

void insertAfter(struct Node* prevNode,int payload){
	if(prevNode == NULL) return;
	struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->payload=payload; // collect the payload
	newNode->next = prevNode->next; //  connect ---> (2) 
	prevNode->next = newNode; // (1)----->(x)----->(2)
	newNode->prev =prevNode; // (1) <-----(x)
	if(newNode->next!=NULL)
		newNode->next->prev = newNode; // (1)<----(x)<------(2)
}//insert After

void append(struct Node** head,int payload){
	struct Node* newNode=(struct Node *)malloc(sizeof(struct Node));
	struct Node* last = *head;
	newNode->payload=payload;
	newNode->next=NULL;
	if(*head == NULL){
		newNode->prev =NULL;
		*head = newNode;
		return;
	}
	while(last->next != NULL)
		last = last->next; // traverse till the last node 
	last->next = newNode;
	newNode->prev= last;
	return;
}//append

void printList(struct Node *N){
	struct Node *last;
	cout << "Traversal in foreward direction.." <<endl;
	while(N != NULL){
		cout << N->payload;
		last = N;
		N=N->next;
	}
	cout << "Traversal in reverse direction .. " << endl;
	while(last != NULL){
		cout << last->payload;
		last=last->prev;
	}

}

int main(){
	struct Node* head= NULL;
	append(&head,6);
	push(&head,7);
	append(&head,9);
	insertAfter(head->next,8);
	printList(head);
	getchar();
	return 0;
	return 0; 
}




