#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int *bubble(int length,int *a){
	for(int i=0;i < length-1 ; i++){
		for(int j=0;j < length-i;j++){
			if(a[j] > a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
	}
	return a;
}

int main(){
	int a[] = {2,10,4,5,7,0,12,8};
    int length=sizeof(a)/sizeof(a[0]);
    int *sorted;
	sorted=bubble(length,a);
	cout  << endl;
	for(int i=0;i < length;i++)
		std :: cout << sorted[i] << " ";
	return 0;
}