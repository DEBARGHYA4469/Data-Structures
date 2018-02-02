#include<iostream>
using namespace std;
struct node{
	char payload;
	struct node *left;
	struct node *right;
};

struct node *newNode(char payload){
	struct node *blob=(struct node *)malloc(sizeof(struct node));
	blob->payload = payload;
	blob->left = NULL;
 	blob->right= NULL;
	return(blob);
}

// Traversal of the trees 
void postorder(struct node *N){
	if(N==NULL)
	return;
    postorder(N->left);
    postorder(N->right);
    cout << N->payload;
}
void preorder(struct node *N){
	if(N==NULL)
	return;
    cout << N->payload;
    preorder(N->left);
    preorder(N->right);   
}

void inorder(struct node *N){
	if(N==NULL)
	return;
    inorder(N->left);
    cout << N->payload;
    inorder(N->right);   
}

int main(){
	struct node *root = newNode('A');
	root->left=newNode('B');
	root->left->left=newNode('C');
	root->left->right=newNode('D');
	root->left->left->left=newNode('E');
	root->left->left->right=newNode('F');
        root->left->left->right->right=newNode('J');
	root->left->right->left=newNode('G');
	root->left->right->right=newNode('H');
	root->left->right->right->left=newNode('K');
	root->left->right->right->right=newNode('L');
	
	cout << endl << "Traversal in pre-order format  "; 	
	preorder(root);
	cout << endl << "Traversal in post-order format ";
	postorder(root);
	cout << endl << "Traversal in in-order format   ";
	inorder(root);
        return 0;
}





