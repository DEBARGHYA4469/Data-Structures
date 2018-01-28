#include <iostream>
using namespace std;

void printarray(int *arr,int len){
for(int i=0;i<len;i++)
	cout << arr[i] << " ";
}

int shellsort(int arr[],int n){
	//Start with a big gap reduce it to 1 where insertion sort happen
	for(int gap=n/2;gap>0;gap/=2){
		for(int i=gap;i<n;i+=1){
			int tmp = arr[i];
			int j;
			for(j=i;j>=gap && arr[j-gap]>tmp;j-=gap)
				arr[j]=arr[j-gap];
			arr[j]=tmp;
		}
	}
		return 0;
}

int main(){
	int arr[]={12,23,443,54,64},i;
	int n=sizeof(arr)/sizeof(arr[0]);
	printarray(arr,n);
	shellsort(arr,n);
	printarray(arr,n);
	return 0;
}