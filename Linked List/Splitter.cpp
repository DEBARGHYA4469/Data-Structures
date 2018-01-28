//Write a program to store some numbers from the user in a linked list and split the list into prime and composites

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

bool isprime(int i){
     int ctr =0; 
	 for(int k=1;k<=i;k++)
	 {
	 	if(i%k == 0) ctr++; 
	 }
	 if(ctr == 2) return true;
	 else return false;
}//isprime for prime check

void display(list<int> L){
	list<int> :: iterator it; ;//creator a iterator of type list int 
	for(it=L.begin();it!= L.end();it++)// print the list 
	{
		cout << ' ' <<*it;
	}//for 
}//display

int main(){

 	list<int> :: iterator ptr; 
 	list<int> natural;
    for(int N=1;N<=50;N++)
    	natural.push_back(N);
    display(natural);

    // Now  split into prime and composites

    list<int> prime ;
    list<int> composite;

    list<int> :: iterator move;

    for(move=natural.begin();move != natural.end();move++)
    {
    	if(isprime(*move)) prime.push_back(*move);
    	else composite.push_back(*move);
    }
    cout << "The sequence of primes are " << endl; 
    display(prime);
    cout <<endl<<"The sequence of composites are " << endl;
    display(composite);

	return 0;
}