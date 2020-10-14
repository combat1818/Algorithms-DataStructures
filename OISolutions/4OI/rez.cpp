#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
return a.second<b.second;}

int czas[30005];
pair<int,int> tab[30005];

int main()
{
//	fstream plik;
//	plik.open("plik.txt", ios::out);
	int n,i,j=0,kmax=0,out=0;
	cin>>n;
	for(i=0;i<n;i++) {cin>>tab[i].first>>tab[i].second; kmax=max(kmax,tab[i].second);}
	
//	for(i=0;i<n;i++) cout<<tab[i].first<<" "<<tab[i].second<<endl;
	
//		for(i=0;i<n;i++) plik>>tab[i].first>>" ">>tab[i].second>>endl;
    sort(tab,tab+n,cmp);
  //  for(i=0;i<n;i++) plik<<tab[i].first<<" "<<tab[i].second<<endl;
  //  cout<<kmax<<endl;
    for(i=1;i<=kmax;i++)
    {
    	if(j<n)
    	{
		if(tab[j].second==i)
		{
		 while(tab[j].second==i && j<n)
    	{
    		czas[i]=max(max(czas[i-1],czas[i]), czas[tab[j].first] + ( tab[j].second-tab[j].first ) );
    		j++;
		}
	    }
	    else czas[i]=czas[i-1];
	    }  
		else break;
	}
	
    cout<<max(czas[kmax],czas[n-1]);
}