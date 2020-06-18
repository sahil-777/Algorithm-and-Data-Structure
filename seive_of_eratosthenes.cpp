
/*
Name : Sahil S. Velhal
Github id: Sahil-777
*/

//Seive Of Eratostenes

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
//#define int long long
#define SIZE 100001
using namespace std;
bool prime[SIZE];

void seive(){
	long long i,j;
	
	prime[0]=prime[1]=0;
	for(long long i=2;i<=SIZE;i++){
		prime[i]=1;
	}
	
	for(i=2;i<=SIZE;i++){
		if(prime[i]){
			for(j=i*i;j<=SIZE;j+=i){
				prime[j]=0;
			}
		}
	}

}
 
int main() 
{
	seive();
 	
 	for(long long i=0;i<=100;i++){
 		if(prime[i]){
 			cout<<i<<" ";
		 }
	 }
	 
  	
   

	return 0;
}
