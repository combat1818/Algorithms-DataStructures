#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> G[500001];
bool visited[500001];

int main()
{
	std::ios_base::sync_with_stdio(false);
	long long n,m,k,i,j,a,b,out=0,l;
	vector<long long> wyniki;
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}


	for(i=1;i<=n;i++){
		if(!visited[i]){
			wyniki.push_back(i);
			for(j=0;j<G[i].size();j++){
				visited[G[i][j]]=true;
				for(l=0;l<G[G[i][j]].size();l++)
					visited[G[G[i][j]][l]]=true;
			}
		}
	}
	cout<<wyniki.size()<<endl;
	for(i=0;i<wyniki.size();i++){
		cout<<wyniki[i]<<" ";
	}
}