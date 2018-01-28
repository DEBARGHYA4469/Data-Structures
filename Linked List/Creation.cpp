#include <iostream>

using namespace std; 

struct node
{
	int payload;
	struct node *link; // pointer to the same structure 
}; 

struct node *head =NULL; // make it global 
struct node *curr =NULL; // make it global

void printList(){
	struct node *ptr =head;
	cout << "The linked list is " << endl;
	while(ptr != NULL){
		if(ptr->link != NULL)
		cout << ptr->payload << "-->";
		else cout << ptr->payload ;
		ptr=ptr->link;
	}
	cout << endl;
}//print list 

void insert(int payload){
	struct node *blob =(struct node*)malloc(sizeof(struct node)); // dynamically allocate the linked list
    blob->payload=payload;
    blob->link = head;//add at the beginning
    head = blob;
}//insert the elements

int main(){
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	printList();
	return 0;
}

