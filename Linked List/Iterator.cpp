// Iterators are used to point at the memory addresses of STL containers.
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
int main(){
vector<int> arr = {1,2,3,4,5};
vector<int> :: iterator ptr; // declaring iterator to a vector
cout << "The vector elements are " ;
for(ptr = arr.begin() ; ptr < arr.end();ptr ++ )
cout << *ptr << " " ;
return 0;
}//main 
