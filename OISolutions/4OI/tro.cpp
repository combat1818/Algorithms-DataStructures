#include<iostream>
#include<algorithm>
using namespace std;

int szare[1005];

int main()
{
	ios::sync_with_stdio(false);
	int n,m,i,x,y,S=0,sum;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		szare[x]++;
		szare[y]++;
	}
	
//	for(i=0;i<=n;i++) cout<<szare[i]<<endl;

    for(i=1;i<=n;i++)
    {
    	S+=szare[i]*(n-1-szare[i]);
	}
	S/=2;
	sum=n*(n-1)*(n-2);
	sum/=6;
	cout<<sum-S;
	
}