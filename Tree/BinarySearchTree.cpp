//Type in a program to create a BST and code its operations
#include <iostream>
using namespace std;

#define GAP 10

struct node
{
	int payload;
	struct node *left;
	struct node *right;
};

struct node *newNode(int payload){
	struct node *N = (struct node *)malloc(sizeof(struct node));
	N->payload=payload;
	N->left=NULL;
	N->right=NULL;
	return N;
}

void InorderBST(struct node *node) // inorder traversal of  BST gives a sorted list
{	
	if(node == NULL)
		return;
    InorderBST(node->left);
    cout << node->payload << " " ;
    InorderBST(node->right);
}

void displayTree(struct node *root,int space){
		if(root==NULL)
			return;
		space=space + GAP;
		displayTree(root->right,space);
		cout << "\n" ;
		for(int i = GAP;i < space ; i++)
			cout << " ";
		cout << root->payload << "\n";
		displayTree(root->left,space);}

struct node *insert(struct node *node,int payload){
	if(node == NULL) return newNode(payload);
	if(payload < node->payload)
		node->left = insert(node->left,payload);
	else node->right=insert(node->right,payload);
	return node;
}

int main(){
	struct node *root =NULL;
	root=insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	displayTree(root,0);
	InorderBST(root);
	return 0;
}