#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool dzialka[2001][2002];
int pom[2001][2002];
int n;
stack<pair<int,int> > S;
void wpisz()
{
	cin>>n;
	for(int i=0;i<=n;i++) dzialka[0][i]=1;
	for(int i=0;i<=n;i++) dzialka[i][n+1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>dzialka[i][j];
}

void przygotuj()
{
	for(int j=1;j<=n+1;j++)
		for(int i=1;i<=n;i++)
			pom[i][j]= dzialka[i][j]==1? i: pom[i-1][j];
}

void clear()
{
	while(!S.empty())
		S.pop();
}

int oblicz()
{
	int out=0,yp,xp;
	
	for(int y=1;y<=n;y++)
	{
		clear();
		for(int x=1;x<=n+1;x++)
		{
			yp=pom[y][x];
			xp=x;
			while(!S.empty() && S.top().second<yp+1)
			{
				out=max(out,(x-S.top().first)*(y-S.top().second+1));
//				cout<<(x-S.top().first)*(y-S.top().second+1)<<endl;
				xp=S.top().first;
				S.pop();
			}
			
		if((S.empty() && yp<y) || (!S.empty() && S.top().second>=yp+1))
			S.push(make_pair(xp,yp+1));
		}
		
	}
	return out;
}
/*
void print()
{
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
			cout<<dzialka[i][j]<<" ";
		cout<<endl;	
	}
}

void printpom()
{
	for(int i=0;i<=n+1;i++)
	{
		for(int j=0;j<=n+1;j++)
			cout<<pom[i][j]<<" ";
		cout<<endl;	
	}
}
*/

int main()
{
	ios::sync_with_stdio(false);
	wpisz();
	przygotuj();
//	print();
//	cout<<endl;
//	printpom();
	cout<<oblicz();
	
	

}