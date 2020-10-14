#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//   FIRST- KOLOR  SECOND- LICZNOSC
int n,k,p,q,i,j,granica,l,pom,pprim,qprim;
pair<int,int> *tab;
vector<int> s1,s2,ciag,alternujacy;

bool mysort( pair<int,int> a, pair<int,int> b ) {
   return a.second < b.second;
 }
 
void odwroc_ciag()
{
	int i=0,j=alternujacy.size()-1;
	while(i<j)
	{
		swap(alternujacy[i],alternujacy[j]);
		i++;
		j--;
	}
}
/*
void wypisz_ciag()
{
	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";
}
*/
void stworz_ciag()
{
	for(i=0;i<k;i++)
	{
		for(j=0;j<tab[i].second;j++) ciag.push_back(tab[i].first);
	}
	
//	for(i=0;i<ciag.size();i++){ if(i==48) cout<<": ";
//	 cout<<ciag[i]<<" ";}
//	cout<<endl<<endl<<endl;
//	cout<<n<<endl;

	
	if(n%2!=0)
	{
		if(tab[k-1].second==(n+1)/2)
		{
			alternujacy.push_back(tab[k-1].first);// tab[k-1].second--;
			
			granica=(n+1)/2;
			for(i=0;i<granica;i++) s1.push_back(ciag[i]);
			for(i=granica;i<ciag.size()-1;i++) s2.push_back(ciag[i]);
			i=0;j=0;
			
			for(l=0;l<n;l++)
		  {
		  	if(l%2==0 && i<s1.size()) {alternujacy.push_back(s1[i]); i++;}
		  	if(l%2==1 && j<s2.size()) {alternujacy.push_back(s2[j]); j++;}
		  }
			
		}
		else
		{
			granica=(n+1)/2;
			for(i=0;i<granica;i++) s1.push_back(ciag[i]);
			for(i=granica;i<ciag.size();i++) s2.push_back(ciag[i]);
			i=0;j=0;
			
			for(l=0;l<n;l++)
		  {
		  	if(l%2==0 && i<s1.size()) {alternujacy.push_back(s1[i]); i++;}
		  	if(l%2==1 && j<s2.size()) {alternujacy.push_back(s2[j]); j++;}
		  }
		}
	}
	else if(n%2==0)
	{
		    granica=(n+1)/2;
		    for(i=0;i<granica;i++) s1.push_back(ciag[i]);
		    for(i=granica;i<ciag.size();i++) s2.push_back(ciag[i]);
		    i=0; j=0;
		  
		    for(l=0;l<n;l++)
		    {
		    if(l%2==0 && i<s1.size()) { alternujacy.push_back(s1[i]); i++;}
		    if(l%2==1 && j<s2.size()) {alternujacy.push_back(s2[j]); j++;}
		    }
		
	}
	
//	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";
//	cout<<endl<<endl<<endl;
}
//   FIRST- KOLOR  SECOND- LICZNOSC
int main()
{
	cin>>k>>p>>q;
	tab=new pair<int,int> [k];
	n=0;
	for(i=0;i<k;i++) {cin>>tab[i].second; tab[i].first=i+1; n+=tab[i].second;}
	
	if(p==q && tab[p-1].second<2)
	{
	 if(n==1) {cout<<1; return 0;}
	 else  {cout<<0; return 0;}
	}
//	 {cout<<0; return 0;}
	
	sort(tab,tab+k,mysort);
	
//	for(i=0;i<k;i++) cout<<tab[i].second<<" ";
	
	
	if(tab[k-1].second<=(n+1)/2)
	{
		if(tab[k-1].second==(n+1)/2)
		{
			if(n%2!=0)
			{
				if(p==q && p==tab[k-1].first)
				{
					stworz_ciag();
				//	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";
					
				}
				else {cout<<0; return 0;}
			}
			else if(n%2==0)
			{
				if(p==tab[k-1].first || q==tab[k-1].first)
				{
		            stworz_ciag();
				//	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";
				}
				else{cout<<0; return 0;}
			}
        }
        else if(tab[k-1].second<=(n-1)/2)
        {
        	n-=2;
//        	cout<<n<<endl;
        	for(i=0;i<k;i++){
        		if(tab[i].first==p) tab[i].second--;
        		if(tab[i].first==q) tab[i].second--;
			}
			sort(tab,tab+k,mysort);
			stworz_ciag();
			
			pprim=alternujacy[0]; qprim=alternujacy[alternujacy.size()-1];
//			cout<<pprim<<" "<<qprim<<endl;
			
			if(pprim==qprim)
			{
				alternujacy.insert(alternujacy.begin(),p);
				alternujacy.push_back(q);
			}
			else if(pprim!=qprim)
			{
				if(p!=pprim && p!=qprim && q!=pprim && q!=qprim)
				{
					alternujacy.insert(alternujacy.begin(),p);
		    	    alternujacy.push_back(q);
		    	}
				else if(p!=q && (p==pprim || q==qprim))
				{
					alternujacy.insert(alternujacy.begin(),p);
		    	    alternujacy.push_back(q);
		    	    
		    	    if(alternujacy[0]==alternujacy[1] || alternujacy[alternujacy.size()-1]==alternujacy[alternujacy.size()-2])
		    	    {
		    	    	swap(alternujacy[0],alternujacy[alternujacy.size()-1]);
		    	    	odwroc_ciag();
					}
				}
				else if(p==q && (p==pprim || q==qprim))
				{
					
					if(p==pprim)
					{
						for(i=1;i<alternujacy.size()-1;i++)
						{
							if(alternujacy[i-1]!=pprim && alternujacy[i+1]!=pprim && alternujacy[i]!=pprim) {swap(alternujacy[i],alternujacy[0]); break;}
						}
						alternujacy.insert(alternujacy.begin(),p);
						alternujacy.push_back(q);
					}
					else if(q==qprim)
					{
						
						for(i=alternujacy.size()-2;i>0;i--)
						{
							if(alternujacy[i-1]!=qprim && alternujacy[i+1]!=qprim && alternujacy[i]!=qprim && alternujacy[alternujacy.size()-2]!=alternujacy[i]) {swap(alternujacy[i],alternujacy[alternujacy.size()-1]); break;}
						}
						alternujacy.insert(alternujacy.begin(),p);
						alternujacy.push_back(q);
					}
				}
				else 
				{
					alternujacy.insert(alternujacy.begin(),p);
					alternujacy.push_back(q);
				}
			}
			
			
			
		}
	}
	else {cout<<0; return 0;}
	
    for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";

	
	
//	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";
	

}
//	for(i=0;i<alternujacy.size();i++) cout<<alternujacy[i]<<" ";