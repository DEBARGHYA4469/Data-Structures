#include<iostream>
using namespace std;

template<class Temp>
class something{
	public :
	    Temp a[2];
            Temp add();
            something();
};

template<class Temp>
something<Temp> :: something(){
  cin >> a[0] >> a[1];
}

template<class Temp>
Temp something<Temp>::add(){
return a[0]+a[1];
}
int main(){
something<float> intsomething;
cout << intsomething.add();
}
