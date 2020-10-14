#include<iostream>
#include<algorithm>
using namespace std;
long long fibb[200];
int main()
{
	long long p,k,i,j,r=0;
	cin>>p;
	fibb[0]=0; fibb[1]=1;
	i=2;
	while(i<=87)
	{
		fibb[i]=fibb[i-2]+fibb[i-1];
		i++;
	}
	
	for(i=0;i<p;i++)
	{
		cin>>k;
		j=0;
		while(fibb[j]<=k) j++;
		r=0;
		while(k>0)
		{
			if(k-fibb[j-1]<=fibb[j]-k)
				k=k-fibb[j-1];
			else
				k=fibb[j]-k;
			
			r++;	
			while(fibb[j-1]>k) j--;	
		}
		cout<<r<<endl;
	}
}