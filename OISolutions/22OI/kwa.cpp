#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

int tab[508];
bool liczby[508];

int sqrt(int x)
{
	int i;
	for(i=0;i<30;i++)
	{
		if(i*i==x) return i;
	}
	return 0;
}

int main()
{
	//fstream dane1;
	//dane1.open("dane.txt",ios::out);
	long long suma=1,i=1,j,k,n,przerasniete=0,licznik=0,out=0;
	vector<int> odjemnik;
	tab[0]=0;
	for(i=0;i<508;i++) {liczby[i]=false; tab[i]=0;}
	for(i=1;i<23;i++) tab[i*i]=i;
	cin>>n;
		
	i=1;
	while(suma<508)
	{
		liczby[suma]=true;
		tab[suma]=i;
		i++;
		suma+=(i*i);
//		cout<<"XD";
	}
	
	tab[1]=1;
	
	for(i=2;i<507;i++)
	{
		if(sqrt(i)) odjemnik.push_back(i);
		if(liczby[i]) {odjemnik.erase(odjemnik.begin()); continue;}
		
		
	//	cout<<"i=="<<i<<"  ";
	//	for(k=0;k<odjemnik.size();k++) cout<<odjemnik[k]<<" ";
	//	cout<<endl;
	    
		
		for(j=odjemnik.size()-1;j>=0;j--)
		{
			if(tab[i-odjemnik[j]] && (tab[i-odjemnik[j]]*tab[i-odjemnik[j]])!=odjemnik[j] && tab[i-odjemnik[j]]<sqrt(odjemnik[j])) tab[i]=sqrt(odjemnik[j]);
		}
	}
	/*
	for(i=0;i<507;i++)
	{
		if(liczby[i]) dane1<<i<<" "<<tab[i]<<" <-"<<licznik++<<endl;
	    else dane1<<i<<" "<<tab[i]<<endl;
	}
	dane.close();
	*/
	suma=0;
	i=0;
	
	if(n<=506)
	{
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<i+6;j++) if(tab[i]>tab[j] && tab[j]!=0) {out++; break;}
			
			if(!tab[i]) out++;
			
		}
		
		if(!tab[n]) cout<<"- "<<out;
		else cout<<tab[n]<<" "<<out;
	}
	else
	{
		while(suma<n)
		{
			i++;
			suma+=(i*i);
		}
		
	
	//	cout<<suma<<"  "<<i<<endl;
		
		out+=31*(i-12);
		out+=175;
		
		for(j=suma-128;j<=n;j++)
		{
			if(!tab[suma-j]) out++;
		}
	//	cout<<suma<<"  "<<i<<endl;
	    if(n==suma) cout<<i<<" "<<out-1;
	    else if(suma-n<=128 && !tab[suma-n]) cout<<i+1<<" "<<out;
	    else cout<<i<<" "<<out;
	
	}





}