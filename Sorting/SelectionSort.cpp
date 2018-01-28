#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int *selection(int length,int *a){
	int tmp,pos;
	for(int i=0;i < length ; i++){
		tmp = a[i];
		pos=i;
		for(int j=i+1;j < length;j++){
			if(a[j] > tmp)
			{
				tmp=a[j];
				pos=j;
			}
		}     
	
		        tmp=a[i];
				a[i]=a[pos];
				a[pos]=tmp;
	
	}
	return a;
}

int main(){
	int a[] = {2,10,4,5,7,0,12,8};
    int length=sizeof(a)/sizeof(a[0]);
    int *sorted;
	sorted=selection(length,a);
	cout  << endl;
	for(int i=0;i < length;i++)
		std :: cout << sorted[i] << " ";
	return 0;
}