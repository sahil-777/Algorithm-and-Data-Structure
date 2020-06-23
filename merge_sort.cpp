/*
Name : Sahil S. Velhal
Github id: Sahil-777
*/

// Merge-sort

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

void merge(int A[], int l, int m, int r){
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2],i,j;
 
	for(i=0;i<n1;i++)
		L[i]=A[l+i];
	
	for(j=0;j<n2;j++)
		R[j]=A[m+1+j]; 
	
	int k=l;i=0;j=0;
	while((i<n1)and(j<n2)){
		if(L[i]<=R[j]){
			A[k]=L[i];
			i++;
		}
		else{
			A[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		A[k]=L[i];
		i++;k++;
	}
	
	while(j<n2){
		A[k]=R[j];
		j++;k++;
	}
}

void mergesort(int A[], int l, int r){
	if(l<r){
		int m=l+(r-l)/2;
		 
		mergesort(A,l,m);
		mergesort(A,m+1,r);
		
		merge(A,l,m,r);
	}
}

int main(){
	int N;
	cin>>N;
	int A[N];
	for(int i=0;i<N;i++)
		cin>>A[i];
 		
	for(int i=0;i<N;i++)
	cout<<A[i]<<" ";
	cout<<"\n";	
		
	mergesort(A,0,N-1);
	cout<<"\n";
	for(int i=0;i<N;i++)
	cout<<A[i]<<" ";
	cout<<"\n\n";
}
