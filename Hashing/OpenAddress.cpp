// Write a program to construct a hash function using open addressing for handling collision.
#include <iostream>
using namespace std;

#define MAX 1000
int hashes[MAX];
bool state[MAX];

int F(int i){           // probing to be done ....
return i*i; // Quadratic probing.
}

void insert(int item){
  int hash_val = item % MAX;
  int i=hash_val;
  while(state[i]==true){
	if(hashes[i]==item){
	cout << "Duplicate Entry!";
	return;	
	}
	i = (i + F(i)) % MAX;
	if(i==hash_val){
	cout << "The hash is full" << endl;
	return;	
	}
}
	hashes[i] = item;
        state[i] = true;
}

void init(){
for(int i=0;i<MAX;i++)
state[i]=false;
return;
}



void search(int item){
int hash_val=item % MAX;
int i=hash_val;
int count=0;
do{
if(state[i] == true && hashes[i]== item)
{
	 cout << "Found,yeah!!" << endl;
  	 return;
}
i=(i+F(i)) % MAX;
count++;
}while(i!=hash_val && count < MAX);
return;
} // search

int main(){
insert(10);
insert(20);
insert(30);
search(30);
return 0;
}
