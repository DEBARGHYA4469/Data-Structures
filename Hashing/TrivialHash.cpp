// Write a program to perform index mapping in hash function.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 
bool has[MAX+1][2];

bool search(int x){
  if(x>=0){
      if(has[x][0]==1)
 	    return true;
      else
	    return false;
          }
x=abs(x);
if(has[x][1]==1)
	return true;
return false;
}//search

void insert(int a[],int n){
   for(int i=0; i < n;i++){
	if(a[i] >= 0)
	   has[a[i]][0]=1;
	else
   	   has[abs(a[i])][1]=1;
   }
}

int main(){
	int a[]={-1,9,-5,-8,-5,-2};
 	int n=sizeof(a)/sizeof(a[0]);
	insert(a,n);
 	int x= 19;
 	if(search(x)==true)
		cout << "Present";
	else
		cout << "Not Present";
        return 0;
}







