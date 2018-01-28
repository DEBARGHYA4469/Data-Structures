//Write a program to rotate a linked list about a pivot.
#include <iostream>
#include <list>
#include <iterator>

using namespace std;

void printlist(list<int> l){
	list<int> :: iterator ptr;
	ptr = l.begin();
	while(ptr != l.end()){
		cout << (*ptr) << " ";
		ptr++;
		}
}

void rotatelist(list<int> l,int pv){
	list<int> rl;
	list<int> :: iterator ptr;
	ptr = l.begin();
	while( pv--> 0){
		ptr++;
	}
	list<int> :: iterator go;
	go=ptr;
	while(go != l.end()){
		//cout << (*go) ;
		rl.push_back(*go); 
		go++;
	}
	go=l.begin();
	while(go!=ptr){
		//cout << " " << (*ptr);
		rl.push_back(*go);
		go++;
	}
	printlist(rl);
}

int main(){
	list<int> ll;
	list<int> :: iterator t;

	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.push_back(40);
	ll.push_back(50);
	ll.push_back(60);

    int pivot = 3;

	printlist(ll);
	cout << endl;
	rotatelist(ll,pivot);

	return 0;
}