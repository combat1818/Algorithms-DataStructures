#include<iostream>
#include<algorithm>
#include<vector>
#include<iomanip>
using namespace std;

vector<int> *tab;
int *size;
double *morale;

int rozmiar(int v)
{
	if(tab[v].size()==0) {size[v]=1; morale[v]=1; return 1;}
	
	for(int i=0;i<tab[v].size();i++)
	{
		size[v]+=rozmiar(tab[v][i]);
	}
	morale[v]=0; 
	size[v]++;
	return size[v];
}

double moraleCalc(int v)
{
	if(tab[v].size()==0) return morale[v];
	
	for(int i=0;i<tab[v].size();i++)
	{
		morale[v]=max(morale[v], min(moraleCalc(tab[v][i])*1.0, ((size[tab[v][i]]*1.0)/(size[v]-1*1.0) ) ) );
	}
	
	return morale[v]*1.0;
}	


int main()
{
	ios::sync_with_stdio(false);
	int n,k,i,j,x;
	double out=0;
	cin>>n>>k;
	tab=new vector<int> [n+1];
	morale =new double [n+1];
	size=new int [n+1];
	
	for(i=1;i<n;i++)
	{
		cin>>x;
		tab[x].push_back(i+1);
		size[i]=0;
	}

	x=rozmiar(1);
	x=moraleCalc(1);

	
	for(i=1;i<=n;i++)
	{
		if(size[i]>k) out=max(out,morale[i]);
	}
	cout<<setprecision(10)<<out;
}