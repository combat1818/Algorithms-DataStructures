#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include <stdio.h>
using namespace std;
bool czyNaD[50005];


int main()
{
//	ios::sync_with_stdio(false);
	int n,i,j,x,y;
	stack <int> S,D;
	vector<int> wyniki,odwroc;
    scanf("%d", &n);
	for(i=0;i<2*n;i++)
	{
		scanf("%d", &x);
	//	S.push(x);
	    odwroc.push_back(x);
	}
	
	for(i=odwroc.size()-1;i>=0;i--) S.push(odwroc[i]);
//	cout<<endl;
	
	
	while(!S.empty())
	{
		x=S.top();
		S.pop();
		if(czyNaD[x]==false)
		{
			czyNaD[x]=true;
			D.push(x);
		}
		else
		{
			j=D.size();
			y=D.top();
			D.pop();
			czyNaD[y]=false;
			if(x!=y)
			{
				wyniki.push_back(j);
				S.push(y);
				S.push(x); 
			}
		}
	}
	cout<<wyniki.size()<<endl;
	for(i=0;i<wyniki.size();i++) 
	{
		x=wyniki[i];
		printf("%d\n", x);
	}//cout<<wyniki[i]<<endl;
}