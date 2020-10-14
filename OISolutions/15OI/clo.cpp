#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> graph[1000001];
int wyniki[1000001],startowy,koncowy;
bool visited[1000001];
bool visited1[1000001];


bool DFS1(int v, int ojciec){
	visited[v]=true;
	bool flaga=false;
//	cout<<v<<" ";
	for(int i=0;i<graph[v].size();i++){
		if(!visited[graph[v][i]]){
			visited[graph[v][i]]=true;
			flaga=DFS1(graph[v][i],v);
			if(flaga) break;
		}
		else if(visited[graph[v][i]] && graph[v][i]!=ojciec){
			//znalezlismy cykl;
			startowy=graph[v][i];
			koncowy=v;
			return true;
		}
	}
	return flaga;
}

void DFS(int v, int ojciec){
	visited1[v]=true;
	wyniki[v]=ojciec;
	for(int i=0;i<graph[v].size();i++){
		if(v!=startowy || graph[v][i]!=koncowy){
			if(!visited1[graph[v][i]]){
				visited1[graph[v][i]]=true;
				DFS(graph[v][i],v);
			}
		}
	}
}

int main()
{
	int n,m,a,b,i,j;
	bool x;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	startowy=-1; koncowy=-1;
	
	for(i=1;i<=n;i++){
		if(!visited1[i]){
			x=DFS1(i,-1);
			if(!x){
				cout<<"NIE";
				return 0;
			}
			DFS(startowy,-1);
			wyniki[startowy]=koncowy;
			startowy=-1; koncowy=-1;
//			cout<<"XD";
		}
	}
	
	cout<<"TAK"<<endl;
	for(i=1;i<=n;i++)
		cout<<wyniki[i]<<endl;
}