//using template to overcome Function overloading.

#include<iostream>
using namespace std;

int add(int a,int b){
return a+b;
}

template <typename Temp>
Temp add(Temp a,Temp b){ // template function
return a+b;
}

int main(){
cout<< add<int>(20,10)<<endl;
cout<< add<float>(1.5,5.9)<<endl;
}
