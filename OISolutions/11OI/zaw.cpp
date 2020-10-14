#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAX_INT=2147483646;
vector<pair<int,int> > graph[5005];
vector< pair<int,int> > graph1[5005];
int p[5005],h[5005],n,m;
int dist[5005];

void Dijkstra(int source,int N){
	priority_queue<pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > Q;
	
	for(int i=0;i<=N;i++) dist[i]=MAX_INT;
	
	dist[source]=0;
	Q.push(make_pair(0,source));
	
	int u,v,w,i;
	
	while(!Q.empty())
	{
		u=Q.top().second;
		Q.pop();
		
		for(i=0; i<graph[u].size(); i++)
		{
			v=graph[u][i].first;
			w=graph[u][i].second;
			
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(u!=1)p[v]=p[u];
				Q.push(make_pair(dist[v],v));
			}
		}
	}
}

void Dijkstra1(int source,int N){
	priority_queue<pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > Q;
	
	for(int i=0;i<=N;i++) h[i]=MAX_INT;
	
	h[source]=0;
	Q.push(make_pair(0,source));
	
	int u,v,w,i;
	
	while(!Q.empty())
	{
		u=Q.top().second;
		Q.pop();
		
		for(i=0; i<graph[u].size(); i++)
		{
			v=graph1[u][i].first;
			w=graph1[u][i].second;
			
			if(h[v]>h[u]+w)
			{
				h[v]=h[u]+w;
//				p[v]=p[u];
				Q.push(make_pair(h[v],v));
			}
		}
	}
}

void transpose(){
	int i,j;
	
	for(i=1;i<=n;i++){
		for(j=0;j<graph[i].size();j++){
			graph1[graph[i][j].first].push_back(make_pair(i,graph[i][j].second));
		}
	}
	
}


int main()
{
	int i,j,a,b,c,d,out=MAX_INT;
	cin>>n>>m;
	
	for(i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		graph[a].push_back(make_pair(b,c));
		graph[b].push_back(make_pair(a,d));
	}
	
	p[1]=1;
	for(i=0;i<graph[1].size();i++) p[graph[1][i].first]=graph[1][i].first;
//	for(i=1;i<=n;i++) cout<<p[i]<<" ";

	Dijkstra(1,n);
	
	transpose();
	Dijkstra1(1,n);
//	for(i=1;i<=n;i++) cout<<p[i]<<" ";
//	cout<<endl;	
//	for(i=1;i<=n;i++) cout<<dist[i]<<" "; 
//	cout<<endl;
//	for(i=1;i<=n;i++) cout<<h[i]<<" ";
	
	for(i=1;i<=n;i++){
		for(j=0;j<graph[i].size();j++){
			if(p[i]!=p[graph[i][j].first] && p[i]!=i){
				
				out=min(out, dist[i]+ graph[i][j].second + h[graph[i][j].first]);
			}
		}
	}	
	cout<<out;
//	cout<<endl<<endl;
/*	
	for(i=1;i<=n;i++){
		for(j=0;j<graph1[i].size();j++) cout<<graph1[i][j].first<<" "<<graph1[i][j].second<<"   ";
		cout<<endl;
	}
	*/
	
	
	
}