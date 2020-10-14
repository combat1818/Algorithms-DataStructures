#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector< pair<int, bool> > linie;

bool cmp(pair<int, bool> a, pair<int, bool> b)
{
	return a.first>b.first;
}

int main()
{
	int m,n,i,x,koszt=0,poziome=1,pionowe=1;
	cin>>m>>n;
	for(i=0;i<m-1;i++){
		cin>>x;
		linie.push_back(make_pair(x,true));
	}
	
	for(i=0;i<n-1;i++){
		cin>>x;
		linie.push_back(make_pair(x,false));
	}
	
	sort(linie.begin(),linie.end(),cmp);
	
	for(i=0;i<linie.size();i++)
	{
		if(linie[i].second){
			koszt+=poziome*linie[i].first;
			pionowe++;
		}
		else{
			koszt+=pionowe*linie[i].first;
			poziome++;
		}
	}
	cout<<koszt;
	
}


//	for(i=0;i<linie.size();i++) cout<<linie[i].first<<" ";