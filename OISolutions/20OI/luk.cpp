#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> tree[300005];

int sprawdz(int v,int k,int ojciec)
{
	int suma=0;
	for(int i=0;i<tree[v].size();i++)
	{
		if(tree[v][i]!=ojciec) suma+=sprawdz(tree[v][i],k,v)+1;
	}
//	cout<<"suma["<<v<<"] = "<<suma<<endl;
	return max(0,suma-k);
}

int main()
{
	ios::sync_with_stdio(false);
	int n,i,j,x,y,k,l,r,mid,out=1000000000;
	cin>>n;
	if(n==1){cout<<0; return 0;}
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	
	l=1; r=n;
	while(l<r)
	{
		mid=(l+r)/2;
		if(!sprawdz(1,mid,-1))
		{
			out=min(out,mid);
			r=mid;
		}
		else
		{
			l=mid+1;
		} 
//		cout<<l<<" "<<r<<endl;
	}
	cout<<out;
	
	
	/*
	for(k=1;k<=n;k++)
	{
		if(!sprawdz(1,k,-1)) break;
	}
	
	
	
//	cout<<endl<<endl;
//	for(i=0;i<=n;i++)
//	{
//		for(j=0;j<tree[i].size();j++) cout<<tree[i][j]<<" ";
//		cout<<endl;
//	}
	
	cout<<k;
	*/
	
}