#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
typedef pair<long long,long long> pii;
const long long INF=2147483646;
vector<pii> graph[5001],tgraph[5001];
//FIRST=WIERZCHOLEK, SECOND-WAGA
long long dist1[5001],dist2[5001],cena[5001];
long long n,m;

void dijkstra1(long long src){
	long long i,v,u,weight;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	for(i=0;i<=n;i++) dist1[i]=INF;
	dist1[src]=0;
	Q.push(make_pair(0,src));
	while(!Q.empty()){
		u=Q.top().second;
		Q.pop();
		for(i=0;i<graph[u].size();i++){
			v=graph[u][i].first;
			weight=graph[u][i].second;
			if(dist1[v]>dist1[u]+weight){
				dist1[v]=dist1[u]+weight;
				Q.push(make_pair(dist1[v],v));
			}
		}
	}
}

void dijkstra2(int src){
	long long i,v,u,weight;
	priority_queue<pii, vector<pii>, greater<pii> > Q;
	for(i=0;i<=n;i++) dist2[i]=INF;
	dist2[src]=0;
	Q.push(make_pair(0,src));
	while(!Q.empty()){
		u=Q.top().second;
		Q.pop();
		for(i=0;i<tgraph[u].size();i++){
			v=tgraph[u][i].first;
			weight=tgraph[u][i].second;
			if(dist2[v]>dist2[u]+weight){
				dist2[v]=dist2[u]+weight;
				Q.push(make_pair(dist2[v],v));
			}
		}
	}
}

void transpose(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<graph[i].size();j++)
			tgraph[graph[i][j].first].push_back(make_pair(i,graph[i][j].second));
	}
}


int main()
{
	long long i,j,x,y,z,out=INF;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>cena[i];
	cin>>m;
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		graph[x].push_back(make_pair(y,z));
	}	
	dijkstra1(1);
	transpose();
	dijkstra2(1);
	for(i=1;i<=n;i++){
//		cout<<dist1[i]<<" "<<cena[i]/2<<" "<<dist2[i]<<" "<<out<<endl;
		out=min(out,dist1[i]+(cena[i]/2)+dist2[i]);
	}
	cout<<out;		
	
}