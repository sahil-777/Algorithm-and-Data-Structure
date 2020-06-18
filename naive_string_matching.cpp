
/*
Name : Sahil S. Velhal
Github id: Sahil-777
*/

//Naive string matching

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;

 
int main() 
{
	while(1){
		int i,j;bool flag=0;
		string l,s;//l:: larger ; s:: smaller ;
		cin>>l>>s;
		
		for(i=0;i<l.size();i++){
			j=0;
			while(l[i]==s[j]){
				if(j==s.size()-1){
				flag=1;
				break;
				}
				i++;j++;
			}
		}
		
		if(flag)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	} 
 
	return 0;

}
