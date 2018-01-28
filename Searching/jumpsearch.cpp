// Code that implemenst jump search Big O(sqrt(n))

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int jumpsearch(int arr[],int x,int n){
int step = sqrt(n); // optimised code...
int prev = 0;
while(arr[min(step,n)-1] < x){
prev = step;
step+=sqrt(n);
if(prev >= n)
return -1;
}
while(arr[prev] < x){
prev++;
if(prev == min(step,n))
return -1;
}
if(arr[prev] == x)
return prev;
return -1;
}



int main(){
int arr[]={0,1,1,2,3,5,13,21,34,55,89,144,233,377,610};
int x=55;
int n=sizeof(arr)/sizeof(arr[0]); // size of the array...
int index = jumpsearch(arr,x,n);//search x in array arr
cout << "Number " << x << "is at index: "<<index;
return 0;
}
