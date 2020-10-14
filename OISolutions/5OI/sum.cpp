#include<iostream>
#include<algorithm>
using namespace std;
/*
void rozklad(int m, int n, int ostatni){
	if(m<=1){
		if(m==1){
			cout<<1<<" ";
		}
		return;
	}
	else{
		if(m>=n){
			cout<<n<<" ";
			rozklad(m-n,n-1);
		}
		else
			rozklad(m,n-1);
	}
} 
*/
int main()
{
	int s,n,m,S,Sn,ostatni=0;
	cin>>n>>S;
	Sn=((n-1)*n)/2;
	
	if(((S+Sn))%2!=0){
		cout<<"NIE";
		return 0;
	}
	if(S<-Sn || S>Sn){
		cout<<"NIE";
		return 0;
	}
	
	m=(S+Sn)/2;
	ostatni=0;
	cout<<0<<" ";
	for(int i=n-1;i>=1;i--){
		if(m>=i){
			m-=i;
			ostatni++;
		}
		else ostatni--;
		cout<<ostatni<<" ";
	} 
	
	
}