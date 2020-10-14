#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include <stdio.h>
using namespace std;
const int N=2097152;
int tree[2*N];
int w[2000005];
int pref[2000005];
int x[2000005];

int update(int x,int val){
	int v=x+N;
	tree[v]+=val;
	while(v!=1)
	{
		v/=2;
		tree[v]=max(tree[2*v],tree[2*v+1]);
	}
}

void print(){
	for(int i=0;i<2*N;i++) cout<<tree[i]<<" ";
}

int query(int a,int b)
{
	int va=a+N, vb=b+N,out;
	out=max(tree[va],tree[vb]);
	
	while(va/2!=vb/2)
	{
		if(va%2==0) out=max(out, tree[va+1]);
		if(vb%2==1) out=max(out, tree[vb-1]);
		va/=2;
		vb/=2;
	}
	return out;
}
int main()
{
	int n,d,i,j=1,rekord,x;
	long long p;
	cin>>n>>p>>d;
	for(i=1;i<=n;i++){
		scanf("%d", &x);
		w[i]=x;
	}
	for(i=1;i<=n;i++) pref[i]=pref[i-1]+w[i];
	
	for(i=1;i<=n-d+1;i++) update(i,pref[i+d-1]-pref[i-1]); //cout<<pref[i+d-1]-pref[i-1]<<" "; 
	
	j=d;
	rekord=d;
	
	for(i=1;i<=n-d+1;i++)
	{
  		while(j<=n && (pref[j]-pref[i-1])-query(i,j-d+1)<=p)
		{			
			rekord=max(rekord,j-i+1);
			j++;
		}
	} 
	
	printf("%d", rekord);

    
    
	
}