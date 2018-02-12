#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	int freq;
	Node *left,*right;

	Node(char data,int freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(Node *l,Node *r){
		return (l->freq > r->freq);
	}
};


void printCodes(struct Node *root,string str){
	if(root == NULL)
		return;
	if(root -> data != '$')
		cout << root->data << ": " << str << '\n';
	printCodes(root->left,str+"0");
	printCodes(root->right,str+"1");
}

void HuffmanCodes(char data[],int freq[],int size){
	struct Node *left,*right,*top;
	priority_queue< Node*,vector<Node *>,compare > minHeap;

	//create a min-heap from the data
	for(int i=0; i < size ; i++)
		minHeap.push(new Node(data[i],freq[i]));

	//run till 1 element found
	while(minHeap.size() !=1){
		left  = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new Node('$',left->freq + right->freq);
		top->left = left ;
		top->right = right ;
		minHeap.push(top);
	}
	printCodes(minHeap.top(),"");
}

int main(){
	char arr[] = {'a','b','c','d','e','f'};
	int freq[] = {5,9,12,13,16,45};
	int size = sizeof(arr)/sizeof(arr[0]);
	HuffmanCodes(arr,freq,size);
	return 0;
} 