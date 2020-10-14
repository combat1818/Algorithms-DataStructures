#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool kupione[1000001];
bool bony[1000001];
int ostatni[1000001];

int main()
{
	ios_base::sync_with_stdio(0);
	long long m,n,a,b,i,j,M=0,licznik=0,ile,c,klient=0,klientp=0;
	vector<long long> klienci;
	cin>>m;
	
	for(i=0;i<m;i++){
		cin>>b;
		bony[b]=true;
		M=max(M,b);
	}
	
	cin>>n;
	
	for(i=1;i<=n;i++){
		cin>>a;
		if(ostatni[a]==0) ostatni[a]=a;
		int ile=0;
		while(ostatni[a]<=M && ile<a){
			if(!kupione[ostatni[a]]){
				kupione[ostatni[a]]=true;
				ile++;
				if(bony[ostatni[a]]){
					licznik++;
					klienci.push_back(ile+klientp);
				}
			}
			ostatni[a]+=a;
		}
		klientp+=a;
	}
	
	cout<<licznik<<endl;
	for(i=0;i<klienci.size();i++)
		cout<<klienci[i]<<"\n";

	
}