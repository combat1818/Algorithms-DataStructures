#include<iostream>
#include<algorithm>
using namespace std;
// RURKA.FIRST -SZEROKOSC, RURKA.SECOND- POZIOM

bool cmp(pair<long long,long long> a, pair<long long,long long> b) {
return a.first<b.first;}

long long krazki[300005];
long long rurka[300005];
pair<long long,long long> minima[300005];

int main()
{
	ios::sync_with_stdio(false);
	long long n,m,i,j=0,poziom,minn=10000000, minpoz;
	cin>>n>>m;
	for(i=0;i<n;i++) cin>>rurka[i];
	for(i=0;i<m;i++) cin>>krazki[i];
	
//	for(i=0;i<n;i++) cout<<rurka[i]<<endl;
//	for(i=0;i<m;i++) cout<<krazki[i]<<" ";
   
   minn=rurka[0]; minpoz=0;
   minima[0].first=minn; minima[0].second=0;
   for(i=1;i<n;i++)
   {
   	 if(rurka[i]==minn) minpoz=i;  	 
	 else if(rurka[i]<minn)
	 {
	 	minn=rurka[i]; minpoz=i;
	 }
	 
	 minima[i].first=minn; minima[i].second=minpoz;
   }
   
  // for(i=0;i<n;i++) cout<<minima[i].first<<" "<<minima[i].second<<endl;
   poziom=n-1;
   
   for(i=0;i<m;i++)
   {
   	  if(krazki[i]>minima[poziom].first)
   	  {
   	  	while(krazki[i]>minima[poziom].first && poziom>0) poziom--;
   	  	
   	  	if(i!=m-1) poziom--; 
//   	  	cout<<poziom<<endl;
   	  	 
	  }
	  else if(i!=m-1) poziom--; // cout<<poziom<<endl;}
   	}
   	if(poziom<0) cout<<0;
	else cout<<poziom+1;
   

	
	
}