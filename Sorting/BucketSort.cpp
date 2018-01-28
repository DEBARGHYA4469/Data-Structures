//Bucket sort is a linear time sorting algorithm for 
//closely related fractional numbers 0 to 1.0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucketsort(float arr[],int n){
	vector<float> b[n]; //n empty buckets(array of vectors)
	for(int i=0;i<n;i++){
	int bi=n*arr[i]; // index in bucket max can be n
	b[bi].push_back(arr[i]);
	}

	//sort individual buckets
	for(int i=0;i<n;i++)
		sort(b[i].begin(),b[i].end());
	int index=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<b[i].size();j++)
			arr[index++]=b[i][j];
}//bucket sort 


int main(){
	float arr[]={0.897,0.565,0.656,0.1234,0.665,0.3434};
	int n=sizeof(arr)/sizeof(arr[0]);
	bucketsort(arr,n);	
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	return 0;
}