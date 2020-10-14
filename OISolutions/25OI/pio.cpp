#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

struct wektor{
	long long x,y;
	double kat;
};

bool cmp(wektor a, wektor b)
{
	return a.kat<b.kat;
}

long long sqr(long long x)
{
	return x*x;
}
bool visited[200005];
vector<wektor> tab,t;

int main()
{
	long long n,i,x,y,glowny,pomoc,wynik,k;
	pair<long long,long long> suma;
	wektor w;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		if(!(x==0 && y==0))
		{
			w.x=x; w.y=y;
			w.kat=atan2(y,x)* (double)180/3.14159265;
			if(w.kat<0) w.kat+=360;
			tab.push_back(w);
		}
	}
	
	sort(tab.begin(),tab.end(),cmp);
	
	for(i=1;i<tab.size();i++)
	{
		if(tab[i].kat==tab[i-1].kat)
		{
			visited[i-1]=true;
			tab[i].x+=tab[i-1].x;
			tab[i].y+=tab[i-1].y;
		}
	}
	
	for(i=0;i<tab.size();i++)
	{
		if(!visited[i]) t.push_back(tab[i]);
	}
	
	wynik=0;
	pomoc=0;
	suma.first=0; suma.second=0;
	k=0;
	
	for(glowny=0;glowny<t.size();glowny++)
	{
//		cout<<"glowny= "<<glowny<<endl;
		while(t[pomoc].kat+k*360 <= t[glowny].kat+180)
		{
			wynik=max(wynik, sqr(suma.first) + sqr(suma.second) );
			suma.first+=t[pomoc].x;
			suma.second+=t[pomoc].y;
			wynik=max(wynik, sqr(suma.first) + sqr(suma.second) );
			pomoc=(pomoc+1)%t.size(); 
			
			if(pomoc==0 && glowny!=0) k++;
			if(pomoc==glowny) break;
		}
//		cout<<"pomoc= "<<pomoc<<endl;
//		cout<<"PRZERWA"<<endl;
		suma.first-=t[glowny].x;
		suma.second-=t[glowny].y;
	}
	
//	cout<<"wynik:= "<<wynik<<endl;
//	for(i=0;i<t.size();i++)
//	 cout<<t[i].x<<" "<<t[i].y<<" "<<t[i].kat<<endl;
//	 cout<<endl<<endl;
	
	for(i=0;i<t.size();i++)
	{
		t[i].y*=-1;
		t[i].kat=360-t[i].kat;
	} 
	sort(t.begin(),t.end(),cmp);
//	cout<<t[0].x<<" "<<t[0].y;
//	sort(t.begin(),t.end(),cmp);
	
	pomoc=0;
	suma.first=0; suma.second=0;
	k=0;
	
	for(glowny=0;glowny<t.size();glowny++)
	{
//		cout<<"glowny= "<<glowny<<endl;
		while(t[pomoc].kat+k*360 <= t[glowny].kat+180)
		{
			wynik=max(wynik, sqr(suma.first) + sqr(suma.second) );
			suma.first+=t[pomoc].x;
			suma.second+=t[pomoc].y;
			wynik=max(wynik, sqr(suma.first) + sqr(suma.second) );
			pomoc=(pomoc+1)%t.size(); 
			
			if(pomoc==0 && glowny!=0) k++;
			if(pomoc==glowny) break;
		}
//		cout<<"pomoc= "<<pomoc<<endl;
//		cout<<"PRZERWA"<<endl;
		suma.first-=t[glowny].x;
		suma.second-=t[glowny].y;
	}
	
	cout<<wynik;
	
//	for(i=0;i<t.size();i++)
//	 cout<<t[i].x<<" "<<t[i].y<<" "<<t[i].kat<<endl;
}