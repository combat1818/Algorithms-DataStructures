#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
int pref[1000001];

int suma(int a, int b){
	if(a<0) return -1;
	return pref[b]-pref[a];
}

int main()
{
	int n,k,i,j,x,d;
	char c;
	stack<int> S,Sp;
	cin>>n>>k;
	
	for(i=1;i<=n;i++){
		cin>>c;
		S.push(i);
	//	d=S.size();
		pref[S.size()]= (c=='b') ? pref[S.size()-1]+1: pref[S.size()-1]-k;
//		cout<<"size= "<<S.size()<<" pref[S.size]= "<<pref[S.size()]<<" size-k-1= "<<d-k-1<<" suma= "<<suma(d-k-1,d);
		if(suma(S.size()-k-1,S.size())==0){
	//		cout<<"i= "<<i<<" ";
			for(j=1;j<=k+1;j++){
				x=S.top();
				S.pop();
				Sp.push(x);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		cout<<Sp.top()<<" ";
		Sp.pop();
		if(i%(k+1)==0) cout<<endl;
	}
}