// Write a program to demonstrate the design of a simple 2-level BST
#include <iostream>

using namespace std;

struct  node
{
	int payload;
	struct node *left;
	struct node *right;  
};

struct node* InsertNode(int payload){
	struct node *blob=(struct node *)malloc(sizeof(struct node));

	blob->payload=payload;
	blob->left=NULL;
	blob->right=NULL;
	return blob;
}
int main(){
	struct node *root=InsertNode(1);
	root->left=InsertNode(2);
	root->right=InsertNode(3);
	root->left->left=InsertNode(4);
	getchar();
	return 0;
	/*
				1
			   / \
			  2   3
			 /   
			4  

	*/
}