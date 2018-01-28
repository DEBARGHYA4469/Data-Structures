// algorithm for merge sort 

#include <iostream>
using namespace std; 

void merge(int left,int  mid,int right,int *arr){      // MERGING OF TWO LISTS 
	int llen,rlen;
	rlen = right - mid; 
	llen = mid - left + 1; // include the mid in left 
	
	int L[llen],R[rlen];

	int i,j,k;
	for(i=0;i<rlen;i++)
		R[i] = arr[mid+1+i];
	for(i=0;i<llen;i++)
		L[i] = arr[left+i];

	i=j=0;
	k=left;
	while(i < llen && j < rlen){
		if(L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else{
			arr[k++] = R[j++];
		}
	}
	//copy the remaining element!
	while(i < llen){
		arr[k++]=L[i++];
	}
	while(j < rlen){
		arr[k++]=R[j++];
	}
}

void sort(int lt,int rt,int arr[]){
	if(lt < rt){
	int mid = lt + (rt - lt)/2; 
	sort(lt,mid,arr);
	sort(mid+1,rt,arr);
	merge(lt,mid,rt,arr);
}
}

int main(){
	int arr[]={4,3,1,7,8,2,5,9,1,6}; // unsorted array
	int len =sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i < len;i++)
		cout << arr[i] << " "; 
	    cout << endl;
	sort(0,len-1,arr);
	//merge(0,4,9,arr);
	for(int i=0;i < len;i++)
		cout << arr[i] << " "; 
}