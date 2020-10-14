#include<iostream>
#include<algorithm>
using namespace std;
const int INF=2000000000;
int T[22][80];
struct trio{
	int t,a,w;
}butle[1001];

int main()
{
	int t,a,n,tp,ap,w,i,j,k,ti,ai,td,ad;
	cin>>t>>a>>n;
	for(i=0;i<n;i++){
		cin>>tp>>ap>>w;
		butle[i].t=tp;
		butle[i].a=ap;
		butle[i].w=w;
	}
	
	for(i=0;i<=21;i++){
		for(j=0;j<=79;j++)
			T[i][j]=INF;
	}
	T[0][0]=0;
	
	for(k=0;k<n;k++){
		for(ti=t;ti>=0;ti--){
			for(ai=a;ai>=0;ai--){
				td=min(t,ti+butle[k].t);
				ad=min(a,ai+butle[k].a);
				T[td][ad]=min(T[td][ad], T[ti][ai]+butle[k].w);
//				if(T[td][ad]!=INF) cout<<T[td][ad]<<" ";
			}
		}
	}
	
//	for(i=0;i<=t+1;i++){
//		for(j=0;j<=a+1;j++)
////			cout<<T[i][j]<<" ";
//		cout<<endl;	
//	}
	
	cout<<T[t][a];
	
	
}