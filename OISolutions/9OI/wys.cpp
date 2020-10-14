#include<iostream>
#include<algorithm>
using namespace std;
int D[500002],wlewo[500002],wprawo[500002],n,L;

int next(int i){
	return (i+1)%n;
}

int prev(int i){
	i-=1;
	if(i<0) return n-1;
	else return i;
}

int distp(int a, int b){
	
	if(a<b){
		return wprawo[prev(b)]-((a-1>=0) ? wprawo[prev(a)] : 0);
	}else if(a>b){
		return wprawo[n-1]-wprawo[prev(a)]+ ((b-1>=0) ? wprawo[prev(b)] : 0);
	}
	else return 0;
}

int distl(int a,int b){
	if(a<b){
		return L-distp(a,b);
	}else if(a>b){
		return distp(b,a);
	}
	else return 0;	
}

int main()
{
	int i,j,x,out=0;
	L=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>D[i];
		L+=D[i];	
	}
	wprawo[0]=D[0];
	for(i=1;i<n;i++)
		wprawo[i]=wprawo[i-1]+D[i];
	wlewo[n-1]=D[n-1];
	for(i=n-2;i>=0;i--)
		wlewo[i]=wlewo[i+1]+D[i];
/*		
	for(i=0;i<=n;i++)
		cout<<wlewo[i]<<" ";
	cout<<endl<<endl;	
	for(i=0;i<=n;i++)
		cout<<wprawo[i]<<" ";
		
	for(i=0;i<n+10;i++){
		int a,b;
		cin>>a>>b;
		cout<<"XD "<<"distP= "<<distp(a,b)<<" distL= "<<distl(a,b)<<endl;
	}*/					
	
	j=0;
	for(i=0;i<n;i++){
		if(i==j) j=next(i);
		out=max(out,min(distp(i,j) ,distl(i,j) ) );
		while(distp(i,j)<distl(i,j)){
			out=max(out,min(distp(i,j) ,distl(i,j) ) );
			j=next(j);
		}
	}
	cout<<out;	
}