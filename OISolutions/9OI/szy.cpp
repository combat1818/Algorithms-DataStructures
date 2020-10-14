#include<iostream>
#include<algorithm>
#include<vector>
#include <cstdio>
using namespace std;

int a[45],n;
int potegi2[23];
int p1[22], p2[22];
vector< pair<int, int> > P,Q;

void decimalToBinary(int n,int dec)
{
	int i=1;
	while(n!=0)
	{
		if(dec) p1[i]=n%2;
		else p2[i]=n%2;
		
		n/=2;
		i++;
    }
  /*  
    if(dec)
    if(i<=dl)
    {
    	while(i!=dl+1)
    	{
    		p1[i]=0;
    		i++;
		}
	}
	
	if(!dec)
    if(i<=dl)
    {
    	while(i!=dl+1)
    	{
    		p2[i]=0;
    		i++;
		}
	}
    **/
    
//    for(i=0;i<35;i++) cout<<tab[i]<<" ";
}

void generate(int value, int s, int index)
{
	
//	cout<<"XD";
	
	if(index==n/2)
	{
		P.push_back(make_pair(value+a[index], s+potegi2[index-1]));
//		cout<<value+a[index]<<"  "<<s+ "1"<<endl;
		P.push_back(make_pair(value, s));
//		cout<<value<<"  "<<s+ "0"<<endl;
	}
	else
	{
//		P.push_back(make_pair(value+a[index], s+ "1"));
//		cout<<value+a[index]<<"  "<<s+ "1"<<endl;
		generate(value+a[index], s+potegi2[index-1], index+1);
		
//		P.push_back(make_pair(value, s+ "0"));
//		cout<<value<<"  "<<s+ "0"<<endl;
		generate(value, s, index+1);
	//	cout<<"XD"<<endl;
	}
	
}

void generate2(int value, int s, int index)
{
	
//	cout<<"XD";
	
	if(index==n)
	{
		Q.push_back(make_pair(value+a[index], s+potegi2[index-1-n/2]));
//		cout<<value+a[index]<<"  "<<s+ "1"<<endl;
		Q.push_back(make_pair(value, s));
//		cout<<value<<"  "<<s+ "0"<<endl;
	}
	else
	{
//		P.push_back(make_pair(value+a[index], s+ "1"));
//		cout<<value+a[index]<<"  "<<s+ "1"<<endl;
		generate2(value+a[index], s+potegi2[index-1-n/2], index+1);
		
//		P.push_back(make_pair(value, s+ "0"));
//		cout<<value<<"  "<<s+ "0"<<endl;
		generate2(value, s, index+1);
	//	cout<<"XD"<<endl;
	}
	
}

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}



int main()
{
	ios::sync_with_stdio(false);
	int i,j,S,x,y,p3=1;
	bool ok=false;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	cin>>S;
	
	for(i=0;i<=22;i++){
		potegi2[i]=p3;
		p3*=2;
	}
	
//	cout<<potegi2[5];
	
	generate( 0 , 0 , 1 );
	generate2( 0, 0 , n/2+1 );
	
//	for(i=0;i<P.size();i++) cout<<P[i].first<<"   "<<P[i].second<<endl;
//	cout<<endl<<endl;
//	for(i=0;i<Q.size();i++) cout<<Q[i].first<<"   "<<Q[i].second<<endl;
	
	sort(P.begin(),P.end(),cmp);
	sort(Q.begin(),Q.end(),cmp);
	
	i=0; j=Q.size()-1;
	
//	cout<<i<<"     "<<j<<endl;
	
	while(i<P.size() && j>=0 && !ok)
	{
//		cout<<"AHA"<<endl;
		if( P[i].first + Q[j].first < S ) i++;
		else if( P[i].first + Q[j].first > S ) j--;
		else
		{
//			cout<<"XDDDD";
			ok=true;
//			cout<<P[i].second<<Q[j].second;
            decimalToBinary(P[i].second,1);
			decimalToBinary(Q[j].second,0);
			
//			cout<<i<<" "<<j<<endl;
			
			for(i=1;i<=n/2;i++) cout<<p1[i];
//			cout<<" ";
			for(i=1;i<=n-n/2;i++) cout<<p2[i];

		}
	}
	
//	cout<<i<<" "<<j;
	
	
	
//	cout<<P.size()<<endl;
	
//	cout<<P[1].first<<P[1].second;
	
//	for(i=0;i<P.size();i++) cout<<P[i].first<<"   "<<P[i].second<<endl;
	
	
	
//	for(i=0;i<Q.size();i++) cout<<Q[i].first<<"   "<<Q[i].second<<endl;
	
//	for(i=0;i<P.size();i++); cout<<P[i].first<<"   "<<P[i].second<<endl;
	
	
	
}