
/*
Name : Sahil S. Velhal
Github id: Sahil-777
*/

// Binary_Serach

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

int binary_search(int A[],int target,int N){
	int left=0;
	int right=N-1;
	int mid=left+(right-left)/2;
	
	while(left<=right){
		mid=left+(right-left)/2;
		if(A[mid]==target){
			return mid;
		}
		else if(A[mid]<target){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	return -1;
}


int main() 
{
	int N;
	cin>>N;
	int A[N];
	int i,j;
	for(i=0;i<N;i++){
		cin>>A[i];
	}
	int target;
	cin>>target;
	
	sort(A,A+N);
	cout<<binary_search(A,target,N)<<"\n";
	
	return 0;
}
