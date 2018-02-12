// Greedy algorithm to find optimal solution to selection of activities with different starting and ending time .


#include <algorithm>
#include <iostream> 

using namespace std;

struct Activity
{
	int start,finish;
};

bool compareActivity(Activity s1,Activity s2){
	return(s1.finish < s2.finish);
}

void maxActivity(Activity arr[],int n){
	sort(arr,arr+n,compareActivity);
	cout << "The order of activities ...";
	int activity=0;
	cout << "(" << arr[activity].start << ", " << arr[activity].finish << ") ,";
	for(int j=1;j<n;j++){
		if(arr[j].start >= arr[activity].finish){
			activity = j;
			cout << "(" << arr[activity].start << ", " << arr[activity].finish << ") ,";
		}
	}
}

int main(){
	Activity arr[] = {{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
	int n=sizeof(arr)/sizeof(arr[0]);
	maxActivity(arr,n);
	return 0;
}

