#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include <stdio.h>
using namespace std;

struct prawnik{
	int a,b,indeks;
};

bool cmp(prawnik a, prawnik b)
{
	return a.a<b.a;
}


struct porownaj{
	bool operator ()(prawnik a, prawnik b)
    {
        return a.b>b.b;
    }
};

vector<prawnik> tab;

int main()
{
//	ios::sync_with_stdio(false);
	int n,k,i,a,b,wynik=0,doUs,pom,wynik1=0;
	prawnik w;
	set<int> S,SQ;
	set<int>::iterator it;
	priority_queue<prawnik, vector<prawnik>, porownaj> Q,Q2;
	cin>>n>>k;
	
	for(i=0;i<n;i++)
	{
		scanf("%d%d", &a, &b);
		w.a=a; w.b=b; w.indeks=i+1;
		tab.push_back(w);
//		Q.push(w);
	}
	
	sort(tab.begin(), tab.end(),cmp);
//	cout<<endl<<endl;
//	for(i=0;i<n;i++)
//		cout<<tab[i].a<<" "<<tab[i].b<<" "<<tab[i].indeks<<endl;
	
	for(i=0;i<k;i++)
	{
		Q.push(tab[i]);
		SQ.insert(tab[i].indeks);
	} 
	wynik=Q.top().b-tab[k-1].a;
//	S=SQ;
/*	cout<<Q.top().a<<" "<<Q.top().b<<endl;
	cout<<tab[k-1].a<<" "<<tab[k-1].b<<endl;
	cout<<wynik<<endl;
	cout<<"wynik 1 razem = "<<wynik<<endl;
	
	while(!Q.empty())
	{
		cout<<Q.top().a<<" "<<Q.top().b<<" "<<Q.top().indeks<<endl;
		Q.pop();
	} */
	
//	for(it=S.begin();it!=S.end();it++)
//		cout<<*it<<" ";
//	cout<<endl;	
	
	if(n==k)
	{
		printf("%d\n", wynik);
		for(it=SQ.begin();it!=SQ.end();it++)
			printf("%d ", *it);
		return 0;
	}
	else
	{
		for(i=k;i<tab.size();i++)
		{
			Q.pop();
			Q.push(tab[i]);

			if(Q.top().b-tab[i].a>wynik)
			{
				wynik=Q.top().b-tab[i].a;
//				S=SQ;
				
			}
		}
				
		
		for(i=0;i<k;i++)
		{
			Q2.push(tab[i]);
			SQ.insert(tab[i].indeks);
		}	
		
		wynik1=Q2.top().b-tab[k-1].a;
		
		if(wynik1==wynik)
		{
			cout<<wynik<<endl;
			while(!Q2.empty())
			{
				cout<<Q2.top().indeks<<" ";
				Q2.pop();
			}
			return 0;
		}
		else
		{
			for(i=k;i<tab.size();i++)
			{
				Q2.pop();
				Q2.push(tab[i]);
				
				if(Q2.top().b-tab[i].a==wynik)
				{
					cout<<wynik<<endl;
					while(!Q2.empty())
					{
						cout<<Q2.top().indeks<<" ";
						Q2.pop();
					}
					return 0;
				}
			}
		}
			
			
		
	}
	
//	printf("%d\n", wynik);
//	for(it=S.begin();it!=S.end();it++)
//		printf("%d ", *it); 

	
	
}