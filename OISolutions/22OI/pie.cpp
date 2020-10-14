#include<iostream>
#include<algorithm>
#include<vector>
#include <cstdio>
using namespace std;
const int MAXN = 1005;
int n,m,a,b;
char dokument[MAXN][MAXN], pieczec[MAXN][MAXN];
vector<pair<int,int> > polozenie;

bool przybij(int x,int y)
{
	int i,wspx,wspy;
	dokument[y][x]='.';
	for(i=0;i<polozenie.size();i++)
	{
		wspx=polozenie[i].first+x; wspy=polozenie[i].second+y;
		
		if(wspx<0 || wspx>=m || wspy<0 || wspy>=n) return false;
		else if(dokument[wspy][wspx]!='x') return false;
		else dokument[wspy][wspx]='.';
	} 
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	int q,i,j,k,l,x,y;
	bool flaga=true;
	vector<string> wyniki;
	scanf("%d", &q);
	
	for(l=0;l<q;l++)
	{
		scanf("%d%d%d%d", &n, &m, &a, &b);
		flaga=true;
		polozenie.clear();
		
		for (i = 0; i < n; i++)
	        scanf("%s", dokument[i]);
		
		for (i = 0; i < a; i++) 
	        scanf("%s", pieczec[i]);
		  
		for(i=0;i<a;i++) {
			for(j=0;j<b;j++){
				if(pieczec[i][j]=='x' && flaga) {flaga=false; x=j; y=i;}
				else if(pieczec[i][j]=='x') {polozenie.push_back(make_pair((j-x),(i-y)));}
			}
		}
		flaga=true;
		
//		for(i=0;i<polozenie.size();i++)
//	{
//		cout<<polozenie[i].first<<" "<<polozenie[i].second<<endl;
//	}
		
		for(i=0;i<n && flaga;i++)
		{
			for(j=0;j<m && flaga;j++)
			{
				if(dokument[i][j]=='x')
				{
					if(!przybij(j,i))
					{
						wyniki.push_back("NIE");
						flaga=false;
					}
				}
			}
		}
		if(flaga) wyniki.push_back("TAK");
	}
	
	for(i=0;i<wyniki.size();i++) cout<<wyniki[i]<<endl;
}



/*		for(i=0;i<polozenie.size();i++)
	{
		cout<<polozenie[i].first<<" "<<polozenie[i].second<<endl;
	}
	*/