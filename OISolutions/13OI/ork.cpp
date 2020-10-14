#include<iostream>
#include<algorithm>
using namespace std;
int T[2001][2001],sum_pref[2001][2001];
int n,m,k;
const int INF=2147483000;

void prep_pref(){
	for(int i=0;i<=n;i++) sum_pref[i][0]=0;
	for(int i=0;i<=m;i++) sum_pref[0][i]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			sum_pref[i+1][j+1]=sum_pref[i][j+1]+sum_pref[i+1][j]-sum_pref[i][j]+T[i+1][j+1];
	}
}

int suma(int x1, int y1, int x2, int y2){
	return sum_pref[y2][x2]-sum_pref[y2][x1-1]-sum_pref[y1-1][x2]+sum_pref[y1-1][x1-1];
}

int skiby_pionowe(int a){
	int x1=1, y1=1, x2=m, y2=n, licznik=0,out=0;
	while(x1<=x2 && y1<=y2){
		if(suma(x1,y1,x1,y2)<=k){
			out++;
			x1++;
		}
		else if(suma(x2,y1,x2,y2)<=k){
			out++;
			x2--;
		}
		else if(suma(x1,y1,x2,y1)<=k && licznik<a){
			out++;
			licznik++;
			y1++;
		}
		else if(suma(x1,y2,x2,y2)<=k){
			out++;
			y2--;
		}
		else return INF;
	}
	return out;
}

int skiby_poziome(int a){
	int x1=1,y1=1,x2=m,y2=n,licznik=0,out=0;
	
	while(x1<=x2 && y1<=y2){
		if(suma(x1,y1,x2,y1)<=k){
			out++;
			y1++;
		}
		else if(suma(x1,y2,x2,y2)<=k){
			out++;
			y2--;
		}
		else if(suma(x1,y1,x1,y2)<=k && licznik<a){
			out++;
			licznik++;
			x1++;
		}
		else if(suma(x2,y1,x2,y2)<=k){
			out++;
			x2--;
		}
		else return INF;
	}
	return out;
}



int main()
{
	ios::sync_with_stdio(false);
	int i,j,wynik=INF,x;
	cin>>k>>m>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cin>>T[i][j];
	}
	prep_pref();
	for(int a=0;a<=n;a++){
		wynik=min(wynik, skiby_pionowe(a));
	}
	for(int a=0;a<=m;a++){
		wynik=min(wynik,skiby_poziome(a));
	}
	
	cout<<wynik;
	
}