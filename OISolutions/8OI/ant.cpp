#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int pierwsze[10]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
vector< pair <int,int> > kandydaci;

bool cmp(pair<int,int> a, pair<int,int> b) {
return a.first<b.first;}


///  kandydaci[i].first- kandydat, kandydaci[i].second- liczba dzielnikow

void generuj(int j, int maxpotega, int kandydat, int l_dzielnikow)
{
	kandydaci.push_back(make_pair(kandydat,l_dzielnikow));
	
	for(int i=1;i<=maxpotega;i++)
	{
		if(pierwsze[j]>n/kandydat) return;
		kandydat*=pierwsze[j];
		generuj(j+1,i,kandydat,l_dzielnikow*(i+1)); 
	}
}


int main()
{
	int out,max_num=0;
	cin>>n;
    generuj(0,31,1,1);
//	cout<<pierwsze[6];
	sort(kandydaci.begin(),kandydaci.end(),cmp);
//	cout<<kandydaci.size()<<endl;
//	for(int i=0;i<kandydaci.size();i++) cout<<kandydaci[i].first<<" "<<kandydaci[i].second<<endl;
    for(int i=0;i<kandydaci.size();i++)
    {
    	if(kandydaci[i].second>max_num)
    	{
    		max_num=kandydaci[i].second;
    		out=kandydaci[i].first;
		}
	}
    cout<<out;
}