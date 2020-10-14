#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include <stdio.h>
using namespace std;
//FIRST=WARTOSC, SECOND-INDEKS
int w[3000005];
int main()
{
	int n,t,i,j,y,rekord=1,ost_cmm=0,ost_crm=0;
//	vector<int> w;
	pair<int,int> x;
	deque< pair<int,int> > CMM;
	deque< pair<int,int> > CRM;
	scanf("%d", &t); scanf("%d", &n);
	for(i=1;i<=n;i++)
	{
	  scanf("%d", &y);
	  w[i]=y;	
	}
//	for(i=0;i<n;i++) cout<<w[i]<<" ";
	
	for(i=1;i<=n;i++)
	{
		x.first=w[i];
		x.second=i;
	//	cout<<"XD"<<i<<endl;
		
		while(!CMM.empty() && CMM.front().first-w[i]>t){
		ost_cmm=CMM.front().second; 	
		CMM.pop_front();
	//	cout<<i<<endl;
		} 
	    		
		
		while(!CRM.empty() && w[i]-CRM.front().first>t){
			ost_crm=CRM.front().second;
			CRM.pop_front();
	//		cout<<i<<endl;
		}
	   
		
		j=max(ost_cmm+1,ost_crm+1);
//	    cout<<"j= "<<j<<endl;
		
		/////////////////////////////
		
		while(!CMM.empty() && CMM.back().first<=w[i]) CMM.pop_back();
		
		if(CMM.empty() || CMM.back().first>w[i]) CMM.push_back(x);
		
		
		
		while(!CRM.empty() && CRM.back().first>=w[i]) CRM.pop_back();
		
		if(CRM.empty() || CRM.back().first<w[i]) CRM.push_back(x);
		
		////////////////////////////////////
		
//		cout<<rekord<<"  "<<i-j+1<<"    ";
		if((i-j)+1>rekord) rekord=(i-j)+1;
		
	}
	
	cout<<rekord;
	
	
	
}