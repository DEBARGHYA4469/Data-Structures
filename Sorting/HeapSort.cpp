// Designing a MAX-Heap

#include <iostream>
using namespace std;

void swap(int *var1,int *var2){
int tmp;
tmp  = *var2;
*var2 = *var1;
*var1 = tmp;
}

void heapify(int *arr,int size,int root_i){
	int max_i = root_i;
	int left_child,right_child;
	left_child = 2*root_i + 1;
	right_child= 2*root_i + 2;
   
        if(arr[left_child] > arr[max_i] && left_child < size) // ensure left child is there 
		max_i = left_child;
        if(arr[right_child]> arr[max_i] && right_child < size)// ensure right child is there	
		max_i = right_child;
   	if(max_i != root_i)
	        {
                	 swap(&arr[max_i],&arr[root_i]);
			 heapify(arr,size,max_i); // cure the affected branch
  		} // if 
}// heapify

void sort(int *arr,int size){
  // first build a heap from the data 
 for(int i=size/2-1;i>=0;i--)
	heapify(arr,size,i);//heapify the binary heap rooted at ith index. 
 // Pop the topmost element from max-heap and rebuild the heap.
 for(int i=size-1;i>=0;i--)
     {
  	swap(&arr[0],&arr[i]); // The largest element goes at last followed by others in order
	heapify(arr,i,0); // heapify on affected sub-tree excluding the sorted tail
     }
}

int main(){
int arr[]= {2,6,7,3,4,9,0,7,8,4,1};
int size=sizeof(arr)/sizeof(arr[0]);// the size of the heap 
sort(arr,size);
for(int i=0;i<size;i++)
cout << arr[i] << " "; 
return 0;
}
