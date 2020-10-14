#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> t[1000005];
int ojciec[30005],gle[30005];
int ancestor[30005][21];
int n;

void make_ojciec_gle(int v)
{
	int u,i,j;
	queue<int> Q;
	ojciec[v]=v;
	gle[v]=0;
	Q.push(v);
	while(!Q.empty())
	{
		u=Q.front();
		Q.pop();
		for(i=0;i<t[u].size();i++)
		{
			if(!ojciec[t[u][i]])
			{
				gle[t[u][i]]=gle[u]+1;
				ojciec[t[u][i]]=u;
				Q.push(t[u][i]);
			}
		}
	}
}

void make_ancestor()
{
	for(int x=1;x<=n;x++) 
		ancestor[x][0]=ojciec[x];
	for(int k=1;k<=20;k++)
	{
		for(int x=1;x<=n;x++)
			ancestor[x][k]=ancestor[ancestor[x][k-1]][k-1];
	}	
}
/*
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=20;j++)
			cout<<ancestor[i][j]<<" ";
		cout<<endl;	
	}
}*/

int find_LCA(int A, int B)
{
	if(gle[B]<gle[A]) swap(A,B);
//	cout<<A<<"  "<<B<<endl;
	for(int k=20;k>=0;k--)
	{
//		cout<<"k= "<<k<<"  "<<ancestor[B][k]<<endl;
		if(gle[ancestor[B][k]]>=gle[A])
			B=ancestor[B][k];
	}
	if(A==B) return A;
	
	for(int k=20;k>=0;k--)
	{
		if(ancestor[A][k]!=ancestor[B][k])
		{
			A=ancestor[A][k];
			B=ancestor[B][k];
		}
	}
	return ojciec[A];
}


int main()
{
	int i,j,x,y,A,B,m,out=0,current=1;
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>x>>y;
		t[x].push_back(y);
		t[y].push_back(x);
	}
	cin>>m;
	make_ojciec_gle(1);
	make_ancestor();
	for(i=0;i<m;i++)
	{
		cin>>x;
		y=find_LCA(current,x);
		
		out+=abs(gle[y]-gle[current])+abs(gle[x]-gle[y]);
//		cout<<"i= "<<i<<"  "<<current<<" "<<y<<" "<<x<<"   "<<gle[current]<<" "<<gle[y]<<" "<<gle[x]<<" "<<out<<endl;
		current=x;
	}	
	cout<<out;
	
}