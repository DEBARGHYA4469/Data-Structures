//Write a program to practise object oriented programming in C++.
//store the information (Address,Area,Cost,Rooms) of the house and create an array of objects.
//the program should take input of room and cost and display the available rooms.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class House{
private :	
   string address;
   float area;
   int cost;
   int rooms;
public:
     House(){
    address ="";
    area = 0.0;
    cost =2;
    rooms=4; 
};

public:
   void set_records(string A,float Area,int C,int R){
	address = A;
	area = Area;
	cost =C;
        rooms = R;
}
public:
   void display_house(){
   cout << "Address:" << address << endl << "Area:"<< area << "cost:"<< cost << endl;
}
};

int main()
{
cout << "Data entry......press 0 for exit " << endl;
string addr; int rooms ; int cost ; float area; 
House house[100];
int ctr=0;
while(1){
cin >> addr;
cin >> area;
cin >> cost;
cin >> rooms;  
if (rooms == 0)
break;
house[ctr++].set_records(addr,area,cost,rooms);
}//while

for(int i=0;i<ctr;i++){
house[i].display_house();
}
return 0;
}

