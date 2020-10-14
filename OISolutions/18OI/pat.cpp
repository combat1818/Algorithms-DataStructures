#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int> > tab;
//FIRST- DLUGOSC , SECOND-KOLOR
int main()
{
	ios::sync_with_stdio(false);
	int k,n,i,j,x;
	pair<int,int> a,b,c;
	cin>>k;
	
	for(i=1;i<=k;i++){
		cin>>n;
		for(j=1;j<=n;j++){
			cin>>x;
			tab.push_back(make_pair(x,i));
		}
		
	}
	sort(tab.begin(),tab.end());
	a=tab[0];
	for(i=1;i<tab.size();i++){
		if(tab[i].second==a.second)
			a=tab[i];
		else{
			b=tab[i];
			break;
		}	
	}
//	j=i;
	i++;
	c.second=0;
	for(i=i;i<tab.size();i++){
		if(tab[i].second!=a.second && tab[i].second!=b.second){
			if(a.first+b.first>tab[i].first){
				//MAMY TROJKAT
				c=tab[i];
				break;
			}else{
				a=b;
				b=tab[i];
			}
		}else if(tab[i].second==a.second){
			a=b;
			b=tab[i];
		}else if(tab[i].second==b.second){
			b=tab[i];
		}
	}
	if(c.second){
		cout<<a.second<<" "<<a.first<<" "<<b.second<<" "<<b.first<<" "<<c.second<<" "<<c.first;
	}
	else cout<<"NIE";
	
	//cout<<a.first<<" "<<a.second<<" "<<b.first<<" "<<b.second;
}