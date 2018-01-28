#include <iostream>
#include <list>
#include <iterator>

using namespace std;


void display(list<int> L){
	list<int> :: iterator ptr ;
	for(ptr=L.begin();ptr!=L.end();ptr++)
		cout << "\t" << *ptr;
		cout << '\n';
}//display

int main(){
	list<int> list1;
	for(int i=1 ; i<= 10; i++ ){
		list1.push_back(i);
	}
	display(list1);
	return 0;
}