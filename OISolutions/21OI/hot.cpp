#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<long long> *tab;
long long * przodek,* prefiksy,n;
bool *visited;
queue <long long> kolejka;

long long oblicz_prefiksy(long long size)
{
	long long out=0;
	if(size>=3)
	{
	for(long long i=2;i<size;i++) out+=prefiksy[i-1]*(prefiksy[i]-prefiksy[i-1])*(prefiksy[size]-prefiksy[i]);
	return out;
    }
    else return 0;
}

void prefiksy_aktualizuj(long long size)
{
	long long i;
	for(i=1;i<=size;i++) prefiksy[i]+=prefiksy[i-1];
}

void prefiksy_wyzeruj_start(void)
{
	for(long long i=0;i<=n;i++) prefiksy[i]=0;
} 

void prefiksy_wyzeruj(void)
{
	long long i=1;
	prefiksy[0]=0;
	while(prefiksy[i]) {prefiksy[i]=0; i++;} 
}

void przygotuj_tablice(void)
{
	for(long long i=0;i<=n;i++)
	{
		visited[i]=false;
		przodek[i]=0;
	}
}


long long oblicz_mozliwosci(long long v)
{
	long long out=0,i,j,x,aktualne=tab[v].size(),przyszle=0,licznik=0,size=tab[v].size();
//	kolejka.push(v);
    visited[v]=true;
			
	for(i=0;i<tab[v].size();i++)
	{
		visited[tab[v][i]]=true;
		przodek[tab[v][i]]=i+1;
		kolejka.push(tab[v][i]);
		prefiksy[i+1]=prefiksy[i]+1;
	}
	
	out+=oblicz_prefiksy(tab[v].size());
//	cout<<"XDD "<<out<<endl;
	prefiksy_wyzeruj();
	
	przyszle=aktualne;
		
	
	while(!kolejka.empty())
	{
		x=kolejka.front();
		kolejka.pop();
		licznik++;
		przyszle+=tab[x].size()-1;
		prefiksy[przodek[x]]+=tab[x].size()-1;
		
		if(licznik==aktualne)
		{
			prefiksy_aktualizuj(size);
			out+=oblicz_prefiksy(size);
//			cout<<out<<endl; ///////////////////////////////
			prefiksy_wyzeruj_start();
			aktualne=przyszle;
		}
		
				
		for(i=0;i<tab[x].size();i++)
		{
			if(!visited[tab[x][i]])
			{
				kolejka.push(tab[x][i]);
				visited[tab[x][i]]=true;
				przodek[tab[x][i]]=przodek[x];
			}
		}
	}
	
	return out;
	
}

int main()
{
	long long i,j,u,v,out=0; 
	cin>>n;
	tab=new vector<long long> [n+1];
	przodek=new long long [n+1];
	visited=new bool [n+1];
	prefiksy=new long long [n+1];
	
	prefiksy_wyzeruj_start();
	przygotuj_tablice();
	
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		tab[u].push_back(v);
		tab[v].push_back(u);
	}
		
	for(i=1;i<=n;i++)
	{
		if(tab[i].size()>=3)
		{
	//		cout<<out+oblicz_mozliwosci(i)<<endl;
			out+=oblicz_mozliwosci(i);
	//		cout<<"i= "<<i<<"  "<<out<<endl;
			prefiksy_wyzeruj();
			przygotuj_tablice();
//			cout<<endl;
		}
	}
	cout<<out;
}



/*
for(i=0;i<=n;i++)
	{
		cout<<i<<" XD  ";
		for(j=0;j<tab[i].size();j++)
		{
			cout<<tab[i][j]<<" ";
		}
		cout<<endl;
	} 
	*/