// program to implement chain hash algorithms.

#include <iostream>
using namespace std;

#define MAX 7

struct hashes{
   int val;
   struct hashes *next;
};

struct hashes *(lookup_table[MAX]);

void initHash(){
	for(int i=0;i<MAX;i++)
	{
          lookup_table[i]=(struct hashes *)malloc(sizeof(struct hashes));
}
}

void insert(int val){
    int hash_index = val % MAX;
    struct hashes *blob = (struct hashes *)malloc(sizeof(struct hashes));
	blob->val=val;
        blob->next=lookup_table[hash_index]->next;	
	lookup_table[hash_index]->next = blob;	
}

void search(int val){
	int hash_index=val % MAX;
	struct hashes *start=lookup_table[hash_index];	
	while(start!=NULL){
		if(start->val==val){
			cout << "Found! , yeah" << endl;
			return;
  		}
		start = start->next;
	}
       cout << "Not found" << endl;
}


int main(){
cout << "Program to implement mechanisms of chain hashing" << endl;
initHash();
insert(10);
insert(20);
insert(30);
insert(40);
insert(48);
insert(80);
search(30);
search(15);
return 0;
}

