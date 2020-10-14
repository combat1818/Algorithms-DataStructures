#include<iostream>
#include<algorithm>
#include<vector>
#include <stdio.h>
using namespace std;

int main()
{
	int n,a,b,c,x,y,z;
	vector<int> tab;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	tab.push_back(a); tab.push_back(b); tab.push_back(c);
	sort(tab.begin(),tab.end());
	
	for(int i=0;i<n-3;i++) scanf("%d%d%d", &x, &y, &z);
	
//	for(int i=0;i<3;i++) cout<<tab[i]<<" ";
	
	if(tab[0]+1==tab[1] && tab[1]+1==tab[2]) printf("TAK");
	else if(tab[0]==0 && tab[1]==n-2 && tab[2]==n-1) printf("TAK");
	else if(tab[0]==0 && tab[1]==1 && tab[2]==n-1) printf("TAK");
	else if(n%2==0) printf("TAK");
	else if(n%2!=0) printf("NIE");
	
}