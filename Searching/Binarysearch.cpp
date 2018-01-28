// Write a code that computes binary search 
// by Divide and Conquer Approach

#include <iostream>
using namespace std;

int binarysearch(int *arr,int low,int high,int e)
{
	if(low > high)
		return -1;
	int mid = (high+low)/2;
	if(arr[mid]==e)
		return mid;
	if(arr[mid] >e)
		return binarysearch(arr,low,mid-1,e);
	if(arr[mid] <e)
		return binarysearch(arr,mid+1,high,e);
}

int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int len =sizeof(arr)/sizeof(arr[0]);
	int e = 9;//element to be searched.
	int index=binarysearch(arr,0,len-1,e);
	cout << "The number " << e << "occurs at " << index;		
	return 0;
}