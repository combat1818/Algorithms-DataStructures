#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct kandydat{
	int x,y,kandydat,indeks,liczx,liczy;
};
const int LEAF_COUNT=524288;
int paczki[500005], wystapienia[500005];
kandydat kandydaci [500005];
pair<int,int> tree[2*LEAF_COUNT];
vector<int> wyniki;

pair<int, int> merdz(pair<int,int> a, pair<int,int> b)
{
	if(a.first==b.first && a.first) return make_pair(a.first, a.second+b.second);
	else if(a.first==b.first && !a.first) return make_pair(0,0);
	else if(a.first!=b.first)
	{
		if(a.first && b.first)
		{
			if(a.second>b.second) return make_pair(a.first, a.second-b.second);
			else if(b.second>a.second) return make_pair(b.first, b.second-a.second);
			else if(a.second==b.second) return make_pair(0,0);
		}
		else if(a.first && !b.first) return make_pair(a.first, a.second);
		else if(!a.first && b.first) return make_pair(b.first, b.second);
	}
}

void aktualizuj_drzewo(int x)
{
	x+=LEAF_COUNT;
	while(x!=0)
	{
		x/=2;
		tree[x]=merdz(tree[2*x],tree[2*x+1]);
	}
}

int kandydant_na_przedziale(int x, int y)
{
	int kandydat,i;
	pair<int, int> p=make_pair(0,0);
	x+=LEAF_COUNT; y+=LEAF_COUNT;
	
	wyniki.push_back(x); wyniki.push_back(y);
	
	while(x/2 != y/2)
	{
		if(x%2==0) wyniki.push_back(x+1);
		if(y%2==1) wyniki.push_back(y-1);
		x/=2; y/=2;
	}
	
	for(i=0;i<wyniki.size();i++)
	{
		p=merdz(p,tree[wyniki[i]]);
	}
	wyniki.clear();
	return p.first;
}

bool cmp1( kandydat a, kandydat b ) {
   return a.x < b.x;
 }
 
bool cmp2(kandydat a, kandydat b){
	return a.y<b.y;
}

bool cmp3(kandydat a, kandydat b){
	return a.indeks<b.indeks;
}

int main()
{
	ios::sync_with_stdio(false);
	int n,m,i,j=0,x,y,dlugosc_przedzialu, ile_wystapien;
	pair<int,int> p;
	cin>>n>>m;
	
	for(i=0;i<n;i++)
	{
		cin>>paczki[i];
		p=make_pair(paczki[i], 1);
		tree[LEAF_COUNT+i]=p;
		aktualizuj_drzewo(i); 
	} 
		
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		kandydaci[i].x=x-1; kandydaci[i].y=y-1;
		kandydaci[i].kandydat=kandydant_na_przedziale(x-1, y-1);
		kandydaci[i].indeks=i;
	}
	
	sort(kandydaci, kandydaci+m, cmp1); 
				
	for(i=0;i<n && j<m;i++)
	{
		while(kandydaci[j].x==i) {kandydaci[j].liczx=wystapienia[kandydaci[j].kandydat]; j++;}
		wystapienia[paczki[i]]++;
	}
	
   for(i=0;i<n;i++) wystapienia[i]=0; /// ZEROWNAIE WYSTAPIEN
		sort(kandydaci,kandydaci+m, cmp2);	
		j=0;
		
	for(i=0;i<n && j<m; i++)
	{
		wystapienia[paczki[i]]++;
		while(kandydaci[j].y==i) {kandydaci[j].liczy=wystapienia[kandydaci[j].kandydat]; j++;}
	}
	
	sort(kandydaci, kandydaci+m, cmp3);
	
	for(i=0;i<m;i++)
	{
		if(kandydaci[i].kandydat==0) {cout<<0<<endl; continue;}
		
		dlugosc_przedzialu=kandydaci[i].y-kandydaci[i].x+1;
		ile_wystapien=kandydaci[i].liczy-kandydaci[i].liczx;
		
		if(ile_wystapien>dlugosc_przedzialu/2) cout<<kandydaci[i].kandydat<<endl;
		else cout<<0<<endl;
	}
}