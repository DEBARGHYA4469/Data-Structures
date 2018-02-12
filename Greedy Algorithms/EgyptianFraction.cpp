// Greedy algorithm to solve to Egyptian Fraction Optimally
// Logic 
/*
 let frac = a/b
     (a/b) E [1/N,1/(N-1)]
      a/b = 1/N + red-frac
      red-frac = (aN-b)/bN
         also,  <i> a/b < 1/N => aN-b > 0 
                <ii>a/b > 1/(N-1) => aN-b < a
                Hence tend to 1
*/
#include <iostream>

using namespace std;

void Egyptian(int num,int deno){
	if(num == 0 || deno == 0) return;
	if(deno%num == 0){
		cout << "1/" << deno/num;
		return;
	}
	if(num % deno == 0){
		cout << num/deno;
		return;
	}
	if(num > deno){
		cout << num/deno << " +";
		Egyptian(num%deno,deno);
		return;
	}

	int n = deno/num + 1 ;
	cout << "1/" << n << " +";
	Egyptian(num*n-deno,deno*n);
}


int main(){
	int num = 101 ,deno = 145;
	cout << "Egyptian Fraction Representation is ..." << endl;
	Egyptian(num,deno);
	return 0;
}
