// Type in a program to implement quick sort
// Employ divide and conquer algorithms

#include <iostream>

using namespace std;

int partitions(int *arr,int low,int high){
//choose pivot by random
	int pivot = arr[high]; // PIVOT
	int wall=low-1; // the wall   smaller....... ||pivot||........ larger
	int y=low;
	for(int i=low;i < high;i++){
		if(arr[i] <= pivot)
			{   wall++;
				int temp = arr[i];
				arr[i] =   arr[y];
				arr[y++] = temp; // swap the variables 
 			}//if
 		}
        //swap pivot to wall's next element
 		arr[high]=arr[wall + 1];
 		arr[wall + 1 ]=pivot;
 		return wall+1;
}

void quick(int *arr,int low,int high){
	if(low < high){
	int pi=partitions(arr,low,high); // pi is the partition index
	quick(arr,low,pi-1);
	quick(arr,pi+1,high);
    }
}
int main(){
	int arr[]={4,6,2,8,9,1,2,6,7,5};
	int j,len =sizeof(arr)/sizeof(arr[0]); // the size of the array
	for(j=0;j < len;j++)
		cout << arr[j] << " "; 
	cout << endl;
	quick(arr,0,len-1);
	for(j=0;j < len;j++)
		cout << arr[j] << " "; 
	return 0;
}