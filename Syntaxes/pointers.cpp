#include<iostream>
using namespace std;

int main(){
int x=5;
cout << &x << endl; // prints the address of x
int *ptr = &x;
cout << *ptr << "  " << ptr << endl;// *ptr holds the values and ptr holds the address
return 0;
}
