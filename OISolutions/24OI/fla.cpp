#include<iostream>
#include<algorithm>
#include <stdio.h>
using namespace std;

struct kolumna
{
	int x,gora,dol;
};

int main()
{
	int n,X,x,i,p=0,q=0,dol=0,gora=0;
	scanf("%d", &n); scanf("%d", &X);
	kolumna *tab=new kolumna [n+1];
	tab[0].x=0;
	for(i=1;i<=n;i++){scanf("%d", &x); tab[i].x=x; scanf("%d", &x); tab[i].dol=x; scanf("%d", &x); tab[i].gora=x;}//cin>>tab[i].x>>tab[i].dol>>tab[i].gora;
	
	for(i=1;i<=n;i++)
	{
	  dol-=(tab[i].x-tab[i-1].x);
	  gora+=(tab[i].x-tab[i-1].x);
	  
	  
	  if(gora<=tab[i].dol) {cout<<"NIE"; return 0;}
	  if(dol>=tab[i].gora) {cout<<"NIE"; return 0;}
	  
	  if(dol<=tab[i].dol)
	  {
	  	if(dol%2==0)
	  	{
	  		if(tab[i].dol%2==0) dol=tab[i].dol+2;
	  		else dol=tab[i].dol+1;
		}
		else
		{
			if(tab[i].dol%2==0) dol=tab[i].dol+1;
			else dol=tab[i].dol+2;
		}
	  }
	  
	  if(gora>=tab[i].gora)
	  {
	  	if(gora%2==0)
	  	{
	  		if(tab[i].gora%2==0) gora=tab[i].gora-2;
	  		else gora=tab[i].gora-1;
		}
		else
		{
			if(tab[i].gora%2==0) gora=tab[i].gora-1;
			else gora=tab[i].gora-2;
		}
	  }
	  
//	  cout<<dol<<" "<<gora<<endl;
	}
	x=(tab[n].x+dol)/2;
	printf("%d", x);


}