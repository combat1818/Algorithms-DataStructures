#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int max_int=2147483646;
int n,m,p,k;
int M[201];
int po[14];
vector<pair<int,pair<int,int> > > G[201];
int timee[201][9000];
//first-wierzchilek, second-potwory
struct trio{
	int v,S,t;
};

struct cmp{
	bool operator()(trio a, trio b){
		return a.t>b.t;
	}
};

int main()
{
	int i,j,x,y,z,v,w,q,r,poo=1,t,s,S,u,out=2147483646,boi;
	trio ti,ti1;
	cin>>n>>m>>p>>k;
	
	for(i=1;i<=13;i++){
		po[i]=poo;
		poo*=2;
	}
	
	for(i=0;i<=n;i++){
		for(j=0;j<=8500;j++) timee[i][j]=max_int;
	}
	
	for(i=0;i<k;i++){
		cin>>w>>q;
		for(j=0;j<q;j++){
			cin>>r;
			M[w]= M[w] | po[r];
		}
	}

	for(i=0;i<m;i++){
		cin>>v>>w>>t>>s;
		x=0;
		for(j=0;j<s;j++){
			cin>>u;
			x= x | po[u];
		}
		G[v].push_back(make_pair(w,make_pair(x,t)));
		G[w].push_back(make_pair(v,make_pair(x,t)));
	}
	
	timee[1][M[1]]=0;
	ti.v=1; ti.S=M[1]; ti.t=0;
	priority_queue<trio, vector<trio>, cmp> Q;
	Q.push(ti);
//	cout<<endl;
	while(!Q.empty()){
		ti=Q.top();
		Q.pop();
		t=ti.t; S=ti.S; v=ti.v;
//		cout<<" "<<v<<" "<<S<<" "<<t<<" ";		
		for(i=0;i<G[v].size();i++){
			w=G[v][i].first;
			if((G[v][i].second.first & S)==G[v][i].second.first){
//				cout<<"zgonosc krawdzi "<<v<<" "<<w<<" "<<S<<" "<<G[v][i].second.first<<endl;
				if(timee[v][S]+ G[v][i].second.second < timee[w][S | M[w]]){
					timee[w][S | M[w]] = timee[v][S] + G[v][i].second.second;
					ti1.v=w;
					ti1.S=S | M[w];
					ti1.t= timee[v][S] + G[v][i].second.second;
					Q.push(ti1);
				}
			}
		}
	}
	for(i=0;i<=8000;i++){
		out=min(out,timee[n][i]);
	}
	if(out==max_int)
		cout<<-1;
	else
		cout<<out;	
}