#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct triple
{
	long long x,a,b;
};


int main()
{
	ios::sync_with_stdio(false);
	long long B,q,i,j,s=0,r,dl=0,wartosc,poczatek,koniec,srodek;
	cin>>B>>q;
	long long *tab=new long long [B];
	long long *zapytania=new long long [q];
//	vector<long long> wektor;
	vector<triple> przedzialy;
	triple p;
	
	
	for(i=0;i<B;i++) cin>>tab[i];
	for(i=0;i<q;i++) cin>>zapytania[i];
	
	
	for(i=0;i<B;i++) s+=tab[i]*i;
//	out<<"s= "<<s<<endl;
	r=s%(B-1);
//	cout<<"PIERWSZED R= "<<r<<endl;
//	cout<<"podejscie 1  "<<r<<endl;
	if(r!=0)
	{
	s=0;
	for(i=0;i<B;i++)
	{
		if(i==r) {s+=(tab[i]-1)*i; tab[i]--;}
		else s+=tab[i]*i;
//		cout<<"s== "<<s<<endl;
	}
	r=s%(B-1);
    }
//    cout<<endl;
    
/*    for(i=0;i<B;i++)
    {
    	if(tab[i] || i==0)
		{
			for(j=0;j<tab[i];j++) wektor.push_back(i);
		} 
	}
	*/
//	for(i=0;i<wektor.size();i++) cout<<wektor[i]<<" ";
	
/*	for(i=0;i<q;i++)
	{
		if(zapytania[i]>=wektor.size()) cout<<"-1"<<endl;
		else cout<<wektor[zapytania[i]]<<endl;
	}
	*/
    
//    cout<<"NOWE R= "<<r<<endl;
//	cout<<"podejscioe 2  "<<r<<endl;
//	for(i=0;i<B;i++) cout<<tab[i]<<" ";
	
	
	
	
	p.a=0; p.b=tab[0]-1; p.x=0;
	przedzialy.push_back(p);
	
	dl+=tab[0];
	
	for(i=1;i<B;i++)
	{
		if(tab[i])
		{
			p.a=p.b+1;
			p.b=p.a-1+tab[i];
			p.x=i;
			przedzialy.push_back(p);
		}
		
		dl+=tab[i];
	}
	
 //   cout<<"  XD "<<przedzialy.size()<<"  XDD "<<endl<<endl;
    
  //  for(i=0;i<przedzialy.size();i++)
  //  {
  //  	cout<<przedzialy[i].a<<" "<<przedzialy[i].b<<" "<<przedzialy[i].x<<endl;
//	}
//	cout<<endl<<endl;
	
	
	for(i=0;i<q;i++)
	{
		poczatek=0; koniec=przedzialy.size()-1;
//		srodek=(poczatek+koniec)/2;
		
		if(zapytania[i]>=dl) cout<<"-1"<<endl; //" i== "<<i<<" "<<"-1"<<endl;
		else
		{
			while(poczatek<=koniec)
			{
				srodek=(poczatek+koniec)/2;
				if(przedzialy[srodek].a>zapytania[i]) koniec=srodek;
				else if(przedzialy[srodek].b<zapytania[i]) poczatek=srodek+1;
				else if(zapytania[i]>=przedzialy[srodek].a && zapytania[i]<=przedzialy[srodek].b) {cout<<przedzialy[srodek].x<<endl; break;}//" i== "<<i<<" "<<przedzialy[srodek].x<<endl; break;}
			} 
		
	    
		}
	}



    
	/*
	for(j=0;j<przedzialy.size();j++)
		{
			if(zapytania[i]>=przedzialy[j].a && zapytania[i]<=przedzialy[j].b) cout<<przedzialy[j].x<<endl;
		}
		*/
	

	 
	 
}


/*
	p.a=0; p.b=tab[0]-1; p.x=0;
	przedzialy.push_back(p);
	
	dl+=tab[0];
	
	for(i=1;i<B;i++)
	{
		if(tab[i])
		{
			poczatek=przedzialy[i-1].b+1;
			koniec=p.a-1+tab[i];
			wartosc=i;
			
			
			p.a=poczatek;
			p.b=koniec;
			p.x=wartosc;
			przedzialy.push_back(p);
		}
		
		dl+=tab[i];
	}
	
	for(i=0;i<q;i++)
	{
		if(zapytania[i]>=dl) cout<<"-1"<<endl;
		else
		{
			
		for(j=0;j<przedzialy.size();j++)
		{
			if(zapytania[i]>=przedzialy[j].a && zapytania[i]<=przedzialy[j].b) {cout<<przedzialy[j].x<<endl; break;}
		}
	    
		}
	}
	*/