#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int drzewa[1000001],w[1000001];
int n,k,q,pushes_done,pops_done;
deque<pair<int,int> > KM;

void push(int v){
	while(!KM.empty() && KM.back().first>v) KM.pop_back();
	while(!KM.empty() && drzewa[KM.back().second]<=drzewa[pushes_done] && KM.back().first==v) KM.pop_back();
	
	KM.push_back(make_pair(v,pushes_done));
	pushes_done++;
}

void pop(){
	if(pops_done==KM.front().second)
		KM.pop_front();
	pops_done++;	
}

pair<int,int> minimum(){
	if(KM.size()==0) return make_pair(-1,-1);
	return KM.front();
}

void clear(){
	while(!KM.empty()) KM.pop_back();
	for(int i=0;i<n;i++) w[i]=0;
}

int main()
{
	int i,j;
	pair<int,int> minn;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>drzewa[i];
	cin>>q;	
	
	for(j=0;j<q;j++){
		cin>>k;
		pushes_done=0; pops_done=0;
		w[0]=0;
		push(0);
	
		for(i=1;i<=k;i++){
			minn=minimum();
			if(drzewa[i]>=drzewa[minn.second]) w[i]=minn.first+1;
			else if(drzewa[i]<drzewa[minn.second]) w[i]=minn.first;
			push(w[i]);
		}	
	
		for(i=k+1;i<n;i++){
			pop();
			minn=minimum();
			if(drzewa[i]>=drzewa[minn.second]) w[i]=minn.first+1;
			else if(drzewa[i]<drzewa[minn.second]) w[i]=minn.first;
			push(w[i]);
		}
		cout<<w[n-1]<<endl;
		clear();
	}
		
}