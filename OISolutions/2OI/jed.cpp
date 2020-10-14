#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<pair<int,int> > g[20005];
//pair<int, int> poprzednicy[20005]; 
bool visited[20005]; //visited1[20005];
string s[20005];

void wypisz(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"i= "<<i<<"   ";
		for(int j=0;j<g[i].size();j++)
			cout<<g[i][j].first<<" "<<g[i][j].second<<"   ";
		cout<<endl;	
	}
}	

int main()
{
	int n,k,i,j,l,p,pom,etyk0, etyk1;
	vector<int> wynik;
	cin>>k;
	
	for(l=0;l<k;l++)
	{
		cin>>n;
		queue<int> K,Q;
		
	//	poprzednicy[1]=-1;
		K.push(1);
		s[1]="1";
		
		while(K.front()!=0 || K.empty())
		{
			pom=K.front();
			K.pop();
						
			etyk0=(pom*(10%n))%n;
			etyk1=( (pom * (10%n) ) +1 ) %n;
			
			if(!visited[etyk0])
			{
				visited[etyk0]=1;
				s[etyk0]=s[pom]+"0";
				g[pom].push_back(make_pair(etyk0 ,0));
				K.push(etyk0);
			}
			
			if(!visited[etyk1])
			{
				visited[etyk1]=1;
				s[etyk1]=s[pom]+"1";
				g[pom].push_back(make_pair(etyk1 ,1));
				K.push(etyk1);
			}
		}
		
//		wypisz(n);
		cout<<s[0]<<endl;
		
		for(i=0;i<=n;i++)
		{
			s[i]="";
			visited[i]=0;
		} 
		
		for(i=0;i<=n;i++) g[i].clear();
		
		
		
/*		Q.push(1);
		poprzednicy[1].first=-1;
		poprzednicy[1]
		
		while(Q.front()!=0)
		{
			p=Q.front();
			Q.pop();
			
			for(i=0;i<g[p].size();i++)
			{
				if(!visited1[g[p][i].first])
				{
					poprzednicy[g[p][i].first].first=p;
					poprzednicy[g[p][i].first].second=g[p][i].second;
					
					visited1[g[p][i].first]=1;
					Q.push(g[p][i].first);
				}
			}
		}
		i=0;
		while(poprzenicy[i].first!=-1)
		{
			wynik.push_back(poprzednicy[i].second);
			i=poprzednicy[i].first;
		}
		
		for(i=wynik.size()-1;i>=0;i--) cout<<wynik[i]<<" ";
		*/
	}
}