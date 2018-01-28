#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int *insertion(int length,int *a){
	
	int key,j;
	for(int i=1;i<length;i++) // outer loop which creates ith sorted list and l-i unsorted
	{
		key = a[i];
        j=i-1;
	while(j>=0 && a[j] > key){
		a[j+1]=a[j];
		j--;
	}
	a[j+1]=key;
	}
	return a;
}

int main(){
	int a[] = {2,10,4,5,7,0,12,8};
    int length=sizeof(a)/sizeof(a[0]);
    int *sorted;
	sorted=insertion(length,a);
	cout  << endl;
	for(int i=0;i < length;i++)
		std :: cout << sorted[i] << " ";
	return 0;
}