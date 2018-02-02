#include <iostream>
using namespace std;

#define GAP 10 

struct node{
	char payload;
	struct node *left;
	struct node *right;};

struct node *newNode(char payload){
	struct node *N=(struct node *)malloc(sizeof(struct node));
	N->payload = payload;
	N->left=NULL;
	N->right=NULL;
	return N; }

int levelofnode(struct node *root,char target,int level){
	if(root == NULL)
		return 0;
	if(root->payload== target)
		return level;
	int downlevel = levelofnode(root->left,target,level+1);
	if(downlevel!=0)
		return downlevel;
	downlevel = levelofnode(root->right,target,level+1);
	return downlevel;


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

bool lookup(struct node *root,char target){
	if(root != NULL){
		if(root->payload==target)
			return true;
		if(lookup(root->left,target))
			return true;
		else if(lookup(root->right,target))
			return true;
	}
	return false;

	}

int size(struct node *root){
	if(root == NULL)
		return 0;
	return (size(root->left) + 1 + size(root->right));}

int maxDepth(struct node *root){
	if(root == NULL)	
	return 0;

	int left_path = maxDepth(root->left);
	int right_path= maxDepth(root->right);
	if(left_path > right_path)
	return(left_path+1);
	else 
	return(right_path+1);	
}

int main(){
	// begin-tree
	struct node *root = newNode('A');
	root->left = newNode('B');
	root->left->left = newNode('C');
	root->left->right= newNode('D');
	root->left->left->left= newNode('E');
	root->left->left->right= newNode('F');
	root->left->left->left->left= newNode('I');
	root->left->right->left= newNode('G');
	root->left->right->right= newNode('H');
	//end-tree
	displayTree(root,0);
	if(lookup(root,'R')) cout << "Present !" << endl;
	else cout << "Absent!" << endl; 
	cout << "size of the tree is:" << size(root);
	cout << "Depth of the tree is:" << maxDepth(root) <<endl;
	cout << "Level of the node is:" << levelofnode(root,'I',1)-1 << endl;
	return 0;
}