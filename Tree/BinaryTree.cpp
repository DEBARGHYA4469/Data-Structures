// Not completed............


#include <iostream>
using namespace std;

struct node
{
	int payload;
	struct node *left; // left child 
	struct node *right;//right child
};

struct node *createNode(int payload){
	return (struct node *)malloc(sizeof(struct node));
}
//Implement the interfaces
int  left(struct node *v){
	return v->left->payload; 
}
int right(struct node *v){
	return v->right->payload;
}
bool  hasLeft(struct node *v){
	if(v->left == NULL)
		return false;
	return true;
}
bool hasRight(struct node *v){
	if(v->right == NULL)
		return false;
	return true;
}
bool isInternal(struct node *v){
	if(v->right == NULL && v->left == NULL)
		return false;
	return true;
}
bool isExternal(struct node *v){
	if(v->right == NULL && v->left == NULL)
		return true;
	return false;
}
/*int height(struct node *root,struct node *v){
		if(isExternal(v)) return 0;
		int h=0;
		h=max(h,height(v->left),height(v->right));
		return h+1;
}

bool isRoot(struct node *root,struct node *v){
if(height(root,root) == height(root,v))
	return true;
return false;
}
int size(struct node *node){ // pass root to find size of the tree.
	if(node == NULL)
		return 0;
	else 
		return(size(node->left)+1+size(node->right));
}
bool isEmpty(struct node *root){
	if(root==NULL)
		return true;
	return false;
}
int depth(struct node *root,struct node *v){
	if(isRoot(root,v)) 
		return 0;
	else
		return(1 + depth(root,parent(root,v->payload)));
}*/


struct node *parent(struct node *root,int payload){ // find parent of node v
    static bool flag=false;
    static struct node *p=NULL;
    if(root==NULL)
        return NULL;
    if(root->payload == payload)
        return root;
    if(parent(root->left,payload)!=NULL || parent(root->right,payload) !=NULL)
	{
		if(flag==false)
			p=root;
	    flag = true;
	    return p;
    }
    return NULL;
}

int main(){
	cout << "Binary Tree..." <<endl;
    struct node *root=NULL;
	root=createNode(10);
	root->left=createNode(20);
	root->right=createNode(30);

	cout << left(root)<< endl;
}



