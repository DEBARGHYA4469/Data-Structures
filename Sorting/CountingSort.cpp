// Write a program to employ count sort on a string of characters say the word "geeksforgeeks" 
// Count sort runs in O(n+k) asymptotic worst case time .... k->Range of string n->character set length
#include <iostream>
#include <cstring>
#define RANGE 255 // ascii character's range 

using namespace std;

void countsort(char arr[]){
    char output[strlen(arr)];   // the output array which has sorted characters
    int count[RANGE + 1],i;
    memset(count,0,sizeof(count)); // allocates a memory space for array of reqd size and all elements '0'

// store count of each characters
   for(i=0;arr[i];++i) // till null character is reached 
	++count[arr[i]];// hashing...
   
   for(i=1; i <= RANGE ; ++i)
	count[i]+=count[i-1]; // cumulative list
   for(i=0;arr[i];++i){
	output[count[arr[i]]-1] =arr[i];
	--count[arr[i]];
   }
   for(i=0;arr[i];++i)
	arr[i]=output[i];
}


int main(){
    char arr[]="debarghya";
    countsort(arr);
    cout << arr << endl; 
return 0;
}
