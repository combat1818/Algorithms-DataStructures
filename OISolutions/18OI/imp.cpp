#include<iostream>
#include<algorithm>
using namespace std;
bool tab[3001][3001];
bool inGraph[3001];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,i,j,x,y,k=0;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		tab[x][y]=1;
		tab[y][x]=1;
	}
	
	for(i=1;i<=n;i++)
	{
		if(!inGraph[i])
		{
			for(j=1;j<=n;j++)
			{
				if(!inGraph[i] && !inGraph[j] && i!=j)
				{
					if(tab[i][j]==0)
					{
						inGraph[i]=1;
						inGraph[j]=1;
//						cout<<"OK"<<i<<j<<endl;
					}
				}
			}
		}
	}
	
//	for(i=0;i<=n;i++) cout<<inGraph[i]<<" ";
//	cout<<"XD";
	for(i=1;i<=n;i++)
	{
		if(k>=n/3) break;
		else if(!inGraph[i])
		{
			k++;
			cout<<i<<" ";
		}
	}
	
}