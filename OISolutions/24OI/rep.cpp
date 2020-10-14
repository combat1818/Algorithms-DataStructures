#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

struct roznica
{
	int indeks1,indeks2,x;
};

bool cmp(roznica a, roznica b)
{
    return a.x<b.x;
}

vector<roznica> Roznice;
roznica p;
vector<int> ciag;
set<int> roznice;
set<int>:: iterator it;

void wyznaczCiag(int X)
{
	p.indeks1=2; p.indeks2=1; p.x=1; Roznice.push_back(p); roznice.insert(1); ciag.push_back(0);
	int x=0,i,r=1,j;
	
	for(i=1;i<100000;i++)
	{
		if(i<=2)
		{
	//		cout<<"X= "<<i<<endl;
	//		cout<<"ROZNICE: ";
	//		for(it=roznice.begin();it!=roznice.end();it++) cout<<*it<<" ";
	//		cout<<endl;
			ciag.push_back(i) ;
			
			if(x>=2*X) break;
		}
		else if(i%2==1)
		{
			x=2*ciag[i-1];
	//		cout<<"X= "<<x<<endl;
			
			for(j=i-1;j>0;j--)
			{
		//		cout<<x-ciag[j]<<endl;
		        p.indeks1=i; p.indeks2=j; p.x=x-ciag[j]; Roznice.push_back(p);
		
				roznice.insert(x-ciag[j]);
			}
			
	//		cout<<"ROZNICE: ";
	//		for(it=roznice.begin();it!=roznice.end();it++) cout<<*it<<" ";
	//		cout<<endl;
			
			while(roznice.find(r)!=roznice.end()) r++;
	//		cout<<"R= "<<r<<endl<<endl;
			ciag.push_back(x) ;
			
			if(x>=2*X) break;
		}
		else
		{
			x=ciag[i-1]+r;
	//		cout<<"X= "<<x<<endl;
			
			for(j=i-1;j>0;j--)
			{
	//			cout<<x-ciag[j]<<endl;
	            p.indeks1=i; p.indeks2=j; p.x=x-ciag[j]; Roznice.push_back(p); 
	
				roznice.insert(x-ciag[j]);
			}
			
	//		cout<<"ROZNICE: ";
	//		for(it=roznice.begin();it!=roznice.end();it++) cout<<*it<<" ";
	//		cout<<endl;
			
			while(roznice.find(r)!=roznice.end()) r++;
	//		cout<<"R= "<<r<<endl<<endl;
		
	        ciag.push_back(x);
	        if(x>=2*X) break;
		}
	}
} 



int main()
{
	int n,X=0,i,j,y=0,z,indeks;
	cin>>n;
	int *tab=new int [n+1];
	for(i=1;i<=n;i++) {cin>>tab[i]; X=max(X,tab[i]);}
	
	wyznaczCiag(X);	
	sort(Roznice.begin(),Roznice.end(),cmp);
	
//	for(i=0;i<Roznice.size();i++)	cout<<Roznice[i].indeks1<<" "<<Roznice[i].indeks2<<" "<<Roznice[i].x<<endl;
	
	
	
	
	for(i=1;i<=n;i++)
	{
		if(roznice.find(tab[i])!=roznice.end())
		{
			for(j=0;j<Roznice.size();j++)
			{
				if(Roznice[j].x==tab[i]) cout<<Roznice[j].indeks1<<" "<<Roznice[j].indeks2<<endl;
			}
		}
		else
		{
			for(it=roznice.begin(); *it<tab[i] ;it++)
			{
				y++;
			}
			z=tab[i]-1-y;
			y=0;
	//		cout<<"Z= "<<z<<endl;
	//		cout<<"dlugosc ciagu= "<<ciag.size()<<endl;
			
			if((ciag.size()-1)%2==1)  //ciag.size()%2!=0
			{
				indeks=ciag.size()-1+(2*z)+1;
				cout<<indeks<<" "<<indeks-1<<endl;
			}
			else
			{
				indeks=ciag.size()-1+(2*z)+2;
				cout<<indeks<<" "<<indeks-1<<endl;
			}
		}
	}
	
	
}