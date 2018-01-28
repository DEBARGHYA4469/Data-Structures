// containers : data structure to hold data.
// vectors are containers
// they are arrays with extended use

#include<iostream>
#include<vector>
using namespace std;
int main(){
  vector<int> v(10);
  for(int i=0;i<v.size();i++){
	v[i]=i*10;
	cout << v[i] << endl;
}
cout << v.empty() << endl; //check empty or not
v.push_back(5);//append to end
v.resize(15);

for(int i=0;i<v.size();i++){
cout << v[i] << endl;
}

for(int i=0;i<v.size();i++){
cout << v[i] <<endl;
}

vector<int> v1 =v;//stores v into v1
}
