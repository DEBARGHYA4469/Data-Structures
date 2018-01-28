//Write a program to implement Gale-Shapley Algorithm to find the best match

#include <iostream>

using namespace std;

#define Pair 5

char men[Pair] = {'A','B','C','D','E'};
char women[Pair] = {'1','2','3','4','5'};

char bride_prefered[Pair][Pair]={{'2','5','1','3','4'},{'1','2','3','4','5'},{'2','3','5','4','1'},{'1','3','2','4','5'},{'5','3','2','1','4'}};
char groom_prefered[Pair][Pair]={{'E','A','D','B','C'},{'D','E','B','A','C'},{'A','D','B','C','E'},{'C','B','D','A','E'},{'D','B','C','E','A'}};

int findbride(char bride){  //find the index of the bride
for(int i=0;i<Pair;i++)
{
	if(women[i]==bride)
		return i;
}} //find the index of the bride.

int findgroom(char groom){  //find the index of the groom
for(int i=0;i<Pair;i++)
{
	if(men[i]==groom)
		return i;
}} //find the index of the groom.

int  wishlist[Pair]={0,0,0,0,0};// index of woman from the wishlist of men

int groomXbride[Pair]={-1,-1,-1,-1,-1};
int brideXgroom[Pair]={-1,-1,-1,-1,-1};

bool allMarried(){
 	for(int i=0;i < Pair ; i++)
 		if(groomXbride[i]==-1)
 			return false;// some are still unmarried !!
 	return true;//all are married
}

bool isEngaged(int bride_wanted){
	if(brideXgroom[bride_wanted]==-1)
		return false; // bride is not engaged 
	return true;
}// check the engagement status of the bride 

void stabliseEngagement(int suitor,int bride_wanted,int her_husband){
	int suitor_index,husband_index;
	for(int i=0;i<Pair;i++)
		{
			if(groom_prefered[bride_wanted][i]==men[suitor])
				suitor_index=i;
			if(groom_prefered[bride_wanted][i]==men[her_husband])
				husband_index=i;
		}//gotcha...

		if(suitor_index < husband_index) // break the marriage
		{
			brideXgroom[bride_wanted]=suitor;
			groomXbride[suitor]=bride_wanted;
			groomXbride[her_husband]=-1;//free the husband	
			wishlist[her_husband]++;//try next one

		}
		else{           // the marriage is stable
			wishlist[suitor]++;
		}
}

void showMarriages(){
	for(int i=0;i < Pair;i++)
		{
			if(groomXbride[i]==-1)
				cout << men[i] << "will marry to " << "XXXX" <<endl;
			else
				cout << men[i] << " will marry to " << women[groomXbride[i]] << endl;
}
}




int main(){
	while(true){
		// check for all marriage stability
		if(allMarried())
			break;//done with match making
		for(int i=0;i<Pair;i++) // scan through the grooms
		{
			if(groomXbride[i]!=-1) 
				continue; // see the next groom
			int suitor = i; // now the ith groom be the suitor
			int bride_wanted  = findbride(bride_prefered[suitor][wishlist[i]]);// index no of the bride
			if(isEngaged(bride_wanted))
				{
				int her_husband = brideXgroom[bride_wanted]; // find her engaged husband  
				stabliseEngagement(suitor,bride_wanted,her_husband);// stablise the engagement
		 	    }//if
		 	//if bride is not engaged to anyone then ....
		 	    else{
		 	    	brideXgroom[bride_wanted]=suitor;
		 	        groomXbride[suitor]=bride_wanted;
		 	    }
		 	    
		 	   

		}//
		cout << endl << endl;
		showMarriages();

	}//while
	//showMarriages();   //*************************to be implemented
	return 0;
}


