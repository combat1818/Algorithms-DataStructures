#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
pair<int,int> tab[1000001];
//first-min, second-max 
int n;
deque<pair<int,int> > q;
int popsdone=0,pushesdone=0;
void push(int a, int pozycja)
{
	while(!q.empty() && q.back().first<=a) q.pop_back();
	q.push_back(make_pair(a,pozycja));
}

void pop(int pozycja)
{
	if(q.front().second<=pozycja)
		q.pop_front();
}

int max()
{
	if(q.size()==0)return -1100000000;
	return q.front().first;
}

void wpisz()
{
	int x,y,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>x>>y;
		tab[i].first=x; tab[i].second=y;
	}
}


int oblicz()
{
	int out=0,i=0,j=0;
	
	for(i=0;i<n;i++)
	{
//		push(tab[i].first);
		while(j<n && max()<=tab[j].second)
		{
//			cout<<i<<" "<<out<<endl;
			push(tab[j].first,j);
			j++;
		}
		out=max(out,j-i);
//		cout<<i<<"  "<<out<<endl;
		pop(i);
	}
	return out;
}

int main()
{
	ios::sync_with_stdio(false);
	wpisz();
//	cout<<endl;
	cout<<oblicz();

	
}